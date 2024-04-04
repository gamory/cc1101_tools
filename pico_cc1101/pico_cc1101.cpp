#include <iostream>
#include <string.h>
#include <stdio.h>
#include <cstdlib> 
#include "pico/stdlib.h"
#include "hardware/spi.h"
#include "cc1101_defs.h"
#include "cc1101_func.h"

// getLine routine is not mine.  See https://github.com/ambotaku/pico-getLine

// Defines for SPI connection
#define MISO 6 // SPI0 RX on Pico
#define CS   7 // SPI0 CSn on Pico
#define SCLK 4 // SPI0 SCK on Pico
#define MOSI 5 // SPI0 TX on Pico
#define SPI_PORT spi0 // Specify that we are using the SPI0 interface hardware on the Pico
const int startLineLength = 8; // the linebuffer will automatically grow for longer lines
const char eof = 255;  

int spi_read(int cc1101_register, int length) {
    return 0;
}
int spi_write(int cc1101_register, int command) {
    return 0;
}
int config_radio(std::string mode, double freq) {
    // For the moment, we are just going to use a static config setup for 304MHz ASK/OOK
    // If we get that working well, we will look at making configurable options
    spi_write_blocking((spi_inst_t*)CC1101_IOCFG2, (const uint8_t*)0x29, 1); // Write IOCFG2 register
    spi_write_blocking((spi_inst_t*)CC1101_IOCFG1, (const uint8_t*)0x2E, 1); // Write IOCFG1 register
    spi_write_blocking((spi_inst_t*)CC1101_IOCFG0, (const uint8_t*)0x06, 1); // Write  register
    spi_write_blocking((spi_inst_t*)CC1101_FIFOTHR, (const uint8_t*)0x47, 1); // Write FIFOTHR register
    spi_write_blocking((spi_inst_t*)CC1101_SYNC1, (const uint8_t*)0x7A, 1); // Write SYNC1 register
    spi_write_blocking((spi_inst_t*)CC1101_SYNC0, (const uint8_t*)0x0E, 1); // Write SYNC0 register
    spi_write_blocking((spi_inst_t*)CC1101_PKTLEN, (const uint8_t*)0x14, 1); // Write PKTLEN register
    spi_write_blocking((spi_inst_t*)CC1101_PKTCTRL1, (const uint8_t*)0x04, 1); // Write PKTCTRL1 register
    spi_write_blocking((spi_inst_t*)CC1101_PKTCTRL0, (const uint8_t*)0x05, 1); // Write PKTCTRL0 register
    spi_write_blocking((spi_inst_t*)CC1101_ADDR, (const uint8_t*)0x00, 1); // Write ADDR register
    spi_write_blocking((spi_inst_t*)CC1101_CHANNR, (const uint8_t*)0x00, 1); // Write CHANNR register
    spi_write_blocking((spi_inst_t*)CC1101_FSCTRL1, (const uint8_t*)0x06, 1); // Write FSCTRL1 register
    spi_write_blocking((spi_inst_t*)CC1101_FSCTRL0, (const uint8_t*)0x00, 1); // Write FSCTRL0 register
    spi_write_blocking((spi_inst_t*)CC1101_FREQ2, (const uint8_t*)0x0B, 1); // Write FREQ2 register
    spi_write_blocking((spi_inst_t*)CC1101_FREQ1, (const uint8_t*)0xB1, 1); // Write FREQ1 register
    spi_write_blocking((spi_inst_t*)CC1101_FREQ0, (const uint8_t*)0x3B, 1); // Write FREQ0 register
    spi_write_blocking((spi_inst_t*)CC1101_MDMCFG4, (const uint8_t*)0xCA, 1); // Write MDMCFG4 register
    spi_write_blocking((spi_inst_t*)CC1101_MDMCFG3, (const uint8_t*)0xF8, 1); // Write MDMCFG3 register
    spi_write_blocking((spi_inst_t*)CC1101_MDMCFG2, (const uint8_t*)0x36, 1); // Write MDMCFG2 register
    spi_write_blocking((spi_inst_t*)CC1101_MDMCFG1, (const uint8_t*)0x22, 1); // Write MDMCFG1 register
    spi_write_blocking((spi_inst_t*)CC1101_MDMCFG0, (const uint8_t*)0xF8, 1); // Write MDMCFG0 register
    spi_write_blocking((spi_inst_t*)CC1101_DEVIATN, (const uint8_t*)0x40, 1); // Write DEVIATN register
    spi_write_blocking((spi_inst_t*)CC1101_MCSM2, (const uint8_t*)0x07, 1); // Write MCSM2 register
    spi_write_blocking((spi_inst_t*)CC1101_MCSM1, (const uint8_t*)0x30, 1); // Write MCSM1 register
    spi_write_blocking((spi_inst_t*)CC1101_MCSM0, (const uint8_t*)0x18, 1); // Write MCSM0 register
    spi_write_blocking((spi_inst_t*)CC1101_FOCCFG, (const uint8_t*)0x16, 1); // Write FOCCFG register
    spi_write_blocking((spi_inst_t*)CC1101_BSCFG, (const uint8_t*)0x6C, 1); // Write BSCFG register
    spi_write_blocking((spi_inst_t*)CC1101_AGCCTRL2, (const uint8_t*)0x43, 1); // Write AGCCTRL2 register
    spi_write_blocking((spi_inst_t*)CC1101_AGCCTRL1, (const uint8_t*)0x49, 1); // Write AGCCTRL1 register
    spi_write_blocking((spi_inst_t*)CC1101_AGCCTRL0, (const uint8_t*)0x91, 1); // Write AGCCTRL0 register
    spi_write_blocking((spi_inst_t*)CC1101_WOREVT1, (const uint8_t*)0x87, 1); // Write WOREVT1 register
    spi_write_blocking((spi_inst_t*)CC1101_WOREVT0, (const uint8_t*)0x6B, 1); // Write WOREVT0 register
    spi_write_blocking((spi_inst_t*)CC1101_WORCTRL, (const uint8_t*)0xFB, 1); // Write WORCTRL register
    spi_write_blocking((spi_inst_t*)CC1101_FREND1, (const uint8_t*)0x56, 1); // Write FREND1 register
    spi_write_blocking((spi_inst_t*)CC1101_FREND0, (const uint8_t*)0x11, 1); // Write FREND0 register
    spi_write_blocking((spi_inst_t*)CC1101_FSCAL3, (const uint8_t*)0xE9, 1); // Write FSCAL3 register
    spi_write_blocking((spi_inst_t*)CC1101_FSCAL2, (const uint8_t*)0x2A, 1); // Write FSCAL2 register
    spi_write_blocking((spi_inst_t*)CC1101_FSCAL1, (const uint8_t*)0x00, 1); // Write FSCAL1 register
    spi_write_blocking((spi_inst_t*)CC1101_FSCAL0, (const uint8_t*)0x1F, 1); // Write FSCAL0 register
    spi_write_blocking((spi_inst_t*)CC1101_RCCTRL1, (const uint8_t*)0x41, 1); // Write RCCTRL1 register
    spi_write_blocking((spi_inst_t*)CC1101_RCCTRL0, (const uint8_t*)0x00, 1); // Write RCCTRL0 register
    spi_write_blocking((spi_inst_t*)CC1101_FSTEST, (const uint8_t*)0x59, 1); // Write FSTEST register
    spi_write_blocking((spi_inst_t*)CC1101_PTEST, (const uint8_t*)0x7F, 1); // Write PTEST register
    spi_write_blocking((spi_inst_t*)CC1101_AGCTEST, (const uint8_t*)0x3F, 1); // Write AGCTEST register
    spi_write_blocking((spi_inst_t*)CC1101_TEST2, (const uint8_t*)0x81, 1); // Write TEST2 register
    spi_write_blocking((spi_inst_t*)CC1101_TEST1, (const uint8_t*)0x35, 1); // Write TEST1 register
    spi_write_blocking((spi_inst_t*)CC1101_TEST0, (const uint8_t*)0x0B, 1); // Write TEST0 register
    spi_write_blocking((spi_inst_t*)CC1101_TEST0, (const uint8_t*)0x0B, 1); // Write TEST0 register
    return 0;
}
int i2c_cmd_loop() {
    // This is where we will drop if acting as an i2c bridge to send commands to the cc1101
    while (true) {

    }
    return 0;
}
static char * getLine(bool fullDuplex = true, char lineBreak = '\n') {
    // th line buffer
    // will allocated by pico_malloc module if <cstdlib> gets included
    char * pStart = (char*)malloc(startLineLength); 
    char * pPos = pStart;  // next character position
    size_t maxLen = startLineLength; // current max buffer size
    size_t len = maxLen; // current max length
    int c;

    if(!pStart) {
        return NULL; // out of memory or dysfunctional heap
    }

    while(1) {
        c = getchar(); // expect next character entry
        if(c == eof || c == lineBreak) {
            break;     // non blocking exit
        }

        if (fullDuplex) {
            putchar(c); // echo for fullDuplex terminals
        }

        if(--len == 0) { // allow larger buffer
            len = maxLen;
            // double the current line buffer size
            char *pNew  = (char*)realloc(pStart, maxLen *= 2);
            if(!pNew) {
                free(pStart);
                return NULL; // out of memory abort
            }
            // fix pointer for new buffer
            pPos = pNew + (pPos - pStart);
            pStart = pNew;
        }

        // stop reading if lineBreak character entered 
        if((*pPos++ = c) == lineBreak) {
            break;
        }
    }

    *pPos = '\0';   // set string end mark
    return pStart;
}
int uart_cmd_loop() {
    // This is where we will drop when awaiting commands over the serial terminal
    while (true) {
        printf("\n> ");
        char * rawcmd;
        rawcmd = getLine();
        if (strcmp(rawcmd, "Butts") == 0) {
            printf("Butts were not only received, but identified.\n");
        }
    }
    return 0; // Shouldn't technically get here anyway, but if we did, clean return
}
int main() {
    stdio_init_all(); // Init UART, we will use USB UART per the CMake config
    spi_init(SPI_PORT, 500000); // Init SPI with a frequency of 500kHz
    gpio_set_function(MISO, GPIO_FUNC_SPI); // Init MISO pin
    gpio_set_function(SCLK, GPIO_FUNC_SPI); // Init SCLK pin
    gpio_set_function(MOSI, GPIO_FUNC_SPI); // Init MOSI pin
    gpio_init(CS); // Init CS pin
    gpio_set_dir(CS, GPIO_OUT); // Set CS as output
    printf("Pico cc1101 tool\n\n");
    // printf("Attempting to send basic config...");
    // config_radio("OOK", 304.0); // Not yet implemented, so this just calls a basic config
    printf("Entering UART shell loop...\n\n");
    uart_cmd_loop(); // Just for testing at this time
    return 0; // Oddly, this appears to be required by the compiler, even though in this instance, 
    // there is nothing to return this to.  If you try instantiating main as a void though, you get an error.  Bizarre.
}
