#define LED_AZUL 15
#define LED_ROJO 13

void setup() {
  pinMode(LED_AZUL, OUTPUT);
  pinMode(LED_ROJO, OUTPUT);

}

void loop() {
  /*
  digitalWrite(LED_AZUL,HIGH);
  delay(1000);
  digitalWrite(LED_AZUL, LOW);
  delay(1000);
  */
  for(int i = 0; i <= 255; i++){
    analogWrite(LED_AZUL, i);
    analogWrite(LED_ROJO, 255-i);
    delay(5);
  }
  delay(1000);

  for(int i = 255; i >=0; i--){
    analogWrite(LED_AZUL, i);
    analogWrite(LED_ROJO, 255-i);
    delay(5);   
  }
  delay(1000);


}
