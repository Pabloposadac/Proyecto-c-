#include "Eventos.h"

int main() {
    // Crear un objeto de la clase Eventos
    Eventos eventos;

    // Agregar eventos de ejemplo (puedes personalizar estos valores)
    eventos.agregarEvento(7, "Einstein", "Rosen");
    eventos.agregarEvento(11, "Rosen", "Einstein");
    eventos.agregarEvento(13, "Rosen", "Einstein");
    eventos.agregarEvento(17, "Rosen", "Einstein");


    eventos.mostrarEventos();
    eventos.mostrarEventosTipoA();
    eventos.mostrarEventosTipoB();
    eventos.verificarRestricciones();

    return 0;
}