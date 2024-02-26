#ifndef BOARD_H
#define BOARD_H
typedef enum {
	EMPTY,
	FIRE,
	WATER,
	BLIZZARD,
	EARTHQUAKE,
	PLAYER_OCCUPIED
	NUM_TILE_STATES
} tile_state_t;

typedef struct {
	tile_state_t state[2];
	void * neighbors[6];
} tile_t;

typedef struct {
	tile_t * tiles;
} board_t;

void init_board(board_t * board);
void init_tile(tile_t * tile);
#endif

#ifndef BOARD_SRC
#define BOARD_SRC

#endif
