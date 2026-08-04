//Definindo pinos

//Motor A(esquerda)
const int ENA = 5; //Pino PWM para controle de velocidade (0 a 255)
const int IN1 = 6; // Controle de direção p/frente
const int IN2 = 7; //Controle de direção p/trás

//Motor B(direita)
const int ENB = 3; //Pino PWM para controle de velocidade (0 a 255)
const int IN3 = 2; // Controle de direção p/frente
const int IN4 = 4; //Controle de direção p/trás

//Configurando Pinos                 Todos são saídas pois é o Arduíno que envia o comando
void setup()
{
pinMode(ENA,OUTPUT);
pinMode(IN1,OUTPUT);
pinMode(IN2,OUTPUT);
  
pinMode(ENB,OUTPUT);
pinMode(IN3,OUTPUT);
pinMode(IN4,OUTPUT);
}

void loop(){
  //1. Andar p/ frente com potência máxima
  digitalWrite(IN1,HIGH); //Motor A acionado p/frente
  digitalWrite(IN2,LOW); // Ré Motor A desligada
  digitalWrite(IN3,HIGH); //Motor B acioando p/frente
  digitalWrite(IN4,LOW); //Ré Motor B desligada
  
  analogWrite(ENA,255); //Garante a potencia máxima do Motor A
  analogWrite(ENB,255); //Garante a potencia máxima do Motor B
  
  delay(5000);  //Esperar 5s
  
  //2.Parar
  digitalWrite(IN1,LOW); //Acelerador Motor A desligado
  digitalWrite(IN2,LOW); // Ré Motor A desiagada
  digitalWrite(IN3,LOW); // Acelerador Motor B desligado
  digitalWrite(IN4,LOW); // Ré Motor B desiagada
  
  analogWrite(ENA,0);
  analogWrite(ENB,0);
  
  delay(5000); //Esperar 5s
    
 //3.Ré com potência máxima
  digitalWrite(IN1,LOW);
  digitalWrite(IN2,HIGH); //Inverte o sinal em relação ao passo 1
  digitalWrite(IN3,LOW);
  digitalWrite(IN4,HIGH); //Inverte o sinal em relação ao passo 1
   
  analogWrite(ENA,255); //Pot máx
  analogWrite(ENB,255); //Pot máx
  
  delay(5000);
  
  //4.Parar
  digitalWrite(IN1,LOW);
  digitalWrite(IN2,LOW);
  digitalWrite(IN3,LOW);
  digitalWrite(IN4,LOW);
  
  analogWrite(ENA,0);
  analogWrite(ENB,0);
  
  delay(5000);
  
  
 //5. Girar no sentido Horário com 50%                       Acelerar o Motor da Esquerda e dar Ré com o Motor da Direita
  digitalWrite(IN1,HIGH); //Acelerando Motor A
  digitalWrite(IN2,LOW);
  digitalWrite(IN3,LOW);
  digitalWrite(IN4,HIGH); // Ré com Motor B
  
  analogWrite(ENA,255/2); //Pot pela metade
  analogWrite(ENB,255/2); //Pot pela metade
  
  delay(5000);
}