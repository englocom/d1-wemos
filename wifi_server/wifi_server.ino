#include <ESP8266WiFi.h>
 
const char* ssid = "AUTOMACAO";
const char* password = "12345678";
 
WiFiServer server(80);
 
void setup() {
  Serial.begin(9600);
  delay(10);
 
  Serial.println();
  Serial.println();
  
  Serial.print("Conectando a ");
  Serial.println(ssid);
 
  WiFi.begin(ssid, password);
 
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  
  Serial.println("");
  Serial.println("WiFi conectado");
 
  server.begin();
  Serial.println("Server iniciado");

   Serial.print("URL do servidor: ");
  Serial.print("http://");
  Serial.print(WiFi.localIP());
  Serial.println("/");

  pinMode(D7, OUTPUT);
  pinMode(D6, OUTPUT);
  pinMode(D5, OUTPUT);
  pinMode(D4, OUTPUT);

  
}
 
void loop() {

  WiFiClient client = server.available();
  if (!client) {
    return;
  }
 
  Serial.println("Novo acesso");
  while(!client.available()){
    delay(1);
  }
 
  String request = client.readStringUntil('\r');
  Serial.println(request);
  client.flush();

  int value = HIGH;
  if (request.indexOf("/LED=ON") != -1) {
    digitalWrite(D7, LOW);
    value = LOW;
  }
  if (request.indexOf("/LED=OFF") != -1){
    digitalWrite(D7, HIGH);
    value = HIGH;
  }

    if (request.indexOf("/LED2=ON") != -1) {
    digitalWrite(D6, LOW);
    value = LOW;
  }
  if (request.indexOf("/LED2=OFF") != -1){
    digitalWrite(D6, HIGH);
    value = HIGH;
  }


 if (request.indexOf("/LED3=ON") != -1) {
    digitalWrite(D5, LOW);
    value = LOW;
  }
  if (request.indexOf("/LED3=OFF") != -1){
    digitalWrite(D5, HIGH);
    value = HIGH;
  }

  if (request.indexOf("/LED4=ON") != -1) {
    digitalWrite(D4, LOW);
    value = LOW;
  }
  if (request.indexOf("/LED4=OFF") != -1){
    digitalWrite(D4, HIGH);
    value = HIGH;
  }

  
  if (request.indexOf("/LEDS=ON") != -1) {
    digitalWrite(D7, LOW);
    digitalWrite(D6, LOW);
    digitalWrite(D5, LOW);
    digitalWrite(D4, LOW);
    value = LOW;
  }
  if (request.indexOf("/LEDS=OFF") != -1){
    digitalWrite(D7, HIGH);
    digitalWrite(D6, HIGH);
    digitalWrite(D5, HIGH);
    digitalWrite(D4, HIGH);
    value = HIGH;
  }
  
 
  client.println("HTTP/1.1 200 OK");
  client.println("Content-Type: text/html");
  client.println(""); 
  client.println("<!DOCTYPE HTML>");
  client.println("<html>");
 
  client.print("Led esta: ");
 
  if(value == HIGH) {
    client.print("OFF");  
  } else {
    client.print("ON");
  }
  client.println("<br><br>");
  client.println("Clique <a href=\"/LED=ON\">aqui</a> para ON RELE 1<br>");
  client.println("Clique <a href=\"/LED2=ON\">aqui</a> para ON RELE 2<br>");
  client.println("Clique <a href=\"/LED3=ON\">aqui</a> para ON RELE 3<br>");
  client.println("Clique <a href=\"/LED4=ON\">aqui</a> para ON RELE 4<br><br>");
  
  client.println("Clique <a href=\"/LED=OFF\">aqui</a> para OFF RELE 1<br>");
  client.println("Clique <a href=\"/LED2=OFF\">aqui</a> para OFF RELE 2<br>");
  client.println("Clique <a href=\"/LED3=OFF\">aqui</a> para OFF RELE 3<br>");
  client.println("Clique <a href=\"/LED4=OFF\">aqui</a> para OFF RELE 4<br>");


  client.println("Clique <a href=\"/LEDS=ON\">aqui</a> para ON todos RELES<br>");
  client.println("Clique <a href=\"/LEDS=OFF\">aqui</a> para OFF todos RELES<br>");

    
  client.println("</html>");
 
  delay(1);
  Serial.println("Cliente desconectado");
  Serial.println("");

  
 
}
