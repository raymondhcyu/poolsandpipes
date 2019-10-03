#include "..\rt.h"

struct Pipe1Struct {
	int data10;
	int data11;
	//int data12[10] = { 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 };
};

struct Pipe2Struct {
	int data20;
	int data21;
};

struct Pipe3Struct {
	int data30;
	int data31;
};

struct Pipe4Struct {
	int data40;
	int data41;
};

int pipe1Data; // int is 4 bytes in C++

int main(void) {
	cout << "Starting parent process..." << endl;

	CTypedPipe <int> Pipe1("Pipeline1", 100);
	//CTypedPipe <int> Pipe2("Pipeline2", 100);
	//CTypedPipe <int> Pipe3("Pipeline1", 100);
	//CTypedPipe <int> Pipe4("Pipeline2", 100);

	CProcess p1("D:\\Documents\\CPEN333\\CPEN333Lab4\\Debug\\PartBChild1.exe",
		NORMAL_PRIORITY_CLASS,
		OWN_WINDOW,
		ACTIVE
	);

	while (1) {
		if ((Pipe1.TestForData()) >= sizeof(pipe1Data)) {
			Pipe1.Read(&pipe1Data);
			cout << "Parent read " << pipe1Data << " from Pipeline 1..." << endl;
		}
	}

	p1.WaitForProcess();
	return 0;
}