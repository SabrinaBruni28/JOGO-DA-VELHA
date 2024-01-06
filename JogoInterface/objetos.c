#include "objetos.h"

int vez = 1;

// Função para definir o tamanho da fonte de um rótulo (GtkLabel)
void set_font_size(GtkLabel *label, int size) {
    PangoAttrList *attr_list = pango_attr_list_new();
    PangoAttribute *attr = pango_attr_size_new_absolute(size * PANGO_SCALE);

    pango_attr_list_insert(attr_list, attr);

    gtk_label_set_attributes(label, attr_list);

    pango_attr_list_unref(attr_list);
}

// Função chamada quando o botão é clicado ou a janela é fechada
void on_insert(GtkWidget *widget, gpointer data) {
    g_print("Posição escolhida!\n");

    InfoBotao *info = (InfoBotao *)data;

    const gchar *textoX = "X";
    const gchar *textoO = "O";
    const gchar *textoVazio = " ";

    gchar *novotexto;
    if (vez == 1){
        novotexto = strdup(textoX);
        vez = 2;
    }

    else if (vez == 2){
        novotexto = strdup(textoO);
        vez = 1;
    }
    // Obtém o texto atual do botão
    const gchar *textoAtual = gtk_button_get_label(GTK_BUTTON(widget));

    // Verifica se o texto é vazio ou não
    if (g_strcmp0(textoAtual, textoVazio) == 0) {
        g_print("O botão não tem texto!\n");
        gtk_button_set_label(GTK_BUTTON(widget), novotexto);
        info->caractere = strdup(novotexto);
        g_print("\n%s\n", info->caractere);
    } 
    else {
        g_print("O botão tem o seguinte texto: %s\n", textoAtual);
        gtk_button_set_label(GTK_BUTTON(widget), textoVazio);
    }

    free(novotexto);
}

// Função chamada quando o botão é clicado ou a janela é fechada
void on_destroy(GtkWidget *widget, gpointer data) {
    g_print("Janela destruída!\n");
    gtk_main_quit();  // Encerra o loop principal do GTK
}

// Função chamada quando o botão Jogar é clicado
void on_button_jogar(GtkWidget *widget, gpointer data) {
    g_print("Botão Jogar!\n");
    gtk_widget_hide(data);
    create_game_window();
}


// Função para criar e configurar a janela de jogo
void create_game_window() {
    // Criar uma janela
    GtkWidget *janelaJogo = gtk_window_new(GTK_WINDOW_TOPLEVEL);
    gtk_window_set_title(GTK_WINDOW(janelaJogo), "Janela de jogo");

    // Definir o tamanho padrão da janela (largura, altura)
    gtk_window_set_default_size(GTK_WINDOW(janelaJogo), 1000, 800);
    gtk_container_set_border_width(GTK_CONTAINER(janelaJogo), 100);


    // Conectar o sinal "destroy" para fechar a nova janela e liberar a referência à janela anterior
    g_signal_connect(janelaJogo, "destroy", G_CALLBACK(on_destroy), NULL);

    // Criar um contêiner de grade (grid)
    GtkWidget *gridJogo = gtk_grid_new();
    gtk_container_add(GTK_CONTAINER(janelaJogo), gridJogo);

    // Criar os botões
    GtkWidget *buttonMatriz[3][3];
    int i, j;
    for(i = 0; i < 3; i++){
        for(j = 0; j < 3; j++){
            const gchar *texto = " ";
            buttonMatriz[i][j] = gtk_button_new_with_label(texto);
            gtk_grid_attach(GTK_GRID(gridJogo), buttonMatriz[i][j], j, i, 1, 1);
            gtk_widget_set_size_request(buttonMatriz[i][j], 50, 50);
            gtk_widget_set_hexpand(buttonMatriz[i][j], TRUE);
            gtk_widget_set_vexpand(buttonMatriz[i][j], TRUE);
            set_font_size(GTK_LABEL(gtk_bin_get_child(GTK_BIN(buttonMatriz[i][j]))), 30);

            // Atribuir informações personalizadas ao botão (linha e coluna)
            InfoBotao *info = g_new(InfoBotao, 1);
            info->linha = i;
            info->coluna = j;
            info->caractere = strdup(texto);
            g_object_set_data(G_OBJECT(buttonMatriz[i][j]), "info", info);
    
            g_signal_connect(buttonMatriz[i][j], "clicked", G_CALLBACK(on_insert), info);

            // Liberar a memória alocada para a estrutura InfoBotao quando o botão for destruído
            g_object_set_data_full(G_OBJECT(buttonMatriz[i][j]), "info", info, (GDestroyNotify)g_free);
        }
    }

    // Definir espaçamento entre as colunas
    gtk_grid_set_column_spacing(GTK_GRID(gridJogo), 10);

    // Definir espaçamento entre as linhas
    gtk_grid_set_row_spacing(GTK_GRID(gridJogo), 10);

    // Exibir todos os elementos da janela
    gtk_widget_show_all(janelaJogo);
}

// Função para criar e configurar a janela inicial
void create_initial_window() {
    // Criar uma janela
    GtkWidget *janelaInicial = gtk_window_new(GTK_WINDOW_TOPLEVEL);
    gtk_window_set_title(GTK_WINDOW(janelaInicial), "Janela de início");

    // Definir o tamanho padrão da janela (largura, altura)
    gtk_window_set_default_size(GTK_WINDOW(janelaInicial), 1000, 1000);
    gtk_container_set_border_width(GTK_CONTAINER(janelaInicial), 250);

     // Conectar o sinal "destroy" para fechar a aplicação quando a janela é fechada
    g_signal_connect(janelaInicial, "destroy", G_CALLBACK(on_destroy), NULL);
     
    // Criar um contêiner de grade (grid)
    GtkWidget *gridInicio = gtk_grid_new();
    gtk_container_add(GTK_CONTAINER(janelaInicial), gridInicio);

    // Criar um rótulo (título não clicável)
    GtkWidget *labelInicio = gtk_label_new("JOGO DA VELHA");

    // Definir alinhamento para centralizar o rótulo
    gtk_label_set_xalign(GTK_LABEL(labelInicio), 1);
    gtk_label_set_yalign(GTK_LABEL(labelInicio), 1);

    // Adicionar o rótulo ao grid (posição 0, 0)
    gtk_grid_attach(GTK_GRID(gridInicio), labelInicio, 1, 0, 1, 1);

    // Aumentar o tamanho da fonte do rótulo para 20 pontos
    set_font_size(GTK_LABEL(labelInicio), 50);

    // Criar os botões
    GtkWidget *buttonJogar = gtk_button_new_with_label("JOGAR");
    GtkWidget *buttonSair = gtk_button_new_with_label("SAIR");

    // Adicionar os botões ao contêiner de grade
    /* (grid, botão, coluna, linha, num de linhas ocupadas, num de colunas ocupadas) */
    gtk_grid_attach(GTK_GRID(gridInicio), buttonJogar, 0, 2, 1, 1);
    gtk_grid_attach(GTK_GRID(gridInicio), buttonSair, 2, 2, 1, 1);

    // Definir tamanho para os botões (largura, altura)
    gtk_widget_set_size_request(buttonJogar, 50, 10);
    gtk_widget_set_size_request(buttonSair, 50, 10);

    // Configurar a expansão horizontal e vertical dos botões
    gtk_widget_set_hexpand(buttonJogar, TRUE);
    gtk_widget_set_hexpand(buttonSair, TRUE);
    gtk_widget_set_vexpand(buttonJogar, TRUE);
    gtk_widget_set_vexpand(buttonSair, TRUE);

    // Aumentar o tamanho da fonte dos botões para 30 pontos
    set_font_size(GTK_LABEL(gtk_bin_get_child(GTK_BIN(buttonJogar))), 30);
    set_font_size(GTK_LABEL(gtk_bin_get_child(GTK_BIN(buttonSair))), 30);

    // Definir espaçamento entre as colunas
    gtk_grid_set_column_spacing(GTK_GRID(gridInicio), 10);

    // Definir espaçamento entre as linhas
    gtk_grid_set_row_spacing(GTK_GRID(gridInicio), 60);

    // Conectar o sinal "clicked" para os botões
    g_signal_connect(buttonJogar, "clicked", G_CALLBACK(on_button_jogar), janelaInicial);
    g_signal_connect(buttonSair, "clicked", G_CALLBACK(on_destroy), janelaInicial);

    // Exibir todos os elementos da janela
    gtk_widget_show_all(janelaInicial);

}