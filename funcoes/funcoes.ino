const int pinRele1 = 12; 
const int pinRele2 = 11;
const int pinRele3 = 10;
const int pinRele4 = 9;

void setup() {
 
    
   pinMode(pinRele1, OUTPUT);   
   pinMode(pinRele2, OUTPUT);   
   pinMode(pinRele3, OUTPUT);   
   pinMode(pinRele4, OUTPUT);   

   
   digitalWrite(pinRele1,HIGH);
   
  Serial.begin(9600);   

  Serial.println("Iniciando o Arduino... ");
  Serial.println("");
  
}
 
void loop() {
   if (Serial.available()) 
   {
    
    switch(Serial.read())  
    {
      case 'A': 
       rele1();
      break;
     case 'b': 
      rele2();        
      break;
    }
  }
}
