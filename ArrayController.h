#pragma once
#include <vector>

class ArrayController
{

public:

	void ArrayControllerInit(Adafruit_MPU6050& mpu);

	void ArrayControllerUpdate(sensors_event_t a, g);

	std::vector<int> GetGyroMemoryX();
	std::vector<int> GetGyroMemoryY();
	std::vector<int> GetGyroMemoryZ();

	std::vector<int> GetAccelMemoryX();
	std::vector<int> GetAccelMemoryY();
	std::vector<int> GetAccelMemoryZ();





private:

		std::vector<int> GyroMemoryX;
		std::vector<int> GyroMemoryY;
		std::vector<int> GyroMemoryZ;

		std::vector<int> AccelMemoryX;
		std::vector<int> AccelMemoryY;
		std::vector<int> AccelMemoryZ;

		int GyroMemoryDivider = 0;
		int AccelMemoryDivider = 0;


};