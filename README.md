# 🏠 Maquete de Casa Inteligente Automatizada

Este projeto consiste no desenvolvimento e automação de uma maquete residencial utilizando a plataforma Arduino. O sistema integra múltiplos sensores e atuadores para gerenciar de forma inteligente a segurança contra incêndios, proteção de roupas contra a chuva e eficiência energética através de iluminação automatizada.

---

## 🛠️ Funcionalidades do Sistema

1. **Varal Automatizado (Proteção contra Chuva):** Utiliza o sensor de chuva MH-RD. Ao detectar as primeiras gotas, um servo motor SG90 é acionado imediatamente para recolher a haste do varal para uma área coberta.
2. **Alarme de Incêndio (Segurança Activa):** Um sensor de chama IR monitora o ambiente interno. Caso detecte fogo/fogo iminente, um alarme sonoro (Buzzer ativo) é disparado imediatamente.
3. **Iluminação Interna Inteligente:** Um sensor de presença PIR gerencia o LED interno, acendendo as luzes apenas quando houver movimentação nos cômodos.
4. **Iluminação Pública (Poste Externo):** Um sensor de luz LDR atua como fotocélula, acendendo o LED do poste externo automaticamente assim que o ambiente escurece.

---

## 📋 Lista de Materiais

Abaixo estão os componentes utilizados no projeto, conforme especificado no documento de referência `materiais casa inteligente.pdf` localizado na pasta `docs/` deste repositório:

### 1. Placa Principal e Energia
* **1x** Placa de Arduino
* **1x** Fonte de Alimentação 9V ou Clipe de Bateria 9V para Arduino

### 2. Sensores (Entradas)
* **1x** Módulo Sensor de Chuva (MH-RD)
* **1x** Sensor de Presença Movimento PIR (HC-SR501)
* **1x** Sensor de Luz LDR de 5mm
* **1x** Módulo Sensor de Chama IR (Fogo)

### 3. Atuadores e Sinalizadores (Saídas)
* **1x** Micro Servo Motor 9g SG90
* **1x** Buzzer Ativo 5V
* **1x** LED Difuso 5mm Vermelho ou Amarelo (Luz interna)
* **1x** LED Difuso 5mm Branco ou Verde (Luz do poste)

### 4. Componentes de Conexão e Proteção
* **1x** Protoboard de 400 ou 830 pontos
* **1x** Kit de Cabos Jumpers Macho-Macho e Macho-Fêmea
* **2x** Resistores de 220 $\Omega$ (para os LEDs)
* **1x** Resistor de 10k $\Omega$ (para o divisor de tensão do LDR)

### 5. Materiais para a Estrutura (Maquete)
* Placa de Isopor Grosso (para a base e embutir a fiação)
* Cola quente, palitos de picolé/arame rígido e linha de costura (para o mecanismo mecânico do varal)

---

## 🔌 Esquema de Conexão dos Pinos

| Componente | Tipo de Pino | Pino Arduino | Observação |
| :--- | :--- | :--- | :--- |
| **Sensor de Chuva (MH-RD)** | Digital | `D2` | Conectado ao pino DO do sensor |
| **Sensor PIR (HC-SR501)** | Digital | `D3` | Sensor de presença interno |
| **LED Interno** | Digital | `D4` | Em série com resistor de 220 $\Omega$ |
| **LED Externo (Poste)** | Digital | `D5` | Em série com resistor de 220 $\Omega$ |
| **Sensor de Chama IR** | Digital | `D6` | Conectado ao pino DO do sensor |
| **Buzzer Ativo** | Digital | `D7` | Sirene do alarme de incêndio |
| **Servo Motor (SG90)** | Digital (PWM)| `D9` | Controle do braço mecânico do varal |
| **Sensor de Luz (LDR)** | Analógico | `A1` | Ligado com resistor de 10k $\Omega$ em pull-down |

---

## 🚀 Como Executar o Projeto

1. Monte o circuito seguindo a tabela de pinos ou o diagrama disponível na pasta `schematics/`.
2. Baixe e instale a [Arduino IDE](https://www.arduino.cc/en/software).
3. Abra o arquivo correspondente ao código fonte em `src/main/main.ino`.
4. Conecte o seu Arduino ao computador via cabo USB.
5. Selecione a placa correta e a porta COM em *Ferramentas*.
6. Clique em **Carregar (Upload)** para gravar o código na placa.
7. Abra o *Serial Monitor* (9600 bps) para acompanhar os alertas e leituras dos sensores em tempo real.
