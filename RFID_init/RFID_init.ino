  #include <SPI.h>
  #include <MFRC522.h>
  
  #define RST_PIN         4         // Configurable, see typical pin layout above
  #define SS_PIN          5         // Configurable, see typical pin layout above
  
  MFRC522 mfrc522(SS_PIN, RST_PIN);  // Create MFRC522 instance
  
  String read_rfid;
  String ok_rfid="57494a2b";
  
  int countG=100;
  
  void setup() {
  	Serial.begin(9600);		// Initialize serial communications with the PC
  	//while (!Serial);		// Do nothing if no serial port is opened (added for Arduinos based on ATMEGA32U4)
  	SPI.begin();			// Init SPI bus
  	mfrc522.PCD_Init();		// Init MFRC522
  	//pinMode(12, OUTPUT);
    pinMode(9, INPUT_PULLUP);
    pinMode(8, OUTPUT);
  	//mfrc522.PCD_DumpVersionToSerial();	// Show details of PCD - MFRC522 Card Reader details
  	//Serial.println(F("Scan PICC to see UID, SAK, type, and data blocks..."));
  }
  
  
  
  
  void dump_byte_array(byte *buffer, byte bufferSize) {
      read_rfid="";
      for (byte i = 0; i < bufferSize; i++) {
          read_rfid=read_rfid + String(buffer[i], HEX);
      }
  }
  
  
  
  
  void loop() {
  	// Look for new cards
  	if (mfrc522.PICC_IsNewCardPresent()) {
     if ( ! mfrc522.PICC_ReadCardSerial()) {
      return;
    }
      dump_byte_array(mfrc522.uid.uidByte, mfrc522.uid.size);
      Serial.println(read_rfid);
      if(read_rfid==ok_rfid){
        if(digitalRead(9)==HIGH){
          do
            {
             digitalWrite(8,HIGH);
            } while (digitalRead(9)==HIGH);
          do
            {
             digitalWrite(8,HIGH);
             Serial.println("HERE");
             delay(1000);
            } while (digitalRead(9)==LOW);
            do
            {
             digitalWrite(8, HIGH);
             delay(100);
             Serial.println("Problem");
             digitalWrite(8,LOW);
             delay(500);
            } while (digitalRead(9)==HIGH);
        
          if(digitalRead(9)==LOW)
          {
            digitalWrite(8,LOW);
          }
          }
          else{
            do
            {
             digitalWrite(8,HIGH);
             Serial.println("HERE");
             delay(1000);
            } while (digitalRead(9)==LOW);
            do
            {
             digitalWrite(8, HIGH);
             delay(100);
             digitalWrite(8,LOW);
             delay(500);
            } while (digitalRead(9)==HIGH);
        
          if(digitalRead(9)==LOW)
          {
            digitalWrite(8,LOW);
          }
          }
        }
        
     }
  }
