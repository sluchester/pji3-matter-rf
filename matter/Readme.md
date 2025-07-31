# Aprendizados
- Protocolo Matter só funciona e integra mesmo com o QRCode matter, que permite ao protocolo setar as configurações e segurança para poder se comunicar.
- Para poder ser usado com aplicativos de integração (Smasrt Things, Google Home, etc...), só é possível mediante a atuadores,como Alexa, para abrir o hub de ações manuais.

# Testes 

## Teste inicial usando ESP Zerocode
- Playlist de vídeos da ESP 32 salva na biblioteca do youtube
- Acesso ao zerocode: keep.
- Acessado o link: https://zerocode.espressif.com/home/new-config/ZRKMYMBRBOH7GPVQKXG5JZ/test-product.
- Conectar a ESP 32 e selecionar o tipo de módulo (a plataforma web irá reconhecer a porta serial conectada; se não reconhecer, provavelmente é sua ESP).
- Seguir o passo a passo descrito no site que está bem explicado.
    - Há vários modos de teste para se usar o matter.
    - Por exemplo: usei um circuito PWM para acender e apagar um LED. Apenas tive que colocar o resistor e o LED na porta desejada. Depois foram configurados o pulso do PWM e a porta em que ele seria aplicado.
- Então basta apenas seguir o passo a passo de enviar o código para a ESP e escanear o código QRCode do matter gerado na própria interface.

## Links
- [Ferramenta ESPLaunchpad.](https://github.com/espressif/esp-matter)
- [Github espressif.](https://github.com/espressif/esp-matter)
- [Github matter](https://github.com/project-chip/connectedhomeip)
- [ESPRESSIF com links, SDK e explicações](https://www.espressif.com/en/solutions/device-connectivity/esp-matter-solution)
- [Developing with Matter SDK](https://docs.espressif.com/projects/esp-matter/en/latest/esp32/developing.html)