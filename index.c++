 const int botao = 7; // Pino do botão
 const int sensorPIR = 8; // Pino do sensor PIR
 const int buzzer = 5; // Pino do buzzer
 const int ledVermelho = 6; // Pino do LED vermelho
 int LeituraPIR = 0; //Leitura do Sensor PIR
 int estadobotao = 0;//Leitura do Estado do botão
 int ultimoestadobotao = 0; //Verificar os estados do botão
 bool alarmeAtivo = false; //Verificar se o alarme está ativo/desativo
 
void setup() {
  Serial.begin(9600);
  
  pinMode(botao, INPUT_PULLUP);
  pinMode(sensorPIR, INPUT);
  pinMode(buzzer, OUTPUT);
  pinMode(ledVermelho, OUTPUT);
}

void loop() {
  
  //Verificando  o estado do botão
 estadobotao = digitalRead(botao);

  // Detectar mudança de estado do botão
  if (estadobotao == LOW && ultimoestadobotao == HIGH) {
    alarmeAtivo = !alarmeAtivo;
  }
  //Atribuindo os valores atuais as variáveis 
  ultimoestadobotao = estadobotao;
  LeituraPIR = digitalRead(sensorPIR);

  // Verificar se o alarme está ativo e se o sensor PIR detectou movimento
  if (alarmeAtivo && LeituraPIR == HIGH) {
    ativarAlarme();
  } else {
    desligarAlarme();
  }
}

void ativarAlarme() {
  
  //Como fazer o led piscar
  digitalWrite(ledVermelho, HIGH);
  delay(300);
  digitalWrite(ledVermelho, LOW);
  
  tone(buzzer, 700);
  delay(300);
  noTone(buzzer);
  
  }

void desligarAlarme(){
  noTone(buzzer);
  digitalWrite(ledVermelho, LOW);
}

//Tive muitos problemas com o protótipo no tinkercad este é o terceiro :(