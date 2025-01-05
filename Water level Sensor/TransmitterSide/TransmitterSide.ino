#include <SPI.h>
#include <LoRa.h>

#define FLOAT_SENSOR1  1     // the number of the float switch1 pin
#define FLOAT_SENSOR2  2     // the number of the float switch2 pin
void setup() {

  Serial.begin(9600);
  while (!Serial);      // Waits for the serial port to be ready

  if (!LoRa.begin(915E6)) {      // Initializes the LoRa module with a frequency of 915 MHz
    Serial.println("Starting LoRa failed!");      // If fails to initialize the LoRa module, the message "Starting LoRa failed!" is printed to the Serial Monitor
    while (1);      // the program halts to an infinite loop if the initializing is failed
  }

  pinMode(FLOAT_SENSOR1, INPUT_PULLUP);     // initialize the first float switch pin as an input:
  pinMode(FLOAT_SENSOR2, INPUT_PULLUP);     // initialize the second float switch2 pin as an input:
}

void loop() {

  int sensor1=digitalRead(FLOAT_SENSOR1);     //taking value from first float switch:
  int sensor2=digitalRead(FLOAT_SENSOR2);     //taking value from second float switch:
  Serial.print("Sending packet: ");
  LoRa.beginPacket();                         //started the packet to send values to receiver side:
  LoRa.print(sensor1);                        //the value from the first float sensor is stored in the packet:
  LoRa.print(sensor2);                        //the value from the second float sensor is stored in the packet:
  LoRa.endPacket();                           //ends the packet to send values to receiver side:
  
  delay(5000);
  
}
