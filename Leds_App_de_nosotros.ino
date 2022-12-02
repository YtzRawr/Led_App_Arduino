#include <SoftwareSerial.h>


SoftwareSerial mySerial (0, 1);


char myChar;


#define LED1 2
#define LED2 3
#define LED3 4

char Nombre = 'B';//variable para el nombre

void setup() {
  // put your setup code here, to run once:

  
  mySerial.begin(9600);
  
  
  mySerial.print("AT");
  delay(1000);
  mySerial.print("AT+NAME");
  mySerial.print(Nombre);
  delay(1000);

  
  mySerial.println("CONEXION EXITOSA");
  pinMode(2, OUTPUT);
  pinMode(3, OUTPUT);
  pinMode(4, OUTPUT);

}

void loop() {
  // put your main code here, to run repeatedly:
  if(mySerial.available()){
    myChar = mySerial.read();
    switch (myChar){

        //Mañana
        case 'm':
        digitalWrite(2, HIGH);
        delay(20000);
        digitalWrite(2, LOW);
        digitalWrite(3, HIGH);
        delay(5000);
        digitalWrite(3, LOW);
        digitalWrite(4, HIGH);
        delay(10000);
        digitalWrite(4, LOW);
        break;

        case 'A':
          digitalWrite(2, LOW);
        break;



        //tarde        
        case 't':
        digitalWrite(2, HIGH);
        delay(10000);
        digitalWrite(2, LOW);
        digitalWrite(3, HIGH);
        delay(5000);
        digitalWrite(3, LOW);
        digitalWrite(4, HIGH);
        delay(15000);
        digitalWrite(4, LOW);
        break;
        case 'A':
        digitalWrite(3, LOW);
        break;

        //noche
        case 'n':
        digitalWrite(2, HIGH);
        delay(8000);
        digitalWrite(2, LOW);
        digitalWrite(3, HIGH);
        delay(1000);
        digitalWrite(3, LOW);
        digitalWrite(4, HIGH);
        delay(4000);
        digitalWrite(4, LOW);
        break;
        case 'A':
        digitalWrite(4, LOW);
        break;


        //prender los 3 de una
        case 'd':
        digitalWrite(2, HIGH);
        digitalWrite(3, HIGH);
        digitalWrite(4, HIGH);

        break;
        //apagar los 3 de una
        case 'D':
        digitalWrite(2, LOW);
        digitalWrite(3, LOW);
        digitalWrite(4, LOW);
        break;

        default:
        mySerial.println("OPCION NO VALIDA");
        break;
    }



    
  }

}
