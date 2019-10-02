#include "..\rt.h"

struct example {
	int x;
	float y;
};

int 	i = 5;									// a simple int
int 	array1[10] = { 1 , 2 , 3 , 4 , 5 , 6 , 7 , 8 , 9 , 0 }; 		// array of 10 integers
char	name[15] = "Hello World";					// a string of 15 characters
struct	 example mystruct 
	= { 2, 5.5 };				// a structure with an int and a float in it
int array2[1025] = {};

int main(void) {

	// Create pipelines
	// Note 1: each pipeline can only have one child reading b/c data is destroyed after,
	// compared to datapool where multiple children can read at once (non-destructive),
	// though no synchronization (can be unpredictable if one read and one update).
	// Note 2: If exceeding 1024 bytes of data written, would loop and overwrite first data.
	cout << "Parent creating pipelines..." << endl;
	CPipe pipe1("MyPipe", 1024); // create pipeline w/ specified size
	CPipe pipe2("MyPipe2", 1024);

	// Create child processes to read from pipelines
	cout << "Parent Process Creating Child Processes to Read from Pipelines.....\n";
	CProcess p1("D:\\Documents\\CPEN333\\CPEN333Lab4\\Debug\\PipelineChild.exe",	// pathlist to child program executable				
		NORMAL_PRIORITY_CLASS,			// priority
		OWN_WINDOW,						// process has its own window					
		ACTIVE							// process is active immediately
	);
	CProcess p2("D:\\Documents\\CPEN333\\CPEN333Lab4\\Debug\\PipelineChild2.exe",	// pathlist to child program executable				
		NORMAL_PRIORITY_CLASS,			// priority
		OWN_WINDOW,						// process has its own window					
		ACTIVE							// process is active immediately
	);

	cout << "Hit RETURN to Write the integer " << i << " to the pipelines.....\n";
	getchar();
	pipe1.Write(&i, sizeof(i));						// write the int 'i' to the pipe
	pipe2.Write(&i, sizeof(1));

	cout << "Hit RETURN to Write the integer array 1 2 3 4 5 6 7 8 9 0 to the pipelines.....\n";
	getchar();
	pipe1.Write(&array1[0], sizeof(array1));			// write the array of integers' to the pipe
	pipe2.Write(&array1[0], sizeof(array1));

	cout << "Hit RETURN to Write the string " << name << " to the pipelines.....\n";
	getchar();
	pipe1.Write(&name[0], sizeof(name));				// write the string to the pipe
	pipe2.Write(&name[0], sizeof(name));

	cout << "Hit RETURN to Write the structure [" << mystruct.x << ", " << mystruct.y << "] to the pipelines.....\n";
	getchar();
	pipe1.Write(&mystruct, sizeof(mystruct));			// write the structure to the pipeline
	pipe2.Write(&mystruct, sizeof(mystruct));

	// Part A: Overflow test
	// Note: By exceeding the byte size, the write request will be suspended, aka nothing happens
	/*for (int i = 0; i < 1025; i++)
	{
		array2[i] = 0;
	}
	cout << "Hit RETURN to overwrite the pipeline data!" << endl;
	getchar();
	pipe1.Write(&array2[0], sizeof(array2));
	*/

	p1.WaitForProcess();
	p2.WaitForProcess();
	return 0;
}