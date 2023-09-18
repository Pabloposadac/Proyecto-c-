//
// Created by posad on 18/09/2023.
//

#include "Nodo.h"

#include <utility>
#include "Calculo.h" // Incluye el archivo de encabezado de la clase Calculo

Nodo::Nodo(int datos, std::string cientifico1, std::string cientifico2)
        : datos(datos), cientifico1(std::move(cientifico1)), cientifico2(std::move(cientifico2)),
          esEventoA(Calculo::esPrimo(datos)), // verifica si datos es primo
          esEventoB(false), // Inicialmente, no es un evento B
          esEventoC(false), // Inicialmente, no es un evento C
          siguiente(nullptr),
          anterior(nullptr) {
}


