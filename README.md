# 🚗 Carrinho Robótico com Controle Bluetooth

Projeto desenvolvido durante o curso de **Programação e Interação da Plataforma Arduino** no **SENAI Itatiba**, utilizando Arduino e controle remoto via Bluetooth/Serial.

---

## 📋 Descrição

Carrinho robótico de 4 rodas controlado remotamente por comandos seriais (Bluetooth). Possui controle de velocidade em 4 níveis e suporte a movimentos diagonais proporcionais, permitindo manobras mais suaves e precisas.

---

## ⚙️ Funcionalidades

- ✅ Movimentação: frente, ré, esquerda, direita
- ✅ Movimentos diagonais: frente-esquerda, frente-direita, ré-esquerda, ré-direita
- ✅ Controle de velocidade em 4 níveis (0, 80, 120, 180, 255)
- ✅ Curvas proporcionais (redução de velocidade no lado interno da curva)
- ✅ Parada imediata por comando
- ✅ Comunicação via Serial/Bluetooth (9600 baud)

---

## 🗂️ Tabela de Comandos

| Comando | Ação               |
|---------|--------------------|
| `F`     | Frente             |
| `B`     | Ré                 |
| `L`     | Esquerda           |
| `R`     | Direita            |
| `G`     | Frente + Esquerda  |
| `I`     | Frente + Direita   |
| `H`     | Ré + Esquerda      |
| `J`     | Ré + Direita       |
| `S`     | Parar              |
| `0`     | Velocidade 0       |
| `1`     | Velocidade 80      |
| `2`     | Velocidade 120     |
| `3`     | Velocidade 180     |
| `4`     | Velocidade 255     |

---

## 🔌 Componentes

| Componente         | Descrição                              |
|--------------------|----------------------------------------|
| Arduino            | Microcontrolador principal             |
| Driver L298N       | Ponte H para controle dos motores DC   |
| Módulo Bluetooth   | Comunicação sem fio (HC-05 ou similar) |
| 2x Motor DC        | Tração do carrinho                     |
| Bateria 9V         | Alimentação do sistema                 |
| Chassi acrílico    | Estrutura física do carrinho           |


---

## 🔧 Mapeamento de Pinos

| Pino Arduino | Função          |
|--------------|-----------------|
| 5            | ENA (Motor A)   |
| 6            | ENB (Motor B)   |
| 9            | IN1             |
| 10           | IN2             |
| 11           | IN3             |
| 12           | IN4             |


---

## 📸 Fotos do Projeto

> *<img width="1600" height="1130" alt="image" src="https://github.com/user-attachments/assets/9edd79df-fd59-4fb4-b95c-5127e85f0ed8" />
*

---

## 🚀 Como usar

1. Faça o upload do arquivo `Carrinho.ino` para o Arduino via Arduino IDE
2. Conecte um módulo Bluetooth (HC-05) ao pino Serial do Arduino
3. Use um app de controle Bluetooth (ex: **Bluetooth RC Controller**) no celular
4. Configure os botões do app com os comandos da tabela acima
5. Ligue o carrinho e controle via celular

---

## 🛠️ Tecnologias utilizadas

![Arduino](https://img.shields.io/badge/Arduino-00979D?style=for-the-badge&logo=arduino&logoColor=white)
![C++](https://img.shields.io/badge/C%2B%2B-00599C?style=for-the-badge&logo=c%2B%2B&logoColor=white)

---

## 👤 Autor

**Matheus Barbosa**  
Estudante de Engenharia da Computação | Técnico em Eletroeletrônica (SENAI)

[![GitHub](https://img.shields.io/badge/GitHub-MatheusBarbosaEng-181717?style=flat&logo=github)](https://github.com/MatheusBarbosaEng)
