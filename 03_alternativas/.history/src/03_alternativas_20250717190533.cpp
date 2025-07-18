/*
PROGRAMACIÓN ESTRUCTURADA
-------------------------
Secuencia
Alternativa
Repetición
*/

int nota = 7;

void setup() {
  // operando operador operando
  // OR ->  ||
  // AND -> &&
  // NOT -> !
  // 
  Serial.begin(115200);
  delay(500);

  if(nota < 5){
    Serial.println("Suspenso.");
  }
  else{
    if(nota < 7){
      Serial.println("Aprobado.");
    }
    else{
      if(nota < 9 ){
        Serial.println("Notable.");
      }
      else{
        Serial.println("Sobresaliente.");
      }
    }
  }


}

void loop() {
  // put your main code here, to run repeatedly:
/*
  if(Serial.available() > 0)
  {
    edad = Serial.read();
    
  }

  if(edad >= 18){
    // Si se cumple
    Serial.println("La persona es mayor de edad");
      
  }
  else{
    // Si no se cumple 
    Serial.println("La persona es menor de edad");
  }
  delay (10000);
  */
}
