#define ROJO 15
#define VERDE 13
#define AZUL 12

void setup() {
  // put your setup code here, to run once:
  pinMode(ROJO, OUTPUT);
  pinMode(VERDE, OUTPUT);
  pinMode(AZUL, OUTPUT);
}

void loop() {
  /*
  // ROJO
  digitalWrite(ROJO, LOW);
  digitalWrite(VERDE, HIGH);
  digitalWrite(AZUL, HIGH);
  delay(500);

  // VERDE
  digitalWrite(ROJO, HIGH);
  digitalWrite(VERDE, LOW);
  digitalWrite(AZUL, HIGH);
  delay(500);

  // AZUL  
  digitalWrite(ROJO, HIGH);
  digitalWrite(VERDE, HIGH);
  digitalWrite(AZUL, LOW);
  delay(500);

  // MAGENTA
  digitalWrite(ROJO, LOW);
  digitalWrite(VERDE, HIGH);
  digitalWrite(AZUL, LOW);
  delay(500);

  // CIAN
  digitalWrite(ROJO, HIGH);
  digitalWrite(VERDE, LOW);
  digitalWrite(AZUL, LOW);
  delay(500);

  // AMARILLO
  digitalWrite(ROJO, LOW);
  digitalWrite(VERDE, LOW);
  digitalWrite(AZUL, HIGH);
  delay(500);

  // BLANCO
  digitalWrite(ROJO, LOW);
  digitalWrite(VERDE, LOW);
  digitalWrite(AZUL, LOW);
  delay(500);
  */

  int r = 0;
  int g = 0;
  int b = 0;

  for(;;){
    r = random(0, 255);
    g = random(0, 255);
    b = random(0, 255);

    analogWrite(ROJO, r);
    analogWrite(VERDE, g); 
    analogWrite(AZUL, b);

    delay(1000);
  }

}
