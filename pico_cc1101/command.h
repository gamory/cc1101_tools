
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <math.h>
#include "pico/mutex.h"
#include "hardware/spi.h"
#include "pico/stdlib.h"
#include "pico/multicore.h"

#include "console.h"

// access to externally defined variables
extern semaphore_t semCommand;
extern char commandLine[];

void reg_write(spi_inst_t *spi, const uint cs, const uint8_t reg, const uint8_t data);
int reg_read(spi_inst_t *spi, const uint cs, const uint8_t reg, uint8_t *buf, uint8_t nbytes);
void uart_clear_screen();
int config_radio(double freq);
void cc1101_getver();
void commandProcessor ();