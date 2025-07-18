#define LED 2
#define ZUMBADOR 15

void setup() {
  Serial.begin(115200);
  pinMode(LED, OUTPUT);
  pinMode(ZUMBADOR, OUTPUT);

}

int duracion = 20;
int silencio = 200;
void loop() {
  duracion = 20;
  for(int i = 0; i < 10; i++){
    digitalWrite(LED, HIGH);
    digitalWrite(ZUMBADOR, HIGH);
    delay(duracion);
    duracion = duracion + i * 10;
    digitalWrite(LED, LOW);
    digitalWrite(ZUMBADOR, LOW);
    delay(silencio);
    Serial.println(duracion);
  }

}
