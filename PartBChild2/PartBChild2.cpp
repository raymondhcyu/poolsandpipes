#include "..\rt.h"

struct Pipe2Struct {
	int data20;
	int data21;
};

int main(void) {
	CTypedPipe <int> Pipe2("Pipeline2", 100);

	Pipe2Struct pipe2data;
	pipe2data.data20 = 2000;
	pipe2data.data21 = 2001;
	int increment = 10;

	while (1) {
		pipe2data.data20 = pipe2data.data20 + increment;
		Pipe2.Write(&pipe2data.data20);
		Sleep(1000);
		cout << "Wrote " << pipe2data.data20 << " to Pipeline2..." << endl;
	}

	return 0;
}