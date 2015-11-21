/*================================================================================================= */
/* This Code is written by JeongHyeon Choi. (Mokpo National University Student in Korea)            */
/*                         KORKIMERA                                                                */
/*                                                                                                  */
/*                                                                                                  */
/* Tool          : Dev C++ 5.10                                                                     */
/* OS            : Windows 7                                                                        */
/* Version       : Prototype 0.0.2                                                                  */
/* Description   : Starting Point Of Omok Algorithm based on Genetic Algorithm                      */
/*================================================================================================= */


/*================================================================================================= */
/* INCLUDE                                                                                          */

#include <stdio.h>
#include <stdlib.h>
#include <Windows.h>
#include "omok.h"

/*================================================================================================= */


/*================================================================================================= */
/* DEFINE                                                                                           */


/*================================================================================================= */


/*================================================================================================= */
/* MAIN                                                                                             */

main()
{
	/*
	omok *GAOMOK = _init_omok();
	
	randomize_stone(GAOMOK);
	
	display_population(GAOMOK->pop);
	
	GAOMOK->fitness_board = getBoardFitness(GAOMOK->board, GAOMOK->fitness_board);
	*/
	
	population *pop = (population *)create_population(16, 8, 2);
	population *new_pop = (population *)create_population(16, 8, 2);
	
	individual *ivd1,
			   *ivd2,
			   *ivd3,
			   *ivd4;
			   
	rand_population(pop);
			   
	display_population(pop);
	new_generate(pop, new_pop);
	puts("================================================\n");
	display_population(new_pop);
}

/*================================================================================================= */
