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



#include <WiFi.h>
#include <WiFiClient.h>
#include <WiFiAP.h>
 
const int Rele1 = 15;
const int Rele2 = 02;
const int Rele3 = 04;

const char *ssid = "PROJETO_LP";
const char *password = "password";
 
  bool Estado_Do_Rele1 = HIGH;
  bool Estado_Do_Rele2 = HIGH;
  bool Estado_Do_Rele3 = HIGH;
  
  bool am = false;
  bool rs = false;
  bool ci = false;
  bool br = false;


     
  WiFiServer server(80);
 
void setup() {
        pinMode(Rele1, OUTPUT);
        pinMode(Rele2, OUTPUT);
        pinMode(Rele3, OUTPUT);
          
          digitalWrite(Rele1, HIGH);
          digitalWrite(Rele2, HIGH);
          digitalWrite(Rele3, HIGH);
          
        Serial.begin(115200);
         Serial.println();
         Serial.println("configurando...");
         
        WiFi.softAP(ssid, password);
          IPAddress myIP = WiFi.softAPIP();
          Serial.print("O Endereço IP Da Rede : ");
          Serial.println(myIP);
         
        //inicia o webserver
        server.begin();
         
          Serial.println("Servidor Iniciado!!");
}


void loop() {
 
  WiFiClient client = server.available(); // verifica e armazena se tem clientes conectados na rede
     
  if (client) { // se você conseguir um cliente,
          Serial.println("Novo Cliente."); // imprime uma mensagem pela porta serial
          String currentLine = ""; // faz uma String para manter os dados recebidos do cliente
          while (client.connected()) { // loop enquanto o cliente está conectado
          if (client.available()) { // se houver bytes para ler do cliente,
          char c = client.read(); // leia um byte e depois
          Serial.write(c); // imprima o monitor serial
    if (c == '\n') { // se o byte for um caractere de nova linha
      
        
        /* se a linha atual estiver em branco, você terá dois caracteres de nova linha em uma linha.
        esse é o fim da solicitação HTTP do cliente, então envie uma resposta: */
      if (currentLine.length() == 0) {
        /* Os cabeçalhos HTTP sempre começam com um código de resposta (por exemplo, HTTP / 1.1 200 OK)
        e um tipo de conteúdo para que o cliente saiba o que está por vir e, em seguida, uma linha em branco: */
        client.println("HTTP/1.1 200 OK");
        client.println("Content-type:text/html");
        client.println();
            
        
        // configuração de estilo do site
        //client.print("<style type=\"text/css\"> a{margin: 50px 50px; background: #000000; color: #ffffff; text-decoration: none; padding: 1% 20% 1%; border-radius: 10px; font-size: 8.0em;}</style>");
        
        client.print(
          "<head>"
          "<meta name='viewport' content='width=device-width, initial-scale=1, user-scalable=no'/>"
          "<title>PROJETO LP</title>"
          "<style>"
          "body{"
          "background-color: black;"
          "text-align: center;"
          "font-family: sans-serif;"
          "font-size: 14px;"
          "padding: 25px;"
          " }"
          "p{"
          "color: #444;"
          "}"
          "#bt1{"        
          "outline: none;"
          "border: 8px solid #ffffff;"
          "border-radius: 100px;"
          "background-color: #ff0000;"
          "color: #ffffff;"
          "padding: 25px 25px;"
          "}"
          "#bt1:active{"
          " color: #fff;"
          " background-color: black;"
          "}"
          "#bt2{"        
          "outline: none;"
          "border: 8px solid #ffffff;"
          "border-radius: 100px;"
          "background-color: #00ff00;"
          "color: #020202;"
          "padding: 25px 25px;"
          "}"
          "#bt2:active{"
          "color: #fff;"
          "background-color: black;"
          "}"
          "#bt3{"
          "outline: none;"
          "border: 8px solid #ffffff;"
          "border-radius: 100px;"
          "background-color: #1100ff;"
          "color: #020202;"
          "padding: 25px 25px;"
          "}"
          "#bt3:active{"
          "color: #fff;"
          "background-color: black;"
          "}"
          "#bt4{"
          "outline: none;"
          "border: 8px solid #ffffff;"
          "border-radius: 100px;"
          "background-color: #fbff00;"
          "color: #020202;"
          "padding: 25px 25px;"
          "}"
          "#bt4:active{"
          "color: #fff;"
          "background-color: black;"
          "}"
          "#bt5{"
          "outline: none;"
          "border: 8px solid #ffffff;"
          "border-radius: 100px;"
          "background-color: #ff00f2;"
          "color: #020202;"
          "padding: 25px 25px;"
          "}"
          "#bt5:active{"
          "color: #fff;"
          "background-color: black;"
          "}"
          "#bt6{"
          "outline: none;"
          "border: 8px solid #ffffff;"
          "border-radius: 100px;"
          "background-color: #00f7ff;"
          "color: #020202;"
          "padding: 25px 25px;"
          "}"
          "#bt6:active{"
          "color: #fff;"
          "background-color: black;"
          "}"
          "#bt7{"
          "outline: none;"
          "border: 8px solid #575757;"
          "border-radius: 100px;"
          "background-color: #fff;"
          "color: #020202;"
          "padding: 25px 25px;"
          "}"
          "#bt7:active{"
          "color: #fff;"
          "background-color: black;"
          "}"
          "#bt8{"
          "outline: none;"
          "border: 8px solid #fff;"
          "border-radius: 100px;"
          "background-color: #575757;"
          "color: #020202;"
          "padding: 25px 25px;"
          "}"
          "#tl{"
          "text-align: center;"
          "color:white;"
          "}"
          "h1{"
          "color:white;"
          "}"
          "</style>"
          "</head>" );

        
        client.print(  "<body>");
        client.print(   "<h1> PROJETO LP </h1> </br>");
            
        client.print("<table>");
          
        client.print("<h1 id='tl'>"
          
        "R&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;"
        "G&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;" 
        "B </h1>");
                  
        client.print("<tr> ");
            
        client.print(   "<a href=\"/T1\"><button id = 'bt1' > </button></a>&nbsp;&nbsp;&nbsp;&nbsp;");
        client.print(   "<a href=\"/T2\"><button id = 'bt2' > </button></a>&nbsp;&nbsp;&nbsp;&nbsp;");
        client.print(   "<a href=\"/T3\"><button id = 'bt3' > </button></a>&nbsp;&nbsp;&nbsp;&nbsp;");
            
        client.print("</tr> ");
        client.print("<h1> ____________________</h1>");
          
        client.print("<table>");
        client.print("<tr>");
        client.print(   "<a href=\"/T4\"><button id = 'bt4' > </button></a>&nbsp;&nbsp;&nbsp;&nbsp;");
        client.print(   "<a href=\"/T5\"><button id = 'bt5' > </button></a>&nbsp;&nbsp;&nbsp;&nbsp;");
        client.print(   "<a href=\"/T6\"><button id = 'bt6' > </button></a>&nbsp;&nbsp;&nbsp;&nbsp;");
          
        client.print("</tr>");
        client.print("</table>");
            
        client.print( " </br></br> <a href=\"/T7\"><button id = 'bt7' > </button></a>");
          
        client.print("<h1> ____________________</h1>");
          
        client.print(   "<h1>SHOW</h1>");
        client.print(   "<a href=\"/T8\"><button id = 'bt8' > </button></a>");
          
        client.print(   "</body>");
        client.print(  "</html>" );
          
          
        // A resposta HTTP termina com outra linha em branco:
        client.println();
        // sair do loop while:
        break;
      } else { // se você tiver uma nova linha, então limpe a linha atual:
        currentLine = "";
      }
    } else if (c != '\r') { // se você tiver qualquer outra coisa além de um caractere de retorno de linha,
      currentLine += c; // adicioná-lo ao final da linha atual
    }
      
    // Verifica se o pedido do cliente foi para atualizar algum dos reles (GET /T)
      
    if (currentLine.endsWith("GET /T1")) {
      
      Estado_Do_Rele1 = !Estado_Do_Rele1;
      digitalWrite(Rele1, Estado_Do_Rele1);
          
      digitalWrite(Rele2, HIGH);
      digitalWrite(Rele3, HIGH);
        if(Estado_Do_Rele1 == HIGH){
            br = true;
            rs = true;  
            am = true;
            ci = true; 
        }
          
      Serial.println("\n\n T1 ESTADO BOOL => " + String(Estado_Do_Rele1) + " \t rele1: " + String(digitalRead(Rele1)) + "\trele2: " + String(digitalRead(Rele2)) + "\trele3: " + String(digitalRead(Rele3)));
          
      
    }
    
    if (currentLine.endsWith("GET /T2")) {
      
      Estado_Do_Rele2 = !Estado_Do_Rele2;
      digitalWrite(Rele2, Estado_Do_Rele2);
      digitalWrite(Rele1, HIGH);
      digitalWrite(Rele3, HIGH);

        if(Estado_Do_Rele2 == HIGH){
          br = true;
          rs = true;  
          am = true;
          ci = true; 
        }
          
          
      Serial.println("\n\n T2 ESTADO BOOL => " + String(Estado_Do_Rele2) + "\trele1: " + String(digitalRead(Rele1)) + "\trele2: " + String(digitalRead(Rele2)) + "\trele3: " + String(digitalRead(Rele3)));
          
    }

    if (currentLine.endsWith("GET /T3")) {
          
      Estado_Do_Rele3 = !Estado_Do_Rele3;
      digitalWrite(Rele3, Estado_Do_Rele3);
      digitalWrite(Rele2, HIGH);
      digitalWrite(Rele1, HIGH);
        if(Estado_Do_Rele3 == HIGH){
          br = true;
          rs = true;  
          am = true;
          ci = true; 
        }
          
      Serial.println("\n\nT3 ESTADO BOOL => " + String(Estado_Do_Rele3) + "\trele1: " + String(digitalRead(Rele1)) + "\trele2: " + String(digitalRead(Rele2)) + "\trele3: " + String(digitalRead(Rele3)));
          
    }
      
    if (currentLine.endsWith("GET /T4")) {
      
      if(Rele1 == LOW || Rele2 == LOW || Rele3 == LOW){
        
        digitalWrite(Rele1, HIGH);
        
        digitalWrite(Rele2, HIGH);
          
        digitalWrite(Rele3, HIGH);  
      
        br = true;
        rs = true;  
        am = true;
        ci = true; 
      }
          
      if(am == true){
          
        digitalWrite(Rele1, LOW);
          
        digitalWrite(Rele2, LOW);
          
        digitalWrite(Rele3, HIGH); 
            
        am = false;

        Estado_Do_Rele1 = HIGH;
        Estado_Do_Rele3 = HIGH;
        Estado_Do_Rele3 = HIGH;
          
      }else{
      
        digitalWrite(Rele1, HIGH);
          
        digitalWrite(Rele2, HIGH);
          
        digitalWrite(Rele3, HIGH); 
      
        br = true;
        rs = true;  
        am = true;
        ci = true; 
      }
      
      Serial.println("\n\nT4 ESTADO AM => " + String(am) + "\trele1: " + String(digitalRead(Rele1)) + "\trele2: " + String(digitalRead(Rele2)) + "\trele3: " + String(digitalRead(Rele3)));
    }
      
    if (currentLine.endsWith("GET /T5")) {
          

      if(Rele1 == LOW || Rele2 == LOW || Rele3 == LOW){
              
        digitalWrite(Rele1, HIGH);
          
        digitalWrite(Rele2, HIGH);
          
        digitalWrite(Rele3, HIGH); 
        
        br = true;
        rs = true;  
        am = true;
        ci = true;
      }
          
      if(rs == true){
          
        digitalWrite(Rele1, LOW);
          
        digitalWrite(Rele2, HIGH);
          
        digitalWrite(Rele3, LOW); 
          
        rs = false;
    
        Estado_Do_Rele1 = HIGH;
        Estado_Do_Rele3 = HIGH;
        Estado_Do_Rele3 = HIGH;
            
      }else{
            
        digitalWrite(Rele1, HIGH);
          
        digitalWrite(Rele2, HIGH);
          
        digitalWrite(Rele3, HIGH); 

        br = true;
        rs = true;  
        am = true;
        ci = true;   
            
      }
  
      Serial.println("\n\nT5 ESTADO RS => " + String(rs) + "\trele1: " + String(digitalRead(Rele1)) + "\trele2: " + String(digitalRead(Rele2)) + "\trele3: " + String(digitalRead(Rele3)));
      
    }
      
    if (currentLine.endsWith("GET /T6")) {
      
      if(Rele1 == LOW || Rele2 == LOW || Rele3 == LOW){
      
        digitalWrite(Rele1, HIGH);
          
        digitalWrite(Rele2, HIGH);
          
        digitalWrite(Rele3, HIGH); 
        
        br = true;
        rs = true;  
        am = true;
        ci = true;
      }
          
      if(ci == true ){
      
        digitalWrite(Rele1, HIGH);
          
        digitalWrite(Rele2, LOW);
          
        digitalWrite(Rele3, LOW); 
            
        ci = false;
    
        Estado_Do_Rele1 = HIGH;
        Estado_Do_Rele3 = HIGH;
        Estado_Do_Rele3 = HIGH;
            
      }else{
      
        digitalWrite(Rele1, HIGH);
                
        digitalWrite(Rele2, HIGH);
            
        digitalWrite(Rele3, HIGH); 
        
        ci = true;
        br = true;
        rs = true;  
        am = true;
      }
      
      Serial.println("\n\nT6 ESTADO CI => " + String(ci) + "\trele1: " + String(digitalRead(Rele1)) + "\trele2: " + String(digitalRead(Rele2)) + "\trele3: " + String(digitalRead(Rele3)));
    }

    if (currentLine.endsWith("GET /T7")) {
      
      
      if(br == true ){
      
        digitalWrite(Rele1, LOW);
        digitalWrite(Rele2, LOW);
        digitalWrite(Rele3, LOW);
      
        br = false;

            
        Estado_Do_Rele1 = HIGH;
        Estado_Do_Rele3 = HIGH;
        Estado_Do_Rele3 = HIGH;
            
      }else if(br == false){
              
        digitalWrite(Rele1, HIGH);
        digitalWrite(Rele2, HIGH);
        digitalWrite(Rele3, HIGH);
       
        br = true;
        rs = true;  
        am = true;
        ci = true; 
      }
      
      Serial.println("\n\nT7 ESTADO BR => " + String(br) + "\trele1: " + String(digitalRead(Rele1)) + "\trele2: " + String(digitalRead(Rele2)) + "\trele3: " + String(digitalRead(Rele3)));
    }
      
      
    if (currentLine.endsWith("GET /T8")) {
      
      digitalWrite(Rele2, LOW);
      delay(200);
      digitalWrite(Rele2, HIGH);
      
        
      digitalWrite(Rele1, LOW);
      delay(200);
      digitalWrite(Rele1, HIGH);
        
      digitalWrite(Rele3, LOW);
      delay(200);
      digitalWrite(Rele3, HIGH);
          
      digitalWrite(Rele2, LOW);
      delay(200);
      digitalWrite(Rele2, HIGH);
      
        
      digitalWrite(Rele1, LOW);
      delay(200);
      digitalWrite(Rele1, HIGH);
          
      digitalWrite(Rele3, LOW);
      delay(200);
      digitalWrite(Rele3, HIGH);
            
      digitalWrite(Rele1, LOW);
          
      digitalWrite(Rele2, LOW);
        
      digitalWrite(Rele3, LOW);
      delay(200);
          
      digitalWrite(Rele1, HIGH);
          
      digitalWrite(Rele2, HIGH);
        
      digitalWrite(Rele3, HIGH);
        
    }
  }//cliente available
  }//client conected
  }//client
  // termina a conexão com o cliente
  client.stop();
  //Serial.println("Cliente desconectado.");
} // fim do loop
