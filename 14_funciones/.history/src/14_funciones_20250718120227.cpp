#include <14_funciones.h>

// Variables globales
int valores[] = {1, 4, 5, 68, 25};

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

  int acumulador = 0;
  for (int i = 0; i < 5; i++)
  {
    acumulador = sumar(acumulador, valores[i]);
  }
  Serial.println("La suma acumulada es: " + String(acumulador));
  delay(200);

  char cadena[] = "Esto es una cadena";
  int lenCadena = cuentaCaracteres(cadena);
  Serial.println("La cadena tiene " + String(lenCadena) + " caracteres.");
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

int sumar(int s1, int s2)
{
  return s1 + s2;
}

int cuentaCaracteres(char cadena[])
{
  int cuenta = 0;
  while (cadena[cuenta] != '\0')
  {
    cuenta++;
  }

  return cuenta;
}

char *cadenaReversa(char *cadena)
{
  int longCadena = cuentaCaracteres(cadena);
  char inversa[longCadena];
  int j = 0;
  for (int i = longCadena; i >= 0; i--)
  {
    inversa[i] = cadena[j];
    j++;
  }

  return inversa;
}
