#include <fstream>
#include <Windows.h>
#include <iostream>

using namespace std;

#define STUB_NAME "Stub.exe"

struct Settings {
	int port;
	char ip[32];
	char built[32];
};

int main() {
	Settings data;
	cout << endl << "Ip: ";
	cin >> data.ip;
	cout << endl << "Port: ";
	cin >> data.port;
	cout << endl << "Built name: ";
	cin >> data.built;
	ifstream stub(STUB_NAME, ios::binary);
	ofstream built(data.built, ios::binary);
	built << stub.rdbuf();
	stub.close();
	built.write((char*)&data, sizeof(Settings));
	built.close();
	return 0;
}