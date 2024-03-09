#pragma once
#include <iostream>
#include <vector>
#include <variant>
#include <chrono>

class Receiver
{

private:

	std::vector<float> dataIMU;
	std::vector<float> dataVoltage;
	std::vector<float> dataShaftSpeed;

	std::vector<float> bufferIMU;
	std::vector<float> bufferVoltage;
	std::vector<float> bufferShaftSpeed;



public:
	bool receiveData;
	/*Init variables*/
	void initFn();

	/*Handling data*/
	void sendDataToBuffer(int key,float data);
	void handleIncomingData(unsigned long simulationTime);
	void handleBuffer(std::vector<float>& buffer, std::vector<float>& dataStorage);
	void startListeningForData(unsigned int simulationTime);

	/*Printing Results*/
	void printResults(std::string sensorName1, std::string sensorName2, std::string sensorName3);

	/*Accesors*/
	std::vector<float> getVoltageData();
	std::vector<float> getIMUData();
	std::vector<float> getShafSpeedData();
	
};

