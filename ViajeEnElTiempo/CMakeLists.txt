cmake_minimum_required(VERSION 3.26)
project(ViajeEnElTiempo)

set(CMAKE_CXX_STANDARD 20)

add_executable(ViajeEnElTiempo main.cpp
        Nodo.cpp
        Nodo.h
        Eventos.cpp
        Eventos.h
        Calculo.cpp
        Calculo.h)
