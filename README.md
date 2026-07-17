# 🏠 Maquete de Casa Inteligente Automatizada

Este projeto consiste no desenvolvimento e automação de uma maquete residencial utilizando a plataforma Arduino. O sistema integra múltiplos sensores e atuadores para gerenciar de forma inteligente um varal automatizado, um sensor de aproximação para garagem, iluminação pública externa multifuncional e um sistema de campainha.

## 🛠️ Funcionalidades do Sistema

* **Varal Automatizado (Proteção contra Chuva):** Utiliza um sensor de chuva conectado à porta analógica. Ao detectar as primeiras gotas (leitura abaixo do limiar), um servo motor SG90 é acionado para recolher o varal para a área coberta (90°).
* **Sensor de Vaga/Aproximação da Garagem:** Um sensor ultrassônico mede a distância de um veículo. Se o carro estiver a menos de 10 cm, um LED de alerta acende na garagem.
* **Iluminação Pública Inteligente:** Um sensor de luz LDR monitora a luminosidade ambiente. Ao escurecer, o sistema aciona simultaneamente 4 postes de iluminação externa.
* **Campainha Residencial:** Um botão (campainha) integrado que aciona instantaneamente um aviso sonoro por meio de um buzzer ativo.

## 🔌 Esquema de Conexão dos Pinos

| Componente | Tipo de Pino | Pino Arduino | Observação |
| :--- | :--- | :--- | :--- |
| **Sensor de Chuva** | Analógico | `A0` | Monitoramento analógico do nível de chuva |
| **Sensor de Luz (LDR)** | Analógico | `A1` | Ligado com divisor de tensão |
| **Servo Motor (SG90)** | Digital (PWM) | `9` | Controle do braço mecânico do varal |
| **Buzzer Ativo** | Digital | `10` | Saída sonora da campainha |
| **Pino Echo (Ultrassônico)**| Digital | `11` | Entrada do pulso do sensor de distância |
| **Pino Trig (Ultrassônico)**| Digital | `12` | Saída do pulso do sensor de distância |
| **LED Indicador Garagem**  | Digital | `8` | Alerta de proximidade do carro |
| **Poste de Luz 1** | Digital | `3` | Saída para o LED do Poste 1 |
| **Poste de Luz 2** | Digital | `4` | Saída para o LED do Poste 2 |
| **Poste de Luz 3** | Digital | `5` | Saída para o LED do Poste 3 |
| **Poste de Luz 4** | Digital | `6` | Saída para o LED do Poste 4 |
| **Botão da Campainha** | Digital | `7` | Entrada do sinal do botão |

## 🚀 Como Executar o Projeto

1. Monte o circuito seguindo a tabela de pinos acima.
2. Baixe e instale a [Arduino IDE](https://www.arduino.cc/en/software).
3. Abra o arquivo correspondente ao código fonte em `src/main/main.ino`.
4. Conecte seu Arduino ao computador via cabo USB.
5. Selecione a placa correta (ex: Arduino Uno) e a porta COM em **Ferramentas**.
6. Clique em **Carregar (Upload)** para gravar o código na placa.
7. Abra o **Serial Monitor** (9600 bps) para acompanhar as leituras em tempo real.
