#include "ArrayController.h" 

	void ArrayControllerInit(Adafruit_MPU6050& mpu )
	{
		//calculate the sample frequency
		int sampleFrequency = (mpu.getCycleRate / mpu.getSampleRateDivisor);
		int sampleRate = 1/sampleFrequency * 1000 // in miliseconds


		//Define size and allocate array (Currently allocating for 1 second);

		GyroMemoryZ.resize(sampleFrequency);
		GyroMemoryY.resize(sampleFrequency);
		GyroMemoryX.resize(sampleFrequency);

		AccelMemoryX.resize(sampleFrequency);
		AccelMemoryY.resize(sampleFrequency);
		AccelMemoryZ.resize(sampleFrequency);

	}


	void ArrayControllerUpdate(sensors_event_t a, g)
	{
		//Take readings from mpu for all 6 DoF at each timestep

				//Gyro

		GyroMemoryX[GyroMemoryDivider] = g.gyro.x;
		GyroMemoryY[GyroMemoryDivider] = g.gyro.y;
		GyroMemoryZ[GyroMemoryDivider] = g.gyro.z;

		GyroMemoryDivider++;

				//Accelerometer

		AccelMemoryX[AccelMemoryDivider] = a.Acceleration.x;
		AccelMemoryY[AccelMemoryDivider] = a.Acceleration.y;
		AccelMemoryZ[AccelMemoryDivider] = a.Acceleration.z;

		AccelMemoryDivider++;


		//Loops the divider back to start of array when it reaches the end;
		if(GyroMemoryDivider > GyroMemoryX.size())
		{
			GyroMemoryDivider = 0;	
		}

		if(AccelMemoryDivider > AccelMemoryX.size())
		{
			AccelMemoryDivider = 0;	
		}
		

	}



	//Getters for the memory, disgusting block of code but oh well probably should be reworked to remove duplication

	std::vector<int> GetGyroMemoryX()
	{
		std::vector<int> v;
		v.resize(GyroMemoryX.size())
		int counter = 0;
		for(int i = GyroMemoryDivider; i < GyroMemoryX.size();i++)
		{
			v[counter] = GyroMemoryX[i];

		}


		for(int i = 0; i < GyroMemoryDivider; i++)
		{
			v[counter] = GyroMemoryX[i];

		}
		return v

	}
	std::vector<int> GetGyroMemoryY()
	{
		std::vector<int> v;
		v.resize(GyroMemoryY.size())
		int counter = 0;
		for(int i = GyroMemoryDivider; i < GyroMemoryY.size();i++)
		{
			v[counter] = GyroMemoryY[i];

		}


		for(int i = 0; i < GyroMemoryDivider; i++)
		{
			v[counter] = GyroMemoryY[i];

		}
		return v

	}
	std::vector<int> GetGyroMemoryZ()
	{
		std::vector<int> v;
		v.resize(GyroMemoryZ.size())
		int counter = 0;
		for(int i = GyroMemoryDivider; i < GyroMemoryZ.size();i++)
		{
			v[counter] = GyroMemoryZ[i];

		}


		for(int i = 0; i < GyroMemoryDivider; i++)
		{
			v[counter] = GyroMemoryZ[i];

		}
		return v

	}

	std::vector<int> GetAccelMemoryX()
	{
		std::vector<int> v;
		v.resize(AccelMemoryX.size())
		int counter = 0;
		for(int i = AccelMemoryDivider; i < AccelMemoryX.size();i++)
		{
			v[counter] = AccelMemoryX[i];

		}


		for(int i = 0; i < AccelMemoryDivider; i++)
		{
			v[counter] = AccelMemoryX[i];

		}
		return v;

	}
	std::vector<int> GetAccelMemoryY()
	{
		std::vector<int> v;
		v.resize(AccelMemoryY.size())
		int counter = 0;
		for(int i = AccelMemoryDivider; i < AccelMemoryY.size();i++)
		{
			v[counter] = AccelMemoryY[i];

		}


		for(int i = 0; i < AccelMemoryDivider; i++)
		{
			v[counter] = AccelMemoryY[i];

		}

		return v;

	}
	std::vector<int> GetAccelMemoryZ()
	{
		std::vector<int> v;
		v.resize(AccelMemoryZ.size())
		int counter = 0;
		for(int i = AccelMemoryDivider; i < AccelMemoryZ.size();i++)
		{
			v[counter] = AccelMemoryZ[i];

		}


		for(int i = 0; i < AccelMemoryDivider; i++)
		{
			v[counter] = AccelMemoryZ[i];

		}

		return v;

	}

