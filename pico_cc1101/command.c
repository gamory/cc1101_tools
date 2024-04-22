
#include <stdio.h>
#include "command.h"
#include "pico/bootrom.h"
#include "pico/stdlib.h"
#include "hardware/spi.h"
#include "cc1101_defs.h"
#include "cc1101_func.h"
#include "spi_defs.h"

#define UART_ID uart0
#define SPI_PORT spi0
uint8_t data[6]; // Storage buffer for SPI calls
spi_inst_t *spi = SPI_PORT;

// help message
const char * HELP = 
  "CC1101 Console - v0.1\n"
  "\n"
  "Commands - General:\n"
  "\n"
  "help - Display this help message\n"
  "clear - Clear console window\n"
  "\n"
  "Commands - cc1101 specific:\n"
  "\n"
  "getver - Grab the chip version number\n"
  "\n"
  "Commands - Special\n"
  "\n"
  "bootrom - Reset and boot into BOOTSEL ROM\n";


void uart_clear_screen() { // Clear the UART console
    // uart_putc(UART_ID, 0x1B);
    // uart_putc(UART_ID, 0x5B);
    // uart_putc(UART_ID, 0x32);
    // uart_putc(UART_ID, 0x4A);
    // uart_putc(UART_ID, 0x1B);
    // uart_putc(UART_ID, 0x63);
    printf("%c", 0x1B);
    printf("%c", 0x5B);
    printf("%c", 0x32);
    printf("%c", 0x4A);
    printf("%c", 0x1B);
    printf("%c", 0x63);
    return;
}
void reg_write(spi_inst_t *spi, const uint cs, const uint8_t reg, const uint8_t data) { // Write 1 byte to the specified register
  uint8_t msg[2];            
  // Construct message (set ~W bit low, MB bit low)
  msg[0] = 0x00 | reg;
  msg[1] = data;

  // Write to register
  gpio_put(cs, 0);
  spi_write_blocking(spi, msg, 2);
  gpio_put(cs, 1);
}
int reg_read(spi_inst_t *spi, const uint cs, const uint8_t reg, uint8_t *buf, const uint8_t nbytes) { // Read byte(s) from specified register. If nbytes > 1, read from consecutive registers.
  int num_bytes_read = 0;
  uint8_t mb = 0;
  // Determine if multiple byte (MB) bit should be set
  if (nbytes < 1) {
    return -1;
  }
  else if (nbytes == 1) {
    mb = 0;
  }
  else {
    mb = 1;
  }

  // Construct message (set ~W bit high)
  uint8_t msg = 0x80 | (mb << 6) | reg;
  // Read from register
  gpio_put(cs, 0);
  spi_write_blocking(spi, &msg, 1);
  num_bytes_read = spi_read_blocking(spi, 0, buf, nbytes);
  gpio_put(cs, 1);
  return num_bytes_read;
}
int config_radio(double freq) { // Send bulk config commands
    // For the moment, we are just going to use a static config setup for 304MHz ASK/OOK
    // If we get that working well, we will look at making configurable options
    printf("Writing CC1101_IOCFG2...");
    spi_write_blocking((spi_inst_t*)CC1101_IOCFG2, (const uint8_t*)0x29, 1); // Write IOCFG2 register
    printf("\n");
    printf("Writing CC1101_IOCFG1...");
    spi_write_blocking((spi_inst_t*)CC1101_IOCFG1, (const uint8_t*)0x2E, 1); // Write IOCFG1 register
    printf("\n");
    printf("Writing CC1101_IOCFG0...");
    spi_write_blocking((spi_inst_t*)CC1101_IOCFG0, (const uint8_t*)0x06, 1); // Write  register
    printf("\n");
    printf("Writing CC1101_FIFOTHR...");
    spi_write_blocking((spi_inst_t*)CC1101_FIFOTHR, (const uint8_t*)0x47, 1); // Write FIFOTHR register
    printf("\n");
    printf("Writing CC1101_SYNC1...");
    spi_write_blocking((spi_inst_t*)CC1101_SYNC1, (const uint8_t*)0x7A, 1); // Write SYNC1 register
    printf("\n");
    printf("Writing CC1101_SYNC0...");
    spi_write_blocking((spi_inst_t*)CC1101_SYNC0, (const uint8_t*)0x0E, 1); // Write SYNC0 register
    printf("\n");
    printf("Writing CC1101_PKTLEN...");
    spi_write_blocking((spi_inst_t*)CC1101_PKTLEN, (const uint8_t*)0x14, 1); // Write PKTLEN register
    printf("\n");
    printf("Writing CC1101_PKTCTRL1...");
    spi_write_blocking((spi_inst_t*)CC1101_PKTCTRL1, (const uint8_t*)0x04, 1); // Write PKTCTRL1 register
    printf("\n");
    printf("Writing CC1101_PKTCTRL0...");
    spi_write_blocking((spi_inst_t*)CC1101_PKTCTRL0, (const uint8_t*)0x05, 1); // Write PKTCTRL0 register
    printf("\n");
    printf("Writing CC1101_ADDR...");
    spi_write_blocking((spi_inst_t*)CC1101_ADDR, (const uint8_t*)0x00, 1); // Write ADDR register
    printf("\n");
    printf("Writing CC1101_CHANNR...");
    spi_write_blocking((spi_inst_t*)CC1101_CHANNR, (const uint8_t*)0x00, 1); // Write CHANNR register
    printf("\n");
    printf("Writing CC1101_FSCTRL1...");
    spi_write_blocking((spi_inst_t*)CC1101_FSCTRL1, (const uint8_t*)0x06, 1); // Write FSCTRL1 register
    printf("\n");
    printf("Writing CC1101_FSCTRL0...");
    spi_write_blocking((spi_inst_t*)CC1101_FSCTRL0, (const uint8_t*)0x00, 1); // Write FSCTRL0 register
    printf("\n");
    printf("Writing CC1101_FREQ2...");
    spi_write_blocking((spi_inst_t*)CC1101_FREQ2, (const uint8_t*)0x0B, 1); // Write FREQ2 register
    printf("\n");
    printf("Writing CC1101_FREQ1...");
    spi_write_blocking((spi_inst_t*)CC1101_FREQ1, (const uint8_t*)0xB1, 1); // Write FREQ1 register
    printf("\n");
    printf("Writing CC1101_FREQ0...");
    spi_write_blocking((spi_inst_t*)CC1101_FREQ0, (const uint8_t*)0x3B, 1); // Write FREQ0 register
    printf("\n");
    printf("Writing CC1101_MDMCFG4...");
    spi_write_blocking((spi_inst_t*)CC1101_MDMCFG4, (const uint8_t*)0xCA, 1); // Write MDMCFG4 register
    printf("\n");
    printf("Writing CC1101_MDMCFG3...");
    spi_write_blocking((spi_inst_t*)CC1101_MDMCFG3, (const uint8_t*)0xF8, 1); // Write MDMCFG3 register
    printf("\n");
    printf("Writing CC1101_MDMCFG2...");
    spi_write_blocking((spi_inst_t*)CC1101_MDMCFG2, (const uint8_t*)0x36, 1); // Write MDMCFG2 register
    printf("\n");
    printf("Writing CC1101_MDMCFG1...");
    spi_write_blocking((spi_inst_t*)CC1101_MDMCFG1, (const uint8_t*)0x22, 1); // Write MDMCFG1 register
    printf("\n");
    printf("Writing CC1101_MDMCFG0...");
    spi_write_blocking((spi_inst_t*)CC1101_MDMCFG0, (const uint8_t*)0xF8, 1); // Write MDMCFG0 register
    printf("\n");
    printf("Writing CC1101_DEVIATN...");
    spi_write_blocking((spi_inst_t*)CC1101_DEVIATN, (const uint8_t*)0x40, 1); // Write DEVIATN register
    printf("\n");
    printf("Writing CC1101_MCSM2...");
    spi_write_blocking((spi_inst_t*)CC1101_MCSM2, (const uint8_t*)0x07, 1); // Write MCSM2 register
    printf("\n");
    printf("Writing CC1101_MCSM1...");
    spi_write_blocking((spi_inst_t*)CC1101_MCSM1, (const uint8_t*)0x30, 1); // Write MCSM1 register
    printf("\n");
    printf("Writing CC1101_MCSM0...");
    spi_write_blocking((spi_inst_t*)CC1101_MCSM0, (const uint8_t*)0x18, 1); // Write MCSM0 register
    printf("\n");
    printf("Writing CC1101_FOCCFG...");
    spi_write_blocking((spi_inst_t*)CC1101_FOCCFG, (const uint8_t*)0x16, 1); // Write FOCCFG register
    printf("\n");
    printf("Writing CC1101_BSCFG...");
    spi_write_blocking((spi_inst_t*)CC1101_BSCFG, (const uint8_t*)0x6C, 1); // Write BSCFG register
    printf("\n");
    printf("Writing CC1101_AGCCTRL2...");
    spi_write_blocking((spi_inst_t*)CC1101_AGCCTRL2, (const uint8_t*)0x43, 1); // Write AGCCTRL2 register
    printf("\n");
    printf("Writing CC1101_AGCCTRL1...");
    spi_write_blocking((spi_inst_t*)CC1101_AGCCTRL1, (const uint8_t*)0x49, 1); // Write AGCCTRL1 register
    printf("\n");
    printf("Writing CC1101_AGCCTRL0...");
    spi_write_blocking((spi_inst_t*)CC1101_AGCCTRL0, (const uint8_t*)0x91, 1); // Write AGCCTRL0 register
    printf("\n");
    printf("Writing CC1101_WOREVT1...");
    spi_write_blocking((spi_inst_t*)CC1101_WOREVT1, (const uint8_t*)0x87, 1); // Write WOREVT1 register
    printf("\n");
    printf("Writing CC1101_WOREVT0...");
    spi_write_blocking((spi_inst_t*)CC1101_WOREVT0, (const uint8_t*)0x6B, 1); // Write WOREVT0 register
    printf("\n");
    printf("Writing CC1101_WORCTRL...");
    spi_write_blocking((spi_inst_t*)CC1101_WORCTRL, (const uint8_t*)0xFB, 1); // Write WORCTRL register
    printf("\n");
    printf("Writing CC1101_FREND1...");
    spi_write_blocking((spi_inst_t*)CC1101_FREND1, (const uint8_t*)0x56, 1); // Write FREND1 register
    printf("\n");
    printf("Writing CC1101_FREND0...");
    spi_write_blocking((spi_inst_t*)CC1101_FREND0, (const uint8_t*)0x11, 1); // Write FREND0 register
    printf("\n");
    printf("Writing CC1101_FSCAL3...");
    spi_write_blocking((spi_inst_t*)CC1101_FSCAL3, (const uint8_t*)0xE9, 1); // Write FSCAL3 register
    printf("\n");
    printf("Writing CC1101_FSCAL2...");
    spi_write_blocking((spi_inst_t*)CC1101_FSCAL2, (const uint8_t*)0x2A, 1); // Write FSCAL2 register
    printf("\n");
    printf("Writing CC1101_FSCAL1...");
    spi_write_blocking((spi_inst_t*)CC1101_FSCAL1, (const uint8_t*)0x00, 1); // Write FSCAL1 register
    printf("\n");
    printf("Writing CC1101_FSCAL0...");
    spi_write_blocking((spi_inst_t*)CC1101_FSCAL0, (const uint8_t*)0x1F, 1); // Write FSCAL0 register
    printf("\n");
    printf("Writing CC1101_RCCTRL1...");
    spi_write_blocking((spi_inst_t*)CC1101_RCCTRL1, (const uint8_t*)0x41, 1); // Write RCCTRL1 register
    printf("\n");
    printf("Writing CC1101_RCCTRL0...");
    spi_write_blocking((spi_inst_t*)CC1101_RCCTRL0, (const uint8_t*)0x00, 1); // Write RCCTRL0 register
    printf("\n");
    printf("Writing CC1101_FSTEST...");
    spi_write_blocking((spi_inst_t*)CC1101_FSTEST, (const uint8_t*)0x59, 1); // Write FSTEST register
    printf("\n");
    printf("Writing CC1101_PTEST...");
    spi_write_blocking((spi_inst_t*)CC1101_PTEST, (const uint8_t*)0x7F, 1); // Write PTEST register
    printf("\n");
    printf("Writing CC1101_AGCTEST...");
    spi_write_blocking((spi_inst_t*)CC1101_AGCTEST, (const uint8_t*)0x3F, 1); // Write AGCTEST register
    printf("\n");
    printf("Writing CC1101_TEST2...");
    spi_write_blocking((spi_inst_t*)CC1101_TEST2, (const uint8_t*)0x81, 1); // Write TEST2 register
    printf("\n");
    printf("Writing CC1101_TEST1...");
    spi_write_blocking((spi_inst_t*)CC1101_TEST1, (const uint8_t*)0x35, 1); // Write TEST1 register
    printf("\n");
    printf("Writing CC1101_TEST0...");
    spi_write_blocking((spi_inst_t*)CC1101_TEST0, (const uint8_t*)0x0B, 1); // Write TEST0 register
    printf("\n");
    printf("Writing CC1101_TEST0...");
    spi_write_blocking((spi_inst_t*)CC1101_TEST0, (const uint8_t*)0x0B, 1); // Write TEST0 register
    printf("\n");
    printf("Register writes complete. \n");
    return 0;
}
void cc1101_getver() {
  reg_read(spi, spi_cs, CC1101_VERSION, data, 1);
  printf("0x%X\n", data[0]);
}
void commandProcessor () { // Main command processor loop (Runs on core 1)
  for (;;) {
    // block until console permits command processing
    sem_acquire_blocking(&semCommand);

    // continue if command line is empty
    if (0 == strlen(commandLine)) continue;
    // help command
    else if (0 == strcmp(commandLine, "help")) printf("%s", HELP);
    // clear command
    else if (0 == strcmp(commandLine, "clear")) uart_clear_screen();
    // cc1101 function - Get chip version
    else if (0 == strcmp(commandLine, "getver")) cc1101_getver();
    // cc1101 function - Set basic config
    else if (0 == strcmp(commandLine, "defaults")) config_radio(304.0);
    // bootrom command
    else if (0 == strcmp(commandLine, "bootrom")) reset_usb_boot(0, 0);
    // invalid input error
    else printf("Unknown command %s. Enter help command for help.\n", commandLine);
  }
}
