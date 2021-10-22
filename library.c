#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include "list.h"

struct song_node **init_library (struct song_node **front) {
	front = malloc(27, sizeof(struct song_node *));
	return front;
}

struct song_node **add_song (struct song_node **front, char *n, char *a) {

}

struct song_node *get_song (struct song_node **front, char *n, char *a) {

}

struct song_node *get_artist (struct song_node **front, char *a) {

}

void print_by_letter (struct song_node **front, char c) {

}

void print_by_artist (struct song_node **front, char *a) {

}

void print_library (struct song_node **front) {

}

void shuffle (struct song_node **front) {

}

struct song_node **delete_song (struct song_node **front, char *n, char *a) {

}

struct song_node **clear_library (struct song_node **front) {

}
