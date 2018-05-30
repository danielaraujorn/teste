#include <Arduino.h>
#include <SaIoTDeviceLib.h>

// #include <Wire.h>  //INCLUSÃO DE BIBLIOTECA
#include <LiquidCrystal_I2C.h> //INCLUSÃO DE BIBLIOTECA

#define qtdSensor 2

LiquidCrystal_I2C lcd(0x3F, 16, 2); // "LiquidCrystal_I2C" 16 colunas 2 linhas
SaIoTDeviceLib device01;

String serial = "tp02";
unsigned int timer = 100;
unsigned int contador = 0;
/* criar um sensor apenas e tentar usar para postar valores */
void setup()
{
  pinMode(A0, INPUT);
  lcd.begin(16, 2);
  lcd.init();
  lcd.backlight();
  lcd.setCursor(0, 0);
  lcd.print("sensores:");
  lcd.print(qtdSensor);
  lcd.setCursor(0, 1);
  lcd.print("serial:");
  lcd.print(serial);
  boolean acummm = true;
  device01.addSensor("key01", "litros");
  device01.start(serial);
}

void loop()
{
  delay(timer);
  lcd.setCursor(0, 0);
  lcd.print("sensor:  ");
  lcd.print(digitalRead(A0));
  Serial.printf("%d\n", ++contador);
  device01.start(serial);
}
