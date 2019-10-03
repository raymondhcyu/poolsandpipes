# include "..\rt.h"
#include <string>
#include <iostream>

using namespace std;

struct myDatapoolData {
	float pi;
	int EIS;
	bool fixedWing;
};

int main() {
	// Create datapool
	cout << "Parent creating datapool..." << endl;
	CDataPool dp("A320", sizeof(struct myDatapoolData));

	// Link datapool
	struct myDatapoolData* myDatapool = (struct myDatapoolData*)(dp.LinkDataPool());
	cout << "Parent datapool linked at address " << myDatapool << endl;

	// Write variables
	myDatapool->pi = 3.1415;
	myDatapool->EIS = 1980;
	myDatapool->fixedWing = true;

	getchar();

	// Create child processes to access data
	CProcess p1("D:\\Documents\\CPEN333\\CPEN333Lab4\\Debug\\DataPoolChild.exe",	// pathlist to child program executable
		NORMAL_PRIORITY_CLASS,			// priority
		OWN_WINDOW,						// process has its own window
		ACTIVE							// process is active immediately
	);

	CProcess p2("D:\\Documents\\CPEN333\\CPEN333Lab4\\Debug\\DataPoolChild2.exe",	// pathlist to child program executable
		NORMAL_PRIORITY_CLASS,			// priority
		OWN_WINDOW,						// process has its own window
		ACTIVE							// process is active immediately
	);

	p1.WaitForProcess();
	p2.WaitForProcess();
	cout << "Parent complete..." << endl;
	return 0;
}