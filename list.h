struct song_node{
	char name[100];
	char artist[100];
	struct song_node *next;
};

struct song_node *create_node(struct song_node *x, char* a, char* n);

void print_node(struct song_node *a);

struct song_node *insert_front(struct song_node *front, char* a, char* n);

struct song_node *insert_order(struct song_node *front, char* a, char* n);

void print_list(struct song_node* front);

struct song_node *find_song(struct song_node *front, char* a, char* n);

struct song_node *find_artist(struct song_node *front, char *a);

struct song_node *get_random(struct song_node *front);

struct song_node *remove_song(struct song_node *front, char* a, char* n);

struct song_node *free_list(struct song_node *front);

void lib_print_list(struct song_node *front);
