cmake_minimum_required(VERSION 3.24.2)

include(pico_sdk_import.cmake)

project(AutoAleTank)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Werror -std=c++17")
set(source_dir "${PROJECT_SOURCE_DIR}/src/")

pico_sdk_init()

file(GLOB_RECURSE source_files CONFIGURE_DEPENDS "${source_dir}/*.cpp")

add_executable(AutoAleTank "${source_files}")

target_link_libraries(AutoAleTank pico_stdlib pico_multicore hardware_gpio hardware_pwm hardware_irq)

pico_enable_stdio_usb(AutoAleTank 1)
pico_enable_stdio_uart(AutoAleTank 0)

pico_add_extra_outputs(AutoAleTank)





