#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

struct song_node{
	char artist[100];
	char name[100];
	struct song_node *next;
};

struct song_node *create_node(struct song_node *x, char *a, char *n) {
	struct song_node *ans = malloc(sizeof(struct song_node));

	strcpy(ans->name, n);
	strcpy(ans->artist, a);
	ans->next = x;

	return ans;
}

void print_node(struct song_node *a) {
	if (a == 0) printf("song/artist not found\n");
	else printf("{%s, %s}", a->artist, a->name);
}

struct song_node *insert_front(struct song_node *front, char* a, char* n) {
	struct song_node *ans = create_node(front, a, n);
	return ans;
}

int comes_before (struct song_node *a, struct song_node *b) {
	int x = strcmp(a->artist, b->artist);
	if (x<0) return 1;
	if (x==0 && strcmp(a->name, b->name)<0) return 1;
	return 0;
}

struct song_node *insert_order(struct song_node *front, char* a, char* n) {
	struct song_node *add = create_node(0, a, n);
	if (front==0 || comes_before(add, front)) {
		add->next = front;
		return add;
	}
	struct song_node *prev = front, *cur = front->next;
	while (cur!=0 && comes_before(cur, add)) {
		prev = cur;
		cur = cur->next;
	}
	add->next = cur;
	prev->next = add;
	return front;
}

void print_list(struct song_node* front) {
	printf("[ ");
	if (front) {
		while (front -> next) {
			print_node(front);
			printf(" | ");
			front = front -> next;
		}
		print_node(front);
	}
	printf(" ]\n");
}

struct song_node *find_song(struct song_node *front, char* a, char* n) {
	while (front) {
		if (!strcmp(front -> name, n) && !strcmp(front -> artist, a)) return front;
		front = front -> next;
	}
	return 0;
}

struct song_node *find_artist(struct song_node *front, char *a) {
	while (front) {
		if (!strcmp(front -> artist, a)) return front;
		front = front -> next;
	}
	return 0;
}

struct song_node *get_random(struct song_node *front) {
	struct song_node *hold = front;
	int size = 0;
	while (hold) {
		size += 1;
		hold = hold -> next;
	}

	// srand(time(NULL));
	int random = rand() % size;
	while (front -> next) {
		if (random == 0) return front;
		random -= 1;
		front = front -> next;
	}
	return front;
}

struct song_node *remove_song(struct song_node *front, char *a, char *n) {
	struct song_node *curr = front;
	struct song_node *next = front -> next;

	if (strcmp(n, curr -> name) == 0 && strcmp(a, curr -> artist) == 0) {
		free(front);
		return next;
	}

	while (next) {
		if (strcmp(n, next -> name) == 0 && strcmp(a, next -> artist) == 0) {
			curr -> next = next -> next;
			free(next);
			break;
		}
		curr = next;
		next = next -> next;
	}
	return front;
}

struct song_node *free_list(struct song_node *front) {
	struct song_node *temp;
	while (front) {
		temp = front -> next;
		free(front);
		front = temp;
	}
	return temp;
}



void lib_print_list(struct song_node *front) {
	if (front) {
		printf("[ ");
		while (front -> next) {
			print_node(front);
			printf(" | ");
			front = front -> next;
		}
		print_node(front);
		printf(" ]\n");
	}
}
