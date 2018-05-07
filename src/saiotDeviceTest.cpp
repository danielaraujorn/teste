#include <Arduino.h>
#include <SaIoTDeviceLib.h>

#define qtdSensor 2

String serial = "tp02";
unsigned int timer = 1000;
unsigned int contador = 0;
/* criar um sensor apenas e tentar usar para postar valores */

SaIoTDeviceLib device01;
void setup(){
	Serial.println(qtdSensor);
	boolean acummm = true;
	device01.addSensor("key01", "litros");
	Serial.begin(115200);
	Serial.println("======================");
	Serial.println(serial);
	device01.start(serial);
}

void loop(){
	delay(timer);
	Serial.printf("%d\n", ++contador);
	device01.start(serial);

}