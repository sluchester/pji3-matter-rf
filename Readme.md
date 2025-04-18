# Objetivo

Desenvolver um sistema microcontrolado acessível capaz de integrar circuitos atuadores de radiofrequência, como por exemplo persianas automá
ticas. Algo voltado para o ramo de Internet of Things (IoT).

Além disso, ele irá utilizar o protocolo Matter (desenvolvido pelas maiores empresas de tecnologia, especificamente para o ramo de IoT) para realizar a comunicação com o dispositivo microcontrolador (ESP 32).

# Como conectar a placa

Ao ligar a ESP32, o programa interno irá gerar uma rede para se conectar chamada de "ESPSomfy RTS". Após conectar, abrir o navegador do seu celular e ir para o endereço http://192.168.4.1 (página principal). Clique no ícone de engrenagem no canto superior direito para abrir a tela de configuração geral.

## Opção System
Primeiramente, na tela System, na aba Options, defina a Time/Zone. Basta tocar em cima da opção que irá aparecer e setar para o seu local (como estamos no Brasil é ETC/GMT-3).

## Opção Network
Na tela Network, ao lado de System, há a opção "Adapter". Nela você pode escolher a rede ao qual se conectar. Basta clicar no botão azul "Scan", selecionar a sua rede local, colocar a senha, e tocar em "Save Adapter".

## Opção Radio
Na tela Radio, opção Transceiver, podemos setar o transceptor. Inicialmente, o ESPSomfyRTS iniciará com o transceptor desabilitado. 

Agora que a rede está conectada, você precisará garantir que os mapeamentos de pinos correspondam à fiação usada ao montar seu dispositivo (neste caso, os pinos que aparecem já setados são os corretos, então você não precisa mudar nada).

Seguimos então para selecionar o protocolo e o comprimento de bits usados ​​para seus motores. Se você não sabe que tipo de rádio para motor você possui, provavelmente é um protocolo RTS com um motor de 56 bits. Depois, é possível setar um protocolo e taxa de bits diferentes para cada motor. 

Uma ferramenta que pode ajudar nas configurações do protocolo é a opção de "Log", ao lado de Transceiver. Nela é possível ver quantos bits estão sendo enviados e qual tipo de protocolo está sendo usado. Ao visualizar a coluna Bits, você pode ver qual sinal de entrada daquele controle remoto está usando. Por exemplo, um sinal RTS de 56 bits será 56-S e um sinal RTS de 80 bits será 80-S. Se o protocolo for RTW, o -S será substituído por -W e, se o protocolo for RTV, o -S será substituído por -V.