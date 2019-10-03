#include "..\rt.h"

struct Pipe4Struct {
	int data40;
	int data41;
};

int main(void) {
	CTypedPipe <int> Pipe4("Pipeline4", 100);

	Pipe4Struct pipe4Data;
	pipe4Data.data40 = 4000;
	pipe4Data.data41 = 4001;
	int increment = 10;

	while (1) {
		pipe4Data.data40 = pipe4Data.data40 + increment;
		Pipe4.Write(&pipe4Data.data40);
		Sleep(2000);
		cout << "Wrote " << pipe4Data.data40 << " to Pipeline4..." << endl;
	}

	return 0;
}