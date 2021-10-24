#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include "list.h"
#include "library.h"

int main() {
	printf("\n\n-----Linkedlist Tests:----\n\n");
	srand(0);
	struct song_node *a = 0, *b;
	char s[5]="A", t[5]="B";
	for (int i = 0; i < 20; i++) {
		s[0]=rand()%26+'A';
		t[0]=rand()%26+'A';
		a = insert_order(a, t, s);
	}
	a = insert_order(a, "Z", "Z");

	// printf("Print list:\n");
	// print_list(a);
	//
	// printf("\n\nFind song X by B:\n[ ");
	// print_node(find_song(a, "B", "X"));
	// printf(" ]");
	//
	// printf("\n\nFind artist B:\n[ ");
	// print_node(find_artist(a, "B"));
	// printf(" ]");
	//
	// printf("\n\nGet random:\n[ ");
	// print_node(get_random(a));
	// printf(" ]");
	//
	// printf("\n\nRemove song X by B:\n");
	// remove_song(a, "B", "X");
	// print_list(a);
	//
	// printf("\nFree list:\n");
	// free_list(a);
	// print_list(a);


	printf("\n\n-----Library Tests:----\n");
	struct song_node **lib;
	lib = init_library(lib);
	for (int i = 0; i < 20; i++) {
		s[0]=rand()%26+'A';
		t[0]=rand()%26+'A';
		lib = add_song(lib, s, t);
	}
	add_song(lib, "Adele", "Hello");

	printf("\nPrint library:\n");
	print_library(lib);

	printf("\n\nGet song:\n");
	print_node(get_song(lib, "M", "B"));

	printf("\n\nGet all songs by artist\n");
	print_by_artist(lib, "a");

	printf("\nDelete song\n");
	delete_song(lib, "Adele", "Hello");
	print_library(lib);

	printf("\nClear library\n");
	clear_library(lib);
	print_library(lib);

}
