#pragma once
#include "SensorBase.h"
#include <numeric>
class ShaftSpeedSensor : public SensorBase {

private:
	Receiver* m_receiverP;
public:
	ShaftSpeedSensor(std::string name, Receiver* receiverP) : SensorBase(name), m_receiverP(receiverP) {};
	void generateData() override;
	void printAverageShaftSpeed();
};


