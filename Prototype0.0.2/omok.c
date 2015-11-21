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

/*================================================================================================= */
/* INCLUDE                                                                                          */

#include "omok.h"
#include "coordinate.h"
#include "genetic.h"
#include "data.h"
#include <stdio.h>
#include <stdlib.h>

/*================================================================================================= */


/*================================================================================================= */
/* DEFINE                                                                                           */

/*================================================================================================= */


/*================================================================================================= */
/* FUNCTION                                                                                         */

/*  Init Omok Turn.  */
omok * _init_omok(void)
{
	/*  Omok Struct  */
	omok *GAOMOK;
	
	/*  Allocate Omok Struct's Space  */
	GAOMOK = (omok *)malloc(sizeof(omok));
	
	/*  Allocate 2 Dimension Array Board's Space  */
	GAOMOK->board = create_board(NONESTONE);
	
	/*  Allocate 2 Dimension Array Board's Space  */
	GAOMOK->fitness_board = create_board(0);
	
	/*  Create Omok Gene's Population  */
	GAOMOK->pop = create_population(POP_SIZE, BIT_COUNT, DATA_COUNT);
	
	/*  Return Address Of Allocated Space  */
	return GAOMOK;
}

/*  Randomize Choromosomes.  */
void randomize_stone(omok *GAOMOK)
{
	rand_population(GAOMOK->pop);
}

/*  Get Fitness Value Of Each Individuals On The Board.  */
int (*getBoardFitness(int (*omok_board)[BOARD_SIZE], int (*fitness_board)[BOARD_SIZE]))[BOARD_SIZE]
{
	int i,
		j;
		
	for(i=0; i<BOARD_SIZE; i++)
	{
		for(j=0; j<BOARD_SIZE; j++)
		{
			/*  Evaluate Board.  */
			fitness_board = evaluate_board(omok_board, fitness_board, i, j);
		}
	}


	for(i=0; i<BOARD_SIZE; i++)
	{
		for(j=0; j<BOARD_SIZE; j++)
		{
			fitness_board[i][j] *= 10;
		}
	}
	
	
	/*  Return Fitness Board.  */
	return fitness_board;
}


int (*evaluate_board(int (*omok_board)[BOARD_SIZE], int (*fitness_board)[BOARD_SIZE], int Xpos, int Ypos))[BOARD_SIZE]
{
	int i,
		temp_Xpos,
		temp_Ypos;
		
	for(i=0; i<8; i++)
	{	
		temp_Xpos = Xpos;
		temp_Ypos = Ypos;
	
		/*  Get Relatively Moved Coordinates' Value In Stone's Position  */
		getFitnessStonePosition(omok_board, &temp_Xpos, &temp_Ypos, i);
		
		/*  If Positions Are Out Of Range, Skip.  */
		if(temp_Xpos < 0 || temp_Xpos > 14 || temp_Ypos < 0 || temp_Ypos >14)
		{
			continue;
		}
		

		
		if(omok_board[temp_Xpos][temp_Ypos] == -1 && fitness_board[temp_Xpos][temp_Ypos] > 1)
		{
			fitness_board[temp_Xpos][temp_Ypos] = fitness_board[temp_Xpos][temp_Ypos] - 1;
		}
		else
		{
			fitness_board[temp_Xpos][temp_Ypos] = fitness_board[temp_Xpos][temp_Ypos] + 1;
		}
	}
	
	return fitness_board;
}

void getFitnessStonePosition(int (*board)[BOARD_SIZE], int *Xpos, int *Ypos, int direction)
{
	switch(direction)
	{
		case UP:
			do
			{
				*Ypos++;
				
				if(isOutOfRange(*Xpos, *Ypos))
				{
					break;
				}
			}while(board[*Xpos][*Ypos] == BLACKSTONE);
			
			break;
		case RIGHT_UP:
			do
			{
				*Xpos++;
				*Ypos++;
				
				if(isOutOfRange(*Xpos, *Ypos))
				{
					break;
				}
			}while(board[*Xpos][*Ypos] == BLACKSTONE);
			
			break;
		case RIGHT:
			do
			{
				*Xpos++;
				
				if(isOutOfRange(*Xpos, *Ypos))
				{
					break;
				}
			}while(board[*Xpos][*Ypos] == BLACKSTONE);
			
			break;
		case RIGHT_DOWN:
			do
			{
				*Xpos++;
				*Ypos--;
				
				if(isOutOfRange(*Xpos, *Ypos))
				{
					break;
				}
			}while(board[*Xpos][*Ypos] == BLACKSTONE);
			
			break;
		case DOWN:
			do
			{
				*Ypos--;
				
				if(isOutOfRange(*Xpos, *Ypos))
				{
					break;
				}
			}while(board[*Xpos][*Ypos] == BLACKSTONE);
			
			break;
		case LEFT_DOWN:
			do
			{
				*Xpos--;
				*Ypos--;
				
				if(isOutOfRange(*Xpos, *Ypos))
				{
					break;
				}
			}while(board[*Xpos][*Ypos] == BLACKSTONE);
			
			break;
		case LEFT:
			do
			{
				*Xpos--;
				
				if(isOutOfRange(*Xpos, *Ypos))
				{
					break;
				}
			}while(board[*Xpos][*Ypos] == BLACKSTONE);
			
			break;
		case LEFT_UP:
			do
			{
				*Xpos--;
				*Ypos++;
				
				if(isOutOfRange(*Xpos, *Ypos))
				{
					break;
				}
			}while(board[*Xpos][*Ypos] == BLACKSTONE);
			
			break;
	}
}
