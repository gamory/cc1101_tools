#include <string.h>
#include <stdio.h>
#include "pico/stdlib.h"
#include "hardware/spi.h"
#include "hardware/uart.h"
#include "pico/bootrom.h"
#include "console.h"
#include "command.h"
#include "spi_defs.h"

// Defines for SPI connection
const uint spi_miso = 6; // SPI0 RX on Pico
const uint spi_cs = 7; // SPI0 CSn on Pico
const uint spi_sclk = 4; // SPI0 SCK on Pico
const uint spi_mosi = 5; // SPI0 TX on Pico

// declare initialization method
void init ();

// declare semaphore to control command execution
semaphore_t semCommand;

// This starts up the UART console on core 1, and then starts up the command processor on core 0
int main () {
  init();
  // run console on core1
  multicore_launch_core1(console);
  // run command processor here on core0
  commandProcessor();
}

// initialize application
void init () {
  // Init SPI
  spi_inst_t *spi = SPI_PORT; // Set port
  gpio_init(spi_cs); // Init our CS pin
  gpio_set_dir(spi_cs, GPIO_OUT); // Set the CS pin to output
  gpio_put(spi_cs, 1); // Set the CS pin high
  spi_init(spi, 500 * 1000); // Initialize SPI port at 500 kHz
  // Set SPI format
  spi_set_format(SPI_PORT,  // SPI instance
                    8,      // Number of bits per transfer
                    1,      // Polarity (CPOL)
                    1,      // Phase (CPHA)
                    SPI_MSB_FIRST);
  // Initialize SPI pins
  gpio_set_function(spi_sclk, GPIO_FUNC_SPI); // Setup clock pin for SPI
  gpio_set_function(spi_mosi, GPIO_FUNC_SPI); // Setup MOSI pin for SPI
  gpio_set_function(spi_miso, GPIO_FUNC_SPI); // Setup MISO pin for SPI
  // initialize stdio
  stdio_init_all();
  stdio_flush();
  setbuf(stdout, NULL); // make sure character input is buffered
  // initialize command semaphore
  sem_init(&semCommand, 0, 1);
}