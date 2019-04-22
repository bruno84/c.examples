#include <stdio.h>   
#include <stdlib.h>

// Prof: Bruno Monteiro
// Objetivo: exemplificar operadores logicos

int main()   
{ 	
	int A = 1; // V
	int B = 0; // F
	int result;
	
	result = (A || B)  &&  !(A && B);
	//		  V    F         V    F
	//          V 			   !F 		
	//			V				V 
	//				     V 
    printf("result: %d \n",  result);

	system("pause");
    return 0;   
}

