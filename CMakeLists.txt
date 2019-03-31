cmake_minimum_required(VERSION 3.13)
project(Reversi C)

set(CMAKE_C_STANDARD 99)

add_executable(Reversi main.c estado.h estado.c comandos.c comandos.h alterarTabuleiro.c alterarTabuleiro.h)