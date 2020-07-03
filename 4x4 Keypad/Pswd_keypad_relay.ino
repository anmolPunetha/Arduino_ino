#include <Keypad.h>

#define Password_Length 4

int signalPin = 10;
char Data[Password_Length]; 
char Master[Password_Length] = "89C"; 
char off[Password_Length] = "***";
byte data_count = 0, master_count = 0;
bool Pass_is_good;
char customKey;

const byte ROWS = 4;
const byte COLS = 4;

char hexaKeys[ROWS][COLS] = {
  {'1', '2', '3', 'A'},
  {'4', '5', '6', 'B'},
  {'7', '8', '9', 'C'},
  {'*', '0', '#', 'D'}
};

byte rowPins[ROWS] = {9, 8, 7, 6};
byte colPins[COLS] = {5, 4, 3, 2};

Keypad customKeypad = Keypad(makeKeymap(hexaKeys), rowPins, colPins, ROWS, COLS);


void setup(){
 Serial.begin(9600);
  pinMode(signalPin, OUTPUT);
  digitalWrite(signalPin,HIGH);
}

void loop(){
 // Serial.println("Enter Password:");

  customKey = customKeypad.getKey();
  if (customKey){
    Data[data_count] = customKey; 
    Serial.print(Data[data_count]); 
    data_count++; 
    }

  if(data_count == Password_Length-1){
    Serial.print('\n');

    if(!strcmp(Data, Master)){
      Serial.println("Device Status: ON");
      digitalWrite(signalPin, LOW); 
      }
    else if(!strcmp(Data, off)){
      digitalWrite(signalPin, HIGH);
      Serial.println("Device Status: OFF");
      }
     else{
      Serial.println("No match");
      }
    
   // Serial.println('\n');
    clearData();  
  }
}

void clearData(){
  while(data_count !=0){
    Data[data_count--] = 0; 
  }
  return;
}
