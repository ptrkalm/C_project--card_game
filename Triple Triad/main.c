#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <gtk/gtk.h>
#include "css.h"
#include "cards.h"
#include "gtk.h"


int main(int argc, char *argv[]) {

    // GTK //
    gtk_init(&argc, &argv);
    gtk_css();
    cards();


    window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
    gtk_window_set_title(GTK_WINDOW(window),"Triple Triad");
    gtk_window_set_position(GTK_WINDOW(window),GTK_WIN_POS_CENTER);
    gtk_window_set_default_size(GTK_WINDOW(window), 900, 650);
    g_signal_connect(G_OBJECT(window),"destroy",G_CALLBACK(gtk_main_quit), NULL);
    gtk_container_set_border_width(GTK_CONTAINER(window), 10);
    gtk_widget_set_name(window, "mm_box");
    global_box = gtk_box_new(GTK_ORIENTATION_VERTICAL, 0);
    gtk_container_add(GTK_CONTAINER(window), global_box);

    //MAIN MENU//
    mm_box = gtk_box_new(GTK_ORIENTATION_VERTICAL, 0);
    gtk_box_pack_start(GTK_BOX(global_box), mm_box, FALSE, FALSE, 0);

    gtk_widget_set_halign (GTK_WIDGET(mm_box),GTK_ALIGN_CENTER);
    gtk_widget_set_valign (GTK_WIDGET(mm_box),GTK_ALIGN_CENTER);

    empty_label = gtk_label_new("");
    play_btn = gtk_button_new();
    quit_btn = gtk_button_new();
    gtk_widget_set_name(play_btn, "play_btn");
    gtk_widget_set_name(quit_btn, "quit_btn");
    g_signal_connect(G_OBJECT(play_btn),"clicked",G_CALLBACK(deck_menu_open), NULL);
    g_signal_connect(G_OBJECT(quit_btn),"clicked",G_CALLBACK(gtk_main_quit), NULL);
    gtk_box_pack_start(GTK_BOX(mm_box), empty_label, FALSE, FALSE, 5);
    gtk_box_pack_start(GTK_BOX(mm_box), play_btn, FALSE, FALSE, 5);
    gtk_box_pack_start(GTK_BOX(mm_box), quit_btn, FALSE, FALSE, 5);
    gtk_widget_set_size_request(empty_label, 0, 400);
    gtk_widget_set_size_request(play_btn, 80, 30);
    gtk_widget_set_size_request(quit_btn, 80, 30);

    gtk_widget_show(window);
    gtk_widget_show(global_box);
    gtk_widget_show_all(mm_box);

    gtk_main();

}
