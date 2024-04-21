cmake_minimum_required(VERSION 3.13)

# initialize the SDK based on PICO_SDK_PATH
# note: this must happen before project()
include(pico_sdk_import.cmake)

project(console)
set(CMAKE_C_STANDARD 11)
set(CMAKE_CXX_STANDARD 17)

pico_sdk_init()
add_executable(console main.c console.c command.c)

target_link_libraries(console pico_stdlib pico_multicore hardware_spi)
pico_add_extra_outputs(console)

pico_enable_stdio_uart(console 1)
pico_enable_stdio_usb(console 1)