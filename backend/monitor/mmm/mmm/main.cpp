#include<iostream>
#include<fstream>
using namespace std;
#include<string.h>
#include<stdlib.h>
#include <time.h> 
#include"SerialPort.h"

char output[1];
char port[] = "\\\\.\\COM3";
clock_t i1,o1,i2,o2 = clock();
int gauge1 =0,gauge2=0,gauge3=0,gauge4=0,niv1 = 25,niv2 = 25,niv3 = 25,niv4 = 25,niv5 = 25,SN = 55,timeout=10;
bool incar1,outcar1,incar2,outcar2;

void exportarvariables(int niv1,int niv2,int niv3,int niv4) {
	ofstream CNnivel1, CNnivel2, CNnivel3, CNnivel4, CNtotal,WCNtotal, SNtotal,WSNtotal, ingauge1,ingauge2,outgauge1,outgauge2;
	CNnivel1.open("CNnivel1.txt");
	CNnivel2.open("CNnivel2.txt");
	CNnivel3.open("CNnivel3.txt");
	CNnivel4.open("CNnivel4.txt");
	CNtotal.open("CNtotal.txt");
	WCNtotal.open("WCNtotal.txt");
	WSNtotal.open("WSNtotal.txt");
	SNtotal.open("SNtotal.txt");
	ingauge1.open("ingauge1.txt");
	ingauge2.open("ingauge2.txt");
	outgauge1.open("outgauge1.txt");
	outgauge2.open("outgauge2.txt");
	CNnivel1 << niv1;
	CNnivel2 << niv2;
	CNnivel3 << niv3;
	CNnivel4 << niv4;
	CNtotal << (niv1 + niv2 + niv3 + niv4);
	WCNtotal << (niv1 + niv2 + niv3 + niv4);
	SNtotal << SN;
	WSNtotal << SN;
	ingauge1 << gauge1;
	outgauge1 << gauge2;
	ingauge2 << gauge3;
	outgauge2 << gauge4;
	cout << gauge1 << " " << gauge2<< " " << gauge3 << " " <<gauge4<< endl;
	CNnivel1.close();
	CNnivel2.close();
	CNnivel3.close();
	CNnivel4.close();
	CNtotal.close();
	WCNtotal.close();
	WSNtotal.close();
	SNtotal.close();
	ingauge1.close();
	outgauge1.close();
	ingauge2.close();
	outgauge2.close();

}


int main() {

	SerialPort arduino(port);
	if (arduino.isConnected()) {
		cout << "Connection made" << endl << endl;
	}
	else {
		cout << "Error in port name" << endl << endl;
	}

	exportarvariables(niv1,niv2,niv3,niv4);

	
	while (arduino.isConnected()) {
		arduino.readSerialPort(output, 1);
		incar1 = false, outcar1 = false, incar2 = false, outcar2 = false;
		if (output[0] == 'a' && niv1 >0) { // entrar primer piso
			niv1 = niv1-1;
			
			
			if (gauge1 < 100) {
				gauge1= gauge1 + 10;
				incar1 = true;
				i1 = clock();
			}
			exportarvariables(niv1, niv2, niv3, niv4);
		}
		if (output[0] == 'c' && niv2>0) { // entrar segundo piso
			niv1++;
			niv2 = niv2 - 1;
			exportarvariables(niv1, niv2, niv3, niv4);
		}
		if (output[0] == 'e' && niv3 > 0) { // entrar tercer piso
			niv2++;
			niv3 = niv3 - 1;
			exportarvariables(niv1, niv2, niv3, niv4);
		}
		if (output[0] == 'g' && niv4 > 0) { // entrar cuarto piso
			niv3++;
			niv4 = niv4 - 1;
			exportarvariables(niv1, niv2, niv3, niv4);
		}


		if (output[0] == 'b' && niv1 <=25) { // salir primer piso
			niv1++;
			if (gauge2 < 100) {
				gauge2 = gauge2 + 10;
				outcar1 = true;
				o1 = clock();
			}
			exportarvariables(niv1, niv2, niv3, niv4);
		}
		if (output[0] == 'd' && niv2 <= 25) { // salir segundo piso
			niv1 = niv1 -1;
			niv2++;
			exportarvariables(niv1, niv2, niv3, niv4);
		}
		if (output[0] == 'f' && niv3 <= 25) { // salir tercer piso
			niv3++;
			niv2 = niv2 - 1;
			exportarvariables(niv1, niv2, niv3, niv4);
		}
		if (output[0] == 'h' && niv4 <= 25) { // salir cuarto piso
			niv4++;
			niv3 = niv3 - 1;
			exportarvariables(niv1, niv2, niv3, niv4);
		}

		if (output[0] == 'i') {
			SN = SN - 1; // entrar SN
			if (gauge3 < 100) {
				gauge3 = gauge3 + 10;
				incar2 = true;
				i2 = clock();
			}
			exportarvariables(niv1, niv2, niv3, niv4);
		}
		if (output[0] == 'j') { // SALIR SN
			SN++;
			if (gauge4 < 100) {
				gauge4 = gauge4 + 10;
				outcar2 = true;
				o2 = clock();
			}
			exportarvariables(niv1, niv2, niv3, niv4);
		}

		if (((clock() - i1) / CLOCKS_PER_SEC) >= timeout) {
			
			if (!incar1 && gauge1 >0) {
				gauge1 = gauge1 - 10;
				exportarvariables(niv1, niv2, niv3, niv4);
			}
			
			i1 = clock();
		}

		if (((clock() - o1) / CLOCKS_PER_SEC) >= timeout) {
			if (!outcar1 && gauge2 > 0) {
				gauge2 = gauge2 - 10;
				exportarvariables(niv1, niv2, niv3, niv4);
			}
			o1 = clock();
		}

		if (((clock() - i2) / CLOCKS_PER_SEC) >= timeout) {
			if (!incar2 && gauge3 > 0) {
				gauge3 = gauge3 - 10;
				exportarvariables(niv1, niv2, niv3, niv4);
			}
			i2 = clock();
		}


		if (((clock() - o2) / CLOCKS_PER_SEC) >= timeout) {
			if (!outcar2 && gauge4 > 0) {
				gauge4 = gauge4 - 10;
				exportarvariables(niv1, niv2, niv3, niv4);
			}
			o2 = clock();
		}

		
		output[0] = 0;
	}

	
	return 0;
}



