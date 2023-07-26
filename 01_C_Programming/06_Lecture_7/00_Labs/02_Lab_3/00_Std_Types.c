
#include <stdio.h>

typedef unsigned char               uint8_t    ;
typedef unsigned short int          uint16_t   ;
typedef unsigned long  int          uint32_t   ;
typedef signed   char               sint8_t    ;
typedef signed   short int          sint16_t   ;
typedef signed   long  int          sint32_t   ;
typedef float                       float32_t  ;
typedef double                      float64_t  ;
typedef long double                 float96_t ;

void main(void)
{
    printf("\n\n"); 
	printf("The Size Of uint8_t   Is %d Bytes\n", sizeof(uint8_t)) ;
	printf("The Size Of uint16_t  Is %d Bytes\n", sizeof(uint16_t));
	printf("The Size Of uint32_t  Is %d Bytes\n", sizeof(uint32_t));
	printf("The Size Of sint8_t   Is %d Bytes\n", sizeof(sint8_t)) ;
	printf("The Size Of sint16_t  Is %d Bytes\n", sizeof(sint16_t));
	printf("The Size Of sint32_t  Is %d Bytes\n", sizeof(sint32_t));
	printf("The Size Of float32_t Is %d Bytes\n", sizeof(float32_t));
	printf("The Size Of float64_t Is %d Bytes\n", sizeof(float64_t));
    printf("The Size Of float96_t Is %d Bytes\n", sizeof(float96_t));
    printf("\n\n");
}