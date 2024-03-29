#include "..\rt.h"
#include <string>
#include <iostream>

using namespace std;

// Same struct as parent
struct myDatapoolData {
	float pi;
	int EIS;
	bool fixedWing;
};

int main(void) {
	cout << "Child process 2 creating/using datapool..." << endl;
	CDataPool dp("A320", sizeof(struct myDatapoolData));

	struct myDatapoolData* myDatapool = (struct myDatapoolData*)(dp.LinkDataPool());
	cout << "Child datapool 2 linked at address " << myDatapool << endl;

	// Show that child access datapool which parent wrote to
	cout << "Name: " << myDatapool->pi << endl;
	cout << "Entry into service: " << myDatapool->EIS << endl;
	cout << "Is it a fixed-wing? " << myDatapool->fixedWing << endl;

	cout << "Child process 2 complete..." << endl;
	getchar();
	return 0;
}