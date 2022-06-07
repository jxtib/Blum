#include <Arduino_PortentaBreakout.h>

const int minPower = 0;
const int maxPower = 256;
const int powerStep = 5;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(ANALOG_A0, INPUT);
  pinMode(PWM8, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:

  for(power=minVolt;power<maxVolt;power+=powerStep){
    Breakout.analogWrite(PWM8, power);

    int voltIn = Breakout.analogRead(ANALOG_A0);
    Serial.print("The voltage is: ");
    Serial.println(voltIn * 5.0/1023);
    delay(1000);
  }

}
