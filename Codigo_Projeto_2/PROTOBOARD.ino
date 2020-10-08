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



int const bt1 = D0;
int const bt2 = D1;

int const ldr = A0;
int const infra = D2;

int const MOD = D8;

int  LED[] = {0 , 2 , 14}; // D3 D4 D5

int const buzer = D6;

bool status1 = false; // botão 1
bool status2 = false; // botão 2
bool status3 = false; // infra vermelho
bool menu = false;


int cont = 0;

void setup() {
  
  Serial.begin(115200);
  
  pinMode(bt1, INPUT_PULLUP);
  pinMode(bt2, INPUT_PULLUP);
  pinMode(infra ,INPUT_PULLUP);
  pinMode(ldr, INPUT);

  pinMode(buzer, OUTPUT);
  pinMode(LED[0], OUTPUT);
  pinMode(LED[1], OUTPUT);
  pinMode(LED[2], OUTPUT);
  pinMode(MOD, OUTPUT);

}

void loop() {

status1 = digitalRead(bt1);
status2 = digitalRead(bt2);
status3 = digitalRead(infra);

if(status1 == true){
  delay(800);
  menu = !menu;
  cont = 0;
  
    Serial.println("MENU: " + String(menu));   
    Serial.println("BT1: " + String(status1));  
   
  }
    
        if(menu == true){
            digitalWrite(MOD, HIGH);
            MENU();
          }else{
            digitalWrite(MOD, LOW);  
            LDR();      
         }
    

}


void MENU(){
    
  if (status2 == true){
    delay(200);
    Serial.println("Bt2: " + String(status2));
    Serial.println("RGB: " + String(cont));          
    cont ++;
      if(cont == 6){
            cont = 0;
        }
    }
            if (cont == 0){
    
                  digitalWrite(LED[0], LOW);
                  digitalWrite(LED[1], LOW);
                  digitalWrite(LED[2], LOW);
    
             }else if (cont == 1){
            
                  digitalWrite(LED[0], HIGH);
                  digitalWrite(LED[1], LOW);
                  digitalWrite(LED[2], LOW);
    
              }else if (cont == 2){
            
                  digitalWrite(LED[0], LOW);
                  digitalWrite(LED[1], HIGH);
                  digitalWrite(LED[2], LOW);
    
                   
              }else if (cont == 3){
            
                  digitalWrite(LED[0], LOW);
                  digitalWrite(LED[1], LOW);
                  digitalWrite(LED[2], HIGH);
    
                
              }else if (cont == 4){
            
                  digitalWrite(LED[0], HIGH);
                  digitalWrite(LED[1], HIGH);
                  digitalWrite(LED[2], LOW);
    
              
              }else if (cont == 5){

            
                  digitalWrite(LED[0], LOW);
                  digitalWrite(LED[1], HIGH);
                  digitalWrite(LED[2], HIGH);
    
              }
                
                                    
  
}// FIM MENU

 void LDR(){
  
  
 digitalWrite(buzer, !status3);
 
    Serial.println("BUZER: " + String(!status3));
    Serial.println("LDR: " + String(analogRead(ldr)));
    
    if(analogRead(ldr) < 50 ){

         // Serial.println(" LDR :  " + String(analogRead(ldr))+ " __________");
          digitalWrite(LED[0], HIGH);
          digitalWrite(LED[1], LOW);
          digitalWrite(LED[2], LOW);      
      }else     if((analogRead(ldr) >  49)  &&  (analogRead(ldr)<  100 ) ){

          //Serial.println(" LDR :  " + String(analogRead(ldr))+ " __________");
          digitalWrite(LED[0], LOW);
          digitalWrite(LED[1], HIGH);
          digitalWrite(LED[2], LOW);      
      }else     if(analogRead(ldr) > 101 ){

         // Serial.println(" LDR :  " + String(analogRead(ldr))+ " __________");
          digitalWrite(LED[0], LOW);
          digitalWrite(LED[1], LOW);
          digitalWrite(LED[2], HIGH);      
      }
        
}// FIM LDR

  
