GtkWidget *window;
GtkWidget *global_box;
GtkWidget *mm_box; //main menu
GtkWidget *play_btn;
GtkWidget *quit_btn;
GtkWidget *empty_label;
GtkWidget *pg_box; //playground
GtkWidget *deck_box; //deck choose
GtkWidget *chdeck_box;
GtkWidget *md_box;
GtkWidget *cont_btn;
GtkWidget *back_btn;
GtkWidget *pgc_box;
GtkWidget *blue_box;
GtkWidget *grid_box;
GtkWidget *grid;
GtkWidget *red_box;
//ZMIANY
GtkWidget *mp_box;
GtkWidget *end_turn_btn;
GtkWidget *quit_pg_btn;

GtkWidget *combo_lbl;
GtkWidget *plus_lbl;
GtkWidget *wallsame_lbl;
// KONIEC
void main_menu_open();
void deck_menu_open(GtkWidget *widget, gpointer data);
void deck_back(GtkWidget *widget, gpointer data);
void pg_box_open(GtkWidget *widget, gpointer data);
void card_pick(GtkWidget *widget, gpointer data);
void card_choose(GtkWidget *widget, gpointer data);
void put_card(GtkWidget *widget, gpointer data);
void red_turn();
void let_red_turn(GtkWidget *widget, gpointer data);
void pg_box_quit(GtkWidget *widget, gpointer data);

void pop_plus();
void pop_wallsame();
void pop_blue_wins();
void pop_red_wins();
