CC = gcc
CFLAGS = -Wextra -Wall -std=gnu99
GTK = $(shell pkg-config --cflags --libs gtk+-3.0)

game: main.c cards.c css.c gtk.c
	$(CC) $(CFLAGS) main.c cards.c css.c gtk.c -o game $(GTK)
