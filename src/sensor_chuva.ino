const int pinoSensor = A0; // Sensor de chuva no A0
const int pinoServo = 9;   // Fio de sinal do servo no pino 9

int w; // atual 
int b; // anterior 

void moverServo(int angulo) {
  int pulso = map(angulo, 0, 180, 500, 2400); 
  for (int i = 0; i < 30; i++) { 
    digitalWrite(pinoServo, HIGH);
    delayMicroseconds(pulso);
    digitalWrite(pinoServo, LOW);
    delay(20); 
  }
}

void setup() {
  Serial.begin(9600);
  
  pinMode(pinoSensor, INPUT);
  pinMode(pinoServo, OUTPUT);
  
  moverServo(90); 
  
  w = digitalRead(pinoSensor); 
} // <--- Chave corrigida bem aqui!

void loop() {
  b = w;                   
  w = digitalRead(pinoSensor); 

  if (w == LOW && b == HIGH) {
    Serial.println("Chuva detectada! Fechando varal.");
    moverServo(0); 
  }
  else if (w == HIGH && b == LOW) {
    Serial.println("A chuva parou! Abrindo varal.");
    moverServo(90); 
  }

  delay(100);
}