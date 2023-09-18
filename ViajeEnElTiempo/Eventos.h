//
// Created by posad on 18/09/2023.
//

#ifndef VIAJEENELTIEMPO_EVENTOS_H
#define VIAJEENELTIEMPO_EVENTOS_H

#include "Nodo.h"

class Eventos {
private:
    Nodo* primero;
    Nodo* ultimo;
    int tamano;

public:
    Eventos();

    void agregarEvento(int datos, std::string cientifico1, std::string cientifico2);
    void mostrarEventos() const;
    void mostrarEventosTipoA() const;
    void mostrarEventosTipoB() const;
    void verificarRestricciones();
};

#endif //VIAJEENELTIEMPO_EVENTOS_H
