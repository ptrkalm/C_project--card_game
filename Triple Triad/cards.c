#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "cards.h"
#include <time.h>



void cards() {

    for (int i = 1; i < 6; i++) {
        for (int j = 1; j < 6; j++) {
            cards_tab[i][j] = (card*)malloc(sizeof(card));
        }
    }

    for (int i = 1; i < 6; i++)
    {
        blue_hand[i] = (card*)malloc(sizeof(card));
        red_hand[i] = (card*)malloc(sizeof(card));
        blue_active[i] = 1;
        red_active[i] = 1;
    }

    card_copy = (card*)malloc(sizeof(card));

    for (int i = 1; i < 4; i++)
    {
        for (int j = 1; j < 4; j++)
        {
            grids_tab[i][j] = (card*)malloc(sizeof(card));
            grids_copy[i][j] = (card*)malloc(sizeof(card));
        }
    }

    red_hands[1][1] = 5;
    red_hands[1][2] = 2;
    red_hands[1][3] = 3;
    red_hands[1][4] = 4;
    red_hands[1][5] = 1;

    red_hands[2][1] = 3;
    red_hands[2][2] = 5;
    red_hands[2][3] = 4;
    red_hands[2][4] = 1;
    red_hands[2][5] = 2;

    red_hands[3][1] = 2;
    red_hands[3][2] = 1;
    red_hands[3][3] = 5;
    red_hands[3][4] = 2;
    red_hands[3][5] = 3;

    red_hands[4][1] = 1;
    red_hands[4][2] = 4;
    red_hands[4][3] = 1;
    red_hands[4][4] = 3;
    red_hands[4][5] = 4;

    red_hands[5][1] = 4;
    red_hands[5][2] = 3;
    red_hands[5][3] = 2;
    red_hands[5][4] = 5;
    red_hands[5][5] = 5;


    sprintf(cards_tab[5][1]->style_b, "t5_c1_btn_b");
    sprintf(cards_tab[5][1]->style_r, "t5_c1_btn_r");
    sprintf(cards_tab[5][1]->style_g, "t5_c1_btn_g");
    cards_tab[5][1]->top = 5;
    cards_tab[5][1]->right = 2;
    cards_tab[5][1]->bottom = 3;
    cards_tab[5][1]->left = 1;
    cards_tab[5][1]->color = GREY;


    sprintf(cards_tab[5][2]->style_b, "t5_c2_btn_b");
    sprintf(cards_tab[5][2]->style_r, "t5_c2_btn_r");
    sprintf(cards_tab[5][2]->style_g, "t5_c2_btn_g");
    cards_tab[5][2]->top = 1;
    cards_tab[5][2]->right = 5;
    cards_tab[5][2]->bottom = 2;
    cards_tab[5][2]->left = 3;
    cards_tab[5][2]->color = GREY;

    sprintf(cards_tab[5][3]->style_b, "t5_c3_btn_b");
    sprintf(cards_tab[5][3]->style_r, "t5_c3_btn_r");
    sprintf(cards_tab[5][3]->style_g, "t5_c3_btn_g");
    cards_tab[5][3]->top = 3;
    cards_tab[5][3]->right = 1;
    cards_tab[5][3]->bottom = 5;
    cards_tab[5][3]->left = 2;
    cards_tab[5][3]->color = GREY;

    sprintf(cards_tab[5][4]->style_b, "t5_c4_btn_b");
    sprintf(cards_tab[5][4]->style_r, "t5_c4_btn_r");
    sprintf(cards_tab[5][4]->style_g, "t5_c4_btn_g");
    cards_tab[5][4]->top = 2;
    cards_tab[5][4]->right = 3;
    cards_tab[5][4]->bottom = 1;
    cards_tab[5][4]->left = 5;
    cards_tab[5][4]->color = GREY;

    sprintf(cards_tab[5][5]->style_b, "t5_c5_btn_b");
    sprintf(cards_tab[5][5]->style_r, "t5_c5_btn_r");
    sprintf(cards_tab[5][5]->style_g, "t5_c5_btn_g");
    cards_tab[5][5]->top = 4;
    cards_tab[5][5]->right = 4;
    cards_tab[5][5]->bottom = 4;
    cards_tab[5][5]->left = 4;
    cards_tab[5][5]->color = GREY;

    sprintf(cards_tab[4][1]->style_b, "t4_c1_btn_b");
    sprintf(cards_tab[4][1]->style_r, "t4_c1_btn_r");
    sprintf(cards_tab[4][1]->style_g, "t4_c1_btn_g");
    cards_tab[4][1]->top = 7;
    cards_tab[4][1]->right = 5;
    cards_tab[4][1]->bottom = 5;
    cards_tab[4][1]->left = 3;
    cards_tab[4][1]->color = GREY;

    sprintf(cards_tab[4][2]->style_b, "t4_c2_btn_b");
    sprintf(cards_tab[4][2]->style_r, "t4_c2_btn_r");
    sprintf(cards_tab[4][2]->style_g, "t4_c2_btn_g");
    cards_tab[4][2]->top = 3;
    cards_tab[4][2]->right = 7;
    cards_tab[4][2]->bottom = 5;
    cards_tab[4][2]->left = 5;
    cards_tab[4][2]->color = GREY;

    sprintf(cards_tab[4][3]->style_b, "t4_c3_btn_b");
    sprintf(cards_tab[4][3]->style_r, "t4_c3_btn_r");
    sprintf(cards_tab[4][3]->style_g, "t4_c3_btn_g");
    cards_tab[4][3]->top = 5;
    cards_tab[4][3]->right = 2;
    cards_tab[4][3]->bottom = 7;
    cards_tab[4][3]->left = 5;
    cards_tab[4][3]->color = GREY;

    sprintf(cards_tab[4][4]->style_b, "t4_c4_btn_b");
    sprintf(cards_tab[4][4]->style_r, "t4_c4_btn_r");
    sprintf(cards_tab[4][4]->style_g, "t4_c4_btn_g");
    cards_tab[4][4]->top = 5;
    cards_tab[4][4]->right = 5;
    cards_tab[4][4]->bottom = 2;
    cards_tab[4][4]->left = 7;
    cards_tab[4][4]->color = GREY;

    sprintf(cards_tab[4][5]->style_b, "t4_c5_btn_b");
    sprintf(cards_tab[4][5]->style_r, "t4_c5_btn_r");
    sprintf(cards_tab[4][5]->style_g, "t4_c5_btn_g");
    cards_tab[4][5]->top = 5;
    cards_tab[4][5]->right = 5;
    cards_tab[4][5]->bottom = 5;
    cards_tab[4][5]->left = 5;
    cards_tab[4][5]->color = GREY;

    sprintf(cards_tab[3][1]->style_b, "t3_c1_btn_b");
    sprintf(cards_tab[3][1]->style_r, "t3_c1_btn_r");
    sprintf(cards_tab[3][1]->style_g, "t3_c1_btn_g");
    cards_tab[3][1]->top = 8;
    cards_tab[3][1]->right = 2;
    cards_tab[3][1]->bottom = 4;
    cards_tab[3][1]->left = 8;
    cards_tab[3][1]->color = GREY;

    sprintf(cards_tab[3][2]->style_b, "t3_c2_btn_b");
    sprintf(cards_tab[3][2]->style_r, "t3_c2_btn_r");
    sprintf(cards_tab[3][2]->style_g, "t3_c2_btn_g");
    cards_tab[3][2]->top = 8;
    cards_tab[3][2]->right = 8;
    cards_tab[3][2]->bottom = 2;
    cards_tab[3][2]->left = 4;
    cards_tab[3][2]->color = GREY;

    sprintf(cards_tab[3][3]->style_b, "t3_c3_btn_b");
    sprintf(cards_tab[3][3]->style_r, "t3_c3_btn_r");
    sprintf(cards_tab[3][3]->style_g, "t3_c3_btn_g");
    cards_tab[3][3]->top = 4;
    cards_tab[3][3]->right = 8;
    cards_tab[3][3]->bottom = 8;
    cards_tab[3][3]->left = 2;
    cards_tab[3][3]->color = GREY;

    sprintf(cards_tab[3][4]->style_b, "t3_c4_btn_b");
    sprintf(cards_tab[3][4]->style_r, "t3_c4_btn_r");
    sprintf(cards_tab[3][4]->style_g, "t3_c4_btn_g");
    cards_tab[3][4]->top = 2;
    cards_tab[3][4]->right = 4;
    cards_tab[3][4]->bottom = 8;
    cards_tab[3][4]->left = 8;
    cards_tab[3][4]->color = GREY;

    sprintf(cards_tab[3][5]->style_b, "t3_c5_btn_b");
    sprintf(cards_tab[3][5]->style_r, "t3_c5_btn_r");
    sprintf(cards_tab[3][5]->style_g, "t3_c5_btn_g");
    cards_tab[3][5]->top = 6;
    cards_tab[3][5]->right = 6;
    cards_tab[3][5]->bottom = 6;
    cards_tab[3][5]->left = 6;
    cards_tab[3][5]->color = GREY;

    sprintf(cards_tab[2][1]->style_b, "t2_c1_btn_b");
    sprintf(cards_tab[2][1]->style_r, "t2_c1_btn_r");
    sprintf(cards_tab[2][1]->style_g, "t2_c1_btn_g");
    cards_tab[2][1]->top = 9;
    cards_tab[2][1]->right = 5;
    cards_tab[2][1]->bottom = 6;
    cards_tab[2][1]->left = 8;
    cards_tab[2][1]->color = GREY;

    sprintf(cards_tab[2][2]->style_b, "t2_c2_btn_b");
    sprintf(cards_tab[2][2]->style_r, "t2_c2_btn_r");
    sprintf(cards_tab[2][2]->style_g, "t2_c2_btn_g");
    cards_tab[2][2]->top = 8;
    cards_tab[2][2]->right = 9;
    cards_tab[2][2]->bottom = 5;
    cards_tab[2][2]->left = 6;
    cards_tab[2][2]->color = GREY;

    sprintf(cards_tab[2][3]->style_b, "t2_c3_btn_b");
    sprintf(cards_tab[2][3]->style_r, "t2_c3_btn_r");
    sprintf(cards_tab[2][3]->style_g, "t2_c3_btn_g");
    cards_tab[2][3]->top = 6;
    cards_tab[2][3]->right = 8;
    cards_tab[2][3]->bottom = 9;
    cards_tab[2][3]->left = 5;
    cards_tab[2][3]->color = GREY;

    sprintf(cards_tab[2][4]->style_b, "t2_c4_btn_b");
    sprintf(cards_tab[2][4]->style_r, "t2_c4_btn_r");
    sprintf(cards_tab[2][4]->style_g, "t2_c4_btn_g");
    cards_tab[2][4]->top = 5;
    cards_tab[2][4]->right = 6;
    cards_tab[2][4]->bottom = 8;
    cards_tab[2][4]->left = 9;
    cards_tab[2][4]->color = GREY;

    sprintf(cards_tab[2][5]->style_b, "t2_c5_btn_b");
    sprintf(cards_tab[2][5]->style_r, "t2_c5_btn_r");
    sprintf(cards_tab[2][5]->style_g, "t2_c5_btn_g");
    cards_tab[2][5]->top = 7;
    cards_tab[2][5]->right = 7;
    cards_tab[2][5]->bottom = 7;
    cards_tab[2][5]->left = 7;
    cards_tab[2][5]->color = GREY;

    sprintf(cards_tab[1][1]->style_b, "t1_c1_btn_b");
    sprintf(cards_tab[1][1]->style_r, "t1_c1_btn_r");
    sprintf(cards_tab[1][1]->style_g, "t1_c1_btn_g");
    cards_tab[1][1]->top = 10;
    cards_tab[1][1]->right = 8;
    cards_tab[1][1]->bottom = 5;
    cards_tab[1][1]->left = 7;
    cards_tab[1][1]->color = GREY;

    sprintf(cards_tab[1][2]->style_b, "t1_c2_btn_b");
    sprintf(cards_tab[1][2]->style_r, "t1_c2_btn_r");
    sprintf(cards_tab[1][2]->style_g, "t1_c2_btn_g");
    cards_tab[1][2]->top = 7;
    cards_tab[1][2]->right = 10;
    cards_tab[1][2]->bottom = 8;
    cards_tab[1][2]->left = 5;
    cards_tab[1][2]->color = GREY;

    sprintf(cards_tab[1][3]->style_b, "t1_c3_btn_b");
    sprintf(cards_tab[1][3]->style_r, "t1_c3_btn_r");
    sprintf(cards_tab[1][3]->style_g, "t1_c3_btn_g");
    cards_tab[1][3]->top = 5;
    cards_tab[1][3]->right = 7;
    cards_tab[1][3]->bottom = 10;
    cards_tab[1][3]->left = 8;
    cards_tab[1][3]->color = GREY;

    sprintf(cards_tab[1][4]->style_b, "t1_c4_btn_b");
    sprintf(cards_tab[1][4]->style_r, "t1_c4_btn_r");
    sprintf(cards_tab[1][4]->style_g, "t1_c4_btn_g");
    cards_tab[1][4]->top = 8;
    cards_tab[1][4]->right = 5;
    cards_tab[1][4]->bottom = 7;
    cards_tab[1][4]->left = 10;
    cards_tab[1][4]->color = GREY;

    sprintf(cards_tab[1][5]->style_b, "t1_c5_btn_b");
    sprintf(cards_tab[1][5]->style_r, "t1_c5_btn_r");
    sprintf(cards_tab[1][5]->style_g, "t1_c5_btn_g");
    cards_tab[1][5]->top = 8;
    cards_tab[1][5]->right = 8;
    cards_tab[1][5]->bottom = 8;
    cards_tab[1][5]->left = 8;
    cards_tab[1][5]->color = GREY;

}

void set_red_hand() {
    srand(time(0));
    which_red_hand = rand();
    which_red_hand = which_red_hand % 5 + 1;
    for (int i = 1; i < 6; i++){
        red_active[i] = 1;
        red_hand[i]->top = cards_tab[i][red_hands[which_red_hand][i]]->top;
        red_hand[i]->right = cards_tab[i][red_hands[which_red_hand][i]]->right;
        red_hand[i]->bottom = cards_tab[i][red_hands[which_red_hand][i]]->bottom;
        red_hand[i]->left = cards_tab[i][red_hands[which_red_hand][i]]->left;
        strcpy(red_hand[i]->style_b, cards_tab[i][red_hands[which_red_hand][i]]->style_b);
        strcpy(red_hand[i]->style_r, cards_tab[i][red_hands[which_red_hand][i]]->style_r);
        red_hand[i]->color = RED;
    }
}

void flip(int line, int column) {

    gtk_widget_set_name(grids_tab[line][column]->button, grids_tab[line][column]->style_b);

    //TOP
    if (line - 1 > 0)
    if (grids_tab[line - 1][column]->color == RED
        && grids_tab[line][column]->top > grids_tab[line - 1][column]->bottom)
    {
        grids_tab[line - 1][column]->color = BLUE;
        flip(line - 1, column);
    }

    //RIGHT
    if (column + 1 < 4) if (grids_tab[line][column + 1]->color == RED
        && grids_tab[line][column]->right > grids_tab[line][column + 1]->left)
    {
        grids_tab[line][column + 1]->color = BLUE;
        flip(line, column + 1);
    }
    //BOTTOM
    if (line + 1 < 4) if (grids_tab[line + 1][column]->color == RED
        && grids_tab[line][column]->bottom > grids_tab[line + 1][column]->top)
    {
        grids_tab[line + 1][column]->color = BLUE;
        flip(line + 1, column);
    }
    //LEFT
    if (column - 1 > 0) if (grids_tab[line][column - 1]->color == RED
        && grids_tab[line][column]->left > grids_tab[line][column - 1]->right)
    {
        grids_tab[line][column - 1]->color = BLUE;
        flip (line, column - 1);
    }

    for (int k = 1; k < 4; k++)
        for (int l = 1; l < 4; l++)
            plus_pom[k][l] = '0';
    plus_same (line,column, 0);
}

void plus_same (int line, int column, int wallsame) {

    if (plus_pom[line][column] == '1') return;

    if (strcmp(gtk_widget_get_name(grids_tab[line][column]->button), grids_tab[line][column]->style_r) == 0) {
        if (wallsame == 0)  pop_plus();
        else pop_wallsame();

        gtk_widget_set_name(grids_tab[line][column]->button, grids_tab[line][column]->style_b);
        grids_tab[line][column]->color = BLUE;
        flip(line, column);
    }

    plus_pom[line][column] = '1';

    int sumat = 0;
    int sumar = 0;
    int sumab = 0;
    int sumal = 0;
    int wallt = 0;
    int wallr = 0;
    int wallb = 0;
    int walll = 0;

    //TOP
    if (line - 1 > 0) {
        if (strcmp(gtk_widget_get_name(grids_tab[line-1][column]->button), "grid_c") != 0)
            sumat = grids_tab[line][column]->top + grids_tab[line-1][column]->bottom;
    } else {
        sumat = grids_tab[line][column]->top + 10;
        wallt = 1;
    }
    //RIGHT
    if (column + 1 < 4) {
        if (strcmp(gtk_widget_get_name(grids_tab[line][column+1]->button), "grid_c") != 0)
            sumar = grids_tab[line][column]->right + grids_tab[line][column+1]->left;
    } else {
        sumar = grids_tab[line][column]->right + 10;
        wallr = 1;
    }
    //BOTTOM
    if (line + 1 < 4) {
        if (strcmp(gtk_widget_get_name(grids_tab[line+1][column]->button), "grid_c") != 0)
            sumab = grids_tab[line][column]->bottom + grids_tab[line+1][column]->top;
    } else {
        sumab = grids_tab[line][column]->bottom + 10;
        wallb = 1;
    }
    //LEFT
    if (column - 1 > 0) {
        if (strcmp(gtk_widget_get_name(grids_tab[line][column-1]->button), "grid_c") != 0)
            sumal = grids_tab[line][column]->left + grids_tab[line][column-1]->right;
    } else {
        sumal = grids_tab[line][column]->left + 10;
        walll = 1;
    }

    if (sumat != 0) {
        if (sumat == sumar) {
            if (wallt == 0 && wallr == 0) {
                if (grids_tab[line - 1][column]->color == RED)
                    plus_same (line - 1, column, 0);
                if (grids_tab[line][column + 1]->color == RED)
                    plus_same (line, column + 1, 0);
            } else if (wallt == 1 && wallr == 0)
                if (grids_tab[line][column + 1]->color == RED)
                    plus_same (line, column + 1, 1);
                else if (wallt == 0 && wallr  == 1)
                    if (grids_tab[line - 1][column]->color == RED)
                        plus_same (line - 1, column, 1);

        }
        if (sumat == sumab) {
            if (wallt == 0 && wallb == 0) {
                if (grids_tab[line - 1][column]->color == RED)
                    plus_same (line - 1, column, 0);
                if (grids_tab[line + 1][column]->color == RED)
                    plus_same (line + 1, column, 0);
            } else if (wallt == 1 && wallb == 0)
                if (grids_tab[line + 1][column]->color == RED)
                    plus_same (line + 1, column, 1);
                else if (wallt == 0 && wallb == 1)
                    if (grids_tab[line - 1][column]->color == RED)
                        plus_same (line - 1, column, 1);
        }
        if (sumat == sumal) {
            if(wallt == 0 && walll == 0) {
                if (grids_tab[line - 1][column]->color == RED)
                    plus_same (line - 1, column, 0);
                if (grids_tab[line][column - 1]->color == RED)
                    plus_same (line, column - 1, 0);
            } else if (wallt == 1 && walll == 0) {
                if (grids_tab[line][column - 1]->color == RED)
                    plus_same (line, column - 1, 1);
            } else if (wallt == 0 && walll == 1) {
                if (grids_tab[line - 1][column]->color == RED)
                    plus_same (line - 1, column, 1);
            }

        }
    }
    if (sumar != 0) {
        if (sumar == sumab) {
            if(wallr == 0 && wallb == 0) {
                if (grids_tab[line][column + 1]->color == RED)
                    plus_same (line, column + 1, 0);
                if (grids_tab[line + 1][column]->color == RED)
                    plus_same (line + 1, column, 0);
            } else if (wallr == 1 && wallb == 0) {
                if (grids_tab[line + 1][column]->color == RED)
                    plus_same (line + 1, column, 1);
            } else if (wallr == 0 && wallb == 1) {
                if (grids_tab[line][column + 1]->color == RED)
                    plus_same (line, column + 1, 1);
            }

        }
        if (sumar == sumal) {
            if (wallr == 0 && walll == 0) {
                if (grids_tab[line][column + 1]->color == RED)
                    plus_same (line, column + 1, 0);
                if (grids_tab[line][column - 1]->color == RED)
                    plus_same (line, column - 1, 0);
            } else if (wallr == 1 && walll == 0) {
                if (grids_tab[line][column - 1]->color == RED)
                    plus_same (line, column - 1, 1);
            } else if (wallr == 0 && walll == 1) {
                if (grids_tab[line + 1][column]->color == RED)
                    plus_same (line + 1, column, 1);
            }
        }
    }
    if (sumab != 0) {
        if (sumab == sumal) {
            if (wallb == 0 && walll == 0) {
                if (grids_tab[line + 1][column]->color == RED)
                    plus_same (line + 1, column, 0);
                if (grids_tab[line][column - 1]->color == RED)
                    plus_same (line, column - 1, 0);
            } else if (wallb == 1 && walll == 0) {
                if (grids_tab[line][column - 1]->color == RED)
                    plus_same (line, column - 1, 1);
            } else if (wallb == 0 && walll == 1) {
                if (grids_tab[line + 1][column]->color == RED)
                    plus_same (line + 1, column, 1);
            }

        }
    }
}

void enemy_flip(int line, int column) {
    //TOP
    if (line - 1 > 0) if (grids_tab[line - 1][column]->color == BLUE
        && grids_tab[line][column]->top > grids_tab[line - 1][column]->bottom)
    {
        grids_tab[line - 1][column]->color = RED;
        gtk_widget_set_name(grids_tab[line - 1][column]->button, grids_tab[line - 1][column]->style_r);
        enemy_flip(line - 1, column);
    }

    //RIGHT
    if (column + 1 < 4) if (grids_tab[line][column + 1]->color == BLUE
        && grids_tab[line][column]->right > grids_tab[line][column + 1]->left)
    {
        grids_tab[line][column + 1]->color = RED;
        gtk_widget_set_name(grids_tab[line][column + 1]->button, grids_tab[line][column + 1]->style_r);
        enemy_flip(line, column + 1);
    }
    //BOTTOM
    if (line + 1 < 4) if (grids_tab[line + 1][column]->color == BLUE
        && grids_tab[line][column]->bottom > grids_tab[line + 1][column]->top)
    {
        grids_tab[line + 1][column]->color = RED;
        gtk_widget_set_name(grids_tab[line + 1][column]->button, grids_tab[line + 1][column]->style_r);
        enemy_flip(line + 1, column);
    }
    //LEFT
    if (column - 1 > 0) if (grids_tab[line][column - 1]->color == BLUE
        && grids_tab[line][column]->left > grids_tab[line][column - 1]->right)
    {
        grids_tab[line][column - 1]->color = RED;
        gtk_widget_set_name(grids_tab[line][column - 1]->button, grids_tab[line][column - 1]->style_r);
        enemy_flip(line, column - 1);
    }
}

void flip_sim(int line, int column) {

    //TOP
    if (line - 1 > 0) if (grids_tab[line - 1][column]->color == BLUE
        && grids_tab[line][column]->top > grids_tab[line - 1][column]->bottom)
    {
        grids_tab[line - 1][column]->color = RED;
        flip_sim(line - 1, column);
    }

    //RIGHT
    if (column + 1 < 4) if (grids_tab[line][column + 1]->color == BLUE
        && grids_tab[line][column]->right > grids_tab[line][column + 1]->left)
    {
        grids_tab[line][column + 1]->color = RED;
        flip_sim(line, column + 1);
    }
    //BOTTOM
    if (line + 1 < 4) if (grids_tab[line + 1][column]->color == BLUE
        && grids_tab[line][column]->bottom > grids_tab[line + 1][column]->top)
    {
        grids_tab[line + 1][column]->color = RED;
        flip_sim(line + 1, column);
    }
    //LEFT
    if (column - 1 > 0) if (grids_tab[line][column - 1]->color == BLUE
        && grids_tab[line][column]->left > grids_tab[line][column - 1]->right)
    {
        grids_tab[line][column - 1]->color = RED;
        flip_sim(line, column - 1);
    }
}

void plus_same_red (int line, int column, int wallsame) {

    if (plus_pom[line][column] == '1') return;

    if (strcmp(gtk_widget_get_name(grids_tab[line][column]->button), grids_tab[line][column]->style_b) == 0) {
        if (wallsame == 0) pop_plus();
        else pop_wallsame();

        gtk_widget_set_name(grids_tab[line][column]->button, grids_tab[line][column]->style_r);
        grids_tab[line][column]->color = RED;
        enemy_flip(line, column);
    }

    plus_pom[line][column] = '1';

    int sumat = 0;
    int sumar = 0;
    int sumab = 0;
    int sumal = 0;
    int wallt = 0;
    int wallr = 0;
    int wallb = 0;
    int walll = 0;

    //TOP
    if (line - 1 > 0) {
        if (strcmp(gtk_widget_get_name(grids_tab[line-1][column]->button), "grid_c") != 0)
            sumat = grids_tab[line][column]->top + grids_tab[line-1][column]->bottom;
    } else {
        sumat = grids_tab[line][column]->top + 10;
        wallt = 1;
    }
    //RIGHT
    if (column + 1 < 4) {
        if (strcmp(gtk_widget_get_name(grids_tab[line][column+1]->button), "grid_c") != 0)
            sumar = grids_tab[line][column]->right + grids_tab[line][column+1]->left;
    } else {
        sumar = grids_tab[line][column]->right + 10;
        wallr = 1;
    }
    //BOTTOM
    if (line + 1 < 4) {
        if (strcmp(gtk_widget_get_name(grids_tab[line+1][column]->button), "grid_c") != 0)
            sumab = grids_tab[line][column]->bottom + grids_tab[line+1][column]->top;
    } else {
        sumab = grids_tab[line][column]->bottom + 10;
        wallb = 1;
    }
    //LEFT
    if (column - 1 > 0) {
        if (strcmp(gtk_widget_get_name(grids_tab[line][column-1]->button), "grid_c") != 0)
            sumal = grids_tab[line][column]->left + grids_tab[line][column-1]->right;
    } else {
        sumal = grids_tab[line][column]->left + 10;
        walll = 1;
    }

    if (sumat != 0) {
        if (sumat == sumar) {
            if (wallt == 0 && wallr == 0) {
                if (grids_tab[line - 1][column]->color == BLUE)
                    plus_same_red (line - 1, column, 0);
                if (grids_tab[line][column + 1]->color == BLUE)
                    plus_same_red (line, column + 1, 0);
            } else if (wallt == 1 && wallr == 0)
                if (grids_tab[line][column + 1]->color == BLUE)
                    plus_same_red (line, column + 1, 1);
                else if (wallt == 0 && wallr  == 1)
                    if (grids_tab[line - 1][column]->color == BLUE)
                        plus_same_red (line - 1, column, 1);

        }
        if (sumat == sumab) {
            if (wallt == 0 && wallb == 0) {
                if (grids_tab[line - 1][column]->color == BLUE)
                    plus_same_red (line - 1, column, 0);
                if (grids_tab[line + 1][column]->color == BLUE)
                    plus_same_red (line + 1, column, 0);
            } else if (wallt == 1 && wallb == 0)
                if (grids_tab[line + 1][column]->color == BLUE)
                    plus_same_red (line + 1, column, 1);
                else if (wallt == 0 && wallb == 1)
                    if (grids_tab[line - 1][column]->color == BLUE)
                        plus_same_red (line - 1, column, 1);
        }
        if (sumat == sumal) {
            if(wallt == 0 && walll == 0) {
                if (grids_tab[line - 1][column]->color == BLUE)
                    plus_same_red (line - 1, column, 0);
                if (grids_tab[line][column - 1]->color == BLUE)
                    plus_same_red (line, column - 1, 0);
            } else if (wallt == 1 && walll == 0) {
                if (grids_tab[line][column - 1]->color == BLUE)
                    plus_same_red (line, column - 1, 1);
            } else if (wallt == 0 && walll == 1) {
                if (grids_tab[line - 1][column]->color == BLUE)
                    plus_same_red (line - 1, column, 1);
            }

        }
    }
    if (sumar != 0) {
        if (sumar == sumab) {
            if(wallr == 0 && wallb == 0) {
                if (grids_tab[line][column + 1]->color == BLUE)
                    plus_same_red (line, column + 1, 0);
                if (grids_tab[line + 1][column]->color == BLUE)
                    plus_same_red (line + 1, column, 0);
            } else if (wallr == 1 && wallb == 0) {
                if (grids_tab[line + 1][column]->color == BLUE)
                    plus_same_red (line + 1, column, 1);
            } else if (wallr == 0 && wallb == 1) {
                if (grids_tab[line][column + 1]->color == BLUE)
                    plus_same_red (line, column + 1, 1);
            }

        }
        if (sumar == sumal) {
            if (wallr == 0 && walll == 0) {
                if (grids_tab[line][column + 1]->color == BLUE)
                    plus_same_red (line, column + 1, 0);
                if (grids_tab[line][column - 1]->color == BLUE)
                    plus_same_red (line, column - 1, 0);
            } else if (wallr == 1 && walll == 0) {
                if (grids_tab[line][column - 1]->color == BLUE)
                    plus_same_red (line, column - 1, 1);
            } else if (wallr == 0 && walll == 1) {
                if (grids_tab[line + 1][column]->color == BLUE)
                    plus_same_red (line + 1, column, 1);
            }
        }
    }
    if (sumab != 0) {
        if (sumab == sumal) {
            if (wallb == 0 && walll == 0) {
                if (grids_tab[line + 1][column]->color == BLUE)
                    plus_same_red (line + 1, column, 0);
                if (grids_tab[line][column - 1]->color == BLUE)
                    plus_same_red (line, column - 1, 0);
            } else if (wallb == 1 && walll == 0) {
                if (grids_tab[line][column - 1]->color == BLUE)
                    plus_same_red (line, column - 1, 1);
            } else if (wallb == 0 && walll == 1) {
                if (grids_tab[line + 1][column]->color == BLUE)
                    plus_same_red (line + 1, column, 1);
            }

        }
    }
}

void who_wins () {

    int score_blue = 0;
    int score_red = 0;

    for (int i = 1; i < 4; i++)
        for (int j = 1; j < 4; j++) {
        if (grids_tab[i][j]->color == BLUE)
            score_blue = score_blue + grids_tab[i][j]->top + grids_tab[i][j]->right + grids_tab[i][j]->bottom + grids_tab[i][j]->left;
        else
            score_red = score_red + grids_tab[i][j]->top + grids_tab[i][j]->right + grids_tab[i][j]->bottom + grids_tab[i][j]->left;
        }

    if (score_blue > score_red) pop_blue_wins();
    else pop_red_wins();
}
