#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include "list.h"

struct song_node **init_library (struct song_node **front) {
	front = malloc(27 * sizeof(struct song_node *));
	for (int i = 0; i < 27; i++) front[i]=0;
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
	if (front[i] != 0) print_list(front[i]);
}

void print_by_artist (struct song_node **front, char *a) {
	struct song_node *song = get_artist(front, a);
	while (song && !strcmp(song->artist, a)) {
		print_node(song);
		song = song->next;
	}
}

void print_library (struct song_node **front) {
	if (front==0) {
		printf("Library is empty\n");
		return;
	}
	char c;
	int i;

	for (c = 'a'; c <= 'z' + 1; c ++) {
		i = char_index(c);
		if (front[i] != NULL) {
			printf("%c: ", c);
			lib_print_list(front[i]);
		}
	}
}

// void shuffle (struct song_node **front) {
// 	srand(0);
//
// }

struct song_node **delete_song (struct song_node **front, char *a, char *n) {
	int i = char_index(*a);
	front[i] = remove_song(front[i], a, n);
	return front;
}

struct song_node **clear_library (struct song_node **front) {
	char c = 'a';
	int i = 0;
	for (char c = 'a'; c <= 'z' + 1; c ++) {
		i = char_index(c);
		if (front[i] != 0) free_list(front[i]);
	}
	return 0;
}
