#include "..\rt.h"

struct Pipe3Struct {
	int data30;
	int data31;
};

int main(void) {
	CTypedPipe <int> Pipe3("Pipeline3", 100);

	Pipe3Struct pipe3Data;
	pipe3Data.data30 = 3000;
	pipe3Data.data31 = 3001;
	int increment = 10;

	while (1) {
		pipe3Data.data30 = pipe3Data.data30 + increment;
		Pipe3.Write(&pipe3Data.data30);
		Sleep(1500);
		cout << "Wrote " << pipe3Data.data30 << " to Pipeline3..." << endl;
	}

	return 0;
}