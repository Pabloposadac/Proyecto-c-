//
// Created by posad on 18/09/2023.
//

#include "Eventos.h"
#include <utility>
#include "Calculo.h"
#include "Nodo.h"

Eventos::Eventos() : primero(nullptr), ultimo(nullptr), tamano(0) {}


void Eventos::agregarEvento(int datos, std::string cientifico1, std::string cientifico2) {
    // Crea un nuevo nodo con los datos proporcionados
    Nodo* nuevoEvento = new Nodo(datos, std::move(cientifico1), std::move(cientifico2));

    // Verifica si es un evento A (datos es primo)
    if (Calculo::esPrimo(datos)) {
        nuevoEvento->esEventoA = true;
        nuevoEvento->cientifico1 = "Einstein"; // Evento A es de Einstein
    }

    // Verifica si es un evento B
    if (nuevoEvento->esEventoA && nuevoEvento->anterior && nuevoEvento->anterior->esEventoA) {
        nuevoEvento->esEventoB = true;
    }

    // Verifica si es un evento C (coprimo con un evento A anterior)
    if (nuevoEvento->esEventoB) {
        Nodo* actual = ultimo;
        while (actual) {
            if (actual->esEventoA && Calculo::sonCoprimos(actual->datos, nuevoEvento->datos)) {
                nuevoEvento->esEventoC = true;
                break; // Termina la búsqueda, si cuando encuentra el evento A anterior
            }
            actual = actual->anterior;
        }
    }

    // Agrega el nuevo evento a la lista
    if (!primero) {
        primero = nuevoEvento;
        ultimo = nuevoEvento;
    } else {
        ultimo->siguiente = nuevoEvento;
        nuevoEvento->anterior = ultimo;
        ultimo = nuevoEvento;
    }

    tamano++;
}

void Eventos::mostrarEventos() const {
    Nodo* actual = primero;

    std::cout << "Lista de Eventos:" << std::endl;
    while (actual) {
        std::cout << "Datos: " << actual->datos << std::endl;
        std::cout << "Científico 1: " << actual->cientifico1 << std::endl;
        std::cout << "Científico 2: " << actual->cientifico2 << std::endl;
        std::cout << "Evento A: " << (actual->esEventoA ? "Sí" : "No") << std::endl;
        std::cout << "Evento B: " << (actual->esEventoB ? "Sí" : "No") << std::endl;
        std::cout << "Evento C: " << (actual->esEventoC ? "Sí" : "No") << std::endl;
        std::cout << "-----------------------------" << std::endl;
        actual = actual->siguiente;
    }
}

void Eventos::mostrarEventosTipoA() const {
    Nodo* actual = primero;

    std::cout << "Eventos de Tipo A:" << std::endl;
    while (actual) {
        if (actual->esEventoA) {
            std::cout << "Datos: " << actual->datos << std::endl;
            std::cout << "Científico 1: " << actual->cientifico1 << std::endl;
            std::cout << "Científico 2: " << actual->cientifico2 << std::endl;
            std::cout << "-----------------------------" << std::endl;
        }
        actual = actual->siguiente;
    }
}

void Eventos::mostrarEventosTipoB() const {
    Nodo* actual = primero;

    std::cout << "Eventos de Tipo B:" << std::endl;
    while (actual) {
        if (actual->esEventoB) {
            std::cout << "Datos: " << actual->datos << std::endl;
            std::cout << "Científico 1: " << actual->cientifico1 << std::endl;
            std::cout << "Científico 2: " << actual->cientifico2 << std::endl;
            std::cout << "-----------------------------" << std::endl;
        }
        actual = actual->siguiente;
    }
}

void Eventos::verificarRestricciones() {
    Nodo* actual = primero;

    while (actual && actual->siguiente) {
        // Verificar restricción para Evento C
        if (actual->esEventoB && actual->siguiente->esEventoA) {
            int datosEventoB = actual->datos;
            int datosEventoA = actual->siguiente->datos;

            // Verificar si los datos son coprimos
            if (Calculo::sonCoprimos(datosEventoA, datosEventoB)) {
                actual->siguiente->esEventoC = true;
            }
        }

        // Verificar restricción para Einstein y Rosen
        if (actual->cientifico1 == "Einstein" && actual->siguiente->cientifico2 == "Rosen") {
            actual->siguiente->cientifico1 = "Einstein";
        }

        actual = actual->siguiente;
    }
}








