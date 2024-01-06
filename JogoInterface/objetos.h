#include <gtk/gtk.h>
#include <pango/pango.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>


// Estrutura para armazenar informações personalizadas de cada botão
typedef struct {
    int linha;
    int coluna;
    gchar* caractere;
} InfoBotao;

void set_font_size(GtkLabel *label, int size);

void on_insert(GtkWidget *widget, gpointer data);

void on_destroy(GtkWidget *widget, gpointer data);

void on_button_jogar(GtkWidget *widget, gpointer data);

void on_button_sair(GtkWidget *widget, gpointer data);

void create_game_window();

void create_initial_window();