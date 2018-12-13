#include <stdio.h> 

int main(int argc, char *argv[])
{
	int i= 0; 

	//go through each stringin argv
	//why am i skipping argv[0]?
	for (i=1; i < argc; i++){
		// if you do int i = 0, it prints out ex13 as an argument
		printf("arg %d: %s\n", i, argv[i]);
	}

	//let's make our array of strings 
	
	char *states[] ={
		"California", "Oregon", 
		"Washington", "Texas"
	};

	int num_states = 4; 

	for (i = 0; i<num_states; i++ ) {
		printf("state %d: %s\n", i, states[i]); 
	}

	return 0; 
}

