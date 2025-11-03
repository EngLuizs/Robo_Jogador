//Incluindo Biblioteca BT
  #include "BluetoothSerial.h"

//Definindo os pinos do ESP32 
  const int MDP = 12; //Motor Direito Positivo
  const int MDN = 13; //Motor Direito Negativo
  const int MEP = 14; //Motor Esquerdo Positivo
  const int MEN = 27; //Motor Esquerdo Negativo

//Difinicição das Velocidades - O APP permite de 0 a 9 velocidades. Irei utilizar passos de 25.5 em cada velocidade.
  #define Passo 25.5 

//Definição da porcentagem nas reduções, proporcionalmente
  #define Porcentagem 80

//Definindo Sintaxe SerialBT
  BluetoothSerial SerialBT;

//Adicionando Variáveis 
  char comando;
  bool conexao;
  float Velocidade;
  float ReducaoCurva; 

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

  ReducaoCurva = Velocidade*(Porcentagem/100);

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
        analogWrite(MDP, Velocidade - ReducaoCurva);
        analogWrite(MDN, 0);
        analogWrite(MEP, Velocidade);
        analogWrite(MEN, 0);
      break;
      case 'G': //frente esquerda
        analogWrite(MDP, Velocidade);
        analogWrite(MDN, 0);
        analogWrite(MEP, Velocidade - ReducaoCurva);
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
        analogWrite(MEN, Velocidade - ReducaoCurva);
      break;
      case 'H': //ré direita
        analogWrite(MDP, 0);
        analogWrite(MDN, Velocidade - ReducaoCurva);
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
        Velocidade = Passo;
      break;
      case '1':
        Velocidade = Passo*2;
      break;
      case '2':
        Velocidade = Passo*3;
      break;
      case '3':
        Velocidade = Passo*4;
      break;
      case '4':
        Velocidade = Passo*5;
      break;
      case '5':
        Velocidade = Passo*6;
      break;
      case '6':
        Velocidade = Passo*7;
      break;
      case '7':
        Velocidade = Passo*8;
      break;
      case '8':
        Velocidade = Passo*9;
      break;
      case '9':
        Velocidade = Passo*10;
      break;
    }
  }
}
