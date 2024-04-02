cmake_minimum_required(VERSION 3.13)

# initialize the SDK based on PICO_SDK_PATH
# note: this must happen before project()
include(pico_sdk_import.cmake)

project(pico_cc1101)

# initialize the Raspberry Pi Pico SDK
pico_sdk_init()

# rest of your project
add_executable(pico_cc1101
    pico_cc1101.cpp
    cc1101_defs.h
)

# Add pico_stdlib library which aggregates commonly used features
target_link_libraries(
    pico_cc1101 
    pico_stdlib 
    hardware_spi
)

pico_enable_stdio_usb(pico_cc1101 1)
pico_enable_stdio_uart(pico_cc1101 0)

# create map/bin/hex/uf2 file in addition to ELF.
pico_add_extra_outputs(pico_cc1101)
