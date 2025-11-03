# 🤖 Robô Jogador de Futebol Bluetooth – ESP32

Projeto de um **robô jogador de futebol** controlado via **Bluetooth**, desenvolvido em **C++ para ESP32**.  
Este robô pode se mover em todas as direções (frente, ré, curvas e rotações) a partir de comandos enviados pelo celular utilizando um aplicativo Bluetooth, como o **MIT App Inventor**.

---

## ⚙️ Funcionalidades

- Controle total via **Bluetooth** (HC-06 ou Bluetooth interno do ESP32);
- Movimentação: frente, ré, curvas e giros;
- Controle de **velocidade ajustável (0–9)**;
- Sistema de **redução proporcional nas curvas**, garantindo mais precisão nas manobras;
- Código simples, comentado e de fácil modificação.

---

## 🧠 Lógica de Controle

O código utiliza o módulo **BluetoothSerial** do ESP32.  
Cada caractere enviado pelo aplicativo representa um comando de movimento ou velocidade.  
Exemplo:

| Comando | Ação |  
|----------|------|  
| F | Frente |  
| B | Ré |  
| L | Esquerda |  
| R | Direita |  
| G / I | Curvas suaves (esquerda/direita) |  
| 0–9 | Ajuste de velocidade (incrementos de 25,5) |

O cálculo da curva aplica uma **redução proporcional de 80%** sobre a velocidade base para suavizar as manobras.

---

## 🧩 Conexões dos Motores

| Pino ESP32 | Função |  
|-------------|---------|  
| 12 | Motor Direito Positivo |  
| 13 | Motor Direito Negativo |  
| 14 | Motor Esquerdo Positivo |  
| 27 | Motor Esquerdo Negativo |

> ⚠️ Certifique-se de usar um **driver de motor** compatível (como L298N ou ponte H equivalente).

---

## 🔌 Requisitos

- **ESP32**  
- **Driver de motor** (L298N, L293D, etc.)  
- **Bateria 7.4V ou 11.1V** (dependendo dos motores)  
- **Aplicativo Bluetooth** (ex: MIT App Inventor personalizado)  
- **IDE Arduino** com suporte ao ESP32 instalado  

---

## 🚀 Como Usar

1. Faça o upload do código para o ESP32.  
2. Pareie o módulo Bluetooth com seu celular (nome padrão: **EngRobots**).  
3. Abra o aplicativo e envie comandos (F, B, L, R, 0–9).  
4. Controle o robô em tempo real!

---

## 📂 Estrutura do Projeto

