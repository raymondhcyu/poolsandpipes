#include "..\rt.h"

void PartBPolling();
void PartBThreads();

int pipe1Data, pipe2Data, pipe3Data, pipe4Data; // int is 4 bytes in C++

struct Pipe1Struct {
	int data10;
	int data11;
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

UINT __stdcall Thread1(void* args) {
	CTypedPipe <int> Pipe1("Pipeline1", 100);
	while (1) {
		if (Pipe1.TestForData() >= sizeof(pipe1Data) / 2) {
			Pipe1.Read(&pipe1Data);
			cout << "Parent read " << pipe1Data << " from Pipeline 1..." << endl;
		}
	}
	return 0;
}

UINT __stdcall Thread2(void* args) {
	CTypedPipe <int> Pipe2("Pipeline2", 100);

	while (1) {
		if (Pipe2.TestForData() >= sizeof(pipe2Data) / 2) {
			Pipe2.Read(&pipe2Data);
			cout << "Parent read " << pipe2Data << " from Pipeline 2..." << endl;
		}
	}
	return 0;
}

UINT __stdcall Thread3(void* args) {
	CTypedPipe <int> Pipe3("Pipeline3", 100);

	while (1) {
		if (Pipe3.TestForData() >= sizeof(pipe3Data) / 2) {
			Pipe3.Read(&pipe3Data);
			cout << "Parent read " << pipe3Data << " from Pipeline 3..." << endl;
		}
	}
	return 0;
}

UINT __stdcall Thread4(void* args) {
	CTypedPipe <int> Pipe4("Pipeline4", 100);

	while (1) {
		if (Pipe4.TestForData() >= sizeof(pipe4Data) / 2) {
			Pipe4.Read(&pipe4Data);
			cout << "Parent read " << pipe4Data << " from Pipeline 4..." << endl;
		}
	}
	return 0;
}

int main(void) {

	/* PART B POLLING*/
	PartBPolling();

	/* PART B THREADS*/
	//PartBThreads();

	return 0;
}

void PartBPolling() {
	cout << "Starting parent process using polling..." << endl;

	CTypedPipe <int> Pipe1("Pipeline1", 100);
	CTypedPipe <int> Pipe2("Pipeline2", 100);
	CTypedPipe <int> Pipe3("Pipeline3", 100);
	CTypedPipe <int> Pipe4("Pipeline4", 100);

	CProcess p1("D:\\Documents\\CPEN333\\CPEN333Lab4\\Debug\\PartBChild1.exe",
		NORMAL_PRIORITY_CLASS,
		OWN_WINDOW,
		ACTIVE
	);

	CProcess p2("D:\\Documents\\CPEN333\\CPEN333Lab4\\Debug\\PartBChild2.exe",
		NORMAL_PRIORITY_CLASS,
		OWN_WINDOW,
		ACTIVE
	);

	CProcess p3("D:\\Documents\\CPEN333\\CPEN333Lab4\\Debug\\PartBChild3.exe",
		NORMAL_PRIORITY_CLASS,
		OWN_WINDOW,
		ACTIVE
	);

	CProcess p4("D:\\Documents\\CPEN333\\CPEN333Lab4\\Debug\\PartBChild4.exe",
		NORMAL_PRIORITY_CLASS,
		OWN_WINDOW,
		ACTIVE
	);

	while (1) {
		if (Pipe1.TestForData() >= sizeof(pipe1Data) / 2) {
			Pipe1.Read(&pipe1Data);
			cout << "Parent read " << pipe1Data << " from Pipeline 1..." << endl;
		}
		if (Pipe2.TestForData() >= sizeof(pipe2Data) / 2) {
			Pipe2.Read(&pipe2Data);
			cout << "Parent read " << pipe2Data << " from Pipeline 2..." << endl;
		}
		if (Pipe3.TestForData() >= sizeof(pipe3Data) / 2) {
			Pipe3.Read(&pipe3Data);
			cout << "Parent read " << pipe3Data << " from Pipeline 3..." << endl;
		}
		if (Pipe4.TestForData() >= sizeof(pipe4Data) / 2) {
			Pipe4.Read(&pipe4Data);
			cout << "Parent read " << pipe4Data << " from Pipeline 4..." << endl;
		}
	}

	p1.WaitForProcess();
	p2.WaitForProcess();
	p3.WaitForProcess();
	p4.WaitForProcess();
}

void PartBThreads() {
	cout << "Starting parent process using threads..." << endl;

	CThread t1(Thread1, ACTIVE, NULL);
	CThread t2(Thread2, ACTIVE, NULL);
	CThread t3(Thread3, ACTIVE, NULL);
	CThread t4(Thread4, ACTIVE, NULL);

	CProcess p1("D:\\Documents\\CPEN333\\CPEN333Lab4\\Debug\\PartBChild1.exe",
		NORMAL_PRIORITY_CLASS,
		OWN_WINDOW,
		ACTIVE
	);
	CProcess p2("D:\\Documents\\CPEN333\\CPEN333Lab4\\Debug\\PartBChild2.exe",
		NORMAL_PRIORITY_CLASS,
		OWN_WINDOW,
		ACTIVE
	);
	CProcess p3("D:\\Documents\\CPEN333\\CPEN333Lab4\\Debug\\PartBChild3.exe",
		NORMAL_PRIORITY_CLASS,
		OWN_WINDOW,
		ACTIVE
	);
	CProcess p4("D:\\Documents\\CPEN333\\CPEN333Lab4\\Debug\\PartBChild4.exe",
		NORMAL_PRIORITY_CLASS,
		OWN_WINDOW,
		ACTIVE
	);

	t1.WaitForThread();
	t2.WaitForThread();
	t3.WaitForThread();
	t4.WaitForThread();

	p1.WaitForProcess();
	p2.WaitForProcess();
	p3.WaitForProcess();
	p4.WaitForProcess();
}