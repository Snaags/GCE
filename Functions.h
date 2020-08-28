#pragma once


	//Array management
	namespace Utils
	{
		void Plotting(int * pVar1)
		{
			int counter = 0;
			int *pInit = pVar1; 
			Serial.print("\n");
			while(pVar1 < (pInit+50))
			{
				Serial.print("  Reading:" );
				Serial.print(*pVar1);
				Serial.print("\n");



				pVar1++;
				counter ++;

			}

			Serial.print("\nTotal length of array: ");
			Serial.print(counter);
		}
	}