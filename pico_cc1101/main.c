#include <string.h>
#include <stdio.h>
#include "pico/stdlib.h"
#include "hardware/spi.h"
#include "hardware/uart.h"
#include "pico/bootrom.h"
#include "console.h"
#include "command.h"

// declare initialization method
void init ();

// declare semaphore to control command execution
semaphore_t semCommand;

// Defines for SPI connection
#define MISO 6 // SPI0 RX on Pico
#define CS   7 // SPI0 CSn on Pico
#define SCLK 4 // SPI0 SCK on Pico
#define MOSI 5 // SPI0 TX on Pico
#define SPI_PORT spi0 // Specify that we are using the SPI0 interface hardware on the Pico
#define UART_ID uart0

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
  // initialize stdio
  stdio_init_all();
  stdio_flush();
  setbuf(stdout, NULL); // make sure character input is buffered
  // initialize command semaphore
  sem_init(&semCommand, 0, 1);
}