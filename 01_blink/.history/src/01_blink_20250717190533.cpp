#define PIN_LED 2
#define PIN_ROJO 12

int contador = 0;

void setup() {
  Serial.begin(115200);
  delay(50);
  Serial.println("Serial encendido");
  pinMode(PIN_LED, OUTPUT);
  pinMode(PIN_ROJO, OUTPUT);

}

void loop() {
  
  digitalWrite(PIN_LED, HIGH);
  digitalWrite(PIN_ROJO, LOW);
  Serial.println("Encendido.");

  contador ++;

  Serial.println(contador);

  delay(500);

  digitalWrite(PIN_LED, LOW);
  digitalWrite(PIN_ROJO, HIGH);
  Serial.println("Apagado.");
  delay(500);

}
