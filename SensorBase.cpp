#include "SensorBase.h"

std::string SensorBase::getName() {
	return m_name;

}
void SensorBase::generateData() {
}

void SensorBase::startSendingData() {
	generateData();
}