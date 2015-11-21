/*================================================================================================= */
/* This Code is written by JeongHyeon Choi. (Mokpo National University Student in Korea)            */
/*                         KORKIMERA                                                                */
/*                                                                                                  */
/*                                                                                                  */
/* Tool          : Dev C++ 5.10                                                                     */
/* OS            : Windows 7                                                                        */
/* Version       : Prototype 0.0.2                                                                  */
/* Description   : Header File For User Interface.                                                  */
/*================================================================================================= */


/*================================================================================================= */
/* INCLUDE                                                                                          */

#include "ui.h"
#include "data.h"
#include <stdio.h>
#include <stdlib.h>

/*================================================================================================= */


/*================================================================================================= */
/* FUNCTION                                                                                         */

display_board(board (*omok_board)[BOARD_SIZE])
{
	int i,
		j;
	
	for(i=0; i<BOARD_SIZE; i++)
	{
		printf("%d\t", i+1);
	}
	
	puts("");
	
	for(i=0; i<BOARD_SIZE; i++)
	{
		printf("%d\t",i+1);
		
		for(j=0; j<BOARD_SIZE; j++)
		{
			switch(omok_board[i][j])
			{
				case BLAKESTONE:
					printf("X\t");
					break;
				case WHITESTONE:
					printf("O\t");
					break;
				case NONESTONE:
					printf(".\t");
					break;
			}
		}
		
		puts("");
	}
}
