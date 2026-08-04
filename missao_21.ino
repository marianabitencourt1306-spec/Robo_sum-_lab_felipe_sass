//Definindo pinos

//Motor A(esquerda)
const int ENA = 5; //Pino PWM (0 a 255) potencia da velocidade
const int IN1 = 6; //Controle da direção p/frente
const int IN2 = 7; //Controle da direção p/trás

//Motor B(direita)
const int ENB = 3; //Pino PWM (0 a 255) potencia da velocidade
const int IN3 = 2; //Controle da direção p/frente
const int IN4 = 4; //Controle da direção p/trás

//Sensor Ultrassônico
const int trig = 8; //Emissor de som
const int echo = 9; //Receptor de som

  
//Definindo variáveis
unsigned long tempo;
int distancia; // Como só nos interessa saber se é o unao > que 20, podemos pensar em interios
  

//Configurando os pinos
void setup(){
  
	pinMode(ENA,OUTPUT);
  	pinMode(IN1,OUTPUT);
 	pinMode(IN2,OUTPUT);
  
  	pinMode(ENB,OUTPUT);
  	pinMode(IN3,OUTPUT);
  	pinMode(IN4,OUTPUT);

	pinMode(trig,OUTPUT);
  	pinMode(echo,INPUT);
  
  Serial.begin(9600); //Iniciando comunicação serial
}

void loop(){
  
 
  //1.Calcular a distancia com o sensor Ultrassônico 
  
  
  // Ativar o sensor
  digitalWrite(trig,LOW);
  delayMicroseconds(2);
  digitalWrite(trig,HIGH);
  delayMicroseconds(10); 
  digitalWrite(trig,LOW);
  
  //Lê o tempo que a onda sonora foi e voltou
  tempo = pulseIn(echo,HIGH);
  
  //Calcula a distancia já em cm
  distancia = tempo* 0.034/2;
  

  //2.  Decisão Rápida if/else
 
  if(distancia <20 && distancia>0){
    
    //SE A CONDIÇÃO FO VERDAEIRA, Objeto para
    digitalWrite(IN1,LOW);
    digitalWrite(IN2,LOW);
    digitalWrite(IN3,LOW);
    digitalWrite(IN4,LOW);
  
    analogWrite(ENA,0);
    analogWrite(ENB,0);
  } 
  
  else  {                                 //Caso contrario, não tem argumento
  
 //Girar no sentido Horário com 50% de  potência       => Acelerar o Motor A e dar Ré com o Motor B 
  
  digitalWrite(IN1,HIGH);
  digitalWrite(IN2,LOW);
  digitalWrite(IN3,LOW);
  digitalWrite(IN4,HIGH);
  
  analogWrite(ENA, 127);
  analogWrite(ENB,127);
  }
  //Fim do loop
  delay(500);   //Arduino espera para recomecar do topo
}
