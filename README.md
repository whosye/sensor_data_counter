# To run this projects, 
Compile and execute the main.cpp file.
Input the desired simulation time when prompted.

Overview: 
This project simulates the asynchronous transmission of data from multiple sensors to a central receiver using C++.
The system consists of three sensor types: IMU (Inertial Measurement Unit), Voltage, and Shaft Speed sensors. Each sensor operates in its own thread, generating simulated data with random delays and sending it to the receiver.

Sensor Classes:
IMU Sensor: Simulates data from an Inertial Measurement Unit. It generates acceleration data with random variations and sends it to the receiver buffer.
Voltage Sensor: Simulates voltage measurements. It generates voltage data with random fluctuations and sends it to the receiver buffer.
Shaft Speed Sensor: Simulates shaft speed measurements. It generates speed data with random fluctuations and sends it to the receiver buffer.
  
Receiver class 
The Receiver class acts as a central hub for receiving and processing data from the sensors.
It periodically checks the sensor buffers for incoming data and stores it. Once the simulation time elapses, the Receiver stops listening for new data and prints the results to the console.

Project Features:
Asynchronous Data Transmission: Each sensor operates independently, asynchronously sending data to the receiver. This allows for efficient parallel processing of sensor data.
Randomized Data Generation: Sensor data is simulated with random variations to mimic real-world conditions.
Flexible Simulation Time: The user can specify the duration of the simulation, allowing for testing under different time constraints

