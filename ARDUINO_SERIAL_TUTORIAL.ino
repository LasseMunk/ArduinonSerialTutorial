
int solenoid = 2;

// ARRAYS
int incomingByte[2]; // DECLARE ARRAY TO HOLD INCOMMING BYTES

void setup()
{
    pinMode(solenoid, OUTPUT); // DECLARE PIN 13 AS OUTPUT
    Serial.begin(9600); // SET BAUDRATE .. GO GO SPEED!
     while (!Serial) {
    ; // wait for serial port to connect. Needed for Leonardo only
  }
}

void loop() {
  
  if(Serial.available() >= 2)    // CHECK TO SEE WHEN THE ARDUINO HAS RECEIVED 2 
  {                              // BYTES.
    incomingByte[0] = Serial.read(); // Fills the first received byte into first space in array
    incomingByte[1] = Serial.read();
   
     // if(incomingByte[1] == 1) {  // BYTE 2 (ARRAY INDEX 1) IS USED AS
                                  // END BYTE. RESULT: PRINT BOTH RECEIVED BYTES
     /*
      Serial.print("byte0: ");
      Serial.println(incomingByte[0], DEC);
                 
      Serial.print("byte1: ");
      Serial.println(incomingByte[1], DEC);        
      */

      if(incomingByte[0] == 2 && incomingByte[1] == 0) {
        digitalWrite(solenoid, LOW);
        
        Serial.print("byte1: ");
        Serial.println(incomingByte[1], DEC);  
      }
      if(incomingByte[0] == 2 && incomingByte[1] == 1) {
        digitalWrite(solenoid, HIGH);
        Serial.print("byte1: ");
        Serial.println(incomingByte[1], DEC);  
      }
  }  
}
