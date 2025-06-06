// Definição dos pinos para o sensor ultrassônico
const int TRIG_PIN = 9;  // Pino Trig do sensor ultrassônico
const int ECHO_PIN = 10; // Pino Echo do sensor ultrassônico

// Definição dos pinos para os LEDs e o Buzzer
const int GREEN_LED_PIN = 2;   // LED Verde
const int YELLOW_LED_PIN = 3;  // LED Amarelo
const int RED_LED_PIN = 4;     // LED Vermelho
const int BUZZER_PIN = 5;      // Buzzer

// Limites de distância em centímetros
const int DISTANCE_HIGH_ALERT = 10; // Distância abaixo de 10cm (alto risco)
const int DISTANCE_MEDIUM_ALERT = 15; // Distância entre 10cm e 15cm (médio risco)

void setup() {
  // Configura os pinos do sensor ultrassônico
  pinMode(TRIG_PIN, OUTPUT);
  pinMode(ECHO_PIN, INPUT);

  // Configura os pinos dos LEDs e do Buzzer como saída
  pinMode(GREEN_LED_PIN, OUTPUT);
  pinMode(YELLOW_LED_PIN, OUTPUT);
  pinMode(RED_LED_PIN, OUTPUT);
  pinMode(BUZZER_PIN, OUTPUT);

  // Inicia a comunicação serial para depuração no Monitor Serial do Tinkercad
  Serial.begin(9600);
  Serial.println("Iniciando Monitoramento de Nível de Água...");
}

void loop() {
  // Garante que o pino Trig esteja LOW antes de enviar o pulso
  digitalWrite(TRIG_PIN, LOW);
  delayMicroseconds(2);

  // Envia um pulso de 10 microssegundos para o pino Trig
  digitalWrite(TRIG_PIN, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIG_PIN, LOW);

  // Mede a duração do pulso de retorno no pino Echo
  long duration = pulseIn(ECHO_PIN, HIGH);

  // Converte a duração em distância (em centímetros)
  float distanceCm = duration / 58.0;

  // *** NOVA LINHA DE DEPURAÇÃO ***
  Serial.print("Distância lida pelo sensor: ");
  Serial.print(distanceCm);
  Serial.println(" cm");
  // ******************************

  // Lógica de controle dos LEDs e Buzzer com base na distância
  if (distanceCm < DISTANCE_HIGH_ALERT) {
    // Nível de água MUITO ALTO (distância baixa) - Alerta Vermelho + Buzzer
    digitalWrite(RED_LED_PIN, HIGH);
    digitalWrite(YELLOW_LED_PIN, LOW);
    digitalWrite(GREEN_LED_PIN, LOW);
    tone(BUZZER_PIN, 1000); // Emite um som de 1000 Hz
    Serial.println("ALERTA MÁXIMO: Nível de água crítico!");
  } else if (distanceCm >= DISTANCE_HIGH_ALERT && distanceCm <= DISTANCE_MEDIUM_ALERT) {
    // Nível de água MÉDIO - Alerta Amarelo
    digitalWrite(RED_LED_PIN, LOW);
    digitalWrite(YELLOW_LED_PIN, HIGH);
    digitalWrite(GREEN_LED_PIN, LOW);
    noTone(BUZZER_PIN); // Desliga o buzzer
    Serial.println("ALERTA MÉDIO: Nível de água subindo!");
  } else {
    // Nível de água BAIXO (distância alta) - Alerta Verde
    digitalWrite(RED_LED_PIN, LOW);
    digitalWrite(YELLOW_LED_PIN, LOW);
    digitalWrite(GREEN_LED_PIN, HIGH);
    noTone(BUZZER_PIN); // Desliga o buzzer
    Serial.println("Nível de água normal.");
  }

  delay(100); // Pequeno atraso para estabilização das leituras
}
