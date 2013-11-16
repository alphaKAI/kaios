#include <stdio.h>
#include <stdlib.h>
// Mygetinfi(stdin)

char *MyGetInfi(FILE *Fp){
	unsigned long long Index;
	int Chr,PointSize = 1;
	char *Point,*Dummy;
	if((Point = (char *)malloc(PointSize)) == NULL) return NULL;
	for(Index = 0; Index < PointSize; Index++){
		Chr = fgetc(Fp);
		if(feof(Fp) || Chr == '\n') break;
		Point[Index] = Chr;
		
		PointSize++;
			if((Dummy = (char *)realloc(Point,PointSize)) == NULL){
				free(Point);
				Point = NULL;
				return NULL;
			}else Point = Dummy;
	}
	 Point[Index] = '\0';

	return Point;
}
