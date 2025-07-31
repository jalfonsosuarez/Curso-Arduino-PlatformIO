#include <Arduino.h>

int pinBuzzer = 15;

// Definición de las notas musicales con prefijo para evitar conflictos
int N_E5 = 659;
int N_D5s = 622;
int N_F5 = 698;
int N_G5s = 830;
int N_A5 = 880;
int N_A4s = 466; // A#4
int N_B4 = 494;
int N_C5 = 523;
int N_D5 = 587;
int N_E4 = 330;
int N_C4 = 262;
int N_A4 = 440;

// Duraciones ajustadas para un ritmo más lento
int negra = 600;
int corchea = negra / 2;
int semicorchea = corchea / 2;
int blanca = negra * 2;
int blancaLarga = negra * 3;

void nota(int frecuencia, int duracion)
{
  tone(pinBuzzer, frecuencia, duracion);
  delay(duracion);
  noTone(pinBuzzer);
  delay(semicorchea); // Pequeña pausa entre notas
}

void setup()
{
  paraElisa();
}

void loop()
{
}

void paraElisa()
{
  // Primera frase
  nota(N_E5, semicorchea);
  nota(N_D5s, semicorchea);
  nota(N_E5, semicorchea);
  nota(N_D5s, semicorchea);
  nota(N_E5, semicorchea);
  nota(N_B4, semicorchea);
  nota(N_D5, semicorchea);
  nota(N_C5, semicorchea);
  nota(N_A4, negra);

  nota(N_C4, semicorchea);
  nota(N_E4, semicorchea);
  nota(N_A4, negra);
  nota(N_A4s, negra);

  nota(N_E4, semicorchea);
  nota(N_G5s, semicorchea);
  nota(N_B4, negra);
  nota(N_C5, negra);

  delay(400); // Pausa para separar frases

  // Segunda frase (repetición con pequeñas variaciones)
  nota(N_E5, semicorchea);
  nota(N_D5s, semicorchea);
  nota(N_E5, semicorchea);
  nota(N_D5s, semicorchea);
  nota(N_E5, semicorchea);
  nota(N_B4, semicorchea);
  nota(N_D5, semicorchea);
  nota(N_C5, semicorchea);
  nota(N_A4, negra);

  nota(N_C4, semicorchea);
  nota(N_E4, semicorchea);
  nota(N_A4, negra);
  nota(N_A4s, negra);

  nota(N_E4, semicorchea);
  nota(N_C5, semicorchea);
  nota(N_B4, negra);
  nota(N_A4, negra);

  delay(400); // Pausa larga

  // Nueva sección
  nota(N_B4, corchea);
  nota(N_C5, corchea);
  nota(N_D5, corchea);
  nota(N_E5, negra);
  nota(N_D5, corchea);
  nota(N_C5, corchea);
  nota(N_B4, corchea);
  nota(N_A4, negra);

  nota(N_A4s, corchea);
  nota(N_B4, corchea);
  nota(N_C5, corchea);
  nota(N_D5, blanca);

  delay(500);

  // Retorno a la primera frase
  nota(N_E5, semicorchea);
  nota(N_D5s, semicorchea);
  nota(N_E5, semicorchea);
  nota(N_D5s, semicorchea);
  nota(N_E5, semicorchea);
  nota(N_B4, semicorchea);
  nota(N_D5, semicorchea);
  nota(N_C5, semicorchea);
  nota(N_A4, negra);

  nota(N_C4, semicorchea);
  nota(N_E4, semicorchea);
  nota(N_A4, negra);
  nota(N_A4s, negra);

  delay(1000); // Pausa larga antes de repetir o terminar
}
