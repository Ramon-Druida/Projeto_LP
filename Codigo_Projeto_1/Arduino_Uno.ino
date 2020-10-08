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


#include "RFIDRdm630.h"

char leitura();

char admTAG[] = "250034222211";
char userTAG[] = "25003494CE4B";
char stopTAG[] = "2500347F8FE1";

bool ADM = false;
bool USER = false;

bool OUT1 = false;
bool OUT2= false;
bool estado = true;

const int rxPin = 0;  // pin that will receive the data
const int txPin = 1;  // connection not necessary.

RFIDtag  tag;  // RFIDtag object

RFIDRdm630 reader = RFIDRdm630(rxPin,txPin);    // the reader object.

const int irqPin = 2; // IRQ on pin 2.

int const adm = 2;
int const user = 3;

int const rele = 5;
int const bt1 = 6;
int const bt2 = 7;
int const out1 = 8;
int const out2 = 9;


int cont = 0;

void setup() {

  Serial.begin(115200);   // open the Serial for show data
  
  Serial.print("\n RFID INICIADO \n");

  pinMode(adm, OUTPUT);
  pinMode(user, OUTPUT);

  pinMode(rele, OUTPUT);
  pinMode(out1, OUTPUT);
  pinMode(out2, OUTPUT);
  pinMode(bt1, INPUT_PULLUP);
  pinMode(bt2, INPUT_PULLUP);

  digitalWrite(out1, OUT1);
  digitalWrite(out2, OUT2);
   digitalWrite(rele, HIGH);
  digitalWrite(adm, ADM);
  digitalWrite(user,USER);


  Serial.println("\n PINOS INICIADOS ");
}





void loop() {

  
   

   if(digitalRead(bt2) > 0){
      delay(500);
      OUT1 = !OUT1;
      digitalWrite(out1, OUT1);
      Serial.println("BOTÂO APERTADO ==> OUT1 : " + String(OUT1));
    }
   
   if((digitalRead(bt1) > 0 ) && ( USER == true)){
    delay(500);
    estado = !estado;
    digitalWrite(rele, estado);
    Serial.println("BOTÂO APERTADO ==> ESTADO : " + String(estado));
    
    }else if((digitalRead(bt1) > 0) && (ADM == true )){
      delay(500);
     
      OUT2 = !OUT2;
      digitalWrite(out2, OUT2);
      Serial.println("------------------------------------------");
      Serial.println("BOTÂO APERTADO ==> OUT2 : " + String(OUT2));
        
    }

    leitura();
    
}

char leitura(){

  if (reader.isAvailable()){  // tests if a card was read by the module

 tag = reader.getTag();  // if true, then receives a pointer to an tag object

  Serial.println(tag.getTag());
  
  if(strcmp(tag.getTag(),admTAG) == 0){


      
          USER = false;
          ADM = true;
          digitalWrite(user,USER);
          digitalWrite(adm, ADM);
          Serial.println(" ADM: " + String(ADM) + " USER: " + String(USER));
          
      }else if(strcmp(tag.getTag(),userTAG) == 0){

            ADM = false;
            USER = true;

            digitalWrite(adm, ADM);
            digitalWrite(user,USER);
             Serial.println(" ADM: " + String(ADM) + " USER: " + String(USER)); 
           
        
       }else if(strcmp(tag.getTag(),stopTAG) == 0){
        
           USER = false;
           ADM = false;
          digitalWrite(adm, ADM);
          digitalWrite(user,USER);
;
          Serial.println(" ADM: " + String(ADM) + " USER: " + String(USER));
        }
 }
}
