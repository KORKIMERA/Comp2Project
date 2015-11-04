/*================================================================================================= */
/* This Code is written by JeongHyeon Choi. (Mokpo National University Student in Korea)            */
/*                         KORKIMERA                                                                */
/*                                                                                                  */
/*                                                                                                  */
/* Tool          : Dev C++ 5.10                                                                     */
/* OS            : Windows 7                                                                        */
/* Version       : Prototype 0.0.1                                                                  */
/* Description   : Header File for Using Gentic Algorithm.                                          */
/*================================================================================================= */


/*================================================================================================= */
/* INCLUDE                                                                                          */

#include "data.h"
#include <stdio.h>
#include <stdlib.h>

/*================================================================================================= */


/*================================================================================================= */
/* FUNCTION                                                                                         */

/*  Allocate New place for New Population in Memory And Return Population's Address.  */
population * create_population(int pop_size, int bit_count, int data_count)
{
	int i;
	/*  Allocate Population's space  */
	population *pop = (population *)malloc(sizeof(population));
	
	/*  Allocate Individuals' space  */
	individual *ivd = (individual *)malloc(sizeof(individual)*pop_size);
	
	/*  Initialize Individual's Values.  */
	for(i=0; i<pop_size; i++)
	{
		ivd[i].crms = (int *)malloc(sizeof(chromosome)*bit_count);
		ivd[i].fitness  = 0.0;
	}
	
	/*  Give Population The Genetic Informations.  */
	pop->ivd = ivd;
	pop->pop_size = pop_size;
	pop->bit_count = bit_count;
	pop->data_count = data_count;
	
	printf("Population is created!\n");
	
	/*  Return New Population's Address And Finish this Function.  */
	return pop;
}

/*  Deallocate place for The Population in Memory.  */
void free_population(population *pop)
{
	int i;
	
	/*  Deallocate Individuals' Gene Array.  */
	for(i=0; i<pop->pop_size; i++)
	{
		free(pop->ivd[i].crms);
	}
	
	/*  Deallocate Individuals  */
	free(pop->ivd);
	
	/*  Deallocate Population  */
	free(pop);
	
	printf("Population is disallocated.\n");
	
}
