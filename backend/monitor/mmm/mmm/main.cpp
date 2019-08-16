#include<iostream>
#include<fstream>
using namespace std;
#include<string>
#include<stdlib.h>
#include"SerialPort.h"

char output[1];
char port[] = "\\\\.\\COM3";

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
	int x = 200;
	myfile << x;
	myfile.close();
	
	while (arduino.isConnected()) {
		output[0] = NULL;
		

	

		arduino.readSerialPort(output,1);
		if (output[0] == 'i' ) {
			ofstream myfile;
			myfile.open("variables.txt");
			x++;
			cout << x <<endl;
			myfile << x;
			myfile.close();
		}

		if (output[0] == 'o') {
			ofstream myfile;
			myfile.open("variables.txt");
			x=x -1;
			cout << x <<endl;
			myfile << x;
			myfile.close();
		}
		

		

	}
	return 0;
}

