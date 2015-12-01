#define pin_intA 1//A相
#define pin_intB 12//B相电压
#define pin_motor1 5
#define pin_motor2 6
#include <string.h>
int  PWM_IN1, PWM_IN2;
String inString = "";
int order=0;
void print1() {

  Serial.println(PWM_IN1);
  Serial.println(PWM_IN2);
}
void PWM(int value) {
  if (value > 0) {
    if (value > 255) {
      PWM_IN1 = 255;
      PWM_IN2 = 0;
    } else {
      PWM_IN1 = value; PWM_IN2 = 0;
    }

  } else {
    if (abs(value) > 255) {
      PWM_IN1 = 0;
      PWM_IN2 = 255;
    } else {
      PWM_IN1 = 0; PWM_IN2 = abs(value);
    }



  }

}
void setup() {
  Serial.begin(9600);
  pinMode(pin_motor1, OUTPUT);
  pinMode(pin_motor2, OUTPUT);
  analogWrite(pin_motor1, 0);
  analogWrite(pin_motor2, 0);

}

void loop() {
    
      while (Serial.available() > 0) {
    int inChar = Serial.read();
    if (isDigit(inChar)) {
      // convert the incoming byte to a char 
      // and add it to the string:
      inString += (char)inChar; 
    }
    // if you get a newline, print the string,
    // then the string's value:
    if (inChar == '\n') {
      Serial.print("Value:");
      Serial.println(inString.toInt());
          PWM(inString.toInt());
      Serial.print("String: ");
      Serial.println(inString);
      // clear the string for new input:
      inString = ""; 
    }
  }
  
//    while (Serial.available() > 0) {
//    int inChar = Serial.read();
//    if (isDigit(inChar)) {
//      Serial.println("while "+inChar);
//      // convert the incoming byte to a char 
//      // and add it to the string:
//      inString += (char)inChar; 
//    }
//    
//    }
//      if(inChar == '\n'){
//        Serial.println("judge");
//        order=inString.toInt();
//        Serial.println(order);
//        inString="";
//        PWM(order);
//        analogWrite(pin_motor1, PWM_IN1);
//        analogWrite(pin_motor2, PWM_IN2);
//      
//    }

    


  analogWrite(pin_motor1, PWM_IN1);
  analogWrite(pin_motor2, PWM_IN2);
  // put your main code here, to run repeatedly:

}
