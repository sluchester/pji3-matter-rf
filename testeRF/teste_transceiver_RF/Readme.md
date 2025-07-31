## 25/03/2025

Para conseguir algo sólido, e também não perder tempo de desenvolvimento com algo que já esteja pronto, começamos a procurar projetos que já tenham algo implementado.

Links no chat, para futuras consultas.

## 01/04/2025

### ESP32 <-> Somfy RTS (https://github.com/rstrouse/ESPSomfy-RTS)

cc1101 radio module ()
- Frequencies between 433MHz
- ESP 32
- https://produto.mercadolivre.com.br/MLB-3927224549-modulo-sfio-cc1101-csma-antena-transceptor-433mhz-nf-_JM?matt_tool=49601181&matt_word=&matt_source=google&matt_campaign_id=22090354496&matt_ad_group_id=173090612396&matt_match_type=&matt_network=g&matt_device=c&matt_creative=727882733433&matt_keyword=&matt_ad_position=&matt_ad_type=pla&matt_merchant_id=5408881927&matt_product_id=MLB3927224549&matt_product_partition_id=2389865441028&matt_target_id=aud-1966857867496:pla-2389865441028&cq_src=google_ads&cq_cmp=22090354496&cq_net=g&cq_plt=gp&cq_med=pla&gad_source=1
- or try this: E07-M1101D-SMA
- https://www.amazon.com/dp/B072Q7319V?psc=1 (antena EUA,  necessita ver correspondência BR)
- Full code


### ESP32 <-> Somfy RTS Simplest Code (https://www.die-welt.net/2021/06/controlling-somfy-roller-shutters-using-an-esp32-and-esphome/)
- Simplest Code
- Control needed
- Take a deepest dive into the code


### ESP8266 <-> Somfy RTS (https://4x5mg.net/2018/06/10/controlling-somfy-blinds-with-esp8266/)
- ESP8266
- 433.42MHz
- there is code

## Pesquisar:

- protocols RTS, RTW, RTV/L (são apenas mudanças de espectro de frequência para regiões diferentes do globo... ver material ESPSomfy-RTS)

## Rolling Code Somfy-RTS

Informaçoes tiradas [deste link.](https://docs.espressif.com/projects/arduino-esp32/en/latest/tutorials/preferences.html)

Basicamente, uma das bilbiotecas que estão sendo utilizadas é a ```<Preferences.h>```,desenvolvida especificamente para Arduino-ESP32. É a sucessora da biblioteca EEPROM do Arduino. Ela usa uma porção da memória não volátil (NVS) do ESP32 para armazenar dados. Esses dados são retidos durante reinicializações e eventos de queda de energia do sistema. As Preferências funcionam melhor para armazenar muitos valores pequenos, em vez de poucos valores grandes. Se precisar armazenar grandes quantidades de dados, considere usar uma biblioteca de sistema de arquivos como o LitteFS.

A biblioteca Preferências pode ser usada por todas as variantes do ESP32.

No projeto, ao qual está sendo feita a análise do código, há a seguinte codificação:

```C
uint16_t SomfyRemote::getNextRollingCode() {
  pref.begin("ShadeCodes");
  uint16_t code = pref.getUShort(this->m_remotePrefId, 0);
  code++;
  pref.putUShort(this->m_remotePrefId, code);
  pref.end();
  this->p_lastRollingCode(code);
  //Serial.printf("Getting Next Rolling code %d\n", this->lastRollingCode);
  return code;
}
```