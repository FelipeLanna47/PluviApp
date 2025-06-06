Feito por: Felipe da Costa Lanna    RM 566578
      
      
      PluviApp - Sistema de Alerta de Enchentes (Edge Computing & IoT)

  Identificação do Problema: Alagamento em Áreas Residenciais
  Este projeto visa resolver o problema de alagamentos residenciais causados por chuvas e elevação do nível de rios. A solução proposta é um sistema de alerta local em tempo real para mitigar danos e riscos.

 
  Visão Geral da Solução: Sistema Físico de Alerta Avançado
Desenvolvemos um protótipo Arduino de monitoramento de enchentes com Edge Computing. Ele detecta níveis de água e umidade do solo, controla atuadores complexos e fornece feedback detalhado.


Como o Sistema Funciona:
Monitoramento de Nível de Água (Sensor Ultrassônico HC-SR04):

Normal (> 15cm): LED Verde.

Atenção (10-15cm): LED Amarelo.

Crítico (≤ 10cm): LED Vermelho + Buzzer.

Monitoramento de Umidade do Solo: Informa sobre saturação do solo e risco de deslizamentos.

Controle de Atuadores (Motor DC com Codificador): Simula acionamento de comportas, com feedback de posição.

Interface com o Usuário (LCD 16x2 e Potenciômetro): Exibe leituras e alertas; potenciômetro para ajustes.

Componentes Utilizados:
Arduino Uno R3

Sensor Ultrassônico HC-SR04

Sensor de Umidade do Solo

Motor DC com Codificador (requer driver e fonte externa)

Potenciômetro

Display LCD 16x2 (com ou sem módulo I2C)

LEDs (Verde, Amarelo, Vermelho) com Resistores 220 Ohm

Buzzer

Protoboard e Fios Jumper


 Código Fonte
O código Arduino (C++) está no repositório, com comentários, nomenclatura clara, indentação adequada e lógica estruturada, seguindo boas práticas.


   Links Importantes
Link Direto para o Projeto no Simulador Tinkercad: (https://www.tinkercad.com/things/duQDQfHa8Kh-mighty-snicket/editel?returnTo=https%3A%2F%2Fwww.tinkercad.com%2Fdashboard%2Fdesigns%2Fcircuits)

Link para o Vídeo Demonstrativo (YouTube/Drive): https://youtu.be/u-jQ0V5bS1c

Link para este Repositório GitHub: https://github.com/FelipeLanna47/-PluviApp-Hardware?tab=readme-ov-file


   Avaliação Funcional no Simulador
O projeto foi projetado para funcionar corretamente no Tinkercad. Sua validação demonstrará a resposta do sistema a diferentes níveis de água, umidade e entradas do usuário
