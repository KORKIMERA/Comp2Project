/*================================================================================================= */
/* This Code is written by JeongHyeon Choi. (Mokpo National University Student in Korea)            */
/*                         KORKIMERA                                                                */
/*                                                                                                  */
/*                                                                                                  */
/* Tool          : Dev C++ 5.10                                                                     */
/* OS            : Windows 7                                                                        */
/* Version       : Prototype 0.0.1                                                                  */
/* Description   : Starting Point Of Omok Algorithm based on Genetic Algorithm                      */
/*================================================================================================= */


/*================================================================================================= */
/* INCLUDE                                                                                          */

#include <stdio.h>
#include <stdlib.h>
#include "data.h"
#include "genetic.h"

/*================================================================================================= */


/*================================================================================================= */
/* DEFINE                                                                                           */

#define POP_SIZE 16
#define BIT_COUNT 4
#define DATA_COUNT 4

/*================================================================================================= */


/*================================================================================================= */
/* MAIN                                                                                             */

main()
{
	/*  Create Population.  */
	population *pop1 = create_population(POP_SIZE, BIT_COUNT, DATA_COUNT);
	
	/*  Free Population.  */
	free_population(pop1); 
}

/*================================================================================================= */
