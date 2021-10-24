#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include "list.h"
#include "library.h"

int main() {
	srand(0);
	struct song_node *a = 0, *b;
	char s[5]="A", t[5]="B";
	for (int i = 0; i < 20; i++) {
		s[0]=rand()%26+'A';
		t[0]=rand()%26+'A';
		a = insert_order(a, t, s);
	}
	a = insert_order(a, "Z", "Z");
	print_list(a);

	printf("\n\n");
	print_node(find_song(a, "B", "X"));

	printf("\n\nLibrary tests:\n");
	struct song_node **lib;
	lib = init_library(lib);
	for (int i = 0; i < 20; i++) {
		s[0]=rand()%26+'A';
		t[0]=rand()%26+'A';
		lib = add_song(lib, s, t);
	}
	// for (char c = 'a'; c <= 'z'+1; c++) {
	// 	print_by_letter(lib, c);
	// }
	printf("\nPrint library:\n");
	print_library(lib);
	printf("\nGet song:\n");
	print_node(get_song(lib, "M", "B"));
	printf("\nGet all songs by artist\n");
	print_by_artist(lib, "J");

}
