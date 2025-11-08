//Incluindo Biblioteca BT
  #include "BluetoothSerial.h"

//Definindo os pinos do ESP32 
  const int MDP = 26; //Motor Direito Positivo
  const int MDN = 27; //Motor Direito Negativo
  const int MEP = 33; //Motor Esquerdo Positivo
  const int MEN = 25; //Motor Esquerdo Negativo

//Difinicição das Velocidades - O APP permite de 0 a 9 velocidades. Irei utilizar Velocidade inicial 178,5 e passos de 7,75 em cada velocidade.
  const float Passo = 25.0;

//Definição da porcentagem nas reduções, proporcionalmente
  const float Porcentagem = 75;

//Definindo Sintaxe SerialBT
  BluetoothSerial SerialBT;

//Adicionando Variáveis 
  char comando;
  bool conexao;
  float Velocidade;
  float ReducaoCurva;
  float Reduzido; 

void setup() 
{
  Serial.begin(9600);
  SerialBT.begin("EngRobots");
  pinMode(MDP, OUTPUT);
  pinMode(MDN, OUTPUT);
  pinMode(MEP, OUTPUT);
  pinMode(MEN, OUTPUT);

}

void loop() {

  ReducaoCurva = Velocidade*(Porcentagem/100.0);
  Reduzido = Velocidade-ReducaoCurva;

  conexao = SerialBT.available();
  if (conexao == true)
  {
    comando = SerialBT.read();

    switch (comando) 
    {     
      case 'F': //move frente
        analogWrite(MDP, Velocidade);
        analogWrite(MDN, 0);
        analogWrite(MEP, Velocidade);
        analogWrite(MEN, 0);
      break;
      case 'I': //frente direita
        analogWrite(MDP, Reduzido);
        analogWrite(MDN, 0);
        analogWrite(MEP, Velocidade);
        analogWrite(MEN, 0);
      break;
      case 'G': //frente esquerda
        analogWrite(MDP, Velocidade);
        analogWrite(MDN, 0);
        analogWrite(MEP, Reduzido);
        analogWrite(MEN, 0);
      break;
      case 'R': //direita
        analogWrite(MDP, 0);
        analogWrite(MDN, 0);
        analogWrite(MEP, Velocidade);
        analogWrite(MEN, 0);
      break;
      case 'L': //esquerda
        analogWrite(MDP, Velocidade);
        analogWrite(MDN, 0);
        analogWrite(MEP, 0);
        analogWrite(MEN, 0);
      break;
      case 'B': // ré
        analogWrite(MDP, 0);
        analogWrite(MDN, Velocidade);
        analogWrite(MEP, 0);
        analogWrite(MEN, Velocidade);
      break;
      case 'J': // ré esquerda
        analogWrite(MDP, 0);
        analogWrite(MDN, Velocidade);
        analogWrite(MEP, 0);
        analogWrite(MEN, Reduzido);
      break;
      case 'H': //ré direita
        analogWrite(MDP, 0);
        analogWrite(MDN, Reduzido);
        analogWrite(MEP, 0);
        analogWrite(MEN, Velocidade);
      break;
      default:
        analogWrite(MDP, 0);
        analogWrite(MDN, 0);
        analogWrite(MEP, 0);
        analogWrite(MEN, 0);
      break;
      case '0':
        Velocidade = Passo;             //Velocidade = 178,5
      break;
      case '1':
        Velocidade = Passo*2;  //Velocidade = 201,75
      break;
      case '2':
        Velocidade = Passo*3;  //Velocidade = 209,50
      break;
      case '3':
        Velocidade = Passo*4;  //Velocidade = 217,25
      break;
      case '4':
        Velocidade = Passo*5;  //Velocidade = 225,00
      break;
      case '5':
        Velocidade = Passo*6;  //Velocidade = 232,75
      break;
      case '6':
        Velocidade = Passo*7;  //Velocidade = 240,50
      break;
      case '7':
        Velocidade = Passo*8;  //Velocidade = 245,15
      break;
      case '8':
        Velocidade = Passo*9;  //Velocidade = 248,25
      break;
      case '9':
        Velocidade = Passo*10;  //Velocidade = 254,45
      break;
    }
  }
}
