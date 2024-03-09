#pragma once
#include "SensorBase.h"

class VoltageSensor : public SensorBase {

private:
	Receiver* m_receiverP;
	float m_referenceVoltage;
public:
	VoltageSensor(std::string name, Receiver* receiverP, float referenceVoltage) : SensorBase(name), m_receiverP(receiverP),
		m_referenceVoltage(referenceVoltage) {};
	void generateData() override;
	void printReferenceVoltage();
};