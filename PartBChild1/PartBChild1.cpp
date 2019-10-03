#include "..\rt.h"

struct Pipe1Struct {
	int data10;
	int data11;
	//int data12[10] = { 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 };
};

int main(void) {
	CTypedPipe <int> Pipe1("Pipeline1", 100);

	Pipe1Struct pipe1data;
	pipe1data.data10 = 10;
	pipe1data.data11 = 11;

	while (1) {
		Pipe1.Write(&pipe1data.data10);
		Sleep(1000);
		cout << "Wrote data to Pipeline1..." << endl;
	}

	return 0;
}