#include <Arduino.h>
#include <pin.h>

class Digit{

    private:
        bool stream[8];
        int temp = 0;
        int pos;
        int digit;

    public:


    Digit(int temperature, int position){
        temp = temperature;
        pos=position;
        setDigit();
        transl();
        killEmAll();
        dataStream();
        setVcc();
        digitalWrite(release, HIGH);
        digitalWrite(release, LOW);
    }
    
    int getDigit(){return digit;}
 
    private: 
    
    void setDigit(){
        int val = temp;
        for(int i=0;i<=pos;i++){
        digit=val%10;
        val /= 10;
        };
    }

    void transl(){
       
        if(digit==0||digit==2||digit==3||digit==5||digit==7||digit==8||digit==9||digit==6){ stream[LedPosA]=true;} else stream[LedPosA]=false;
        if(digit==0||digit==1||digit==2||digit==3||digit==4||digit==7||digit==8||digit==9){stream[LedPosB]=true;}else stream[LedPosB]=false;
        if(digit==0||digit==1||digit==3||digit==4||digit==5||digit==6||digit==7||digit==8||digit==9){stream[LedPosC]=true;}else stream[LedPosC]=false;
        if(digit==0||digit==2||digit==3||digit==5||digit==6||digit==8||digit==9){stream[LedPosD]=true;}else stream[LedPosD]=false;
        if(digit==0||digit==2||digit==6||digit==8){stream[LedPosE]=true;}else stream[LedPosE]=false;
        if(digit==0||digit==4||digit==5||digit==6||digit==8||digit==9){stream[LedPosF]=true;}else stream[LedPosF]=false;
        if(digit==3||digit==4||digit==5||digit==6||digit==8||digit==2||digit==9){stream[LedPosG]=true;}else stream[LedPosG]=false;
        if(temp >50){stream[FanPos]=true;} 
        if(temp <45){stream[FanPos]=false;}
    }

    void setVcc(){
          
        if(pos==0){
             digitalWrite(dig0, HIGH);
        }
        else digitalWrite(dig0, LOW);
        if (pos==1)
        {
             digitalWrite(dig1, HIGH);
        }
          else digitalWrite(dig1, LOW);
        if (pos==2)
        {
             digitalWrite(dig2, HIGH);
        }
          else digitalWrite(dig2, LOW);
    }

    void dataStream(){    
    
    digitalWrite(serial, LOW);
    for (int i=0;i<=7;i++){
         if (stream[i]){
             digitalWrite(serial, HIGH);        
             }
        else {
            digitalWrite(serial, LOW);
        }       
    digitalWrite(clk, HIGH);
    digitalWrite(clk, LOW);
    }
    }
 
    void killEmAll(){
        digitalWrite(dig0, LOW);
        digitalWrite(dig1, LOW);
        digitalWrite(dig2, LOW);
    }
};
//------------------------------------------------------
class Delay{
    private:
        unsigned long interv;
        unsigned long previousMillis;
        unsigned long currentMillis;

    public:
    Delay(long interval){
        interv=interval;
        currentMillis = millis();
    }
    
    void reset(){
        previousMillis=currentMillis;
    }

    bool interval(){
        currentMillis = millis();
        if ((currentMillis - previousMillis) <= interv){return false;}
        else{return true;}
    }

 };
