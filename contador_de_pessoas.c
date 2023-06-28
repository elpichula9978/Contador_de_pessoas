#include <LiquidCrystal.h>
//Variavies 
const int sensorDentro = A0;
const int sensorFora = A1;
const int pinBotao = 8;

//Variavies pra entrar e sair e espera 
const int ESPERA = 0;
const int ENTRANDO = 1;
const int SAINDO = 2;

//contador de pessoas 
int contPessoas = 0;
int modo = 0;

//sensores ldrs
int ldr1 = 0;
int ldr2 = 0;

// Inicializar a biblioteca com os números dos pinos de interface
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

void setup() {
  // Configura o número de colunas e linhas do LCD:
  lcd.begin(16, 2);

  pinMode(sensorDentro, INPUT);
  pinMode(sensorFora, INPUT);

  Serial.begin(9600);
}

void loop() {
  //sobre os LDRs
  ldr1 = analogRead(sensorDentro);
  ldr2 = analogRead(sensorFora);
  //printa na Monitor serial
  Serial.print("ldr1: ");
  Serial.println(ldr1);
  Serial.print("ldr2: ");
  Serial.println(ldr2);
  // Verificar o estado dos sensores e do botão
  int estadoSensorDentro = !analogRead(sensorDentro); // Leitura do sensor dentro (inverte o valor)
  int estadoSensorFora = !analogRead(sensorFora); // Leitura do sensor fora (inverte o valor)
  

  // Incrementar contador de pessoas se ambos os sensores estiverem ativos
  if (ldr1 < 600 && ldr2 < 600) {
    contPessoas++;
    Serial.print("contador de pessoa: ");
    Serial.println(contPessoas);
  }

  lcd.clear(); // Limpa o LCD para evitar sobreposição de números
  lcd.setCursor(0, 0);
  lcd.print("TOTAL DE PESSOAS:");
  lcd.setCursor(0, 1);
  lcd.print(contPessoas);

  delay(1000); // Aguarda 1 segundo
}
