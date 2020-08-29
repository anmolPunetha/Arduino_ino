/* code developed by Anmol Punetha
   Controlling 3 led from keyboard and also managing their blink rate through +/- sign*/
const int led_1 = 6;
const int led_2 = 8;
const int led_3 = 10;
int val;
int prev = 0;
void setup() {
  pinMode(led_1, OUTPUT);
  pinMode(led_2, OUTPUT);
  pinMode(led_3, OUTPUT);
  Serial.begin(9600);
}

void loop() {
    val = (Serial.read()-'0');
    Serial.println(val);
    while(!Serial.available()){
      
      if(val == 1) blink1();      // blinking LED-1 (Green)
         
      if(val == 2) blink2();      // blinking LED-2 (White)

      if(val == 3) blink3();      // blinking LED-3 (Red)
        
      // for increasing the blink rate by 0.25 second of led-1
      if (val == -5 && prev ==1){
        digitalWrite(led_1, HIGH);
        delay(750);
        digitalWrite(led_1, LOW);
        delay(750);
      }
      
      // for decreasing the blink rate by 0.25 second of led-1
      if (val == -3 && prev ==1){
        digitalWrite(led_1, HIGH);
        delay(1250);
        digitalWrite(led_1, LOW);
        delay(1250);
      }

      // for increasing the blink rate by 0.25 second of led-2
      if (val == -5 && prev ==2){
        digitalWrite(led_2, HIGH);
        delay(750);
        digitalWrite(led_2, LOW);
        delay(750);
      }

      // for decreasing the blink rate by 0.25 second of led-2
      if (val == -3 && prev ==2){
        digitalWrite(led_2, HIGH);
        delay(1250);
        digitalWrite(led_2, LOW);
        delay(1250);
      }

      // for increasing the blink rate by 0.25 second of led-3
      if (val == -5 && prev ==3){
        digitalWrite(led_3, HIGH);
        delay(750);
        digitalWrite(led_3, LOW);
        delay(750);
      }

      // for decreasing the blink rate by 0.25 second of led-3
       if (val == -3 && prev ==3){
        digitalWrite(led_3, HIGH);
        delay(1250);
        digitalWrite(led_3, LOW);
        delay(1250);
      }
   }
}

void blink1(){
      digitalWrite(led_1, HIGH);
      delay(1000);
      digitalWrite(led_1, LOW);
      delay(1000);
      prev = val;
}
void blink2(){
     digitalWrite(led_2, HIGH);
     delay(1000);
     digitalWrite(led_2, LOW);
     delay(1000);
     prev = val;
}
void blink3(){
      digitalWrite(led_3, HIGH);
      delay(1000);
      digitalWrite(led_3, LOW);
      delay(1000);
      prev = val;
}
