#include<iostream>
#include<fstream>
using namespace std;
#include<string>
#include<stdlib.h>
#include"SerialPort.h"

char output[1];
char port[] = "\\\\.\\COM3";
int x;

int main() {
	SerialPort arduino(port);
	if (arduino.isConnected()) {
		cout << "Connection made" << endl << endl;
	}
	else {
		cout << "Error in port name" << endl << endl;
	}

	ofstream myfile;
	myfile.open("variables.txt");
	if (myfile.is_open()) {
		myfile << "12341234" ;
	}


	while (arduino.isConnected()) {
		output[0] = NULL;

		arduino.readSerialPort(output,1);
		if (output[0] == 'y') {
			x++;
			cout << x;
		}
		
	}
	return 0;
}

