const int sensorTopf1Pin = A1;
const int sensorTopf2Pin = A2;
const int sensorTopf3Pin = A3;

const int pumpeTopf1Pin = 5;
const int pumpeTopf2Pin = 6;
const int pumpeTopf3Pin = 7;

//Unterhalb dieser Sensorwerte wird nicht gegossen
int sollTopf1 = 440;
int sollTopf2 = 440;
int sollTopf3 = 440;

//Anfangswerte der Sensorsignale
int istTopf1 = 700;
int istTopf2 = 700;
int istTopf3 = 700;

//Wartezeit zwischen den Messungen
unsigned long Wartezeit = 60000;

//Solang wird bei zu trockenem Boden gepumpt
int Pumpzeit = 4000;

void setup() {
  
  // Alle Sensoren sind Eingänge
  pinMode(sensorTopf1Pin, INPUT);
  pinMode(sensorTopf2Pin, INPUT);
  pinMode(sensorTopf3Pin, INPUT);

  //Alle Pumpen sind Ausgänge
  pinMode(pumpeTopf1Pin, OUTPUT);
  pinMode(pumpeTopf2Pin, OUTPUT);
  pinMode(pumpeTopf3Pin, OUTPUT);

  //Pumpen zu Beginn aus
  digitalWrite(pumpeTopf1Pin, LOW);
  digitalWrite(pumpeTopf2Pin, LOW);
  digitalWrite(pumpeTopf3Pin, LOW);
  
  //Serieller Monitor starten
  Serial.begin(9600);
  
}
      
void loop() {
  //Wartezeit für die Senoren zu Beginn
  delay(Wartezeit);

  //Messen
  istTopf1 = analogRead(sensorTopf1Pin);
  istTopf2 = analogRead(sensorTopf2Pin);
  //istTopf3 = analogRead(sensorTopf3Pin);
  
  //Werte seriell ausgeben
  Serial.print("Sensorwert Topf 1: ");
  Serial.println(istTopf1);
  Serial.print("Sensorwert Topf 2: ");
  Serial.println(istTopf2);
  //Serial.print("Sensorwert Topf 3: ");
  //Serial.println(istTopf3);    

  //bei Bedarf pumpen
  if(istTopf1 > sollTopf1) 
    {
      digitalWrite(pumpeTopf1Pin, HIGH);
      Serial.println("Topf1 zu trocken!!!"   );
      delay(Pumpzeit);
      digitalWrite(pumpeTopf1Pin, LOW);
    } 
  else
    {
      Serial.println("Topf1 ist ok!"); 
    }
    
  if(istTopf2 > sollTopf2) 
    {
      digitalWrite(pumpeTopf2Pin, HIGH);
      Serial.println("Topf2 zu trocken!!!"   );
      delay(Pumpzeit);
      digitalWrite(pumpeTopf2Pin, LOW);
    } 
  else
    {
      Serial.println("Topf2 ist ok!"); 
    }

  //if(istTopf3 > sollTopf3) 
    //{
      //digitalWrite(pumpeTopf3Pin, HIGH);
      //Serial.println("Topf3 zu trocken!!!"   );
      //delay(Pumpzeit);
      //digitalWrite(pumpeTopf3Pin, LOW);
    //} 
  //else
    //{
      //Serial.println("Topf3 ist ok!"); 
    //}
    
delay(Wartezeit);
}
