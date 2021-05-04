// INTRODUÇÃO À AUTOMAÇÃO
// @claudiomorijr
// #4 - REVISÃO C/C++

int var = 1;

void setup() {
  Serial.begin(9600);   

  Serial.println("Iniciando o Arduino... ");
  Serial.println("");
}
 
void loop() {

switch (var) {
  case 1:
    Serial.println("A informação é 1");
    break;
  case 2:
    Serial.println("A informação é 2");
    break;
  default:
    Serial.println("Sem informação");
    break;
}


delay(2000);


}
