// INTRODUÇÃO À AUTOMAÇÃO
// @claudiomorijr
// #4 - REVISÃO C/C++

String vr1 = "A soma total é: ";

int a = 5;
int b = 10;
int c = 0;

float d = 5.5;
float e = 6.6;
float f = 0;


char C[] = "AT";

 int var = 0;
 
void setup() {
  Serial.begin(9600);   

Serial.println("Iniciando o Arduino... ");
  Serial.println("");
}
 
void loop() {
  /*
   c = a + b;
   Serial.print("A soma total é: ");
   Serial.println(c);
   delay(1000); //1000 = 1s
*/
/*
   f = d + e;
    Serial.print("A soma total float é: ");
   Serial.println(f);
   delay(1000); //1000 = 1s
   */
  /*
  Serial.println(c);
  Serial.println(f);
  Serial.print(C);
  */

  
while (var < 200) {
  Serial.println(var);
  var++;
   delay(300);
}



}
