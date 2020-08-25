#include "functions.h"
#include "ArrayController.h"
#include <Adafruit_MPU6050.h>
#include <Adafruit_Sensor.h>
#include <Wire.h>
#include <vector>

void Plotter(std::vector<int> array)
{
	for(int i = 0; i < array.size();i++)
	{
		Serial.println(array[i])
	}

}

void setup() 
{
	// put your setup code here, to run once:
	
	Adafruit_MPU6050 mpu;



	/////////////////////////////////////////////
	//
	//	MPU6050 initialisation code, sets the ranges and frequences for the sensors and prints debug info to console.
	//
	/////////////////////////////////////////////


	Serial.begin(115200);
	while (!Serial)
		delay(10); // will pause Zero, Leonardo, etc until serial console opens

	Serial.println("Adafruit MPU6050 test!");

	// Try to initialize!
	if (!mpu.begin())
	{
		Serial.println("Failed to find MPU6050 chip");

		while (1) 
		{
			delay(10);
		}
	}

	Serial.println("MPU6050 Found!");


	//Setting up Ranges for sensors

	mpu.setAccelerometerRange(MPU6050_RANGE_8_G);

	mpu.setGyroRange(MPU6050_RANGE_500_DEG);

	mpu.setFilterBandwidth(MPU6050_BAND_21_HZ);


  	Serial.println("");
  	delay(100);

  	///////////////////////////////////////////////////////////////////////////////////




	//Creates Memory array object
	ArrayController memoryArray;
	//Initializes the memory array based on the sample frequency of the gyro chip
	memoryArray.ArrayControllerInit(mpu);

}




void loop() 
{
  // put your main code here, to run repeatedly:


 	 /* Get new sensor events with the readings */
  	sensors_event_t a, g;
 	mpu.getEvent(&a, &g);

	//Adds most recent sensor readings to the memory arrays
	memoryArray.ArrayControllerUpdate(a,g);


	
	
}


