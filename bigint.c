#include "bigint.h"
#include <stdlib.h>

bigint_t new_bigint(int a){	
	//these two variables helps to create the link list
	biginteger  * numbers = NULL; 
	biginteger  * current;	
	
	//first reverse the number for convenience(it makes addition easy!)
	 int reva = 0, rem;
	 while(a != 0){
		rem = a%10;
		reva = reva*10 + rem;
		a /= 10;
	}
	
	//Then store the reversed number in the linked list
	while(reva>0){
		 
		current = (biginteger  *)malloc(sizeof(biginteger ));
		current -> num  = reva%10;
		current -> next = numbers;
		
		numbers = current;
		reva=reva/10;
	}
	return numbers; //returning the stored big integer
}


int add(bigint_t *sum, bigint_t a, bigint_t b){
	
	*sum=NULL;//sum is initialized to null so that the tailof linked list is pointed to null
	biginteger  * current;
	int temp=0;//this variable is used to store the carry out in addition if any
	
	while(a!= NULL && b!= NULL){
		current = (biginteger  *)malloc(sizeof(biginteger ));
		if((a->num+b->num+temp)>9){//summing up the integers and checking whether there is an carry out,
			current->num=(a->num+b->num+temp)%10; //if carry out is available
			temp=1;//it is stored in temp
		}else{
			current -> num  = a->num+b->num+temp; //if carry out is not available
			temp=0;
		}
		
		current -> next = *sum;//building the linked list
		*sum= current;
		a= a->next;
		b=b->next;
	}
	if(a== NULL && b!= NULL){ //if a reached to end first
		while(b!=NULL){ //storing the remaining in b to sum as it is
			current = (biginteger  *)malloc(sizeof(biginteger ));
			current -> num =b->num+temp;
			current -> next = *sum;
			*sum= current;
			temp=0;
			b=b->next;
			
		}
			
	}else if(a!= NULL && b== NULL){//if b reached to end first
		while(a!=NULL){ //storing the remaining in a to sum as it is
			current = (biginteger  *)malloc(sizeof(biginteger ));
			current -> num =a->num+temp;
			current -> next = *sum;
			*sum= current;
			temp=0;
			a=a->next;
			
		}
			
	}if(temp!=0){//after all checking for any remaining carry out and storing it in sum
		current = (biginteger  *)malloc(sizeof(biginteger ));
			current -> num =1;
			current -> next = *sum;
			*sum= current;
			temp=0;
				
	}
	//reversing the result for convenient displaying and further addition
		biginteger *temp0,*temp1,*var;
		temp0=*sum;
		var=NULL;
		while(temp0!=NULL){
			 temp1=var;
			 var=temp0;
			 temp0=temp0->next;
			 var->next=temp1;
		}
		*sum=var;
		
		//show_bigint(*sum);

	return 0;
}


void show_bigint(bigint_t v){
	//since the number is stored in the linked list in reversed order a recursive mechanism 
	//is used to display it in correct way.
    if (v== NULL)//checking whethe the tail of the linked list has reached
       return;
    show_bigint(v->next); //calling the show fuction again until the end
 
    printf("%d", v->num); //Printing the number stored in the node in coming back way.
	
}

void free_bigint(bigint_t v){
	biginteger *current=v; //this temporary variable is used to free up the memory node by node
	while (v!= NULL) { 
    v = v->next;          //iterating till the end
    free (current);       //freeing each node
	}           
 
}
