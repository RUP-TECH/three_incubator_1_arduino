#include <SimpleDHT.h>

#define SEN1 2
#define SEN2 4
#define SEN3 7
#define LIGHT1 8
#define LIGHT2 12
#define LIGHT3 11

SimpleDHT11 dht1(SEN1);

SimpleDHT11 dht2(SEN2);

SimpleDHT11 dht3(SEN3);

void setup() {
  Serial.begin(115200);
  pinMode(LIGHT1,OUTPUT);
  pinMode(LIGHT2,OUTPUT);
  pinMode(LIGHT3,OUTPUT);
  digitalWrite(LIGHT1, LOW);
  digitalWrite(LIGHT2, LOW);
  digitalWrite(LIGHT3, LOW);
  delay(500);
}

void loop() {
  byte temp1 = 0;
  byte temp2 = 0;
  byte temp3 = 0;
  byte hum1 = 0;
  byte hum2 = 0;
  byte hum3 = 0;
  // start working...
  Serial.println("=================================");
  
  // read without samples.

  int err1 = SimpleDHTErrSuccess;
  if ((err1 = dht1.read(&temp1, &hum1, NULL)) != SimpleDHTErrSuccess) {
    delay(1000);
   
  }
  Serial.print("SENSOR 1----->");
  Serial.print((int)temp1); Serial.println(" *C "); 

int err2 = SimpleDHTErrSuccess;
    if ((err2 = dht2.read(&temp2, &hum2, NULL)) != SimpleDHTErrSuccess) {
    delay(1000);
  
  }
  
  Serial.print("SENSOR 2----->");
  Serial.print((int)temp2); Serial.println(" *C "); 
int err3 = SimpleDHTErrSuccess;
    if ((err3 = dht3.read(&temp3, &hum3, NULL)) != SimpleDHTErrSuccess) {
    delay(1000);
  
  }

  Serial.print("SENSOR 3----->");
  Serial.print((int)temp3); Serial.println(" *C "); 
  
  if((int)temp1 >= 37)
  {
    digitalWrite(LIGHT1, LOW);
    delay(10);
  }
  if((int)temp1 < 36)
  {
    digitalWrite(LIGHT1, HIGH);
    delay(10);
  }

  
    if((int)temp2 >= 37)
  {
    digitalWrite(LIGHT2, LOW);
    delay(10);
  }
  if((int)temp2 < 36)
  {
    digitalWrite(LIGHT2, HIGH);
    delay(10);
  }

  
    if((int)temp3 >= 37)
  {
    digitalWrite(LIGHT3, LOW);
    delay(10);
  }
  if((int)temp3 < 36)
  {
    digitalWrite(LIGHT3, HIGH);
    delay(10);
  }
  
  delay(1500);

}
