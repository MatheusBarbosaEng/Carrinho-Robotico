// ============================================================
//  Carrinho Robótico com Controle Bluetooth
//  Curso: Arduino — SENAI Itatiba
//  Autor: Matheus Barbosa
// ============================================================

// =====================
// PINOS
// =====================
int ENA = 5;  // PWM Motor A (velocidade)
int ENB = 6;  // PWM Motor B (velocidade)

int IN1 = 9;   // Direção Motor A
int IN2 = 10;  // Direção Motor A
int IN3 = 11;  // Direção Motor B
int IN4 = 12;  // Direção Motor B

// =====================
// CONTROLE
// =====================
char state = 'S';   // estado inicial: parado
int vSpeed = 180;   // velocidade padrão (0-255)

// =====================
void setup() {

  pinMode(ENA, OUTPUT);
  pinMode(ENB, OUTPUT);

  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  pinMode(IN3, OUTPUT);
  pinMode(IN4, OUTPUT);

  Serial.begin(9600);  // comunicação Bluetooth a 9600 baud
}

// =====================
void loop() {

  // leitura serial sem perda de comandos
  while (Serial.available()) {
    state = Serial.read();
  }

  // -------- VELOCIDADE --------
  if (state == '0') vSpeed = 0;
  if (state == '1') vSpeed = 80;
  if (state == '2') vSpeed = 120;
  if (state == '3') vSpeed = 180;
  if (state == '4') vSpeed = 255;

  // -------- MOVIMENTO --------
  if (state == 'F') frente();
  else if (state == 'B') re();
  else if (state == 'L') esquerda();
  else if (state == 'R') direita();

  else if (state == 'G') frenteEsquerda();
  else if (state == 'I') frenteDireita();

  else if (state == 'H') reEsquerda();
  else if (state == 'J') reDireita();

  else if (state == 'S') parar();
}

// =====================
// MOVIMENTOS
// =====================

void frente() {
  analogWrite(ENA, vSpeed);
  analogWrite(ENB, vSpeed);

  digitalWrite(IN1, 1);
  digitalWrite(IN2, 0);
  digitalWrite(IN3, 1);
  digitalWrite(IN4, 0);
}

void re() {
  analogWrite(ENA, vSpeed);
  analogWrite(ENB, vSpeed);

  digitalWrite(IN1, 0);
  digitalWrite(IN2, 1);
  digitalWrite(IN3, 0);
  digitalWrite(IN4, 1);
}

void esquerda() {
  analogWrite(ENA, vSpeed);
  analogWrite(ENB, vSpeed);

  digitalWrite(IN1, 0);
  digitalWrite(IN2, 1);
  digitalWrite(IN3, 1);
  digitalWrite(IN4, 0);
}

void direita() {
  analogWrite(ENA, vSpeed);
  analogWrite(ENB, vSpeed);

  digitalWrite(IN1, 1);
  digitalWrite(IN2, 0);
  digitalWrite(IN3, 0);
  digitalWrite(IN4, 1);
}

// curvas proporcionais: reduz velocidade no lado interno da curva
void frenteEsquerda() {
  analogWrite(ENA, vSpeed * 0.5);
  analogWrite(ENB, vSpeed);

  digitalWrite(IN1, 1);
  digitalWrite(IN2, 0);
  digitalWrite(IN3, 1);
  digitalWrite(IN4, 0);
}

void frenteDireita() {
  analogWrite(ENA, vSpeed);
  analogWrite(ENB, vSpeed * 0.5);

  digitalWrite(IN1, 1);
  digitalWrite(IN2, 0);
  digitalWrite(IN3, 1);
  digitalWrite(IN4, 0);
}

void reEsquerda() {
  analogWrite(ENA, vSpeed * 0.5);
  analogWrite(ENB, vSpeed);

  digitalWrite(IN1, 0);
  digitalWrite(IN2, 1);
  digitalWrite(IN3, 0);
  digitalWrite(IN4, 1);
}

void reDireita() {
  analogWrite(ENA, vSpeed);
  analogWrite(ENB, vSpeed * 0.5);

  digitalWrite(IN1, 0);
  digitalWrite(IN2, 1);
  digitalWrite(IN3, 0);
  digitalWrite(IN4, 1);
}

void parar() {
  analogWrite(ENA, 0);
  analogWrite(ENB, 0);

  digitalWrite(IN1, 0);
  digitalWrite(IN2, 0);
  digitalWrite(IN3, 0);
  digitalWrite(IN4, 0);
}
