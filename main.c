#include  "bigint.h"
#include <stdio.h>
#include <assert.h>
#include <stdlib.h>

int main()
{
  int i, f; 
  for(f = 1; f <= 100; f++) {
    bigint_t a, b, fib;  //they goes for big numbers! Hence stored in bigint
    for(i=2, a = new_bigint(1), b = new_bigint(1), fib = new_bigint(1); i < f; i++) { 
     add(&fib,a,b); //addition is done by calling the relevant function
     a = b; 
     b = fib; 
    }
    printf("%d the Fib is ", f);//printing the corresponding fibonacci
    show_bigint(fib); //showing is done by calling the corresponding function
    printf("\n");
	
	//nodes are freed finally
	free_bigint(fib);
	
  } 

  return 0; 
}
  
  
