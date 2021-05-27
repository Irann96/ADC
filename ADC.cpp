#include<iostream>
#include<fstream>
#include<string>
#include<sstream>
#include<cmath>
#include<unistd.h>
#include<stdio.h>
#include<stdlib.h>
using namespace std;

#define LDR_PATH "/sys/bus/ioo/devices/ioo:device0/in_voltage"

int readAnalog(int number){
	
	stringstream ss;
	ss << LDR_PATH << number << "_raw";
	fstream fs;
	fs.open(ss.str().c_str(), fstream::in);
	fs >> number;
	fs.close();
	return number;
}

int main(int argc, char* argv[]){
	cout << "Valor de voltaje en el ADC: " << endl;
		for (int i=0; i<1000; i++){
		int value = readAnalog(0);
		cout << "  = " << readAnalog(0) << "/4095   " << '\r' << flush;
		usleep(50000); 
	}
	return 0;
}



