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

int comes_before (struct song_node *a, struct song_node *b) {
	int x = strcmp(a->artist, b->artist);
	if (x<0) return 1;
	if (x==0 && strcmp(a->name, b->name)<0) return 1;
	return 0;
}

struct song_node *insert_order(struct song_node *front, char* n, char* a) {
	struct song_node *add = create_node(n, a, 0);
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

// void print_list(struct song_node* front) {
//
// }

// struct song_node *find_song(struct song_node *front, char* n, char* a) {
//
// }

// struct song_node *find_artist(struct song_node *front, char *n) {
//
// }

struct song_node *get_random(struct song_node *front) {
	struct song_node *hold = front;
	int size = 0;
	while (hold) {
		size += 1;
		hold = hold -> next;
	}

	srand(time(NULL));
	int random = rand() % size;
	while (front -> next) {
		if (random == 0) return front;
		random -= 1;
		front = front -> next;
	}
	return front;
}

struct song_node *remove_song(struct song_node *front, char *n, char *a) {
  struct song_node *curr = front;
  struct song_node *next = curr -> next;

  if (!strcmp(n, curr -> name) && !strcmp(a, curr -> artist)) return next;

  while (next) {
    if (!strcmp(n, next -> name) && !strcmp(a, next -> artist)) {
      curr -> next = next -> next;
      break;
    }
    curr = next;
    next = next -> next;
  }
  return front;
}

struct song_node *free_list(struct song_node *front) {
	struct song_node *beginning = front;
  struct song_node *next = front -> next;
  while (next) {
    free(front);
    front = next;
    next = front -> next;
  }
	free(front);
  return 0;
}
