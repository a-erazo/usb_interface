#define DATA_LENGTH 255

#include "SerialPort.h"
#include <iostream>
#include <stdio.h>
#include <string>

//using namespace std;

char* portName = "\\\\.\\COM15";

//Declare a global object
SerialPort *arduino;
char *sendString = "";
char variable[] = "";
char receivedString[DATA_LENGTH];

int main(void)
{
  arduino = new SerialPort(portName);
  std::cout << "is connected: " << arduino->isConnected() << std::endl;
  
  while(1){
  	  
  	
	  if (arduino->isConnected()){
	  	std::cout << "what do you want to send?"<<std::endl;
	  	std::cin >> variable;
	  	sendString = variable;
	    bool hasWritten = arduino->writeSerialPort(sendString, DATA_LENGTH);
	    
	    
	    int hasRead = arduino->readSerialPort(receivedString, DATA_LENGTH);
	    
	    if (hasRead){
	    	printf("%s", receivedString);
	    	std::cout << *receivedString <<std::endl;
		} 
	    else printf("Error occured reading data");
	  }
	}
}
