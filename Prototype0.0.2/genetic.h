/*================================================================================================= */
/* This Code is written by JeongHyeon Choi. (Mokpo National University Student in Korea)            */
/*                         KORKIMERA                                                                */
/*                                                                                                  */
/*                                                                                                  */
/* Tool          : Dev C++ 5.10                                                                     */
/* OS            : Windows 7                                                                        */
/* Version       : Prototype 0.0.2                                                                  */
/* Description   : Header File for Using Gentic Algorithm.                                          */
/*================================================================================================= */


#ifndef GENETIC_H
#define GENETIC_H


/*================================================================================================= */
/* INCLUDE                                                                                          */

#include "data.h"

/*================================================================================================= */


/*================================================================================================= */
/* PROTOTYPE                                                                                        */

population *         create_population 		( int, int, int );
void                 free_population   		( population * );
int 				 rand_between	   		( int, int );
void 				 rand_population   		( population * );
void 				 decode			   		( chromosome *, int *, int, int );
void 				 display_population		( population * );
void 				 evaluate				( population * );
double 				 getFitness				( int *, int );
void 				 mutate					( chromosome *, int );
individual * 		 select_individual		( population *pop );
void 				 crossover				( chromosome *, chromosome *, chromosome *, chromosome *, int );
void 				 breed					( individual *, individual *, individual *, individual *, int );
void 				 new_generate			( population *, population * );
int 				 isExist				( chromosome *, bit, int );
bit 				 *getIndexOfBit			( chromosome *, bit, int );
void 				 display_chromosome		( chromosome *, int );


/*================================================================================================= */

#endif
