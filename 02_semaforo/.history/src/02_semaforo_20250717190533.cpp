#define ROJO  12
#define VERDE 13
#define AZUL  14

void setup() {
  Serial.begin(115200);
  pinMode(ROJO, OUTPUT);
  pinMode(VERDE, OUTPUT);
  pinMode(AZUL, OUTPUT);
  

}

void loop() {
  // Rojo encendido
  Serial.print("Rojo encendido.\n");
  digitalWrite(ROJO, HIGH);
  digitalWrite(VERDE, LOW);
  digitalWrite(AZUL, LOW);
  delay(500);

  // Verde encendido
  Serial.print("Verde encendido.\n");
  
  digitalWrite(ROJO, LOW);
  digitalWrite(VERDE, HIGH);
  digitalWrite(AZUL, LOW);
  delay(500);

  // Azul encendido
  Serial.print("Azul encendido.\n");
  digitalWrite(ROJO, LOW);
  digitalWrite(VERDE, LOW);
  digitalWrite(AZUL, HIGH);
  delay(500);


}
