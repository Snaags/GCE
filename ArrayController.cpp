#include "ArrayController.h" 

	void ArrayController::ArrayControllerInit()
	{



		//Define size and allocate array (Currently allocating for 1 second);

		for (int i = 0 ; i < arraysize; i++)
		{

			GyroMemoryZ [i] = 0 ;
			GyroMemoryY [i] = 0 ;
			GyroMemoryX [i] = 0 ;

			AccelMemoryX [i] = 0 ;
			AccelMemoryY [i] = 0 ;
			AccelMemoryZ [i] = 0 ;

		}

	}


	void ArrayController::ArrayControllerUpdate(sensors_event_t a,sensors_event_t g)
	{
		//Take readings from mpu for all 6 DoF at each timestep

				//Gyro

		GyroMemoryX[MemoryDivider] = g.gyro.x;
		GyroMemoryY[MemoryDivider] = g.gyro.y;
		GyroMemoryZ[MemoryDivider] = g.gyro.z;


				//Accelerometer

		AccelMemoryX[MemoryDivider] = a.acceleration.x;
		AccelMemoryY[MemoryDivider] = a.acceleration.y;
		AccelMemoryZ[MemoryDivider] = a.acceleration.z;



		MemoryDivider++;


		//Loops the divider back to start of array when it reaches the end;
		if(MemoryDivider > arraysize)
		{
			MemoryDivider = 0;	
		}

		if(MemoryDivider > arraysize)
		{
			MemoryDivider = 0;	
		}
		

	}



	//Getters for the memory, disgusting block of code but oh well, probably should be reworked to remove duplication

	float* ArrayController::getArray(float* array)
	{

		//Dynamic memory allocation!!! Remember to deallocate!!!///////////////////////////////////////
		float * v = new float[arraysize];
		
		int counter = 0;

		for(int i = MemoryDivider; i < arraysize;i++)
		{
			v[counter] = array[i];
			counter++;

		}


		for(int i = 0; i < MemoryDivider; i++)
		{
			v[counter] = array[i];
			counter++;

		}

		return v;
	}


	float* ArrayController::GetGyroMemoryX()
	{
		return getArray(GyroMemoryX);
	}

	float* ArrayController::GetGyroMemoryY()
	{
		return getArray(GyroMemoryY);
	}

	float* ArrayController::GetGyroMemoryZ()
	{
		return getArray(GyroMemoryZ);
	}

	float* ArrayController::GetAccelMemoryX()
	{
		return getArray(AccelMemoryX);
	}

	float* ArrayController::GetAccelMemoryY()
	{
		return getArray(AccelMemoryY);		
	}

	float* ArrayController::GetAccelMemoryZ()
	{
		return getArray(AccelMemoryZ);	
	}

