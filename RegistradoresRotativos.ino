/*----------------------------------------------------------------------------
Projeto: Piscar 8 Leds 
Objetivo: Controlar os Leds
Versão: 1.3
Descrição: Piscar 8 Leds em For dentro do For
-----------------------------------------------------------------------------*/
//Definir
  #define numMax 5
  int i;
  #define ligado 1
  #define desligado 0
//------------------------------------------------------------------------------
//Variavéis
  const unsigned int tempoLedLigado = 400;
  const unsigned int tempoLedDesligado = 400;
//------------------------------------------------------------------------------
//Pisca direita para esquerda e repete
 void fase1() {
    PORTD=B00000001;  
    for (i=0;i<=7;i++) {
      delay(tempoLedLigado);
      PORTD=PORTD<<1;
    }
    PORTD=B01000000;
    for(i=6;i>=1;i--){
      delay(tempoLedLigado);
      PORTD=PORTD>>1;
    }

   /*for (i=6;i>=0;i=i-2) {
    digitalWrite(i, ligado);
    delay(tempoLedLigado);
    digitalWrite(i, desligado);
    delay(tempoLedDesligado);
    Serial.print("Valor: ");
    Serial.println(i);
   }*/
 }

  void fase2(){
  for (byte i=0;i<=7;i++) {
    digitalWrite(i, ligado);
    delay(tempoLedLigado);
  }
  for (i=7;i>=0;i--) {
    digitalWrite(i, ligado);
    //delay(tempoLedLigado);
    digitalWrite(i, desligado);
    delay(tempoLedDesligado);
  }  
}
  void fase3(){
  PORTD = B00000001<<1;
  for (byte y=1;y<=(numMax*2)-1;y++) {
    delay(500);
    PORTD = PORTD^B11111111; //Ligando os Leds do pino 0 ao 7 Função XOR
  }
  delay(1000);
}  
//------------------------------------------------------------------------------
//Configurar Placa
void setup(){
DDRD = B11111111;//Configurando os pinos de 0 a 7 todos como saída (Registrador de Direção)
//Serial.begin(9600);
}
//-------------------------------------------------------------------------------
void loop() {

  fase1();
  //fase2();
  //fase3();

}
