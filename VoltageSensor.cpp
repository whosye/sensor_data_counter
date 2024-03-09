#include "VoltageSensor.h"

void VoltageSensor::generateData() {
	std::random_device rd;
	std::mt19937 gen(rd());
	std::uniform_int_distribution<int> dist(100, 200);
	std::uniform_int_distribution<int> dist2(-0.01, 0.02);
	int delay = dist(gen);

	float data = m_referenceVoltage;
	while (m_receiverP->receiveData) {
		data -= 0.05 + dist2(gen);
		m_receiverP->sendDataToBuffer(1, data);
		std::this_thread::sleep_for(std::chrono::milliseconds(delay));
	}
}

void VoltageSensor::printReferenceVoltage() {
	std::vector<float> voltageData= m_receiverP->getVoltageData();
	float VoltageDrop = voltageData.front() - voltageData.back();

	float partialVoltageDropSum = 0;
	for (int i = 0; i < voltageData.size() - 1; i++) {
		partialVoltageDropSum += voltageData[i] - voltageData[i + 1];
	}

	float averageVoltageDrop = partialVoltageDropSum/voltageData.size(); 

	std::cout << "Last measurement: " << voltageData.back() << " V" << std::endl;
	std::cout << "Reference voltage: " << m_referenceVoltage << " V" << std::endl;
	std::cout << "Voltage drop: " << VoltageDrop << " V" << std::endl;
	std::cout << "Average voltage drop: " << averageVoltageDrop <<" V"<< std::endl;
}


