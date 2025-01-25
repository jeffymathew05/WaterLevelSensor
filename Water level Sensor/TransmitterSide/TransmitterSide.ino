#include <SPI.h>
#include <LoRa.h>

#define ss 15
#define rst 16
#define dio0 2
#define FLOAT_SENSOR1  D2                       // the number of the float switch1 pin
#define FLOAT_SENSOR2  D1                       // the number of the float switch2 pin

int sensor1,sensor2;
char counter = '0';
void setup() {

  Serial.begin(9600);
  while (!Serial);                               // Waits for the serial port to be ready
  LoRa.setPins(ss, rst, dio0);
  if (!LoRa.begin(915E6)) {                      // Initializes the LoRa module with a frequency of 915 MHz
    Serial.println("Starting LoRa failed!");     // If fails to initialize the LoRa module, the message "Starting LoRa failed!" is printed to the Serial Monitor
    while (1);                                   // the program halts to an infinite loop if the initializing is failed
  }

  pinMode(FLOAT_SENSOR1, OUTPUT);                 // initialize the first float switch pin as an input:
  pinMode(FLOAT_SENSOR2, OUTPUT);                 // initialize the second float switch2 pin as an input:
  
}

void loop() { 
  digitalWrite(FLOAT_SENSOR1,HIGH);                //Taking Value from first sensor, making it high is for testing the module
  digitalWrite(FLOAT_SENSOR2,HIGH);                //Taking Value from second sensor, making it high is for testing the module
  sensor1=digitalRead(FLOAT_SENSOR1);              //taking value from first float switch:
  sensor2=digitalRead(FLOAT_SENSOR2);              //taking value from second float switch:
  if(sensor1==0&&sensor2==0){
    counter='1';
  }
  else if(sensor1==1&&sensor2==1){
    counter='0';
  }
  Serial.print("Sending packet: ");
  Serial.println(counter);
  LoRa.beginPacket();
  LoRa.println(counter);                       
  LoRa.endPacket();                           
  delay(3000); 
}