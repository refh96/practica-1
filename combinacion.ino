//musica
#include <pitches.h>
#define REST 0
//diodo led
int pinled1=12;
int pinled2=13;
#include <Wire.h>
//Switch
int tiempoAc = 0;
int inicioMillis = 0, finMillis = 0;
int lastR = 1, lastR2 = 1;
int actR = 1, actR2 = 1;
int both = 0;
//sensor rotacion
int actVal = 0;
int preVal = actVal;
//sensor tempLM35
float valorsensor;
int pinLM35=2;
//sensor hum&temp
#include<DHT.h>
#define DHTPIN 4
#define DHTTYPE DHT11
DHT dht(DHTPIN,DHTTYPE);

void setup() {
  Serial.begin(9600);
  dht.begin();
  pinMode(pinled1, OUTPUT);
  pinMode(pinled2, OUTPUT);
  pinMode(2, INPUT_PULLUP);
  pinMode(3, INPUT_PULLUP);
  pinMode(9, OUTPUT);
  pinMode(10, OUTPUT);
  pinMode(11, OUTPUT);
  Serial.print("Bienvenido al Menu de Arduino Uno.\n");
  Serial.print("1)-Semaforo\n");
  Serial.print("2)-Sensor DHT11\n");
  Serial.print("3)-Luces\n");
  Serial.print("4)-Sensor luminico\n");
  Serial.print("5)-Sensor temperatura LM35\n");
  Serial.print("6)-Sensor rotacion\n");
  Serial.print("7)-Switch\n");
  Serial.print("8)-Diodo Led\n");
  Serial.print("9)-Musica/Buzzer\n");
} 
void checkTime(){
    if(tiempoAc<1000){
      return;
    }
}
void ambos(){
    if(inicioMillis ==0){
      inicioMillis = millis();
    }
    finMillis = millis();
    tiempoAc = finMillis - inicioMillis;
}
int preguntarTiempo(){
  Serial.print("¿Cuantas decimas de segundo (10 decimas = 1 segundos) desea?\n");
  int aux;
  do {
    while(Serial.available()==0){
      }
    aux = Serial.parseInt();

    if(aux < 5 || aux > 50){
      Serial.println("debe estar entre 5 y 50 decimas");
      
      }
    }while(aux<5 || aux > 50);

    Serial.print(aux);
    Serial.print(" Decimas de segundo seleccionadas\n");
    return aux;
  }
void Encender(int R,int G, int B){
  digitalWrite(9, R);
  digitalWrite(10, B);
  digitalWrite(11, G);
 }
void loop() {
int num = Serial.read();
if(num == '1'){
  //semaforo:
  int decimas = 0;
  decimas = preguntarTiempo();
  int inicio = millis();
  int fin = inicio;

  while((fin - inicio)<=15000){
    Encender(0,1,0);
    delay(100*decimas);
    Encender(1,1,0);
    delay(100*decimas);
    Encender(1,0,0);
    delay(100*decimas);
    fin = millis();
    }
    Encender(0,0,0);
}else if(num == '2'){
  // sensor hum&temp
  int t=0;
  do{
  delay(1000);
  float humedad= dht.readHumidity();
  float temperatura = dht.readTemperature();
  Serial.print("Humedad: ");
  Serial.print(humedad);
  Serial.print("%\t");
  Serial.print("\nTemperatura: ");
  Serial.print(temperatura);
  Serial.print("*C");
  Serial.print("\n");
  }while(t==0);
}else if(num == '3'){
  //Luces
  delay(1000);
  Serial.print("a)Azul\n");
  Serial.print("b)Verde\n");
  Serial.print("c)Rojo\n");
  Serial.print("d)celeste\n");
  Serial.print("e)amarillo\n");
  Serial.print("f)morado\n");
  Serial.print("g)blanco\n");
  int inicio = millis();
  int fin = inicio;
  while((fin - inicio)<=15000){
        char dato = Serial.read();
        if(dato == 'a'){
          Serial.println("Azul");
          Encender(0,0,1);
          delay(100);
        }
        if(dato =='b'){
          Serial.println("Verde");
          Encender(0,1,0);
          delay(100);
        }
        if(dato =='c'){
          Serial.println("Rojo");
          Encender(1,0,0);
          delay(100);
        }
        if(dato =='d'){
          Serial.println("Celeste");
          Encender(0,1,1);
          delay(100);
        }
        if(dato =='e'){
          Serial.println("Amarillo");
          Encender(1,1,0);
          delay(100);
        }
        if(dato =='f'){
          Serial.println("Morado");
          Encender(1,0,1);
          delay(100);
        }
        if(dato =='g'){
          Serial.println("Blanco");
          Encender(1,1,1);
          delay(100);
        }
    fin = millis();
   }
   Encender(0,0,0);
}else if(num == '4'){
   //sensor luminico
  int x=0;
  do{
   delay(1000);
   int v = analogRead(A1);
   Serial.print("intensidad luminica: ");
   Serial.println(v);
  }while(x==0);
}else if(num == '5'){
   //sensor tempLM35
  int e=0;
  do{
   delay(1000);
   valorsensor=analogRead(pinLM35);
   valorsensor=(5.0*valorsensor*100.0)/1024.0;
   Serial.print("temperatura actual: ");
   Serial.println(valorsensor);
   delay(4000);
  }while(e==0);
}else if(num == '6'){
   // sensor rotacion o potenciometro
  int w=0;
  do{
   delay(1000);
   Serial.print("potenciometro: ");
   float aux = analogRead(A0);
   Serial.print(aux);
   Serial.print(" \nAngulo: ");
   float escalaAuxl = float(aux)*320/1023;
   Serial.print(escalaAuxl);
   Serial.print(" \nAngulo persiana: ");
   float escalaAux2= escalaAuxl*180/320 -90;
   Serial.println(escalaAux2);

   delay(50);
  }while(w==0);
}else if(num == '7'){
   // Switch
   int y=0;
  do{
   delay(1000);
   actR = digitalRead(2);
   actR2 = digitalRead(3); 
   delay(10);
   if((1-actR)*(1-actR2)){
     ambos();
   }else if(abs((lastR - actR)*(lastR2 - actR2))){
     checkTime();
   }else{
     tiempoAc = 0;
     inicioMillis = 0;
     finMillis = 0;
   }
  
   Serial.print("Boton 1:");
   if(1 - actR){
     Serial.print("pulsado");
     }else{
       Serial.print("No pulsado");
   }
   Serial.print(" \nBoton 2:");
   if(1 - actR2){
     Serial.print("pulsado");
   }else{
     Serial.print("No pulsado");
   }
   Serial.print("\n");
   Serial.print(" \nTiempo Acumulado: ");
   Serial.println(float(tiempoAc)/1000);

   lastR = actR;
   lastR2 = actR2;
  }while(y==0);
}else if(num=='8'){
   // diodo led
   int CAD = 0;
   CAD = preguntarTiempo();
   int inicio = millis();
   int fin = inicio;

   while((fin - inicio)<=inicio){
    digitalWrite(pinled1,HIGH);

    digitalWrite(pinled2,HIGH);

    fin = millis();
    }
    
    digitalWrite(pinled1, LOW);
    digitalWrite(pinled2,LOW);
}else if(num =='9'){
  //musica
  
          Serial.println("Noche de paz");
          int tempo = 140;
          int buzzer = 5;
          int melody[] = {

  
  

            NOTE_G4,-4, NOTE_A4,8, NOTE_G4,4,
            NOTE_E4,-2, 
            NOTE_G4,-4, NOTE_A4,8, NOTE_G4,4,
            NOTE_E4,-2, 
            NOTE_D5,2, NOTE_D5,4,
            NOTE_B4,-2,
            NOTE_C5,2, NOTE_C5,4,
            NOTE_G4,-2,

            NOTE_A4,2, NOTE_A4,4,
            NOTE_C5,-4, NOTE_B4,8, NOTE_A4,4,
            NOTE_G4,-4, NOTE_A4,8, NOTE_G4,4,
            NOTE_E4,-2, 
            NOTE_A4,2, NOTE_A4,4,
            NOTE_C5,-4, NOTE_B4,8, NOTE_A4,4,
            NOTE_G4,-4, NOTE_A4,8, NOTE_G4,4,
            NOTE_E4,-2, 
  
            NOTE_D5,2, NOTE_D5,4,
            NOTE_F5,-4, NOTE_D5,8, NOTE_B4,4,
            NOTE_C5,-2,
            NOTE_E5,-2,
            NOTE_C5,4, NOTE_G4,4, NOTE_E4,4,
            NOTE_G4,-4, NOTE_F4,8, NOTE_D4,4,
            NOTE_C4,-2,
            NOTE_C4,-1,
 
           };
           int notes = sizeof(melody) / sizeof(melody[0]) / 2;
           int wholenote = (60000 * 4) / tempo;
           int divider = 0, noteDuration = 0;

           for (int thisNote = 0; thisNote < notes * 2; thisNote = thisNote + 2) {
               divider = melody[thisNote + 1];
            if (divider > 0) {
               noteDuration = (wholenote) / divider;
            } else if (divider < 0) {
               noteDuration = (wholenote) / abs(divider);
               noteDuration *= 1.5;
            }
             tone(buzzer, melody[thisNote], noteDuration * 0.9);
             delay(noteDuration);
             noTone(buzzer);
            }
            delay(100);
           }
 
}
