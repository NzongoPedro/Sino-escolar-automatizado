#include <Ds1302.h>

#define CLKpin 4
#define DATpin 5
#define RSTpin 6
#define BUZZER 7
#define RELE 8  // Pino do relé

Ds1302 rtc(RSTpin, CLKpin, DATpin);

// Função para tocar o buzzer e acionar o relé simultaneamente

void acionarAlarme(int vezes, int duracao, int intervalo) {
  for (int i = 0; i < vezes; i++) {
    digitalWrite(RELE, HIGH);  // Liga o sino
    tone(BUZZER, 1000);        // Aciona o buzzer
    delay(duracao);

    digitalWrite(RELE, LOW);   // Desliga o sino
    noTone(BUZZER);            // Desliga o buzzer
    delay(intervalo);
  }
}

void setup() {
  Serial.begin(9600);
  rtc.init();
  pinMode(BUZZER, OUTPUT);
  pinMode(RELE, OUTPUT);

  Serial.println("Lendo a hora armazenada...");
  Ds1302::DateTime now;
  rtc.getDateTime(&now);

  Serial.print("Hora armazenada: ");
  Serial.print(now.hour);
  Serial.print(":");
  Serial.print(now.minute);
  Serial.print(":");
  Serial.println(now.second);
}

void loop() {
  Ds1302::DateTime now;
  rtc.getDateTime(&now);

  Serial.print("Hora Atual: ");
  Serial.print(now.hour);
  Serial.print(":");
  Serial.print(now.minute);
  Serial.print(":");
  Serial.println(now.second);

  // Verifica se está dentro do horário permitido (07h00 - 17h59) e em um dia útil

  if (now.hour < 7 || now.hour >= 18 || now.dow == 7 || now.dow == 1) {
    Serial.println("Fora do horário ou fim de semana. Alarme desativado.");
    delay(1000);
    return;
  }
  

  // Turno da manhã
  if (now.hour == 8 && now.minute == 0 && now.second == 0) {
    acionarAlarme(1, 15000, 0);
  }

  // RECREIO
  if (now.hour == 10 && now.minute == 0 && now.second == 0) {
    acionarAlarme(1, 500, 500);
    acionarAlarme(1, 500, 500);
    acionarAlarme(1, 10000, 0);
  }

  // Fim do recreio
  if (now.hour == 10 && now.minute == 15 && now.second == 0) {
    acionarAlarme(1, 30000, 0);
  }

  // Saida
  if (now.hour == 12 && now.minute == 0 && now.second == 0) {
    acionarAlarme(1, 500, 500);
    acionarAlarme(1, 500, 500);
    acionarAlarme(1, 10000, 500);
  }

  /*
     ###########################################################################################
     ###########################################################################################
  */

  // Turno da tarde
  if (now.hour == 13 && now.minute == 0 && now.second == 0) {
    acionarAlarme(1, 15000, 0);
  }

  // Primeiro tempo
  if (now.hour == 13 && now.minute == 45 && now.second == 0) {
    acionarAlarme(1, 2000, 1000);
  }

  // Segundo tempo
  if (now.hour == 14 && now.minute == 30 && now.second == 0) {
    acionarAlarme(2, 2000, 2000);
  }

  // Terceiro tempo (INTERVALO MAIOR)
  if (now.hour == 0 && now.minute == 19  && now.second == 50) {
    acionarAlarme(1, 500, 500);
    acionarAlarme(1, 500, 500);
    acionarAlarme(1, 10000, 0);
  }

  // Fim do Intervalo
  if (now.hour == 15 && now.minute == 30 && now.second == 0) {
    acionarAlarme(1, 15000, 0);
  }

  // Quarto tempo
  if (now.hour == 16 && now.minute == 15 && now.second == 0) {
    acionarAlarme(1, 500, 500);
    acionarAlarme(1, 500, 500);
    acionarAlarme(1, 500, 500);
    acionarAlarme(1, 2000, 500);
  }

  // Quinto tempo
  if (now.hour == 17 && now.minute == 0 && now.second == 0) {
    acionarAlarme(1, 500, 500);
    acionarAlarme(1, 500, 500);
    acionarAlarme(1, 500, 500);
    acionarAlarme(1, 500, 500);
    acionarAlarme(1, 3000, 500);
  }

  // Saida
  if (now.hour == 17 && now.minute == 20 && now.second == 0) {
    acionarAlarme(1, 500, 500);
    acionarAlarme(1, 500, 500);
    acionarAlarme(1, 500, 500);
    acionarAlarme(1, 500, 500);
    acionarAlarme(1, 500, 500);
    acionarAlarme(1, 15000, 500);
  }

  delay(500); // Aguarda um segundo antes de verificar novamente
}
