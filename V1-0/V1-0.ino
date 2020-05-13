/*----------------- DEFINICAO DOS PINOS ------------------*/
#define pino_LED 2
#define pino_botao 3 
#define pino_servo 9

/*---------- POSICOES DENTRO E FORA DA CAIXA -------------*/
#define pos_dentro 45
#define pos_fora 180

/*--------------------- BIBLIOTECAS ----------------------*/
#include <Servo.h>


/*---------------------- VARIAVEIS -----------------------*/
Servo s1;
int pos=0;

void setup() {
  s1.attach(pino_servo);
  s1.write(pos_dentro); //Inicia dentro da caixa
  
  pinMode(pino_botao,INPUT_PULLUP);
  pinMode(pino_LED,OUTPUT);
  
  Serial.begin(9600); // Pra imprimir o estado do botão pra verificação
}

void loop(){
  
  int estado_botao = digitalRead(pino_botao);
  digitalWrite(pino_LED,estado_botao); //Alterna o LED entre aceso e apagado de acordo com o botão
  
  if(estado_botao==HIGH){// Se for ligando
    for(pos=pos;pos<pos_fora;pos++){//O braço sai da posição que estiver até a posição fora da caixa
      s1.write(pos);
    }
      
  }else{// se for desligado
    for(pos=pos;pos>pos_dentro;pos--){//O braço sai da posição que estiver até a posição dentro da caixa
      s1.write(pos);
      delay(10);// pra voltar um pouco mais devagar
    }
  }
  Serial.println(estado_botao);// imprime o estado do botão para controle
}
