#include <stdio.h>
#include <stdlib.h>

typedef enum {} tile_state_t;

typedef struct {} tile_t;

//typedef struct {} board_t; //Probably unecessary if it contains one item

void init_board(tile_t ** board);
void init_tile(tile_t * tile);

int main(void){
	printf("Hello, world!\n");
	return 0;
}
