#include "hc-sr04_module.hh"

Hcsr04Module::Hcsr04Module(int rxpin,int txpin) : RxTxModule(rxpin,txpin)
{
    initPin();
}

std::string Hcsr04Module::GetStatus()
{
  digitalWrite(this->rxpin, LOW);
  delayMicroseconds(2);
  digitalWrite(this->rxpin, HIGH);
  delayMicroseconds(10);
  digitalWrite(this->rxpin, LOW);
  duration = pulseIn(this->txpin, HIGH);
  distance = duration * 0.034 / 2;
  Serial.println(distance);
  return std::to_string(distance);
}

void Hcsr04Module::initPin()
{
    pinMode(this->rxpin, OUTPUT); 
    pinMode(this->txpin, INPUT);
}
