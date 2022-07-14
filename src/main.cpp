#include <Arduino.h>
#include <pin.h>
#include <serial.h>
      
int tmmp =888; 
Delay TempTimer(1000);

int temp() {                    
      float val = analogRead(A0); 
      float voltage= val * (5.0 / 1023.0);
      float r = (5.0-voltage)/(voltage/10000.0);
      float te=((3950*298.15)/(log(r/100000)*298.15+3950))-273.15;
      int t=te;
      return t;
}
    
void setup() {
      pinMode(serial, OUTPUT);
      pinMode(clk, OUTPUT);
      pinMode(release, OUTPUT);
      pinMode(dig0, OUTPUT);
      pinMode(dig1, OUTPUT);
      pinMode(dig2, OUTPUT);
}

void loop() {
      if (TempTimer.interval()) {
            tmmp=temp();
            TempTimer.reset();
      }
      else {
            for(int i=0;i<3;i++){
            Digit ds(tmmp,i);
           delay(1);
            }    
      }
}
