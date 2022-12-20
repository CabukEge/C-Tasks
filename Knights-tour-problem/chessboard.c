#include "chessboard.h"
#include <stdlib.h>
#include <stdio.h>

void new_jump(struct board_t* b, int x, int y){
	b->fields[b->x += x][b->y += y] = ++b->i;  //Feld wird ermittelt durch Standort + neue Eingabe, fields zeigt nun auf den Wert i der Zahl des Zuges angibt
}
void remove_jump(struct board_t* b, int x, int y){
	b->fields[b->x][b->y] = 0;  //nun soll der Pointer wieder auf 0 zeigen, da dieser Schritt noch nicht gegangen wurde und i noch gesetzt werden soll
	b->x -= x;  //x,y werden um die vorherige Eingabe subtrahiert, Schrittzähler wird um 1 dekrementiert
	b->y -= y;
	b->i -= 1;
}
int isfree(struct board_t* b, int x, int y){
	int new_x = b->x + x;  //neue Werte für x und y werden temporär gespeichert um zu testen, ohne x und y tatsächtlich zu verändern
	int new_y = b->y + y;
	if( new_x >= 0 && new_x < b->n && new_y >= 0 && new_y < b->n && b->fields[new_x][new_y] == 0) return 1;  //sowohl x als auch y dürfen nicht kleiner 0 sein, und nicht größer n
	else return 0;  //wenn 0 returnd dann interpretiert als false in zeile 30 von springer.c
}
int visited_fields(struct board_t* b){
	return b->i;  //i gibt derzeitigen Zug an also i= anzahl züge
}
void print_board(struct board_t* b) {
    for (int i = 0; i <= b->n; i++) { //alle reihen zählen
        for (int j = 0; j < b->n; j++) { // platzhalter über und zwischen zeilen
            printf("+---");
            if (j == b->n - 1) printf("+\n"); //Zeilenumbruch sobald n negativ wird für platzhalter
        }

        if (i < b->n){  
            for (int j = 0; j < b->n; j++) {  //werte der einzelnen felder einfügen
                printf("+%3i", b->fields[i][j]);
                if (j == b->n - 1) printf("+\n"); //Zeilenumbruch sobald n negativ wird für werte
            }
        }
    }
}
int init_board(struct board_t* b, int n, int x, int y) {
   
    b->fields = malloc(n * sizeof(int *));  //Speicherplatz freigeben für die n Pointer 
    if (b->fields == NULL) return 1;  //für den Fall, dass Fehlgeschlagen und malloc einen NULL-Pointer zurück gibt

    b->fields[0] = calloc(n*n, sizeof(int));  //Speicherplatz freigeben für die Felder, hier mitt calloc, da dadurch alle speicherstellen mit 0 initialisiert, wichtig für isfree
    if (b->fields[0] == NULL) return 1;  //gleicher Check wie zuvor

    for (int i = 1; i < n; i++) b->fields[i] = &b->fields[0][i * n];  //je ein Zeiger soll nun auf n viele Felder zeigen, einmal n zeiger und n² felder ablaufen

    b->fields[x][y] = b->i = 1;  //startfeld mit zug 1 aufladen, ebenfalls x und y sowie n festlegen
    b->x = x;
    b->y = y;
    b->n = n;

    return 0;
}
void free_board(struct board_t *b) {
    free(b->fields[0]);  //Speicher für Pointer und Felder freigeben
    free(b->fields);
}
