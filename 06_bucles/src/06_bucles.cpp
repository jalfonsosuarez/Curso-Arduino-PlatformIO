#include <Arduino.h>

void setup() {
  Serial.begin(115200);
  delay(500);

// Bucles controlados por un contador
/*
for(int i = 0; i < 10; i++){
  Serial.println("Número: " + String(i));
  //Serial.println(i);

}
*/

/*
for(int i = 0; i < 100; i += 2){
  Serial.println("Número: " + String(i));
}
*/

/*
for (int i = 100; i > 0; i--){
  Serial.println("Número: " + String(i));
}
*/

// Bucles en dos dimensiones
/*
String salida = "";

for(int fila = 0; fila < 10; fila ++ ){
  for(int col = 0; col < 10; col ++){
    //Serial.print(String(fila) + ":" + String(col) + "\t");
    salida += String(fila) + ":" + String(col) + "\t";
  }
  //Serial.print("\n");
  salida += "\n";
}

Serial.print(salida);
*/

// Bucles infinitos
int limite = 10;
int contador = 0;
for(;;){
  if (contador == limite){
    break;
  }
  Serial.print("Infinito: ");
  Serial.println(contador);
  contador ++;
}

// Bucles while
contador = 0;
while (contador < limite){
  Serial.print("While: ");
  Serial.println(contador);
  contador ++;
}



}

void loop() {
  // put your main code here, to run repeatedly:


}
