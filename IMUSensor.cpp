#include "IMUSensor.h"
#include <numeric>
void IMUSensor::generateData() {
	std::random_device rd;
	std::mt19937 gen(rd()); 
	std::uniform_int_distribution<int> dist(50, 100);
	std::uniform_int_distribution<int> dist2(-0.1,0.1);
	int delay = dist(gen);

	float data = 0;
	while (m_receiverP->receiveData) {
		data += 2 + dist2(gen);
		m_receiverP->sendDataToBuffer(0,data);
		std::this_thread::sleep_for(std::chrono::milliseconds(delay));
	}
}
void IMUSensor::printAverageAcceleration() {
	std::vector<float> dataIMU = m_receiverP->getIMUData();
	auto sum = std::accumulate(dataIMU.begin(), dataIMU.end(), 0);
	float average = sum / dataIMU.size();
	auto maxElement = std::max_element(dataIMU.begin(), dataIMU.end());

	std::cout << "Average acceleration: " << average << " m/s^2" << std::endl;
	std::cout << "Max acceleration: " << *maxElement << " m/s^2" << std::endl;
}