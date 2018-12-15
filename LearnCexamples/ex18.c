#include <stdio.h> 
#include <stdlib.h> 
#include <errno.h> 
#include <string.h>

//Our old friend from ex17

void die(const char *message){
	//same exiting error-handling function
	if (errno){
		perror(message); 
	}
	else{
		printf("ERROR: %s:\n", message); 
	}
	exit(1); 
}

// a typedef creates a fake type,
// in this case for a function pointer
//make it an int so you can compare it in bubble_sort and test_sorting
typedef int (*compare_cb) (int a, int b); 

/** 
 * A classic bubble sort function that uses the compare_cb to do the sorting 
 */

int *bubble_sort(int *numbers, int count, compare_cb cmp)
{
	//use typedef for compare_cb as cmp
	int temp = 0; 
	int i = 0; 
	int j = 0; 
	//new array of integer on the heap using malloc
	//LOOK UP WHAT COUNT * SIZEOF(INT) MEANS 
	int *target = malloc(count * sizeof(int)); 

	if (!target)
		die("Memory error"); 
	//LOOK UP WHAT MEMCPY DOES
	memcpy(target, numbers, count * sizeof(int));

	for(i=0; i<count; i++){
		for(j=0; j<count-1; j++){
			//use cmp as if it's a normal function 
			//target is the sorted result array
			if(cmp(target[j], target[j+1])>0){
				temp = target[j+1];
				target[j+1];
				target[j+1] = target[j]; 
				target[j] = temp; 
			}
		}
	}
	return target; 
}
//3 different versions of the compare_cb function type

int sorted_order(int a, int b)
{
	return a-b; 
}
int reverse_order(int a, int b)
{
	return b-a; 
}

int strange_order(int a, int b)
{
	if (a == 0 || b == 0) {
		return 0; 
	}
	else{
		return a%b;
	}
}

//Used to test that we are sorting things correctly by 
//doing the sort and printing it out

void test_sorting(int *numbers, int count, compare_cb cmp)
{
	int i = 0; 
	int *sorted = bubble_sort(numbers, count, cmp); 

	if (!sorted) 
		die("Failed to sort as requested"); 
	for(i = 0; i<count; i++){
		printf("%d ", sorted[i]); 
	}
	printf("\n"); 

	free(sorted); 
}

int main(int argc, char *argv[]){
	if (argc<2)
		die("USAGE: ex18 4 3 1 5 6"); 
	int count = argc -1; 
	int i = 0; 
	char **inputs = argv + 1; 

	int *numbers = malloc(count * sizeof(int)); 
	if(!numbers)
		die("Memory error"); 
	for (i = 0; i < count; i++){
		numbers[i] = atoi(inputs[i]); 
	}

	test_sorting(numbers, count, sorted_order); 
	test_sorting(numbers, count, reverse_order); 
	test_sorting(numbers, count, strange_order); 

	free(numbers); 
	return 0; 
}

