#pragma once

#include <iostream>
#include <vector>
#include <stdlib.h>
#include "Receiver.h"
#include <thread>
#include <random>


using namespace std::chrono_literals;
class SensorBase
{
private:
	std::string m_name;
public:
	SensorBase(std::string name) : m_name(name) {};
	std::string getName();
	void virtual generateData();
	void startSendingData();

};


