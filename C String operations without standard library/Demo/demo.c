#include "mystddef.h"
#include "mystring.h"
#include <stdlib.h>
#include <stdio.h>


int main(){
	char *in_a = "Hello";
	char *in_b = "World";
	
	char *temp = malloc(mystrlen(in_a)+1); //genung speicher belegen für pointer und nullbyte
	mystrcpy(temp, in_b);                  
	printf("Before mymemcpy:%s\n", temp); 
	mymemcpy(temp, in_a, mystrlen(in_a)+1);
	printf("After mymemcpy before mymemset:%s\n", temp);
	mymemset(temp, 'A', 3);
	printf("After mymemset:%s\n", temp);  //jeweils direktes feedback für jeden der schritte
	
	free(temp);
	 
	char *sum = malloc(mystrlen(in_a) + mystrlen(in_b) + 1); //Speicher belegen um beide pointer einzufügen + nullbyte
	
	mystrcpy(sum, in_a); 
	mystrcat(sum, in_b); 
	
	
	if (mystrcmp(sum, "HelloWorld") ==0) { //falls alles geklappt hat bisher bekommen wir hier feedback
		printf("%s\n", sum);
		free(sum);
		return 0;
	}
	else{
		printf("Error: %s\n", sum);
		free(sum);
		return -1;
	}
	 
}
