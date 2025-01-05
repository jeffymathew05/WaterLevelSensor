#include <SPI.h>
#include <LoRa.h>

#define FLOAT_SENSOR1  1                          // the number of the float switch1 pin
#define FLOAT_SENSOR2  2                          // the number of the float switch2 pin
void setup() {

  Serial.begin(9600);
  while (!Serial);                                // Waits for the serial port to be ready

  if (!LoRa.begin(915E6)) {                       // Initializes the LoRa module with a frequency of 915 MHz
    Serial.println("Starting LoRa failed!");      // If fails to initialize the LoRa module, the message "Starting LoRa failed!" is printed to the Serial Monitor
    while (1);                                    // the program halts to an infinite loop if the initializing is failed
  }

  pinMode(FLOAT_SENSOR1, INPUT_PULLUP);           // initialize the first float switch pin as an input:
  pinMode(FLOAT_SENSOR2, INPUT_PULLUP);           // initialize the second float switch2 pin as an input:
}

void loop() {
 
  int packetSize = LoRa.parsePacket();            // try to parse packet
  if (packetSize) {
    
    Serial.print("Received packet '");            // received a packet

    
    while (LoRa.available()) {                    // read packet
      Serial.print((char)LoRa.read());
    }
    if()                                          //ADDITIONAL DATA IS REQUIRED TO COMPLETE THE CODE 
    
    Serial.print("' with RSSI ");                 // print RSSI of packet
    Serial.println(LoRa.packetRssi());
  
}
