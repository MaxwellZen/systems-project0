#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include "list.h"

struct song_node **init_library (struct song_node **front) {
	front = malloc(27 * sizeof(struct song_node *));
	return front;
}

int char_index(char c) {
	if (c>='a' && c<='z') return c-'a';
	if (c>='A' && c<='Z') return c-'A';
	return 26;
}

int artist_index(char *a) {
	return char_index(a[0]);
}

struct song_node **add_song (struct song_node **front, char *a, char *n) {
	int i = artist_index(a);
	front[i] = insert_order(front[i], a, n);
	return front;
}

struct song_node *get_song (struct song_node **front, char *a, char *n) {
	int i = artist_index(a);
	return find_song(front[i], a, n);
}

struct song_node *get_artist (struct song_node **front, char *a) {
	int i = artist_index(a);
	return find_artist(front[i], a);
}

void print_by_letter (struct song_node **front, char c) {
	int i = char_index(c);
	print_list(front[i]);
}

void print_by_artist (struct song_node **front, char *a) {
	struct song_node *song = get_artist(front, a);
	while (song && !strcmp(song->a, a)) {
		print_node(song);
		song = song->next;
	}
}

void print_library (struct song_node **front) {

}

void shuffle (struct song_node **front) {

}

struct song_node **delete_song (struct song_node **front, char *a, char *n) {

}

struct song_node **clear_library (struct song_node **front) {

}
