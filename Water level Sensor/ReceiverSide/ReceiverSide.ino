#include <SPI.h>
#include <LoRa.h>

char data;
int value;
void setup() {
  Serial.begin(9600);
  while (!Serial);                                // Waits for the serial port to be ready

  if (!LoRa.begin(915E6)) {                       // Initializes the LoRa module with a frequency of 915 MHz
    Serial.println("Starting LoRa failed!");      // If fails to initialize the LoRa module, the message "Starting LoRa failed!" is printed to the Serial Monitor
    while (1);                                    // the program halts to an infinite loop if the initializing is failed
  }
}
void loop() {
 
  int packetSize = LoRa.parsePacket();            // try to parse packet
  if (packetSize) {
    
    Serial.print("Received packet ");            // received a packet

    while (LoRa.available()) {  
      data = (char)LoRa.read();
      Serial.print(data);
      if (data>='0' && data <='z'){             // Eliminating the '\0' form the char
        value=data-'0';
      }
    }
    Serial.println(value);
    if(value==1){                               // Condition for motor to be ON or OFF
      Serial.println("Motor is turned on");
    }                                         
    else{
      Serial.println("Motor is turned off");
    }  
    Serial.print(" with RSSI ");                 // print RSSI of packet
    Serial.println(LoRa.packetRssi());
    delay(3000);
  }
}