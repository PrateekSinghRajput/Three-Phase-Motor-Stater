//Prateek
//https://justdoelectronics.com
https://www.youtube.com/@JustDoElectronics/videos

String textMessage;

String light1State = "HIGH";

#define Yellow 4
#define Green 5

const int light1 = 7;

void setup() {

  pinMode(light1, OUTPUT);
  pinMode(Yellow, OUTPUT);
  pinMode(Green, OUTPUT);

  digitalWrite(light1, HIGH);
  Serial.begin(9600);
  delay(20000);
  Serial.print("AT+CMGF=1\r");
  delay(100);
  Serial.print("AT+CNMI=2,2,0,0,0\r");
  delay(100);
}


void loop() {
  if (Serial.available() > 0) {
    textMessage = Serial.readString();
    textMessage.toUpperCase();
    delay(10);
  }
  if (textMessage.indexOf("START") >= 0) {
    digitalWrite(light1, LOW);
    light1State = "on";
    textMessage = "";
    digitalWrite(Green, HIGH);
    digitalWrite(Yellow, LOW);
  }

  if (textMessage.indexOf("STOP") >= 0) {
    digitalWrite(light1, HIGH);
    light1State = "off";
    textMessage = "";
    digitalWrite(Yellow, HIGH);
    digitalWrite(Green, LOW);

  }

  if (textMessage.indexOf("STARTSTATE") >= 0) {
    String message = "light1 is " + light1State;
    sendSMS(message);
    textMessage = "";
  } 
  
 if (textMessage.indexOf("STOPSTATE") >= 0) {
    String message = "light1 is " + light1State;
    sendSMS(message);
    textMessage = "";
  }
}

void sendSMS(String message) {
  Serial.print("AT+CMGF=1\r");
  delay(100);

  Serial.println("AT + CMGS = \"+918830584864\"");
  delay(100);
  Serial.println(message);
  delay(100);

  Serial.println((char)26);
  delay(100);
  Serial.println();
  delay(5000);
}
