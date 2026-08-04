//Missão : Sensor Ultrassônico

/*Esse sensor usa ondas sonoras para identificar presença.
o "trig" envias as ondas,e ao bater no objeto, elas voltam e são capturadas pelo "echo"*/



//Definição dos pinos

const int trig = 11; //Portas Digitais
const int echo = 9;

//Variáveis para o cálculo

unsigned long tempo;
float distancia;


//Configuração dos pinos

void setup(){
	pinMode(trig, OUTPUT); //Pino de saída
	pinMode(echo,INPUT);  // Pino de Entrada
	Serial.begin(9600); //Iniciar a comunicação serial (para ler os dados)
}


//Realizar o código
void loop(){
	
//Iniciando o sensor (desligado)	
	digitalWrite(trig,LOW);
	delayMicroseconds(2);

//Sensor emite ondas por 10 microsegundos
	digitalWrite(trig,HIGH);
	delayMicroseconds(10);
	
//Interrompendo envio de sinal
	digitalWrite(trig,LOW);

//Lendo o  tempo de viagem da onda em microsegundos
	tempo = pulseIn(echo,HIGH);
  
// Cálculo dessa distância
  //como v = d/t , e vsom =340m/s = 340.10^2/10^6 cm/us => vsom = 0,340 cm/us  => 
	distancia = tempo * 0.034 /2;  //vai e volta

//Exibir o resultado no Monitor Serial
    Serial.print("Distancia:");
    Serial.print(distancia);
    Serial.println("cm");

//Aguarda 1 segundo (1000ms) para a próxima leitura
	delay(1000);
}
