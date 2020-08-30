
#include <Adafruit_MPU6050.h>
#include <Adafruit_Sensor.h>
#include <Wire.h>
#include "MemoryFree.h"
#include "ArrayController.h"
//#include "Functions.h"
Adafruit_MPU6050 mpu;
ArrayController memoryArray;
int counter  = 0;
void setup() 
{
	// put your setup code here, to run once:

	/////////////////////////////////////////////
	//
	//	MPU6050 initialisation code, sets the ranges and frequences for the sensors and prints debug info to console.
	//
	/////////////////////////////////////////////


	Serial.begin(9600);
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



  sensors_event_t a;
  sensors_event_t g;
	//Creates Memory array object

	//Initializes the memory array based on the sample frequency of the gyro chip
	memoryArray.ArrayControllerInit();
	int counter = 0;
}




void loop() 
{
  // put your main code here, to run repeatedly:

 	 /* Get new sensor events with the readings */
  	sensors_event_t a, g, t;
 	mpu.getEvent(&a, &g, &t);

	//Adds most recent sensor readings to the memory arrays
	memoryArray.ArrayControllerUpdate(a,g);
	delay(2);

	if(Serial.available()> 0)
	{
 		char data = Serial.read();
 		Serial.println(data);
	}
	delay(50);

	
	if (counter > 24)
	{

		float* pArray = memoryArray.GetAccelMemoryY();
		

		//int * pShots = ConvertToShot(pArray);

		

		for(int i = 0; i < 24; i++)
		{
			Serial.println("Y: ");
			Serial.println(pArray[i]);

		}
		delete[] pArray;


		counter = 0;
	}
	
	counter++;

	/*
	if (ShotDetector() == true)
	{

		float* pArray = memoryArray.GetAccelMemoryY();
		
		CorrectOrientation(pArray);

		int * pShots = ConvertToShot(pArray);

		delete[] pArray;
	}
	*/



	
	
}
