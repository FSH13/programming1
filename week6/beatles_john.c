//***********************
// Fleur Smit
// The Beatles - John
// name; instrument; born
//***********************

#include <stdio.h>
#include <cs50.h>

struct musician {
    string name;
    string instrument;
    int year_born;
};

void print_musician(struct musician m);

int main()
{
    // Step 1: Create a 'john' variable
	struct musician john; // = malloc(sizeof(struct musician));

    // Step 2: Set the fields to the appropriate values
	john.name = "John";
	john.instrument = "guitar, vocals";
	john.year_born = 1940;

    // Step 4: Call the print function on 'john'
	print_musician(john);
}

// Step 3: create a print function
void print_musician(struct musician m){
	printf("The members of The Beatles are: \nName:        %s\n", m.name);
	printf("Instrument:  %s\n", m.instrument);
	printf("Born:        %i\n", m.year_born);
}
