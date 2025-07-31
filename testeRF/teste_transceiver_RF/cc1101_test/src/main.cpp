#include <Arduino.h>
#include <SPI.h>
#include <ELECHOUSE_CC1101_SRC_DRV.h>

const int PACKET_SIZE = 400; // tamanho esperado do pacote

void setup() {
  Serial.begin(9600);
  delay(1000);

  Serial.println(">>> Iniciando setup");

  // ELECHOUSE_cc1101.setGDO(13,12);  // GDO0, GDO2 
  // SPI: SCK=18, MISO=19, MOSI=23, CS=15
  // SPI.begin(18, 19, 23, 15);  // CLK, MISO, MOSI, CS
  // SPI.beginTransaction(SPISettings(1000000, MSBFIRST, SPI_MODE0)); // 1 MHz
  ELECHOUSE_cc1101.setSpiPin(18, 19, 23, 15);

  Serial.println(">>> SPI configurado");

  if (ELECHOUSE_cc1101.getCC1101()) {
    Serial.println("CC1101 detectado.");
  } else {
    Serial.println("Erro: CC1101 não detectado!");
    while (!ELECHOUSE_cc1101.getCC1101()){
      Serial.println("Tryingg");
      // ELECHOUSE_cc1101.getCC1101();
      delay(3000);
    }
    Serial.println("CC1101 detectado.");
  }

  ELECHOUSE_cc1101.Init();
  ELECHOUSE_cc1101.setMHZ(433.42);
  ELECHOUSE_cc1101.SetRx();

  Serial.println("Pronto para receber.");
}


void loop() {
  Serial.println("antes do if");
  if (ELECHOUSE_cc1101.CheckRxFifo(1000)) {
    Serial.println("depois do if");
  
    byte rxBuffer[PACKET_SIZE] = {0};
    Serial.println("criou o pacote");

    Serial.println("---------TAMANHO DO PACOTE RECEBIDO-------------");
    byte size_data = ELECHOUSE_cc1101.ReceiveData(rxBuffer);
    Serial.println(size_data);
    Serial.println("-------------------------------------------------");

    Serial.println("Pacote recebido: ");
    for (int i = 0; i < size_data; i++) {
      Serial.print(rxBuffer[i], HEX);
      Serial.print(" ");
      ELECHOUSE_cc1101.SetRx(); // volta pro modo recepção
    }
    Serial.println();

    // ELECHOUSE_cc1101.SetRx(); // volta pro modo recepção
  }

  Serial.println();
  delay(2000);
  Serial.println("Loop de teste");
}