#include "Receiver.h"

	void Receiver::startListeningForData(unsigned int simulationTime) {
		handleIncomingData(simulationTime);
	}
	void Receiver::initFn() {

		receiveData = true;
		bufferIMU.clear();
		bufferVoltage.clear();
		bufferShaftSpeed.clear();
	}
	void Receiver::handleBuffer(std::vector<float>& buffer, std::vector<float>& dataStorage) {
		dataStorage.push_back(buffer[0]);
		buffer.clear();
	}
	void Receiver::handleIncomingData(unsigned long simulationTime) {
		std::cout << "Waiting for data .." << std::endl;
		auto startTime = std::chrono::steady_clock::now();
		while (true) {
			auto iterationStartTime = std::chrono::steady_clock::now();
			if (!bufferIMU.empty()) {
				handleBuffer(bufferIMU, dataIMU);
			
			};
			if (!bufferVoltage.empty()) {
				handleBuffer(bufferVoltage, dataVoltage);
			};
			if (!bufferShaftSpeed.empty()) {
				handleBuffer(bufferShaftSpeed, dataShaftSpeed);
			};


			auto endTime = std::chrono::steady_clock::now(); // Record end time
			auto elapsedTime = std::chrono::duration_cast<std::chrono::milliseconds>(endTime - startTime);


			if (elapsedTime.count() >= simulationTime) {
				std::cout << "exit" << std::endl;
				receiveData = false;
				return;
			}

		}
	}
void Receiver::sendDataToBuffer(int key, float data) {
	switch (key) {
		case 0:
			if (bufferIMU.empty()) {
					bufferIMU.push_back(data);
					break;
			}
			else {
				break;
			}
		case 1:
				if (bufferVoltage.empty()) {
					bufferVoltage.push_back(data);
					break;
				}
				else {
					break;
				}
		case 2:
				if (bufferShaftSpeed.empty()) {
					bufferShaftSpeed.push_back(data);
					break;
				}
				else {
					break;
				}
		default:
			break;
	}
}

void Receiver::printResults(std::string sensorName1, std::string sensorName2, std::string sensorName3) {
	if (receiveData == false) {
		std::cout << "Number of messages from " << sensorName1 <<"sensor:  " << dataIMU.size()	     <<std::endl;
		std::cout << "Number of messages from " << sensorName2 <<"sensor:  " << dataVoltage.size()	 <<std::endl;
		std::cout << "Number of messages from " << sensorName3 <<"sensor:  " << dataShaftSpeed.size()  <<std::endl;
	}
	else {
		std::cout << "Error, transmiting not over yet" << std::endl;
	}
}

std::vector<float> Receiver::getVoltageData() {
	return dataVoltage; 
}
std::vector<float> Receiver::getIMUData() {
	return dataIMU;
}
std::vector<float> Receiver::getShafSpeedData() {
	return dataShaftSpeed;
}


