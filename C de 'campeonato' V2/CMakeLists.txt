cmake_minimum_required(VERSION 3.13)
project(proj C)

set(CMAKE_C_STANDARD 99)

add_executable(proj main.c estado.h estado.c menu.c menu.h comandos.c comandos.h stack.c stack.h bot.c bot.h)