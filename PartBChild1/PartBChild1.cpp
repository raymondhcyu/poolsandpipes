#include "..\rt.h"

struct Pipe1Struct {
	int data10;
	int data11;
};

int main(void) {
	CTypedPipe <int> Pipe1("Pipeline1", 100);

	Pipe1Struct pipe1data;
	pipe1data.data10 = 1000;
	pipe1data.data11 = 1001;
	int increment = 10;

	while (1) {
		pipe1data.data10 = pipe1data.data10 + increment;
		Pipe1.Write(&pipe1data.data10);
		Sleep(500);
		cout << "Wrote " << pipe1data.data10 << " to Pipeline1..." << endl;
	}

	return 0;
}