
/***********************************************************************
*                          PROJETO_LP                                  *
*                                                                      *
*              Autor: Ramon Moreira.                                   *
*                                                                      *
*      Esse código pode ser baixado, modificado e compartilhado        *
*      com o intuito educativo.                                        *
*                                                                      *
*      Contato: ramonalexander20@gmail.com                             *
*                                                                      *
* *********************************************************************/


#include <LiquidCrystal.h>
#include <UltrasonicSensor.h>

#define TMP2 500
#define TMP1 500


void anima(void);
void menu(void);
void MSG(void);
void fotoV(void);
void ULTRAS(void);
void adm(void);
void user(void);
void desenho(void);
// variables:


int sensorValue = 0;
const float ftv = A0;

const int bt1 = 6;
const int bt2 = 7;


const int ADM = 11;
const int USER = 10;


int i= 0, j= 0;
int intro1= 0, intro2 = 0, intro3 = 0;

bool estado = false;



LiquidCrystal lcd(13, 12, 5, 4, 3, 2);

UltrasonicSensor ultrasonic(8, 9);


void setup() {
  
  lcd.begin(16, 2);
  Serial.begin(115200);


  int temperature = 22;
  ultrasonic.setTemperature(temperature);
  
  Serial.println("\n Iniciando portas\n");
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Iniciando PINOS");


        pinMode(ftv, INPUT_PULLUP);
        pinMode( bt1 , INPUT_PULLUP);
        pinMode( bt2 , INPUT_PULLUP);
        pinMode( ADM , INPUT_PULLUP);
        pinMode( USER , INPUT_PULLUP);


         
  delay(3000);

  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Iniciando WiFi");
  delay(5000);
  
  anima();

}//**************************************************************************************


void loop() {
 menu();

}

//########################################################################################

void menu(){
        
  if(digitalRead(ADM) > 0){
      intro2 = 0;
      intro3 = 0;

      adm();
  }else if(digitalRead(USER) > 0){
       intro1 = 0;
       intro3 = 0;
       user();
         //****************************************
  }else{ 
          switch(digitalRead(bt1)){

      case 0:{
             
        }
      case 1:{
              lcd.clear();
              lcd.setCursor(3, 0);
              lcd.print("PROJETO LP");
              delay(500);
              break;
                                     
              break;
        }
     }//Fim Do SWITCH


             intro1 = 0; 
             intro2 = 0; 
             intro3 = 0; 
    }//FIM DO ELSE
             
  
}//------------------------------------------------------------------------  
//########################################################################################
void MSG(){
              
    switch(digitalRead(bt1)){

      case 1:{
              
              lcd.clear();
              lcd.setCursor(1, 0);
              lcd.print("Conecte-se no");
              lcd.setCursor(0, 1);
              lcd.print("IP:192.168.4.1");
              delay(TMP1);
              break;
        }
      case 0:{
  
              lcd.clear();
              lcd.setCursor(0, 0);
              lcd.print("WiFi: PROJETO_LP");
              lcd.setCursor(1, 1);
              lcd.print("Senha: password");
              delay(TMP1);
              break;
        }
     }

}//---------------------------------------------------------------------------

//########################################################################################
void fotoV(){
 sensorValue = analogRead(ftv);

  sensorValue = map(sensorValue, 0, 255, 0, 121);
  if (sensorValue < 120){
    
        sensorValue = 0;

            lcd.clear();
            lcd.setCursor(1, 0);
            lcd.print("Fotovoltaico:");
            lcd.setCursor(2, 1);
            lcd.print(String(sensorValue)+ " Volts");
            delay(TMP1);
    
    }else{
            lcd.clear();
            lcd.setCursor(1, 0);
            lcd.print("Fotovoltaico:");
            lcd.setCursor(2, 1);
            lcd.print(String(sensorValue/100) + "."+ (sensorValue - 100)+ " Volts");
            delay(TMP1);
    }    
}//FIM DO INFRA ---------------------------------------------



void ULTRAS(){
  int distance = ultrasonic.distanceInCentimeters();
      if(distance > 30){
          distance = 30;
        }
      lcd.clear();
      lcd.setCursor(2, 0);
      lcd.print("ULTRASONICO");
      lcd.setCursor(4, 1);
      lcd.print(String(distance) + " CM");
       delay(TMP1);

    
}//FIM DO ULTRA SONICO---------------------------------------------------------

//########################################################################################
void adm(){

            if(intro1 == 0){
              lcd.clear();
              lcd.setCursor(6, 0);
              lcd.print("ADM");
              delay(1500);
              intro1=1;
            }

            switch(digitalRead(bt2)){ 
              
              case 0:{
                       MSG();
                       break;     
                }

              case 1:{
                       ULTRAS();
                      break;
                    }  
               
              
              }//FIM DO SWITCH
           
}//-------------------------------------------------------------


void user(){
             if(intro2 == 0){
              lcd.clear();
              lcd.setCursor(6, 0);
              lcd.print("USER");
              delay(1500);
              intro2 = 1;
            }
            
         
      switch(digitalRead(bt1)){
       
      case 0:{

              fotoV();
              break;
        }
      case 1:{
            //Limpa a tela
  lcd.clear();
  //Posiciona o cursor na coluna 3, linha 0;
  lcd.setCursor(3, 0);
  //Envia o texto entre aspas para o LCD
  lcd.print("PROJETO_PL");
  lcd.setCursor(3, 1);
  lcd.print(" LCD 16x2");
  delay(5000);
   
  //Rolagem para a esquerda
  for (int posicao = 0; posicao < 3; posicao++)
  {
    lcd.scrollDisplayLeft();
    delay(300);
  }
   
  //Rolagem para a direita
  for (int posicao = 0; posicao < 6; posicao++)
  {
    lcd.scrollDisplayRight();
    delay(300);
  }
            break;
        }
     }//FIM DO SWITCH
  
}//--------------------------------------------------------------------------


void desenho(){
 
  int D = 16;
  
  lcd.clear();
  for(i= 0 ; i != 16 ; i++){

  D -= 1;
   
    lcd.setCursor(i, 0);
    lcd.print(" * ");
 
  
    lcd.setCursor(D, 1);
    lcd.print(" * ");

    delay(100);
    }
    
  
}//------------------------------------------------------
//########################################################################################
