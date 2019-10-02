#include "..\rt.h"
#include <string>
#include <iostream>

using namespace std;

// Same struct as parent
struct myDatapoolData {
	char name[99] = "Airbus A320";
	int EIS;
	bool fixedWing;
};

int main(void) {
	cout << "Child process creating/using datapool..." << endl;
	CDataPool dp("A320", sizeof(struct myDatapoolData));

	struct myDatapoolData* myDatapool = (struct myDatapoolData*)(dp.LinkDataPool());
	cout << "Child datapool linked at address " << myDatapool << endl;

	// Show that child access datapool which parent wrote to
	cout << "Name: " << myDatapool->name[0] << endl;
	cout << "Entry into service: " << myDatapool->EIS << endl;
	cout << "Is it a fixed-wing? " << myDatapool->fixedWing << endl;

	cout << "Child process complete..." << endl;
	getchar();
	return 0;
}