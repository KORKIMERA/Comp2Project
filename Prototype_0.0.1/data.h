/*================================================================================================= */
/* This Code is written by JeongHyeon Choi. (Mokpo National University Student in Korea)            */
/*                         KORKIMERA                                                                */
/*                                                                                                  */
/*                                                                                                  */
/* Tool          : Dev C++ 5.10                                                                     */
/* OS            : Windows 7                                                                        */
/* Version       : Prototype 0.0.1                                                                  */
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
