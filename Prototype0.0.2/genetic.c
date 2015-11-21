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


/*================================================================================================= */
/* INCLUDE                                                                                          */

#include "data.h"
#include "genetic.h"
#include <math.h>
#include <stdio.h>
#include <stdlib.h>

/*================================================================================================= */


/*================================================================================================= */
/* DEFINE                                                                                           */

#define min(a,b) (((a)>(b))?(b):(a))

/*================================================================================================= */


/*================================================================================================= */
/* FUNCTION                                                                                         */

/*  Allocate New place for New Population in Memory And Return Population's Address.  */
population * create_population(int pop_size, int bit_count, int data_count)
{
	int i, j;
	/*  Allocate Population's space  */
	population *pop = (population *)malloc(sizeof(population));
	
	/*  Allocate Individuals' space  */
	individual *ivd = (individual *)malloc(sizeof(individual)*pop_size);
	
	/*  Initialize Individual's Values.  */
	for(i=0; i<pop_size; i++)
	{
		ivd[i].crms = (int *)malloc(sizeof(chromosome)*bit_count);
		ivd[i].fitness  = 0.0;
		
		for(j=0; j<bit_count; j++)
		{
			ivd[i].crms[j] = 0;
		}
		
	}
	
	/*  Give Population The Genetic Informations.  */
	pop->ivd = ivd;
	pop->pop_size = pop_size;
	pop->bit_count = bit_count;
	pop->data_count = data_count;
	
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
	
}

/*  Get Random Number Between a And b */
int rand_between(int a, int b)
{
	int delta, randnum;
	
	/*  Input Absolute Number Into delta. */
	delta = abs(a - b) + 1;
	
	randnum = rand() % delta;
	
	/*  Return Random Number. */
	return (min(a, b) + randnum);
}

/*  Randomize Individuals' Gene  */
void rand_population(population *pop)
{
	int i,
		pos;
	
	/*  Change Seed Value By Time.  */
	srand(time(NULL));
	
	for(i=0; i<pop->pop_size; i++)
	{
		for(pos=0; pos<pop->bit_count; pos++)
		{
			/*  Randomize Individuals' Gene  */
			pop->ivd[i].crms[pos] = rand_between(0, 1);
		}
	}
}

/*  Convert Gene into DEC  */
void decode(chromosome *crms, int *param, int bit_count, int data_count)
{
	int pos,
		n,
		i;
	
	int data_bit_count = bit_count / data_count;
	pos = 0;
	
	
	for(n=0; n<data_count; n++)
	{
		param[n] = 0;
		
		for(i=0; i<data_bit_count; i++)
		{
			/*  Decode  */
			param[n] = param[n] + pow(2.0, (double)i) * crms[pos++];
		}
	}
}

/*  Display Decoded Gene Of Individuals  */
void display_population(population *pop)
{
	int n,
		i;
	
	/*  Define Param For Saving Decoded Data  */
	int *param = (int *)malloc(sizeof(int) * pop->data_count);
	
	
	for(i=0; i<pop->pop_size; i++)
	{
		/*  Decode  */
		decode(pop->ivd[i].crms, param, pop->bit_count, pop->data_count);
		
		printf("[ ");
		
		/*  Devide Space By Blank And Display Each */
		for(n=0; n<pop->data_count; n++)
		{
			printf("%d", param[n]);
			
			if(n==0)
			{
				printf(", ");
			}
		}
		
		printf(" ]\n");
	}
	
	/*  Free Parameter  */
	free(param);
}

/*  Estimate Individuals' Fitness  */
void evaluate(population *pop)
{
	int index;
	
	int *param = (int *)malloc(sizeof(int)*(pop->data_count));
	
	for(index = 0; index<pop->pop_size; index++)
	{
		/*  Decode And Save Decoded Data Into param  */
		decode(pop->ivd[index].crms, param, pop->bit_count, pop->data_count);
		
		/*  Estimate Fitness  */
		pop->ivd[index].fitness = getFitness(param, pop->data_count);
	}
	
	free(param);
}

/*  Get Fitness Value  */
double getFitness(int *param, int data_count)
{
	int i;
	double average = 0,
		   variance = 0;
	
	for(i=0; i<data_count; i++)
	{
		average += param[i];
	}
	average /= data_count;
	
	for(i=0; i<data_count; i++)
	{
		variance += (average-param[i])*(average-param[i]);
	}
	variance /= data_count;
	
	return variance;
}

/*  Generate Mutant Individual  */
void mutate(chromosome *crms, int bit_count)
{
	int i;
	
	for(i=0; i<bit_count; i++)
	{
		/*  Mutate Individual's Gene with Probability Of 1/300  */
		if(rand_between(0,300) == 0)
		{
			/*  Mutate By XOR Operator */
			crms[i] ^= 1;
		}
	}
}

/*  Get Randomly Selected Individual  */
individual * select_individual(population *pop)
{
	unsigned int index1,
				 index2;
	
	int i,
		count = 0;
	
	do
	{
		count++;
		
		index1 = rand_between(0, pop->pop_size-1);
		index2 = rand_between(0, pop->pop_size-1);
		
		if(pop->ivd[index1].fitness == 0)
		{
			break;
		}
		
		if(count > 3)
		{
			for(i=0; i<pop->pop_size; i++)
			{
				mutate(pop->ivd[i].crms, pop->bit_count);
			}
			break;
		}
		
		
	}while(pop->ivd[index1].fitness == pop->ivd[index2].fitness);

	/*  Return One Has Higher Fitness Value */
	if(pop->ivd[index1].fitness > pop->ivd[index2].fitness)
	{
		return &pop->ivd[index1];
	}
	else
	{
		return &pop->ivd[index2];
	}
}

/*  Crossover Two Individuals' Gene By Using Uniform Crossover And Make Babies' Gene  */
void crossover(chromosome *Person1, chromosome *Person2, chromosome *Baby1, chromosome *Baby2, int bit_count)
{
	int i;
	
	/*  Create Random Number's Space  */
	double *FitChrome = (double *)malloc(sizeof(double)*bit_count);
	
	/*  Rand_Number  */
	for(i=0; i<bit_count; i++)
	{
		FitChrome[i] = (rand()%100/100);
	}
	
	/*  If Gene's Number Is Bigger Than PZERO, Get Person1's Gene, If Not, Get Person2's.  */
	for(i=0; i<bit_count; i++)
	{
		if(FitChrome[i] > PZERO)
		{
			Baby1[i] = Person1[i];
			Baby2[i] = Person2[i];
		}
		else
		{
			Baby1[i] = Person2[i];
			Baby2[i] = Person1[i];
		}
	}

}

/*  Create New Individuals  */
void breed(individual *old_v1, individual *old_v2, individual *new_v1, individual *new_v2, int bit_count)
{
	/*  Crossover Individuals' Gene  */
	crossover(old_v1->crms, old_v2->crms, new_v1->crms, new_v2->crms, bit_count);
	
	/*  Generate Mutant  */
	mutate(new_v1->crms, bit_count);
	mutate(new_v2->crms, bit_count);
}

/*  Evolution  */
void new_generate(population *old_pop, population *new_pop)
{
	int i;
	individual *v1, *v2;
	
	for(i=0; i<old_pop->pop_size; i+=2)
	{
		v1 = select_individual(old_pop);
		v2 = select_individual(old_pop);
		
		/*  Create New Individuals  */
		breed(v1, v2, &new_pop->ivd[i], &new_pop->ivd[i+1], old_pop->bit_count);
		
		
	}
}

int isExist(chromosome *crms, bit gene, int bit_count)
{
	int i;
	
	for(i=0; i<bit_count; i++)
	{
		if(crms[i] == gene)
			return 1;
	}
	
	return 0;
}

bit *getIndexOfBit(chromosome *crms, bit gene, int bit_count)
{
	int i;
	
	for(i=0; i<bit_count; i++)
	{
		if(crms[i] == gene)
			return (&crms[i]);
	}
}

/*  Evolution  */
void display_chromosome(chromosome *crms, int bit_count)
{
	int i;
	
	for(i=0; i<bit_count; i++)
	{
		printf("%d", crms[i]);
	}
	
	printf("\n");
}

