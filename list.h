struct song_node{
	char name[100];
	char artist[100];
	struct song_node *next;
};

struct song_node *insert_front(struct song_node *front, char* n, char* a);
struct song_node *insert_order(struct song_node *front, char* n, char* a);
void print_list(struct song_node* front);
struct song_node *find_song(struct song_node *front, char* n, char* a);
struct song_node *find_artist(struct song_node *front, char *n);
struct song_node *get_random(struct song_node *front);
struct song_node *remove_song(struct song_node *front, chat *n, char *a);
struct song_node *free_list(struct song_node *front);
