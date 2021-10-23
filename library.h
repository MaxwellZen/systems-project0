
struct song_node **init_library (struct song_node **front);

struct song_node **add_song (struct song_node **front, char *a, char *n);

struct song_node *get_song (struct song_node **front, char *a, char *n);

struct song_node *get_artist (struct song_node **front, char *a);

void print_by_letter (struct song_node **front, char c);

void print_by_artist (struct song_node **front, char *a);

void print_library (struct song_node **front);

void shuffle (struct song_node **front);

struct song_node **delete_song (struct song_node **front, char *a, char *n);

struct song_node **clear_library (struct song_node **front);
