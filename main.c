#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include "list.h"
#include "library.h"

int main() {
	srand(time(NULL));
	struct song_node *a = 0, *b, *c;
	char s[5]="A", t[5]="B";
	for (int i = 0; i < 20; i++) {
		s[0]=rand()%26+'A';
		t[0]=rand()%26+'A';
		a = insert_order(a, s, t);
	}
	b=a;
	b = insert_front(b, "H", "E");
	c = b;
	while(c) {
		print_node(c);
		printf("\n");
		c=c->next;
	}
	printf("\n\n");
	print_node(get_random(b));


}
