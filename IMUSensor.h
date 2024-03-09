#pragma once
#include "SensorBase.h"


class IMUSensor : public SensorBase{

private:
	Receiver* m_receiverP; 
public:
	IMUSensor(std::string name, Receiver* receiverP) : SensorBase(name), m_receiverP(receiverP) {};
	void generateData() override;
	void printAverageAcceleration();
};

