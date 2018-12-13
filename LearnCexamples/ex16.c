#include <stdio.h> 
#include <assert.h> 
#include <stdlib.h> 
#include <string.h> 

struct Person{
	//create a struct with four adjectives
	char *name; 
	int age; 
	int height ; 
	int weight ; 
};

struct Person *Person_create(char *name, int age, int height, int weight)
{ 
	//allocate space for that person with the malloc by the size of the struct
	
	struct Person *who = malloc(sizeof(struct Person)); 
	// make it space you'll use
	assert(who != NULL); 

	//say what part of the structure you'll set with which variable?
	//strdup is like malloc. it duplicates the string for the name for the struct
	who->name = strdup(name); 
	who->age = age; 
	who->height = height; 
	who->weight = weight; 

	return who; 
}

void Person_destroy(struct Person *who)
{
	//make sure it's not already empty
	assert(who != NULL); 
	//free the memory so you don't get "memory leak"
	free(who->name); 
	free(who); 
}

void Person_print(struct Person *who)
{
	//same x->y syntax as before in order to print
	printf("Name: %s\n", who->name); 
	printf("\tAge: %d\n", who->age); 
	printf("\tHeight: %d\n", who->height); 
	printf("\tWeight: %d\n", who->weight); 
}

int main(int argc, char *argv[])
{
	//make a struct of joe, using the Person skeleton
	struct Person *joe = Person_create("Joe Alex", 32, 64, 140); 

	//same with frank
	struct Person *frank = Person_create("Frank Blank", 20, 72, 180); 

	//print them out and where they are in memory
	
	printf("Joe is at memory location %p:\n", joe);
        Person_print(joe); 
	printf("Frank is at memory location %p: \n", frank);	
	Person_print(frank); 
	//make everyone age 20 and preing them again
	
	joe->age +=20; 
	joe->height -=2; 
	joe->weight +=40; 
	Person_print(joe); 

	frank->age +=20; 
	frank->weight += 20; 
	Person_print(frank); 

	//destroy them both so we clean up 
	Person_destroy(joe); 
	Person_destroy(frank); 
	
	return 0; 
}

