#include <Arduino.h>

int sumar(int s1, int s2)
{
  return s1 + s2;
}

void setup()
{
  // put your setup code here, to run once:
  Serial.begin(115200);
}

void loop()
{
  // put your main code here, to run repeatedly:
  int s1 = 45;
  int s2 = 5;
  Serial.println("La suma de " + String(s1) + " y " + String(s2) + " es " + String(sumar(s1, s2)));
}

// FUNCIONES

/*
tipo_retorno funcion(tipo param1, tipo param2, ....) {

  cuerpo de la función
  .
  .
  .

  return valor_que_retorna;
}
*/
