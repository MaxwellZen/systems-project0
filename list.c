#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

struct song_node{
	char name[100];
	char artist[100];
	struct song_node *next;
};

struct song_node *create_node(char* n, char* a, struct song_node *x) {
	struct song_node *ans = malloc(sizeof(struct song_node));

	strcpy(ans->name, n);
	strcpy(ans->artist, a);
	ans->next = x;

	return ans;
}

void print_node(struct song_node *a) {
	printf("%s: %s", a->artist, a->name);
}

struct song_node *insert_front(struct song_node *front, char* n, char* a) {
	struct song_node *ans = create_node(n, a, front);
	return ans;
}

struct song_node *insert_order(struct song_node *front, char* n, char* a) {

}

void print_list(struct song_node* front) {

}

struct song_node *find_song(struct song_node *front, char* n, char* a) {

}

struct song_node *find_artist(struct song_node *front, char *n) {

}

struct song_node *get_random(struct song_node *front) {

}

struct song_node *remove_song(struct song_node *front, char *n, char *a) {

}

struct song_node *free_list(struct song_node *front) {

}
