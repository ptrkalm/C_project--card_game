#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <gtk/gtk.h>

#define GREY 0
#define BLUE 1
#define RED 2

typedef struct card {
    char style_b[12];
    char style_r[12];
    char style_g[12];
    int top;
    int right;
    int bottom;
    int left;
    int color;
    GtkWidget *button;
} card;

card *cards_tab[6][6];

int red_hands[6][6];
int which_red_hand;

card *blue_hand[6];
int blue_active[6];
card *red_hand[6];
int red_active[6];


GtkWidget *tier[6];

card *grids_tab[4][4];
card *grids_copy[4][4];

card *card_copy;

char plus_pom [4][4];
int blue_hand_help [6];
int move_number;

void cards();
void set_red_hand();
void flip(int line, int column);
void flip_sim(int line, int column);
void enemy_flip(int line, int column);
void plus_same(int line, int column, int wallsame);
void plus_same_red (int line, int column, int wallsame);
void who_wins ();



