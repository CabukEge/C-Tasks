#include "chessboard.h"

void new_jump(struct board_t* b, int x, int y){
	b->fields[b->x += x][b->y += y] = ++b->i;
}
void remove_jump(struct board_t* b, int x, int y){
	b->fields[b->x][b->y] = 0;
	b->x -= x;
	b->y -= y;
	b->i -= 1;
}
int isfree(struct board_t* b, int x, int y){
	int new_x = b->x + x;
	int new_y = b->y + y;
	if( new_x >= 0 && new_x < b->n && new_y >= 0 && new_y < b->n && b->fields[new_x][new_y] 		== 0;)return 1;
	else return 0;
}
int visited_fields(struct board_t* b){
	return b->i;
}
void print_board(struct board_t* b){
    printf("+");
    for(j= 0; j< b->n; j++){
        printf("---+");
    }
    printf("\n");
    for(k= 0; k< b->n; k++){
        printf("+");
        for(j= 0; j< b->n; j++){
            printf(" " + b->fields[j][k] + "+");
        }
        printf("\n");
        printf("+");
        for(j= 0; j< b->n; j++){
            printf("---+");
        }
        printf("\n");
    }
}
int init_board(struct board_t* b, int n, int x, int y){
	b->n = n;
    b->x = x;
    b->y = y;
    b->i = 0;
    b->fields = int fields[n][n];

}
void free_board(struct board_t *b){

}
