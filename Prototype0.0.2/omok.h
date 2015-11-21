/*================================================================================================= */
/* This Code is written by JeongHyeon Choi. (Mokpo National University Student in Korea)            */
/*                         KORKIMERA                                                                */
/*                                                                                                  */
/*                                                                                                  */
/* Tool          : Dev C++ 5.10                                                                     */
/* OS            : Windows 7                                                                        */
/* Version       : Prototype 0.0.2                                                                  */
/* Description   : Header File For Main Omok Algorithms                                             */
/*================================================================================================= */


#ifndef OMOK_H
#define OMOK_H


/*================================================================================================= */
/* INCLUDE                                                                                          */

#include "data.h"

/*================================================================================================= */


/*================================================================================================= */
/* DEFINE                                                                                           */

/*================================================================================================= */


/*================================================================================================= */
/* DEFINE STRUCT                                                                                    */

/*  Define Omok Board Struct  */
typedef struct omok
{
	/*  Define 2 Dimension Array Board  */
	int (*board)[BOARD_SIZE];
	int (*fitness_board)[BOARD_SIZE];
	
	/*  Population Pointer  */
	population *pop;
	
}omok;

/*================================================================================================= */


/*================================================================================================= */
/* PROTOTYPE                                                                                        */

omok * 				 _init_omok						( void );
int 				 ( *getBoardFitness 			( int (*)[BOARD_SIZE], int (*)[BOARD_SIZE] ))[BOARD_SIZE];
int 				 ( *evaluate_board				( int (*)[BOARD_SIZE], int (*)[BOARD_SIZE], int, int ))[BOARD_SIZE];
void 				 getFitnessStonePosition		( int (*)[BOARD_SIZE], int *, int *, int );

/*================================================================================================= */

#endif
