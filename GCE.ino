#include "functions.h"
#include "ArrayController.h"

#include <Adafruit_MPU6050.h>
#include <Adafruit_Sensor.h>
#include <Wire.h>



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
	Serial.print("Accelerometer range set to: ");

	switch (mpu.getAccelerometerRange()) 
	{
		case MPU6050_RANGE_2_G:
		Serial.println("+-2G");
		break;

		case MPU6050_RANGE_4_G:
		Serial.println("+-4G");
		break;

		case MPU6050_RANGE_8_G:
		Serial.println("+-8G");
		break;

		case MPU6050_RANGE_16_G:
		Serial.println("+-16G");
		break;
	}

	mpu.setGyroRange(MPU6050_RANGE_500_DEG);
	Serial.print("Gyro range set to: ");

	switch (mpu.getGyroRange())
	{
		case MPU6050_RANGE_250_DEG:
		Serial.println("+- 250 deg/s");
		break;

		case MPU6050_RANGE_500_DEG:
		Serial.println("+- 500 deg/s");
		break;

		case MPU6050_RANGE_1000_DEG:
		Serial.println("+- 1000 deg/s");
		break;

		case MPU6050_RANGE_2000_DEG:
		Serial.println("+- 2000 deg/s");
		break;
	}

	mpu.setFilterBandwidth(MPU6050_BAND_21_HZ);
	Serial.print("Filter bandwidth set to: ");

	switch (mpu.getFilterBandwidth()) 
	{
		case MPU6050_BAND_260_HZ:
		Serial.println("260 Hz");
		break;

		case MPU6050_BAND_184_HZ:
		Serial.println("184 Hz");
		break;

		case MPU6050_BAND_94_HZ:
		Serial.println("94 Hz");
		break;

		case MPU6050_BAND_44_HZ:
		Serial.println("44 Hz");
		break;

		case MPU6050_BAND_21_HZ:
		Serial.println("21 Hz");
		break;

		case MPU6050_BAND_10_HZ:
		Serial.println("10 Hz");
		break;

		case MPU6050_BAND_5_HZ:
		Serial.println("5 Hz");
		break;
	}

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
  	sensors_event_t a, g, temp;

	//Adds most recent sensor readings to the memory arrays
	memoryArray.ArrayControllerUpdate(a,g);

	
}

