// INTRODUÇÃO À AUTOMAÇÃO
// @claudiomorijr
// #4 - REVISÃO C/C++

float temperatura = 45;

void setup() {
  Serial.begin(9600);   

  Serial.println("Iniciando o Arduino... ");
  Serial.println("");
}
 
void loop() {
 if (temperatura >= 40) {
  Serial.println("Perigo! Desligar o sistema");
}
else if (temperatura >= 30 && temperatura < 40) {
  Serial.println("Cuidado! Requerida a atenção do usuário");
}
else {
  Serial.println("Seguro! Continue as tarefas usuais...");
}

delay(2000);


}
