#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include "list.h"

struct song_node **init_library (struct song_node **front) {
	front = malloc(27, sizeof(struct song_node *));
	return front;
}

int artist_index(char *a) {
	if (a[0]>='a' && a[0]<='z') return a[0]-'a';
	if (a[0]>='A' && a[0]<='Z') return a[0]-'A';
	return 26;
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
