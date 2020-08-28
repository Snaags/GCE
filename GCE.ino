
#include <Adafruit_MPU6050.h>
#include <Adafruit_Sensor.h>
#include <Wire.h>
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



  sensors_event_t a;
  sensors_event_t g;
	//Creates Memory array object

	//Initializes the memory array based on the sample frequency of the gyro chip
	memoryArray.ArrayControllerInit();

}




void loop() 
{
  // put your main code here, to run repeatedly:

 	 /* Get new sensor events with the readings */
  	sensors_event_t a, g, t;
 	mpu.getEvent(&a, &g, &t);

	//Adds most recent sensor readings to the memory arrays
	memoryArray.ArrayControllerUpdate(a,g);
	delay(10);

	if (ShotDetector() == true)
	{

		float* pArray = memoryArray.GetAccelMemoryY();
		
		CorrectOrientation(pArray);

		int * pShots = ConvertToShot(pArray);

		delete[] pArray;
	}



	
	
}
