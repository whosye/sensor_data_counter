#include "ShaftSpeedSensor.h"
void ShaftSpeedSensor::generateData() {
	std::random_device rd;
	std::mt19937 gen(rd());
	std::uniform_int_distribution<int> dist(50, 100);
	std::uniform_int_distribution<int> dist2(-0.5, 1);
	int delay = dist(gen);


	float data = 0; 
	while (m_receiverP->receiveData) {
		data += dist2(gen) + 10;
		m_receiverP->sendDataToBuffer(2, data);
		std::this_thread::sleep_for(std::chrono::milliseconds(delay));

	}
}

void ShaftSpeedSensor::printAverageShaftSpeed() {
	std::vector<float> shaftSpeedData = m_receiverP->getShafSpeedData();

	auto sum = std::accumulate(shaftSpeedData.begin(), shaftSpeedData.end(), 0);
	float average = sum / shaftSpeedData.size();
	auto maxElement = std::max_element(shaftSpeedData.begin(), shaftSpeedData.end());

	std::cout << "Average shaft speed: " << average<< " rpm" << std::endl;
	std::cout << "Max shaft speed: " << *maxElement <<" rpm" << std::endl;

}