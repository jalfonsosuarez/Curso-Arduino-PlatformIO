
#define ROJO 13
#define VERDE 12
#define AZUL 14

#define POTROJO 15
#define POTVERDE 2
#define POTAZUL 4

void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);

  pinMode(ROJO, OUTPUT);
  pinMode(VERDE, OUTPUT);
  pinMode(AZUL, OUTPUT);

  pinMode(POTROJO, INPUT);
  pinMode(POTVERDE, INPUT);
  pinMode(POTAZUL, INPUT);


}

void loop() {
  // put your main code here, to run repeatedly:

  int valueRojo = 255 - (analogRead(POTROJO) / 16);
  int valueVerde = 255 - (analogRead(POTVERDE) / 16);
  int valueAzul = 255 - (analogRead(POTAZUL) / 16);

  Serial.println( "R: " + String(valueRojo) + ", V: " +  String(valueVerde) + ", A: " + String(valueAzul));

  analogWrite(ROJO, valueRojo);
  analogWrite(VERDE, valueVerde);
  analogWrite(AZUL, valueAzul);

}
