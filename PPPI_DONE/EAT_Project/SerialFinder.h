#ifndef SERIALFINDER_H_INCLUDED
#define SERIALFINDER_H_INCLUDED

#define ARDUINO_WAIT_TIME 2000

#include <windows.h>
#include <stdio.h>
#include <stdlib.h>

class Serial
{
private:
    DWORD errors;
	bool NotConnected;

public:
    Serial(char *portName);
    ~Serial();
    int ReadData(char *buffer, unsigned int nbChar);
    bool WriteData(char *buffer, unsigned int nbChar);
    


};

#endif
