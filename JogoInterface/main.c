#include "objetos.h"


int main(int argc, char *argv[]){

    // Inicializar GTK
    gtk_init(&argc, &argv);

    // Chamar a função para criar a janela inicial
    create_initial_window();

    // Iniciar o loop principal do GTK
    gtk_main();
}
