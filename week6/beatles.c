//***********************
// Fleur Smit
// The Beatles
// name; instrument; born
//***********************

#include <stdio.h>
#include <cs50.h>
#include <string.h>


struct musician {
    string name[4];
    string instrument[4];
    int year_born[4];
};

void print_musician(struct musician m);

int main()
{
    // Step 1: Create a 'john' variable
	struct musician beatles; // = malloc(sizeof(struct musician));

    // Step 2: Set the fields to the appropriate values
	beatles.name[0] = "John";
	beatles.name[1] = "Paul";
	beatles.name[2] = "George";
	beatles.name[3] = "Ringo";
	beatles.instrument[0] = "guitar, vocals";
        beatles.instrument[1] = "bass, vocals";
        beatles.instrument[2] = "guitar, vocals";
        beatles.instrument[3] = "drum";
	beatles.year_born[0] = 1940;
        beatles.year_born[1] = 1942;
        beatles.year_born[2] = 1943;
        beatles.year_born[3] = 1940;
//	int test_array[] = {1940, 1942, 1943, 1940};
//	beatles.year_born = test_array;
    // Step 4: Call the print function on 'john'
	print_musician(beatles);
}

// Step 3: create a print function
void print_musician(struct musician m){
	printf("The members of The Beatles are: \n");

	for (int c = 0; c < 4; c++){
		printf("Name:        %s\n", m.name[c]);
		printf("Instrument:  %s\n", m.instrument[c]);
		printf("Born:        %i\n\n", m.year_born[c]);
	}
}
