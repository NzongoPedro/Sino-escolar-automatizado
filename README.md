# Documentação do Projeto: Sino e Buzzer Escolar



## 1. Introdução

O projeto visa automatizar a sinalização dos horários de entrada, intervalos e saída dos turnos matutino e vespertino, garantindo pontualidade e organização dentro da instituição de ensino.

## 2. Componentes Utilizados

### 2.1. Hardware

- Microcontrolador: Arduino Uno
- Módulo RTC (Real Time Clock): DS1302
- Buzzer Piezoelétrico: 5V
- Módulo Relé: 5V para acionar o sino principal
- Sino Eletrônico: Ligado ao relé
- Resistores e Jumpers para conexão dos componentes
- Fonte de Alimentação: 5V DC para o Arduino e 12V para o sino

### 2.2. Software

- IDE Arduino para programação
- Linguagem C++ (Arduino)
- Biblioteca Ds1302.h para comunicação com o RTC

## 3. Esquemático de Ligação

### Ligação dos pinos:

- DS1302 RTC:
  - CLK -> Pino 4 do Arduino
  - DAT -> Pino 5 do Arduino
  - RST -> Pino 6 do Arduino
  - VCC e GND -> 5V e GND do Arduino
- Buzzer:
  - Terminal positivo -> Pino 7 do Arduino
  - Terminal negativo -> GND
- Relé:
  - Sinal de controle -> Pino 8 do Arduino
  - VCC e GND -> 5V e GND do Arduino
  - Contatos do relé conectados ao sino

## 4. Lógica de Funcionamento

O sistema verifica continuamente o horário atual através do módulo RTC. Quando um horário de toque é atingido, o buzzer e o sino são ativados simultaneamente conforme as regras:

### 4.1. Turno da Manhã

- 08:00 - Toque de 10 segundos
- 10:00 (Início do Recreio) - Três toques (1s, 1s, 10s)
- 10:15 (Fim do Recreio) - Toque de 30 segundos
- 12:00 (Saída) - Toque de 20 segundos

### 4.2. Turno da Tarde

- 13:00 - Toque de 15 segundos
- 13:45 (Fim 1º tempo) - 5 toques de 1s
- 14:30 (Fim 2º tempo) - 2 toques de 2s
- 15:15 (Início do Recreio) - Três toques (2s, 2s, 10s)
- 15:30 (Fim do Recreio) - Toque de 15 segundos
- 16:15 (Fim 4º tempo) - 4 toques de 1s
- 17:00 (Fim 5º tempo) - 5 toques de 1s
- 17:20 (Saída) - Toque de 30 segundos

### 4.3. Regras Gerais

- O alarme **não toca antes das 07:00 e após as 17:59**.
- Aos **sábados e domingos, o sistema é desativado**.

## 5. Programação do Arduino

A lógica do código consiste em:

1. Inicializar os componentes (RTC, buzzer, relé).
2. Ler a hora atual do RTC.
3. Verificar se o horário corresponde a um momento de acionamento.
4. Ativar o buzzer e o relé de acordo com o padrão especificado.
5. Aguardar o próximo ciclo.

## 6. Configuração e Uso

### 6.1. Como Carregar o Código

1. Instale a **IDE do Arduino** e a biblioteca **Ds1302.h**.
2. Conecte o Arduino via USB e selecione a porta correta.
3. Carregue o código para o microcontrolador.

### 6.2. Ajuste da Hora

Se o RTC não estiver sincronizado, configure a hora corretamente antes de iniciar o sistema.

### 6.3. Instalação Física

- Posicione o Arduino e o RTC em um local protegido.
- Certifique-se de que o buzzer e o sino estejam audíveis para toda a escola.
- O relé deve estar corretamente isolado para evitar curto-circuitos.

## 7. Manutenção e Solução de Problemas

| Problema                      | Solução                                             |
| ----------------------------- | --------------------------------------------------- |
| O sistema não liga            | Verifique as conexões elétricas e a alimentação     |
| Horário está incorreto        | Reconfigure o RTC manualmente                       |
| O buzzer toca fora do horário | Confirme a lógica do programa e os limites de tempo |
| O sino não toca               | Verifique a ligação do relé e sua alimentação       |

## 8. Conclusão

Este projeto fornece uma solução eficiente para a gestão dos sinais sonoros em uma escola, garantindo precisão nos horários e maior organização. Com ajustes simples, pode ser adaptado para outras instituições ou empresas que necessitem de sinalização programada.
