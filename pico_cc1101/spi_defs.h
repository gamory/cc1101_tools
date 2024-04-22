// Defines for SPI connection
extern const uint spi_miso; // SPI0 RX on Pico
extern const uint spi_cs; // SPI0 CSn on Pico
extern const uint spi_sclk; // SPI0 SCK on Pico
extern const uint spi_mosi; // SPI0 TX on Pico
#define SPI_PORT spi0 // Specify that we are using the SPI0 interface hardware on the Pico
#define UART_ID uart0