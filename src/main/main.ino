#include <Servo.h>

const int pinoSensorChuva = A0;
const int pinoServo = 9;
const int LIMIAR_CHUVA = 500;
const int POS_FORA = 0;
const int POS_DENTRO = 90;

Servo meuServo;
int posicaoAtual = POS_FORA;

const int pinoTrig = 12; 
const int pinoEcho = 11; 
const int pinoLED = 8;   
const float DISTANCIA_MAX_ALERTA = 10.0; 

const int pinoLDR = A1;        
const int limiarLuz = 850;    
const int poste1 = 3;         
const int poste2 = 4;
const int poste3 = 5;
const int poste4 = 6;

const int pinoCampainha = 7;  
const int pinoBuzzer = 10;    

void setup() {
  Serial.begin(9600);
  
  meuServo.attach(pinoServo);
  meuServo.write(posicaoAtual);
  
  pinMode(pinoTrig, OUTPUT);
  pinMode(pinoEcho, INPUT);
  pinMode(pinoLED, OUTPUT);
  digitalWrite(pinoTrig, LOW);
  digitalWrite(pinoLED, LOW);

  pinMode(pinoLDR, INPUT);
  pinMode(poste1, OUTPUT);
  pinMode(poste2, OUTPUT);
  pinMode(poste3, OUTPUT);
  pinMode(poste4, OUTPUT);

  pinMode(pinoCampainha, INPUT);
  pinMode(pinoBuzzer, OUTPUT);
  digitalWrite(pinoBuzzer, LOW);
}

void loop() {
  int leitura = analogRead(pinoSensorChuva);
  Serial.print("Leitura Chuva: ");
  Serial.print(leitura);

  bool estaChovendo = (leitura < LIMIAR_CHUVA);
  int novaPosicao = estaChovendo ? POS_DENTRO : POS_FORA;

  if (novaPosicao != posicaoAtual) {
    meuServo.write(novaPosicao);
    posicaoAtual = novaPosicao;
    delay(300);
  }

  digitalWrite(pinoTrig, HIGH);
  delayMicroseconds(10);
  digitalWrite(pinoTrig, LOW);
  
  long duracao = pulseIn(pinoEcho, HIGH); 
  float distancia = (duracao * 0.0343) / 2;
  
  Serial.print(" | Distancia Carro: ");
  Serial.print(distancia);
  Serial.print(" cm");
  
  if (distancia > 0 && distancia <= DISTANCIA_MAX_ALERTA) {
    digitalWrite(pinoLED, HIGH); 
  } else {
    digitalWrite(pinoLED, LOW);  
  }

  int valorLDR = analogRead(pinoLDR);
  Serial.print(" | Luz LDR: ");
  Serial.print(valorLDR);

  if (valorLDR > limiarLuz) { 
    digitalWrite(poste1, HIGH); 
    digitalWrite(poste2, HIGH);
    digitalWrite(poste3, HIGH);
    digitalWrite(poste4, HIGH);
  } else {
    digitalWrite(poste1, LOW);  
    digitalWrite(poste2, LOW);
    digitalWrite(poste3, LOW);
    digitalWrite(poste4, LOW);
  }

  int estadoCampainha = digitalRead(pinoCampainha);
  
  if (estadoCampainha == HIGH) { 
    digitalWrite(pinoBuzzer, HIGH);  
    Serial.println(" | 🔔 Campainha Tocando!");
  } 
  else { 
    digitalWrite(pinoBuzzer, LOW);   
    Serial.println(" | Campainha em silêncio.");
  }
  
  delay(100); 
}
