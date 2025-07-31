/*#include <Arduino.h>
#include <SPI.h>
#include <ELECHOUSE_CC1101_SRC_DRV.h>

#define PACKET_SIZE 30

// Pinos SPI da ESP32-WROOM-32
#define PIN_SCK   18  // SPI Clock
#define PIN_MISO  19  // SPI MISO
#define PIN_MOSI  23  // SPI MOSI
#define PIN_CS    15   // Chip Select (pode trocar, ex: 15)

// Frequência do controle RF
#define FREQ_MHZ  433.42

void setup() {
  Serial.begin(9600);
  delay(1000);

  Serial.println("Iniciando CC1101...");

  // Inicializa o SPI manualmente
  SPI.begin(PIN_SCK, PIN_MISO, PIN_MOSI, PIN_CS);
  SPI.beginTransaction(SPISettings(1000000, MSBFIRST, SPI_MODE0)); // 1 MHz

  // Informa os pinos SPI para a biblioteca
  ELECHOUSE_cc1101.setSpiPin(PIN_SCK, PIN_MISO, PIN_MOSI, PIN_CS);

  // Tenta detectar o CC1101
  if (ELECHOUSE_cc1101.getCC1101()) {
    Serial.println("CC1101 detectado!");

    // Inicialização do módulo
    ELECHOUSE_cc1101.Init();
    ELECHOUSE_cc1101.setMHZ(FREQ_MHZ);
    ELECHOUSE_cc1101.SetRx();  // Modo recepção
  } else {
    Serial.println("Erro: CC1101 não detectado!");
    while (true); // trava o código
  }
}

void loop() {
  if (ELECHOUSE_cc1101.CheckRxFifo(1)) {
    byte rxBuffer[PACKET_SIZE] = {0};
    ELECHOUSE_cc1101.ReceiveData(rxBuffer);

    Serial.print("Pacote recebido: ");
    for (int i = 0; i < PACKET_SIZE; i++) {
      Serial.print(rxBuffer[i], HEX);
      Serial.print(" ");
    }
    Serial.println();

    ELECHOUSE_cc1101.SetRx();  // volta ao modo recepção
  }

  delay(500);
}*/