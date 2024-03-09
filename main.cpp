#include <iostream>
#include "IMUSensor.h"
#include "Receiver.h"
#include "VoltageSensor.h"
#include "ShaftSpeedSensor.h"
#include <thread>


int main() {
    /*initialize sensors and receiver */
    Receiver receiver;
    IMUSensor imuSensor("MPU6050", &receiver);
    VoltageSensor voltageSensor("VoltageMeasurementUnit", &receiver, 12.2);
    ShaftSpeedSensor shaftSpeedSensor("shaftMeas3000", &receiver);
    receiver.initFn(); // init receiver values
    /*Start Sensors threads*/
    std::thread voltageThread(&VoltageSensor::startSendingData, &voltageSensor);
    std::thread imuThread(&IMUSensor::startSendingData, &imuSensor);
    std::thread shaftMeasThread(&ShaftSpeedSensor::startSendingData, &shaftSpeedSensor);

    int transmittingTime;
    std::cout << "Choose the transmiting time." << std::endl;
    std::cout << "1 second == 1000" << std::endl;

    while (true) {
        std::cout << "Enter an integer value for the transmitting time: ";
        if (std::cin >> transmittingTime) {
            break;
        }
        else {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "Invalid input. Please enter an integer value." << std::endl;
        }
    }


    receiver.startListeningForData(transmittingTime);// receiver starts to listen for data 
    
    /*Join the sensor threads */
    imuThread.join();
    voltageThread.join();
    shaftMeasThread.join();

    /*Results*/
    receiver.printResults(imuSensor.getName(), voltageSensor.getName(), shaftSpeedSensor.getName());
    voltageSensor.printReferenceVoltage();
    shaftSpeedSensor.printAverageShaftSpeed();
    imuSensor.printAverageAcceleration();
    return 0;
}