#include	"..\rt.h"			// change the pathlist to rt.h to suit location on your disk

struct		example {		// structure template for some data that we intend to read from pipeline
	int 	x;
	float 	y;
};

// Some variables to hold the read from the pipeline.
int 	i;				// a simple int
int 	array1[10]; 		// array of 10 integers
char	name[15];			// a string of 15 characters
struct	 example mystruct;	// a structure with an int and a float in it
int array2[1025] = {};

int	main()
{
	int 	x;					// a temporary variable for use with the 'for' loop below

	printf("Child Process 1 Opening Pipeline.....\n");
	CPipe	p1("MyPipe", 1024);		// Create a pipe 'p1' with the name "MyPipe"

	p1.Read(&i, sizeof(i));				// Read the int 'i' from the pipe
	cout << "Child Process 1 read integer = " << i << " from Pipeline.....\n";

	p1.Read(&array1[0], sizeof(array1));		// Read the array of integers' from the pipe
	printf("Child Process 1 read array = ");
	for (x = 0; x < sizeof(array1) / sizeof(array1[0]); x++)
		cout << " " << array1[x];

	putchar('\n');

	p1.Read(&name[0], sizeof(name));	// Read the string from the pipe
	cout << "Child Process 1 read string = " << name << ", from Pipeline.....\n";

	p1.Read(&mystruct, sizeof(mystruct));	// Read the structure from the pipeline
	cout << "Child Process 1 read [" << mystruct.x << "," << mystruct.y << "] from Pipeline.....\n";

	//p1.Read(&array2[0], sizeof(array2));
	//cout << "Child process 1 read overflow array = ";
	//for (int j = 0; j < sizeof(array2) / sizeof(array2[0]); j++)
	//	cout << array2[j] << endl;

	Sleep(4000);
	return 0;

}	// pipe destructor called here to destroy p. Note however if pipeline still has unread data in it,
	// that data will be preserved