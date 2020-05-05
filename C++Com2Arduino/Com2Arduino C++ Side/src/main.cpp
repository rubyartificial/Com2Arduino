#include <stdio.h>
#include <string.h>
#include <iostream>
#include <windows.h>
#include "SerialPort.h"
#include <istream>
using namespace std;

#define MAX_DATA_LENGTH 255
char* portInput;
char* Port;
char* portName;
string fart;



char incomingData[MAX_DATA_LENGTH];

//Control signals for turning on and turning off the led
//Check arduino code
char ledON[] = " " ;
char ledOFF[] = " ";
char status[] =" ";
char exitStatus[] =" ";
//Arduino SerialPort object
SerialPort *arduino;

//Blinking Delay
const unsigned int BLINKING_DELAY = 1000;

//If you want to send data then define "SEND" else comment it out
#define SEND

void exampleReceiveData(void)
{

    int readResult = arduino->readSerialPort(incomingData, MAX_DATA_LENGTH);
    printf("%s", incomingData);
    Sleep(10);
}

void exampleWriteData(unsigned int delayTime)
{
    cout<<("Enter Command:");
    cin>> status;
    if (exitStatus != status)

{
    arduino->writeSerialPort(status, MAX_DATA_LENGTH);
    Sleep(delayTime);
}
else
{
}
}

void autoConnect(void)
{

    //better than recusion
    //avoid stack overflows
    while(1) {
        // ui - searching
        std::cout << "";

        // wait connection
        while (!arduino->isConnected()) {
            Sleep(100);
            arduino = new SerialPort(portName);
        }

        //Checking if arduino is connected or not
        if (arduino->isConnected()) {
            std::cout  << std::endl << "Connection established at port " << portName << std::endl;
        }

        #ifdef SEND
            while(arduino->isConnected()) exampleWriteData(BLINKING_DELAY);
        #else // SEND
            while(arduino->isConnected()) exampleReceiveData();
        #endif // SEND
    }
}

int main()
{

cout<< "Please specify port number: \n";
//convert string to Char
string str;
cout <<("Logging in on port %s", str);
cin>>str;
char *cstr = new char[str.length() + 1];
strcpy(cstr, str.c_str());
//end convert string to char, casted to cster
cout <<"Logging in to ";
cout <<str;
portName = ("\\\\.\\%c", cstr);
    arduino = new SerialPort(portName);
    autoConnect();
}

