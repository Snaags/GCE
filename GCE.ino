#include "functions.h"
#include "ArrayController.h"


void setup() {
  // put your setup code here, to run once:
	ArrayControllerInit(mpu);
}

void loop() {
  // put your main code here, to run repeatedly:

	ArrayControllerUpdate(a,g);

	
}
