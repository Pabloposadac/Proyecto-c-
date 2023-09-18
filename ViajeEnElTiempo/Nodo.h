//
// Created by posad on 18/09/2023.
//

#ifndef VIAJEENELTIEMPO_NODO_H
#define VIAJEENELTIEMPO_NODO_H
#include <iostream>
#include <string>

class Nodo {
public:
    int datos;               // Datos del evento (número aleatorio entre 1 y 100)
    std::string cientifico1; // Nombre del científico 1 (Einstein o Rosen)
    std::string cientifico2; // Nombre del científico 2 (Einstein o Rosen)
    bool esEventoA;          // Variable para determinar si es un evento tipo A
    bool esEventoB;          // Variable para determinar si es un evento tipo B
    bool esEventoC;          // Variable para determinar si es un evento tipo C
    Nodo* siguiente;         // Puntero hacia el siguiente nodo
    Nodo* anterior;          // Puntero hacia el nodo anterior

    Nodo(int datos, std::string cientifico1, std::string cientifico2);

};

#endif //VIAJEENELTIEMPO_NODO_H
