/*================================================================================================= */
/* This Code is written by JeongHyeon Choi. (Mokpo National University Student in Korea)            */
/*                         KORKIMERA                                                                */
/*                                                                                                  */
/*                                                                                                  */
/* Tool          : Dev C++ 5.10                                                                     */
/* OS            : Windows 7                                                                        */
/* Version       : Prototype 0.0.2                                                                  */
/* Description   : Header File for Gene Sturuct On Gentic Algorithm.                                */
/*================================================================================================= */


#ifndef DATA_H
#define DATA_H


/*================================================================================================= */
/* TYPEDEF                                                                                          */

typedef int bit;
typedef bit chromosome;

/*================================================================================================= */


/*================================================================================================= */
/* DEFINE                                                                                           */

#define POP_SIZE 		10
#define BIT_COUNT 		8
#define DATA_COUNT 		2

#define BOARD_SIZE 		15
#define NONESTONE		-1
#define BLACKSTONE 		0
#define WHITESTONE 		1

#define PZERO 			0.5

#define UP 				0
#define RIGHT_UP 		1
#define RIGHT 			2
#define RIGHT_DOWN 		3
#define DOWN 			4
#define LEFT_DOWN 		5
#define LEFT 			6
#define LEFT_UP 		7


/*================================================================================================= */


/*================================================================================================= */
/* DEFINE STRUCT                                                                                    */

/*  Define Struct for Individual  */
typedef struct individual
{
	/*  Gene Array Pointer  */
	chromosome *crms;
	
	/*  Fitness ( Display How Much is the Individual Good for Survive. )  */
	double fitness;
	
}individual;


/*  Define Struct for Population ( a Set Of Individuals ) */
typedef struct population
{
	/*  Individual Array Pointer  */
	individual *ivd;
	
	/*  Size Of This Population  */
	int pop_size;
	
	/*  Number Of Each Individual's Bit in This Population */
	int bit_count;
	
	/*  The Max Number Of Gene that Each Individual has.*/
	int data_count;
	
}population;

#endif
