cmake_minimum_required(VERSION 3.2)

project(
  KeyPad
  VERSION 0.1
  LANGUAGES C)

include_directories("./driver/")

add_executable(KeyPad)

target_sources(KeyPad PUBLIC source/keypad.c)
add_subdirectory(driver/matrixkeypad)
target_link_libraries(KeyPad matrixkeypad)


add_subdirectory(test)


include(CTest)
add_test(NAME matrixKeyPadTest COMMAND KeyPad)
