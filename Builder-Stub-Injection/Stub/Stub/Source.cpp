#include <iostream>
#include <fstream>
#include <Windows.h>

using namespace std;

#define STUB_SIZE 232448

struct Settings {
	int port;
	char ip[32];
};

int main() {
	Settings data;
	char filename[256];
	GetModuleFileNameA(NULL, filename, 256);
	ifstream file(filename, ios::binary);
	file.seekg(STUB_SIZE);
	file.read((char*)&data, sizeof(Settings));
	file.close();
	cout << data.ip << endl;
	cout << data.port << endl;
	system("pause");
	return 0;
}