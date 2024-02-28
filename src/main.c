#include <errno.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef enum {
	EMPTY,
	FIRE,
	FLOOD,
	BLIZZARD,
	EARTHQUAKE,
	PLAYER_OCCUPIED,
	NUM_TILE_STATES
} tile_state_t;
// A hexagonal tile will look like so
//  /\
// |  |
//  \/
// angles for faces are 30, 90, 150, 210, 270, 330
typedef struct {
	int tile_id;			// for identification purposed
	tile_state_t state[2];	// can possibly be in more than one state
	void * neighbors[6];	// 6 neighbors for 6 sides
} tile_t;

void error(char * msg){
	printf("[ERROR] %s: %s\n", msg, strerror(errno));
	exit(EXIT_FAILURE);
}

void debug(char * msg){
	printf("[DEBUG] %s\n", msg);
}

int init_tile(tile_t * tile, int id){
	if(tile == NULL){
		#ifndef
		debug("Tile pointer was NULL!");
		#endif
		return 0;
	}

	tile->tile_id = id;
	memset(tile->state, 0, sizeof(int) * 2);
	memset(tile->neighbors, 0, sizeof(void *) * 6);

	return 1;
}

int init_board(tile_t ** board, int num_tiles){
	if(board == NULL){
		#ifndef
		debug("Board pointer was NULL!");
		#endif
		return 0;
	}

	for(int i = 0; i < num_tiles; i++)
		if(!init_tile(&(*board)[i], i))
			error("Failed to initialize tile!");

	return 1;
}

int main(void){
	int num_tiles = 128;
	tile_t * board;
	#ifdef DEBUG_MODE
	debug("Debug messages enabled.");
	#endif
	if(!init_board(&board, num_tiles))
		error("Failed to initialize board!");

	return EXIT_SUCCESS;
}

