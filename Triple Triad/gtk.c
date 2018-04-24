#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <gtk/gtk.h>
#include "css.h"
#include "cards.h"
#include "gtk.h"

void deck_menu_open(GtkWidget *widget, gpointer data) {
    for (int i = 1; i < 6; i++) {
        blue_hand_help[i] = 0;
        move_number = 0;
    }
    for (int i = 1; i < 6; i++){
        blue_active[i] = 1;
        red_active[i] = 1;
    }

    chdeck_box = gtk_box_new(GTK_ORIENTATION_VERTICAL, 0);
    gtk_box_pack_start(GTK_BOX(global_box), chdeck_box, FALSE, FALSE, 0);
    gtk_widget_set_halign (GTK_WIDGET(chdeck_box),GTK_ALIGN_CENTER);
    gtk_widget_set_valign (GTK_WIDGET(chdeck_box),GTK_ALIGN_CENTER);

    empty_label = gtk_label_new("");
    gtk_box_pack_start(GTK_BOX(chdeck_box), empty_label, FALSE, FALSE, 0);
    gtk_widget_set_size_request(empty_label, 0, 150);

    deck_box = gtk_box_new(GTK_ORIENTATION_HORIZONTAL, 31);
    gtk_box_pack_start(GTK_BOX(chdeck_box), deck_box, FALSE, FALSE, 0);

    for (int i = 1; i < 6; i++) {
        tier[i] = gtk_box_new(GTK_ORIENTATION_VERTICAL, 0);
        gtk_box_pack_end(GTK_BOX(deck_box), tier[i], FALSE, FALSE, 0);
        cards_tab[i][5]->button = gtk_button_new();
        gtk_widget_set_name(cards_tab[i][5]->button, cards_tab[i][5]->style_g);
        gtk_widget_set_size_request(cards_tab[i][5]->button, 130, 173);
        g_signal_connect(G_OBJECT(cards_tab[i][5]->button),"clicked",G_CALLBACK(card_pick), NULL);
        gtk_box_pack_end(GTK_BOX(tier[i]), cards_tab[i][5]->button, FALSE, FALSE, 0);
        for (int j = 4; j > 0; j--) {
            cards_tab[i][j]->button = gtk_button_new();
            gtk_widget_set_name(cards_tab[i][j]->button, cards_tab[i][j]->style_g);
            gtk_widget_set_size_request(cards_tab[i][j]->button, 130, 60);
            g_signal_connect(G_OBJECT(cards_tab[i][j]->button),"clicked",G_CALLBACK(card_pick), NULL);
            gtk_box_pack_end(GTK_BOX(tier[i]), cards_tab[i][j]->button, FALSE, FALSE, 0);
        }
    }

    empty_label = gtk_label_new("");
    gtk_box_pack_start(GTK_BOX(chdeck_box), empty_label, FALSE, FALSE, 0);
    gtk_widget_set_size_request(empty_label, 0, 10);

    md_box = gtk_box_new(GTK_ORIENTATION_HORIZONTAL, 20);
    gtk_box_pack_start(GTK_BOX(chdeck_box), md_box, FALSE, FALSE, 0);

    back_btn = gtk_button_new();
    gtk_box_pack_start(GTK_BOX(md_box), back_btn, FALSE, FALSE, 0);
    g_signal_connect(G_OBJECT(back_btn),"clicked",G_CALLBACK(deck_back), NULL);
    gtk_widget_set_name(back_btn, "back_btn");
    gtk_widget_set_size_request(back_btn, 130, 50);

    empty_label = gtk_label_new("");
    gtk_box_pack_start(GTK_BOX(md_box), empty_label, FALSE, FALSE, 0);
    gtk_widget_set_size_request(empty_label, 482, 0);

    cont_btn = gtk_button_new();
    gtk_box_pack_start(GTK_BOX(md_box), cont_btn, FALSE, FALSE, 0);
    g_signal_connect(G_OBJECT(cont_btn),"clicked",G_CALLBACK(pg_box_open), NULL);
    gtk_widget_set_name(cont_btn, "cont_btn");
    gtk_widget_set_size_request(cont_btn, 130, 50);
    gtk_widget_set_sensitive(cont_btn, FALSE);

    set_red_hand();

    gtk_widget_hide(mm_box);
    gtk_widget_show_all(chdeck_box);
    gtk_widget_set_name(window, "deck_box");
}

void deck_back(GtkWidget *widget, gpointer data) {
    gtk_widget_hide(chdeck_box);
    gtk_widget_show_all(mm_box);
    gtk_widget_set_name(window, "mm_box");

}

void pg_box_open(GtkWidget *widget, gpointer data) {
    gtk_widget_hide(chdeck_box);

    card_copy = blue_hand[1];

    pg_box = gtk_box_new(GTK_ORIENTATION_VERTICAL, 0);
    gtk_container_add(GTK_CONTAINER(global_box), pg_box);
    gtk_widget_set_halign (GTK_WIDGET(pg_box),GTK_ALIGN_CENTER);
    gtk_widget_set_valign (GTK_WIDGET(pg_box),GTK_ALIGN_CENTER);

    empty_label = gtk_label_new("");
    gtk_box_pack_start(GTK_BOX(pg_box), empty_label, FALSE, FALSE, 0);
    gtk_widget_set_size_request(empty_label, 0, 60);

    pgc_box = gtk_box_new(GTK_ORIENTATION_HORIZONTAL, 60);
    gtk_box_pack_start(GTK_BOX(pg_box), pgc_box, FALSE, FALSE, 0);
    gtk_widget_set_halign (GTK_WIDGET(pgc_box),GTK_ALIGN_CENTER);
    gtk_widget_set_valign (GTK_WIDGET(pgc_box),GTK_ALIGN_CENTER);

    blue_box = gtk_box_new(GTK_ORIENTATION_VERTICAL, 0);
    gtk_box_pack_start(GTK_BOX(pgc_box), blue_box, FALSE, FALSE, 0);
    gtk_widget_set_halign (GTK_WIDGET(blue_box),GTK_ALIGN_CENTER);
    gtk_widget_set_valign (GTK_WIDGET(blue_box),GTK_ALIGN_CENTER);
    blue_hand[1]->button = gtk_button_new();
    gtk_box_pack_end(GTK_BOX(blue_box), blue_hand[1]->button, FALSE, FALSE, 0);
    gtk_widget_set_size_request(blue_hand[1]->button, 130, 173);
    gtk_widget_set_name(blue_hand[1]->button, blue_hand[1]->style_b);
    g_signal_connect(G_OBJECT(blue_hand[1]->button),"clicked",G_CALLBACK(card_choose), NULL);
    for (int i = 2; i <= 5; i++) {
        blue_hand[i]->button = gtk_button_new();
        gtk_box_pack_end(GTK_BOX(blue_box), blue_hand[i]->button, FALSE, FALSE, 0);
        gtk_widget_set_size_request(blue_hand[i]->button, 130, 60);
        gtk_widget_set_name(blue_hand[i]->button, blue_hand[i]->style_b);
        g_signal_connect(G_OBJECT(blue_hand[i]->button),"clicked",G_CALLBACK(card_choose), NULL);
    }



    grid_box = gtk_box_new(GTK_ORIENTATION_VERTICAL, 0);
    gtk_box_pack_start(GTK_BOX(pgc_box), grid_box, FALSE, FALSE, 0);
    grid = gtk_grid_new();
    gtk_box_pack_start(GTK_BOX(grid_box), grid, FALSE, FALSE, 0);
    for (int i = 1; i < 4; i++) {
        for (int j = 1; j < 4; j++) {
            grids_tab[i][j]->button = gtk_button_new();
            grids_tab[i][j]->color = GREY;
            grids_tab[i][j]->top = 11;
            grids_tab[i][j]->right = 11;
            grids_tab[i][j]->bottom = 11;
            grids_tab[i][j]->left = 11;
            gtk_widget_set_size_request(grids_tab[i][j]->button, 130, 173);
            gtk_grid_attach(GTK_GRID(grid), grids_tab[i][j]->button, j, i, 1, 1);
            gtk_widget_set_name(grids_tab[i][j]->button, "grid_c");
            g_signal_connect(G_OBJECT(grids_tab[i][j]->button),"clicked",G_CALLBACK(put_card), NULL);
        }
    }

    //set_red_hand();

    red_box = gtk_box_new(GTK_ORIENTATION_VERTICAL, 0);
    gtk_box_pack_start(GTK_BOX(pgc_box), red_box, FALSE, FALSE, 0);
    gtk_widget_set_halign (GTK_WIDGET(red_box),GTK_ALIGN_CENTER);
    gtk_widget_set_valign (GTK_WIDGET(red_box),GTK_ALIGN_CENTER);
    red_hand[1]->button = gtk_button_new();
    gtk_box_pack_end(GTK_BOX(red_box), red_hand[1]->button, FALSE, FALSE, 0);
    gtk_widget_set_size_request(red_hand[1]->button, 130, 173);
    gtk_widget_set_name(red_hand[1]->button, red_hand[1]->style_r);
    for (int i = 2; i <= 5; i++) {
        red_hand[i]->button = gtk_button_new();
        gtk_box_pack_end(GTK_BOX(red_box), red_hand[i]->button, FALSE, FALSE, 0);
        gtk_widget_set_size_request(red_hand[i]->button, 130, 60);
        gtk_widget_set_name(red_hand[i]->button, red_hand[i]->style_r);
    }

    mp_box = gtk_box_new(GTK_ORIENTATION_HORIZONTAL, 20);
    gtk_box_pack_start(GTK_BOX(pg_box), mp_box, FALSE, FALSE, 0);

    end_turn_btn = gtk_button_new();
    gtk_box_pack_start(GTK_BOX(mp_box), end_turn_btn, FALSE, FALSE, 0);
    gtk_widget_set_sensitive(end_turn_btn, FALSE);
    g_signal_connect(G_OBJECT(end_turn_btn),"clicked",G_CALLBACK(let_red_turn), NULL);
    gtk_widget_set_name(end_turn_btn, "end_turn_btn");
    gtk_widget_set_size_request(end_turn_btn, 130, 50);

    empty_label = gtk_label_new("");
    gtk_box_pack_start(GTK_BOX(mp_box), empty_label, FALSE, FALSE, 0);
    gtk_widget_set_size_request(empty_label, 482, 0);

    quit_pg_btn = gtk_button_new();
    gtk_box_pack_start(GTK_BOX(mp_box), quit_pg_btn, FALSE, FALSE, 0);
    g_signal_connect(G_OBJECT(quit_pg_btn),"clicked",G_CALLBACK(pg_box_quit), NULL);
    gtk_widget_set_name(quit_pg_btn, "quit_btn");
    gtk_widget_set_size_request(quit_pg_btn, 130, 50);

    for (int i = 1; i < 4; i++)
    {
        for (int j = 1; j < 4; j++)
        {
            gtk_widget_set_sensitive(grids_tab[i][j]->button, FALSE);
        }
    }

    gtk_widget_show_all(pg_box);
    gtk_widget_set_name(window, "pg_box");
    red_turn();
}

void card_pick(GtkWidget *widget, gpointer data) {
    int which_tier;
    int which_card;
    for (int i = 1; i < 6; i++)
        for (int j = 1; j < 6; j++) {
            if (widget == cards_tab[i][j]->button) {
                which_tier = i;
                which_card = j;
            }
        }
    blue_hand_help[which_tier] = 1;
    for (int i = 1; i < 6; i++) {
        gtk_widget_set_size_request(cards_tab[which_tier][i]->button, 130, 60);
        gtk_widget_set_name(cards_tab[which_tier][i]->button, cards_tab[which_tier][i]->style_g);
        cards_tab[which_tier][i]->color = GREY;
    }
    gtk_widget_set_size_request(cards_tab[which_tier][which_card]->button, 130, 173);
    gtk_widget_set_name(cards_tab[which_tier][which_card]->button, cards_tab[which_tier][which_card]->style_b);
    cards_tab[which_tier][which_card]->color = BLUE;
    strcpy(blue_hand[which_tier]->style_b, cards_tab[which_tier][which_card]->style_b);
    strcpy(blue_hand[which_tier]->style_r, cards_tab[which_tier][which_card]->style_r);
    blue_hand[which_tier]->top = cards_tab[which_tier][which_card]->top;
    blue_hand[which_tier]->right = cards_tab[which_tier][which_card]->right;
    blue_hand[which_tier]->bottom = cards_tab[which_tier][which_card]->bottom;
    blue_hand[which_tier]->left = cards_tab[which_tier][which_card]->left;
    blue_hand[which_tier]->color = cards_tab[which_tier][which_card]->color;

    int chosen = 0;
    for (int i = 1; i < 6; i++) {
        if (blue_hand_help[i] == 1) chosen++;
    }
    if (chosen == 5) gtk_widget_set_sensitive(cont_btn, TRUE);
}

void card_choose(GtkWidget *widget, gpointer data) {
    int which_card = 0;
    for (int i = 1; i <= 5; i++)
    {
        if (widget == blue_hand[i]->button)
        {
            which_card = i;
        }
    }
    for (int i = 1; i <= 5; i++)
    {
        gtk_widget_set_size_request(blue_hand[i]->button, 130, 60);
    }
    gtk_widget_set_size_request(blue_hand[which_card]->button, 130, 173);
    card_copy = blue_hand[which_card];
}

void put_card(GtkWidget *widget, gpointer data) {
    int which_card = 0;
    for (int i = 1; i <= 5; i++)
    {
        if (card_copy == blue_hand[i])
        {
            which_card = i;
        }
    }
    for (int i = 1; i < 4; i++) {
        for (int j = 1; j < 4; j++) {
            if (grids_tab[i][j]->button == widget) {
                grids_tab[i][j]->top = card_copy->top;
                grids_tab[i][j]->right = card_copy->right;
                grids_tab[i][j]->bottom = card_copy->bottom;
                grids_tab[i][j]->left = card_copy->left;
                grids_tab[i][j]->color = card_copy->color;
                strcpy(grids_tab[i][j]->style_b, card_copy->style_b);
                strcpy(grids_tab[i][j]->style_r, card_copy->style_r);
                grids_tab[i][j]->bottom = card_copy->bottom;
                gtk_widget_set_name(widget, card_copy->style_b);

                flip(i, j);
            }
        }
    }
    blue_active[which_card] = 0;
    int x = 1;
    while (blue_active[x] == 0)
    {
      x++;
      if (x == 6)  break;
    }
    if (x == 6)
    {
        gtk_widget_set_name(blue_hand[which_card]->button, "trans");
        for (int i = 1; i < 4; i++)
        {
            for (int j = 1; j < 4; j++)
            {
                gtk_widget_set_sensitive(grids_tab[i][j]->button, FALSE);
            }
        }
    }
    else
    {
        gtk_widget_hide(blue_hand[which_card]->button);
        gtk_widget_set_size_request(blue_hand[x]->button, 130, 173);
        card_copy = blue_hand[x];
    }
    gtk_widget_set_sensitive(widget, FALSE);
    gtk_widget_set_sensitive(end_turn_btn, TRUE);
    move_number++;
    if (move_number == 9) who_wins();
}

void red_turn() {
    int red_before = 0;
    int red_after = 0;
    int red_after_max = 0;
    int which_card;
    int line;
    int column;
    for (int i = 1; i < 4; i++)
    {
        for (int j = 1; j < 4; j++)
        {
            grids_copy[i][j]->top = grids_tab[i][j]->top;
            grids_copy[i][j]->right = grids_tab[i][j]->right;
            grids_copy[i][j]->bottom = grids_tab[i][j]->bottom;
            grids_copy[i][j]->left = grids_tab[i][j]->left;
            grids_copy[i][j]->color = grids_tab[i][j]->color;
            if (grids_tab[i][j]->color == RED) red_before++;
        }
    }
    for (int i = 1; i < 6; i++)
    {
        if (red_active[i] == 1)
        for (int k = 1; k < 4; k++)
        {
            for (int l = 1; l < 4; l++)
            {
                if (strcmp(gtk_widget_get_name(grids_tab[k][l]->button), "grid_c") == 0)
                {
                    grids_tab[k][l]->top = red_hand[i]->top;
                    grids_tab[k][l]->right = red_hand[i]->right;
                    grids_tab[k][l]->bottom = red_hand[i]->bottom;
                    grids_tab[k][l]->left = red_hand[i]->left;
                    grids_tab[k][l]->color = red_hand[i]->color;
                    flip_sim(k, l);
                    for (int x = 1; x < 4; x++)
                    {
                        for (int y = 1; y < 4; y++)
                        {
                            if (grids_tab[x][y]->color == RED) red_after++;
                        }
                    }
                    if (red_after >= red_after_max)
                        {
                            red_after_max = red_after;
                            which_card = i;
                            line = k;
                            column = l;
                        }
                    for (int x = 1; x < 4; x++)
                    {
                        for (int y = 1; y < 4; y++)
                        {
                            grids_tab[x][y]->top = grids_copy[x][y]->top;
                            grids_tab[x][y]->right = grids_copy[x][y]->right;
                            grids_tab[x][y]->bottom = grids_copy[x][y]->bottom;
                            grids_tab[x][y]->left = grids_copy[x][y]->left;
                            grids_tab[x][y]->color = grids_copy[x][y]->color;
                        }
                    }
                }
                red_after = 0;
            }
        }
    }
    red_active[which_card] = 0;
    strcpy(grids_tab[line][column]->style_b, red_hand[which_card]->style_b);
    strcpy(grids_tab[line][column]->style_r, red_hand[which_card]->style_r);
    grids_tab[line][column]->top = red_hand[which_card]->top;
    grids_tab[line][column]->right = red_hand[which_card]->right;
    grids_tab[line][column]->bottom = red_hand[which_card]->bottom;
    grids_tab[line][column]->left = red_hand[which_card]->left;
    grids_tab[line][column]->color = red_hand[which_card]->color;
    gtk_widget_set_name(grids_tab[line][column]->button, grids_tab[line][column]->style_r);
    int x = 1;
    while (red_active[x] == 0)
    {
      x++;
      if (x == 6)  break;
    }
    if (x == 6)
    {
        gtk_widget_set_name(red_hand[which_card]->button, "trans");
        for (int i = 1; i < 4; i++)
        {
            for (int j = 1; j < 4; j++)
            {
                gtk_widget_set_sensitive(grids_tab[i][j]->button, FALSE);
            }
        }
    }
    else
    {
         gtk_widget_hide(red_hand[which_card]->button);
         gtk_widget_set_size_request(red_hand[x]->button, 130, 173);
    }

    enemy_flip(line, column);
    gtk_widget_set_sensitive(grids_tab[line][column]->button, FALSE);


    for (int i = 1; i < 4; i++)
    {
        for (int j = 1; j < 4; j++)
        {
            if (strcmp(gtk_widget_get_name(grids_tab[i][j]->button), "grid_c") == 0)
            {
                gtk_widget_set_sensitive(grids_tab[i][j]->button, TRUE);
            }
        }
    }
    gtk_widget_set_sensitive(end_turn_btn, FALSE);

    move_number++;
    if (move_number == 9) who_wins();
}

void let_red_turn(GtkWidget *widget, gpointer data){
    red_turn();
}

void pg_box_quit(GtkWidget *widget, gpointer data) {
    gtk_widget_hide(pg_box);
    gtk_widget_show_all(mm_box);
    gtk_widget_set_name(window, "mm_box");
    move_number = 0;
}

void pop_plus()
{
    gtk_widget_set_name(empty_label, "plus");
}

void pop_wallsame()
{
    gtk_widget_set_name(empty_label, "wallsame");
}

void pop_blue_wins()
{
    gtk_widget_set_name(empty_label, "blue_wins");
}

void pop_red_wins()
{
    gtk_widget_set_name(empty_label, "red_wins");
}
