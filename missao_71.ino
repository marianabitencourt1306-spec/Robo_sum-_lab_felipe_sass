// Definição dos Pinos
 
//Motor A(esquerda)
 const int ENA = 5; //PWM para controle de potencia (0 a 255)
 const int IN1 = 6; // Controle de direção p/frente
 const int IN2 = 7; //Controle de direção p/trás
    
//Motor B(direita)   
 const int IN3 = 3; //PWM para controle de potencia (0 a 255)
 const int IN4 = 2; //Controle de direção p/frente
 const int ENB = 4; //Controle de direção p/trás
   
//Sensor de refletancia
 const int Sensor = A0; //Pino Analógico
   
   
//Definição das variáveis
int valorSensor;

void setup(){
//Definindo Configurações dos Pinos
	pinMode(IN1,OUTPUT);
  	pinMode(IN2,OUTPUT);
  
	pinMode(IN3,OUTPUT);
	pinMode(IN4,OUTPUT);
	
  	pinMode(Sensor,INPUT);
	
  Serial.begin(9600);
}

void loop(){

  //1. Ler o sensor
 valorSensor = analogRead(Sensor); 
  
 //2. Decisão
 
  
  //Se estiver na borda branca 
  if (valorSensor <= 512 ){                    //Sabendo que valores <= 512 significam BRANCO     
  
  //Andar para trás 
  digitalWrite(IN1,LOW);
  digitalWrite(IN2,HIGH);
  digitalWrite(IN3,LOW);
  digitalWrite(IN4,HIGH);

  //Por uma distância de 10 a 20 cm
  delay(400);
  
   
  //Girar 180*       => uma roda p frente e outra roda para trás ( Motot A p/frente e Motor B p/trás)
  
  	digitalWrite(IN1,HIGH);
    digitalWrite(IN2,LOW);
    digitalWrite(IN3,LOW);
    digitalWrite(IN4,HIGH);
  
  delay(200);
  
  }
  else{
  
  //Andar para frente com máxima potência
  
  digitalWrite(IN1,HIGH);
  digitalWrite(IN2,LOW);
  digitalWrite(IN3,HIGH);
  digitalWrite(IN4,LOW);
  
  analogWrite(ENA,255);
  analogWrite(ENB,255);
}

}