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
 
}
 
void loop() {

}
