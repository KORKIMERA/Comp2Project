/*================================================================================================= */
/* This Code is written by JeongHyeon Choi. (Mokpo National University Student in Korea)            */
/*                         KORKIMERA                                                                */
/*                                                                                                  */
/*                                                                                                  */
/* Tool          : Dev C++ 5.10                                                                     */
/* OS            : Windows 7                                                                        */
/* Version       : Prototype 0.0.2                                                                  */
/* Description   : Header File For Coordinates                     									*/
/*================================================================================================= */


/*================================================================================================= */
/* INCLUDE                                                                                          */

#include "coordinate.h"
#include "data.h"
#include <stdio.h>
#include <stdlib.h>

/*================================================================================================= */


/*================================================================================================= */
/* FUNCTION                                                                                         */

/*  Create Board  */
int (*create_board(int initNumber))[BOARD_SIZE]
{
	int i, j;
	
	int (*board)[BOARD_SIZE] = (int (*)[BOARD_SIZE])malloc(sizeof(int)*BOARD_SIZE*BOARD_SIZE);
	
	for(i=0; i<BOARD_SIZE; i++)
	{
		for(j=0; j<BOARD_SIZE; j++)
		{
			board[i][j] = initNumber;
		}
	}
	
	return board;
}

/*  Put The Stone on The Board.  */
void inputCoordinate(int (*board)[BOARD_SIZE], int Xpos, int Ypos)
{
	board[Xpos][Ypos] = BLACKSTONE;
}

/*  Judge Coordinates Are Out Of Range Or Not.  */
int isOutOfRange(int x, int y)
{
	/*  Out Of Range, Return 1  */
	if(x < 0 || x > BOARD_SIZE-1 || y < 0 || y > BOARD_SIZE)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}
