#pragma once
#include <Adafruit_MPU6050.h>
#include <Adafruit_Sensor.h>

class ArrayController
{

private: 
	static const int arraysize = 25;
public:

	void ArrayControllerInit();

	void ArrayControllerUpdate(sensors_event_t a,sensors_event_t g);

	float* GetGyroMemoryX();
	float* GetGyroMemoryY();
	float* GetGyroMemoryZ();

	float* GetAccelMemoryX();
	float* GetAccelMemoryY();
	float* GetAccelMemoryZ();

	float* getArray(float* array);




private:


		float GyroMemoryX[arraysize];
		float GyroMemoryY[arraysize];
		float GyroMemoryZ[arraysize];

		float AccelMemoryX[arraysize];
		float AccelMemoryY[arraysize];
		float AccelMemoryZ[arraysize];

		int MemoryDivider = 0;



};
