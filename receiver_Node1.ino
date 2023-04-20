#include <SPI.h>
#include <nRF24L01.h>
#include <RF24.h>

RF24 radio(7, 8); // CE, CSN

int buttonval1 = 1;
int buttonval2 = 1;
int buttonval3 = 1;
int buttonval4 = 1;

int Mosfet1 = 2;
int Mosfet2 = 3;
int Mosfet3 = 4;
int Mosfet4 = 5;

const byte address[6] = "Node1";


void setup() {

  Serial.begin(9600);
  pinMode(Mosfet1, OUTPUT);
  pinMode(Mosfet2, OUTPUT);
  pinMode(Mosfet3, OUTPUT);
  pinMode(Mosfet4, OUTPUT);

  radio.begin();
  radio.openReadingPipe(0, address);
  radio.setPALevel(RF24_PA_MIN);
}

void loop() {
  radio.startListening();
  while (!radio.available());
  radio.read(&buttonval1, sizeof(buttonval1));
  radio.read(&buttonval2, sizeof(buttonval2));
  radio.read(&buttonval3, sizeof(buttonval3));
  radio.read(&buttonval4, sizeof(buttonval4));


  if (buttonval1 == 0) {
    digitalWrite(Mosfet1, HIGH);
    delay(100);
  }

  else if (buttonval2 == 0) {
    digitalWrite(Mosfet2, HIGH);
    delay(100);
  }

  else if (buttonval3 == 0) {
    digitalWrite(Mosfet3, HIGH);
    delay(100);
  }

  else if (buttonval4 == 0) {
    digitalWrite(Mosfet4, HIGH);
    delay(100);
  }

  else {
    digitalWrite(Mosfet1, LOW);
    digitalWrite(Mosfet2, LOW);
    digitalWrite(Mosfet3, LOW);
    digitalWrite(Mosfet4, LOW);

  }





}
