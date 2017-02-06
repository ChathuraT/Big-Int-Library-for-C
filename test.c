#include <stdio.h>
#include "bigint.h"


int main(){
	
	//testing the big integer library. Please input only int numbers!
	
	//taking 1st user input and saving them as bigint
	int input1,input2;
	printf("Enter the big integer1: ");
	scanf("%d",&input1);
	bigint_t bigInt1 =new_bigint(input1);
	
	//taking 2nd user input and saving them as bigint
	printf("Enter the big integer2: ");
	scanf("%d",&input2);
	bigint_t bigInt2 =new_bigint(input2);
	
	//Printing the 2 big Integers
	printf("\nPrinting Big Integer 1 \n");
	show_bigint(bigInt1);
	printf("\n\nPrinting Big Integer 2 \n");
	show_bigint(bigInt2);
	
	//Add the two bigInts and storing them in sum
	bigint_t sum;
	add(&sum,bigInt1,bigInt2);
	printf("\n\nPrinting The sum of Big Integer 1 and Big Integer 2 \n");
	show_bigint(sum);
	
	//Free all the memory used by the given 2 bigints.
	free_bigint(bigInt1);
	free_bigint(bigInt2);
	
	printf("\n\nEnd of testing bigInt library\n");
	return 0;
	
	}
