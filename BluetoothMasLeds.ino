
#include <SoftwareSerial.h>
SoftwareSerial BTSerial(10,11);
int x;
int ledVerde = 9; 
int ledAzul = 3; 
int ledRojo = 5;
int ledStand = 6;
int r, g, b, s;
int cont1, cont2;
int numRand;
bool flag = true; 
int fadeL, fadeM, fadeR;

char Letra;
void setup() {
  // put your setup code here, to run once:

  Serial.begin(9600);
  BTSerial.begin(9600);
  pinMode(ledAzul, OUTPUT);
  pinMode(ledRojo, OUTPUT);
  pinMode(ledVerde, OUTPUT);
  pinMode(ledStand, OUTPUT);
  Serial.setTimeout(1);

}
void delays()
      {
        if(fadeL==1){
          delay(50);
        }
        else if(fadeM==1){
          delay(20);
        }
        else if(fadeR==1)
        {
          delay(3);
        }
        else
        {
          delay(20);
          fadeL=0;
          fadeM=0;
          fadeR=0;
        }
      }

void delays2()
{
  if(fadeL==1)
    {
   delay(2000);
    }
    else if(fadeM==1)
    {
    delay(500);
    }

    else if(fadeR==1)
    {
      delay(100);
    }
    else{
    delay(500);
    }
}
void loop()

{  
  int fadetime;

  
if (BTSerial.available()){
    Letra = BTSerial.read(); 
     Serial.println(Letra); 
        
     if(Letra == 'Z'){
      fadeL=1;
      fadeM=0;
      fadeR=0;
      r=0;
                                        g=0;
                                        b=0;
      
     }
     else if(Letra == 'W'){
      fadeL=0;
      fadeM=1;
      fadeR=0;
      r=0;
                                        g=0;
                                        b=0;
     }
     else if(Letra == 'L'){
      fadeL=0;
      fadeM=0;
      fadeR=1;
      r=0;
                                        g=0;
                                        b=0;
     }
      
      else if (Letra == 'R') //SI FUCKING ROJO
      {
        digitalWrite(ledStand, HIGH);
        digitalWrite(ledRojo, HIGH);
        if(b>0||g>0)
        {
          for(b;b>0;b--)
          {
          analogWrite(ledAzul,b);
          delay(10);
          }
                                        b=0;
            for(g;g>0;g--)
            {
            analogWrite(ledVerde,g);
            delay(10);
            }
                                        g=0;
              if(r!=255)
              {
                for(r;r<255;r++)
                {
                analogWrite(ledRojo,r);
                delay(10);
                }
              }
          }
          else
        {
          for(r=0;r<255;r++)
          {
          analogWrite(ledRojo, r);
          analogWrite(ledAzul, 0);
          analogWrite(ledVerde, 0);
          delay(10);
          }
                                        r=255;
                                        g=0;
                                        b=0;
        }
    }
    

    //SI FUCKING N
    else if(Letra == 'N') //FUCKING NARANJA 
    {
      digitalWrite(ledStand, LOW);
      if(b>0||g>10)
        {
          for(b;b>0;b--)
          {
          analogWrite(ledAzul,b);
          delay(10);
          }
                                        b=0;
            if(g>10){
            for(g;g>10;g--)
            {
            analogWrite(ledVerde,g);
          delay(10);
          }
            }
            else{
            for(g;g<10;g++)
        {
        analogWrite(ledVerde,g);
        delay(10);
        }
            }
                                        g=10;
              if(r<255)
              {
                for(r;r<255;r++)
                {
                analogWrite(ledRojo,r);
                delay(10);
                }
              }
          }
      else if(r==255&&g!=10){
        for(g;g<10;g++){
          analogWrite(ledVerde,g);
          delay(10);
        }
                                        g=10;
      }
        else
        {
        for(r;r<255;r++)
        {
        g=map(r, 1, 255, 0, 20);
        analogWrite(ledRojo,r);
        analogWrite(ledVerde, g);
        analogWrite(ledAzul, 0);
        delay(10);
        }
                                      r=255;
                                      g=20;
                                      b=0;
     }
    }    
    else if(Letra == 'V') //FUCKING VERDE
      {
        cont1+=5;
      if(b>0||r>0)
        {
          for(b;b>0;b--)
          {
          analogWrite(ledAzul,b);
          delay(10);
          }
                                        b=0;
            for(r;r>0;r--)
            {
            analogWrite(ledRojo,r);
            delay(10);
            }
                                        r=0;
              if(g!=255)
              {
                for(g;g<255;g++)
                {
                analogWrite(ledVerde,g);
                delay(10);
                }
              }
          }
          else
        {
          for(g=0;g<255;g++)
          {
          analogWrite(ledRojo, 0);
          analogWrite(ledAzul, 0);
          analogWrite(ledVerde, g);
          delay(10);
          }
                                        r=0;
                                        g=255;
                                        b=0;
    }
      }
    else if(Letra == 'B')//FUCKING ROSA 
    {
      if(g>0||b>20)
        {
          for(g;g>0;g--)
          {
          analogWrite(ledVerde,g);
          delay(10);
          }
                                        g=0;
            if(b>20){
            for(b;b>20;b--)
            {
            analogWrite(ledAzul,b);
          delay(10);
          }
            }
            else{
            for(b;b<20;b++)
        {
        analogWrite(ledAzul,b);
        delay(10);
        }
            }
                                        b=20;
              if(r<255)
              {
                for(r;r<255;r++)
                {
                analogWrite(ledRojo,r);
                delay(10);
                }
              }
          }
      else if(r==255&&b!=20){
        for(b;b<20;b++){
          analogWrite(ledAzul,b);
          delay(10);
        }
                                        b=20;
      }
        else
        {
        for(r;r<255;r++)
        {
        b=map(r, 1, 255, 0, 20);
        analogWrite(ledRojo,r);
        analogWrite(ledVerde, 0);
        analogWrite(ledAzul, b);
        delay(10);
        }
                                      r=255;
                                      g=0;
                                      b=20;
    }
    }
    else if(Letra == 'U')//FUCKING AZUL
    {
      if(r>0||g>0)
        {
          for(r;r>0;r--)
          {
          analogWrite(ledRojo,r);
          delay(10);
          }
                                        r=0;
            for(g;g>0;g--)
            {
            analogWrite(ledVerde,g);
            delay(10);
            }
                                        g=0;
              if(b!=255)
              {
                for(b;b<255;b++)
                {
                analogWrite(ledAzul,b);
                delay(10);
                }
              }
          }
          else
        {
          for(b=0;b<255;b++)
          {
          analogWrite(ledRojo, 0);
          analogWrite(ledAzul, b);
          analogWrite(ledVerde, 0);
          delay(10);
          }
                                        r=0;
                                        g=0;
                                        b=255;
        }
    }
    
      else if (Letra == 'X')//FUCKING VIOLETA 
      {
      if(g>0||r>40)
        {
          for(g;g>0;g--)
          {
          analogWrite(ledVerde,g);
          delay(10);
          }
                                        g=0;
            if(r>20){
            for(r;r>20;r--)
            {
            analogWrite(ledRojo,r);
          delay(10);
          }
            }
            else{
            for(r;r<20;r++)
        {
        analogWrite(ledRojo,r);
        delay(10);
        }
            }
                                        r=40;
              if(b<255)
              {
                for(b;b<255;b++)
                {
                analogWrite(ledAzul,b);
                delay(10);
                }
              }
          }
      else if(b==255&&r!=40){
        for(r;r<20;r++){
          analogWrite(ledRojo,r);
          delay(10);
        }
                                        r=40;
      }
        else
        {
        for(b;b<255;b++)
        {
        r=map(b, 1, 255, 0, 40);
        analogWrite(ledRojo,r);
        analogWrite(ledVerde, 0);
        analogWrite(ledAzul, b);
        delay(10);
        }
                                      r=40;
                                      g=0;
                                      b=255;
    }
   }
      
      else if (Letra == 'Y')//FUCKING AMARILLO 
      {
      if(b>0||g>70)
        {
          for(b;b>0;b--)
          {
          analogWrite(ledAzul,b);
          delay(10);
          }
                                        b=0;
            if(g>70){
            for(g;g>70;g--)
            {
            analogWrite(ledVerde,g);
          delay(10);
          }
            }
            else{
            for(g;g<70;g++)
        {
        analogWrite(ledVerde,g);
        delay(10);
        }
            }
                                        g=70;
              if(r<255)
              {
                for(r;r<255;r++)
                {
                analogWrite(ledRojo,r);
                delay(10);
                }
              }
          }
      else if(r==255&&g!=70){
        for(g;g<70;g++){
          analogWrite(ledVerde,g);
          delay(10);
        }
                                        g=70;
      }
        else
        {
        for(r;r<255;r++)
        {
        g=map(r, 1, 255, 0, 70);
        analogWrite(ledRojo,r);
        analogWrite(ledVerde, g);
        analogWrite(ledAzul, 0);
        delay(10);
        }
                                      r=255;
                                      g=70;
                                      b=0;
    }
      }
     else if (Letra == 'K')//FUCKING CELESTE 
     {
      if(r>0||g<255)
        {
          for(r;r>0;r--)
          {
          analogWrite(ledRojo,r);
          delay(10);
          }
            r=0;
            if(g>255){
            for(g;g>255;g--)
            {
            analogWrite(ledVerde,g);
          delay(10);
          }
            }
            else{
            for(g;g<255;g++)
        {
        analogWrite(ledVerde,g);
        delay(10);
        }
            }
                                        g=255;
              if(b<255)
              {
                for(b;b<255;b++)
                {
                analogWrite(ledAzul,b);
                delay(10);
                }
              }
          }
      else if(b==255&&g!=255){
        for(g;g<255;g++){
          analogWrite(ledVerde,g);
          delay(10);
        }
                                        g=255;
      }
        else
        {
        for(b;b<255;b++)
        {
        analogWrite(ledRojo,0);
        analogWrite(ledVerde, b);
        analogWrite(ledAzul, b);
        delay(10);
        }
                                      r=0;
                                      g=255;
                                      b=255;
    }
     }
     else if (Letra == 'Q')//FUCKING BLANCO
     {
      if(r!=0||b!=0||g!=0)
      {
      for(r;r<255;r++){
        analogWrite(ledRojo,r);
        delay(5);
      }
      for(b;b<255;b++){
        analogWrite(ledAzul,b);
        delay(5);
      }
      for(g;g<255;g++){
        analogWrite(ledVerde,g);
        delay(5);
      }
      }
      else
      {
        for(x=0;x<255;x++)
        {
      analogWrite(ledRojo, x);
      analogWrite(ledAzul, x);
      analogWrite(ledVerde, x);
      delay(10);
        }
                                      r=255;
                                      g=255;
                                      b=255;
      }
     }
    else if (Letra == 'A') {
      analogWrite(ledRojo, 0);
      analogWrite(ledAzul, 0);
      analogWrite(ledVerde, 0);
      r=0;
      g=0;
      b=0;
      fadeL=0;
      fadeM=0;
      fadeR=0;
      cont2=0;
    }
         
    else if (Letra == 'q') {
      r+=10;
      if(r<=255){
      analogWrite(ledRojo, r);
      }
      else{
        analogWrite(ledRojo,255);
      }
    }
    else if (Letra == 'w') {
      r+=50;
      if(r<=255){
      analogWrite(ledRojo, r);
      }
      else{
        analogWrite(ledRojo,255);
      }
    }
    else if (Letra == 'e') {
      r+=100;
      if(r<=255){
      analogWrite(ledRojo, r);
      }
      else{
        analogWrite(ledRojo,255);
      }
    }
    else if (Letra == 'r') {
      r+150;
      if(r<=255){
      analogWrite(ledRojo, r);
      }
      else{
        analogWrite(ledRojo,255);
      }
    }
    else if (Letra == 't') {
      r+=200;
      if(r<=255){
      analogWrite(ledRojo, r);
      }
      else{
        analogWrite(ledRojo,255);
      }
    }
    else if (Letra == 'y') {
      r+=255;
      if(r<=255){
      analogWrite(ledRojo, r);
      }
      else{
        analogWrite(ledRojo,255);
      }
    }
    else if (Letra == 'u') {
      g+=10;
      if(g<=255){
      analogWrite(ledVerde, g);
      }
      else{
        analogWrite(ledVerde,255);
      }
    }
    else if (Letra == 'i') {
     g+=50;
      if(g<=255){
      analogWrite(ledVerde, g);
      }
      else{
        analogWrite(ledVerde,255);
      }
    }
    else if (Letra == 'o') {
      g+=100;
      if(g<=255){
      analogWrite(ledVerde, g);
      }
      else{
        analogWrite(ledVerde,255);
      }
    }
    else if (Letra == 'p') {
      g+=150;
      if(g<=255){
      analogWrite(ledVerde, g);
      }
      else{
        analogWrite(ledVerde,255);
      }
    }
    else if (Letra == 'a') {
      g+=200;
      if(g<=255){
      analogWrite(ledVerde, g);
      }
      else{
        analogWrite(ledVerde,255);
      }
    }
    else if (Letra == 's') {
      g+=255;
      if(g<=255){
      analogWrite(ledVerde, g);
      }
      else{
        analogWrite(ledVerde,255);
      }
    }
    else if (Letra == 'd') {
      b+=10;
      if(b<=255){
      analogWrite(ledAzul, b);
      }
      else{
        analogWrite(ledAzul,255);
      }
    }
    else if (Letra == 'f') {
      b+=50;
      if(b<=255){
      analogWrite(ledAzul, b);
      }
      else{
        analogWrite(ledAzul,255);
      }
    }
    else if (Letra == 'g') {
      b+=100;
      if(b<=255){
      analogWrite(ledAzul, b);
      }
      else{
        analogWrite(ledAzul,255);
      }
    }
    else if (Letra == 'h') {
      b+=150;
      if(b<=255){
      analogWrite(ledAzul, b);
      }
      else{
        analogWrite(ledAzul,255);
      }
    }
    else if (Letra == 'j') {
     b+=200;
      if(b<=255){
      analogWrite(ledAzul, b);
      }
      else{
        analogWrite(ledAzul,255);
      }
    }
    else if (Letra == 'k') {
      b+=255;
      if(b<=255){
      analogWrite(ledAzul, b);
      }
      else {
        analogWrite(ledAzul,255);
      }
    }
    }
    /////////////// EMPIEZA EL FADE
    else if(Letra=='l') /////////////// fade rojo
    {
    for(r=0;r<255;r++)
    {
        analogWrite(ledRojo,r);
        Serial.println(r);
         if(fadeL==1&&r>100){
        delay(30);
        }
        else if(fadeL==1&&r<=100){
          delay(50);
        }
        else if(fadeM==1&&r>100){
          delay(10);
        }
        else if(fadeM==1&&r<=100){
          delay(20);
        }
        else if(fadeR==1&&r>100){
          delay(3);
        }
        else if(fadeR==1&&r<=100){
          delay(5);}
        else{
          delay(10);
          fadeL=0;
          fadeM=0;
          fadeR=0;
        }
        
        }
r=255;
    g=0;
    b=0;
    analogWrite(ledRojo,r);
    analogWrite(ledAzul,b);
    analogWrite(ledVerde,g);

    if(fadeL==1)
    {
   delay(2000);
    }
    else if(fadeM==1)
    {
    delay(500);
    }

    else if(fadeR==1)
    {
      delay(250);
    }
    else{
    delay(500);
    }
    for(r=255;r>0;r--){
      analogWrite(ledRojo,r);
        Serial.println(r);
          if(fadeL==1&&r>100){
        delay(30);
        }
        else if(fadeL==1&&r<=100){
          delay(50);
        }
        else if(fadeM==1&&r>100){
          delay(10);
        }
        else if(fadeM==1&&r<=100){
          delay(20);
        }
        else if(fadeR==1&&r>100){
          delay(3);
        }
        else if(fadeR==1&&r<=100){
          delay(5);}
        else{
          delay(10);
          fadeL=0;
          fadeM=0;
          fadeR=0;
          
        }
        } 
    r=0;
    g=0;
    b=0;
    analogWrite(ledRojo,r);
    analogWrite(ledAzul,b);
    analogWrite(ledVerde,g);
        if(fadeL==1)
    {
   delay(2000);
    }
    else if(fadeM==1)
    {
    delay(500);
    }

    else if(fadeR==1)
    {
      delay(250);
    }
    else{
    delay(500);
    }
    }
    else if(Letra=='z')/////////////// fade rosa
    {
    for(r=0;r<255;r++)
    {
        analogWrite(ledRojo,r);
        b=map(r, 1, 255, 0, 20);
        analogWrite(ledAzul,b);
       if(fadeL==1&&r>100){
        delay(30);
        }
        else if(fadeL==1&&r<=100){
          delay(50);
        }
        else if(fadeM==1&&r>100){
          delay(10);
        }
        else if(fadeM==1&&r<=100){
          delay(20);
        }
        else if(fadeR==1&&r>100){
          delay(3);
        }
        else if(fadeR==1&&r<=100){
          delay(5);}
        else{
          delay(10);
          fadeL=0;
          fadeM=0;
          fadeR=0;
        }
    }
    r=255;
    g=0;
    b=20;
    analogWrite(ledRojo,r);
    analogWrite(ledAzul,b);
    analogWrite(ledVerde,g);
    if(fadeL==1)
    {
   delay(2000);
    }
    else if(fadeM==1)
    {
    delay(500);
    }

    else if(fadeR==1)
    {
      delay(250);
    }
    else{
    delay(500);
    }
    for(r=255;r>0;r--){
      analogWrite(ledRojo,r);
      b=map(r, 1, 255, 0, 20);
      analogWrite(ledAzul,b);
        if(fadeL==1&&r>100){
        delay(30);
        }
        else if(fadeL==1&&r<=100){
          delay(50);
        }
        else if(fadeM==1&&r>100){
          delay(10);
        }
        else if(fadeM==1&&r<=100){
          delay(20);
        }
        else if(fadeR==1&&r>100){
          delay(3);
        }
        else if(fadeR==1&&r<=100){
          delay(5);}
        else{
          delay(10);
          fadeL=0;
          fadeM=0;
          fadeR=0;
        }
    }
    if(fadeL==1)
    {
   delay(2000);
    }
    else if(fadeM==1)
    {
    delay(500);
    }

    else if(fadeR==1)
    {
      delay(250);
    }
    else{
    delay(500);
    }
    r=0;
    g=0;
    b=0;
    analogWrite(ledRojo,r);
    analogWrite(ledAzul,b);
    analogWrite(ledVerde,g);
    }
else if(Letra=='x')/////////////// fade naranja
    {
    for(r=0;r<255;r++)
    {
        analogWrite(ledRojo,r);
        g=map(r, 1, 255, 0, 20);
        analogWrite(ledVerde,g);
        if(fadeL==1&&r>100){
        delay(30);
        }
        else if(fadeL==1&&r<=100){
          delay(50);
        }
        else if(fadeM==1&&r>100){
          delay(10);
        }
        else if(fadeM==1&&r<=100){
          delay(20);
        }
        else if(fadeR==1&&r>100){
          delay(3);
        }
        else if(fadeR==1&&r<=100){
          delay(5);}
        else{
          delay(10);
          fadeL=0;
          fadeM=0;
          fadeR=0;
        }
}

    r=255;
    g=20;
    b=0;
    analogWrite(ledRojo,r);
    analogWrite(ledAzul,b);
    analogWrite(ledVerde,g);

    
    if(fadeL==1)
    {
   delay(2000);
    }
    else if(fadeM==1)
    {
    delay(500);
    }

    else if(fadeR==1)
    {
      delay(250);
    }
    else{
    delay(500);
    }
    for(r=255;r>0;r--){
      analogWrite(ledRojo,r);
      g=map(r, 1, 255, 0, 20);
      analogWrite(ledVerde,g);
        if(fadeL==1&&r>100){
        delay(30);
        }
        else if(fadeL==1&&r<=100){
          delay(50);
        }
        else if(fadeM==1&&r>100){
          delay(10);
        }
        else if(fadeM==1&&r<=100){
          delay(20);
        }
        else if(fadeR==1&&r>100){
          delay(3);
        }
        else if(fadeR==1&&r<=100){
          delay(5);}
        else{
          delay(10);
          fadeL=0;
          fadeM=0;
          fadeR=0;
        }
    }

    r=0;
    g=0;
    b=0;
    analogWrite(ledRojo,r);
    analogWrite(ledAzul,b);
    analogWrite(ledVerde,g);
    if(fadeL==1)
    {
   delay(2000);
    }
    else if(fadeM==1)
    {
    delay(500);
    }

    else if(fadeR==1)
    {
      delay(250);
    }
    else{
    delay(500);
    }
    }
    else if(Letra=='c')/////////////// fade azul
    {
    for(b=0;b<255;b++)
    {
        analogWrite(ledAzul,b);
        
        if(fadeL==1&&r>100){
        delay(30);
        }
        else if(fadeL==1&&b<=100){
          delay(50);
        }
        else if(fadeM==1&&b>100){
          delay(10);
        }
        else if(fadeM==1&&b<=100){
          delay(20);
        }
        else if(fadeR==1&&b>100){
          delay(3);
        }
        else if(fadeR==1&&b<=100){
          delay(5);}
        else{
          delay(10);
          fadeL=0;
          fadeM=0;
          fadeR=0;
        }
    }
    
    r=0;
    g=0;
    b=255;
    analogWrite(ledRojo,r);
    analogWrite(ledAzul,b);
    analogWrite(ledVerde,g);
    if(fadeL==1)
    {
   delay(2000);
    }
    else if(fadeM==1)
    {
    delay(500);
    }

    else if(fadeR==1)
    {
      delay(250);
    }
    else{
    delay(500);
    }
    
    for(b=255;b>0;b--){
      analogWrite(ledAzul,b);
      
       if(fadeL==1&&r>100){
        delay(30);
        }
        else if(fadeL==1&&b<=100){
          delay(50);
        }
        else if(fadeM==1&&b>100){
          delay(10);
        }
        else if(fadeM==1&&b<=100){
          delay(20);
        }
        else if(fadeR==1&&b>100){
          delay(3);
        }
        else if(fadeR==1&&b<=100){
          delay(5);}
        else{
          delay(10);
          fadeL=0;
          fadeM=0;
          fadeR=0;
        }
    }
    r=0;
    g=0;
    b=0;
    analogWrite(ledRojo,r);
    analogWrite(ledAzul,b);
    analogWrite(ledVerde,g);
    if(fadeL==1)
    {
   delay(2000);
    }
    else if(fadeM==1)
    {
    delay(500);
    }

    else if(fadeR==1)
    {
      delay(250);
    }
    else{
    delay(500);
    }
    }
    else if(Letra=='v') /////////////// fade violeta
    {
    for(b=0;b<255;b++)
    {
        analogWrite(ledAzul,b);
        r=map(b, 1, 255, 0, 40);
        analogWrite(ledRojo,r);
        if(fadeL==1&&r>100){
        delay(30);
        }
        else if(fadeL==1&&b<=100){
          delay(50);
        }
        else if(fadeM==1&&b>100){
          delay(10);
        }
        else if(fadeM==1&&b<=100){
          delay(20);
        }
        else if(fadeR==1&&b>100){
          delay(3);
        }
        else if(fadeR==1&&b<=100){
          delay(5);}
        else{
          delay(10);
          fadeL=0;
          fadeM=0;
          fadeR=0;
     }
    }
    
    r=40;
    g=0;
    b=255;
    analogWrite(ledRojo,r);
    analogWrite(ledAzul,b);
    analogWrite(ledVerde,g);
    if(fadeL==1)
    {
   delay(2000);
    }
    else if(fadeM==1)
    {
    delay(500);
    }

    else if(fadeR==1)
    {
      delay(250);
    }
    else{
    delay(500);
    }
    for(b=255;b>0;b--){
      analogWrite(ledAzul,b);
      r=map(b, 1, 255, 0, 40);
      analogWrite(ledRojo,r);
        if(fadeL==1&&b>100){
        delay(30);
        }
        else if(fadeL==1&&b<=100){
          delay(50);
        }
        else if(fadeM==1&&b>100){
          delay(10);
        }
        else if(fadeM==1&&b<=100){
          delay(20);
        }
        else if(fadeR==1&&b>100){
          delay(3);
        }
        else if(fadeR==1&&b<=100){
          delay(5);}
        else{
          delay(10);
          fadeL=0;
          fadeM=0;
          fadeR=0;
      }
    }
    
    r=0;
    g=0;
    b=0;
    analogWrite(ledRojo,r);
    analogWrite(ledAzul,b);
    analogWrite(ledVerde,g);
    if(fadeL==1)
    {
   delay(2000);
    }
    else if(fadeM==1)
    {
    delay(500);
    }

    else if(fadeR==1)
    {
      delay(250);
    }
    else{
    delay(500);
    }
    }
    else if(Letra=='b')/////////////// fade amarillo
    {
    for(r=0;r<255;r++)
    {
        analogWrite(ledRojo,r);
        g=map(r, 1, 255, 0, 70);
        analogWrite(ledVerde,g);
        if(fadeL==1&&r>100){
        delay(30);
        }
        else if(fadeL==1&&r<=100){
          delay(50);
        }
        else if(fadeM==1&&r>100){
          delay(10);
        }
        else if(fadeM==1&&r<=100){
          delay(20);
        }
        else if(fadeR==1&&r>100){
          delay(3);
        }
        else if(fadeR==1&&r<=100){
          delay(5);}
        else{
          delay(10);
          fadeL=0;
          fadeM=0;
          fadeR=0;
     }
    }
    
    r=255;
    g=70;
    b=0;
    analogWrite(ledRojo,r);
    analogWrite(ledAzul,b);
    analogWrite(ledVerde,g);
    if(fadeL==1)
    {
   delay(2000);
    }
    else if(fadeM==1)
    {
    delay(500);
    }

    else if(fadeR==1)
    {
      delay(250);
    }
    else{
    delay(500);
    }
    for(r=255;r>0;r--){
      analogWrite(ledRojo,r);
      g=map(r, 1, 255, 0, 70);
      analogWrite(ledVerde,g);
        if(fadeL==1&&r>100){
        delay(30);
        }
        else if(fadeL==1&&r<=100){
          delay(50);
        }
        else if(fadeM==1&&r>100){
          delay(10);
        }
        else if(fadeM==1&&r<=100){
          delay(20);
        }
        else if(fadeR==1&&r>100){
          delay(3);
        }
        else if(fadeR==1&&r<=100){
          delay(5);}
        else{
          delay(10);
          fadeL=0;
          fadeM=0;
          fadeR=0;
     }
    }
    
    r=0;
    g=0;
    b=0;
    analogWrite(ledRojo,r);
    analogWrite(ledAzul,b);
    analogWrite(ledVerde,g);
    if(fadeL==1)
    {
   delay(2000);
    }
    else if(fadeM==1)
    {
    delay(500);
    }

    else if(fadeR==1)
    {
      delay(250);
    }
    else{
    delay(500);
    }
    }
    else if(Letra=='n')/////////////// fade verde
    {
    for(g=0;g<255;g++)
    {
        analogWrite(ledVerde,g);
       
        if(fadeL==1&&g>100){
        delay(30);
        }
        else if(fadeL==1&&g<=100){
          delay(50);
        }
        else if(fadeM==1&&g>100){
          delay(10);
        }
        else if(fadeM==1&&g<=100){
          delay(20);
        }
        else if(fadeR==1&&g>100){
          delay(3);
        }
        else if(fadeR==1&&g<=100){
          delay(5);}
        else{
          delay(10);
          fadeL=0;
          fadeM=0;
          fadeR=0;
      }
    }
    
    r=0;
    g=255;
    b=0;
    analogWrite(ledRojo,r);
    analogWrite(ledAzul,b);
    analogWrite(ledVerde,g);
    if(fadeL==1)
    {
   delay(2000);
    }
    else if(fadeM==1)
    {
    delay(500);
    }

    else if(fadeR==1)
    {
      delay(250);
    }
    else{
    delay(500);
    }
    for(g=255;g>0;g--){
      analogWrite(ledVerde,g);

        if(fadeL==1&&g>100){
        delay(30);
        }
        else if(fadeL==1&&g<=100){
          delay(50);
        }
        else if(fadeM==1&&g>100){
          delay(10);
        }
        else if(fadeM==1&&g<=100){
          delay(20);
        }
        else if(fadeR==1&&g>100){
          delay(3);
        }
        else if(fadeR==1&&g<=100){
          delay(5);}
        else{
          delay(10);
          fadeL=0;
          fadeM=0;
          fadeR=0;
      }
    }
    
    r=0;
    g=0;
    b=0;
    analogWrite(ledRojo,r);
    analogWrite(ledAzul,b);
    analogWrite(ledVerde,g);
    if(fadeL==1)
    {
   delay(2000);
    }
    else if(fadeM==1)
    {
    delay(500);
    }

    else if(fadeR==1)
    {
      delay(250);
    }
    else{
    delay(500);
    }
    }
    else if(Letra=='m')/////////////// fade celeste
    {
    for(x=0;x<255;x++)
    {
        analogWrite(ledAzul,x);
        analogWrite(ledVerde,x);
        if(fadeL==1&&x>100){
        delay(30);
        }
        else if(fadeL==1&&x<=100){
          delay(50);
        }
        else if(fadeM==1&&x>100){
          delay(10);
        }
        else if(fadeM==1&&x<=100){
          delay(20);
        }
        else if(fadeR==1&&x>100){
          delay(3);
        }
        else if(fadeR==1&&x<=100){
          delay(5);}
        else{
          delay(10);
          fadeL=0;
          fadeM=0;
          fadeR=0;
     }
    }
    
    r=0;
    g=255;
    b=255;
    
    analogWrite(ledRojo,r);
    analogWrite(ledAzul,b);
    analogWrite(ledVerde,g);
    if(fadeL==1)
    {
   delay(2000);
    }
    else if(fadeM==1)
    {
    delay(500);
    }

    else if(fadeR==1)
    {
      delay(250);
    }
    else{
    delay(500);
    }
    
    for(x=255;x>0;x--){
      analogWrite(ledAzul,x);
      analogWrite(ledVerde,x);
        if(fadeL==1&&x>100){
        delay(30);
        }
        else if(fadeL==1&&x<=100){
          delay(50);
        }
        else if(fadeM==1&&x>100){
          delay(10);
        }
        else if(fadeM==1&&x<=100){
          delay(20);
        }
        else if(fadeR==1&&x>100){
          delay(3);
        }
        else if(fadeR==1&&x<=100){
          delay(5);}
        else{
          delay(10);
          fadeL=0;
          fadeM=0;
          fadeR=0;
     }
    }
    
    r=0;
    g=0;
    b=0;
    analogWrite(ledRojo,r);
    analogWrite(ledAzul,b);
    analogWrite(ledVerde,g);
    if(fadeL==1)
    {
   delay(2000);
    }
    else if(fadeM==1)
    {
    delay(500);
    }

    else if(fadeR==1)
    {
      delay(250);
    }
    else{
    delay(500);
    }
    }
    else if(Letra=='C')/////////////// fade blanco
    {
    for(x=0;x<255;x++)
    {
        analogWrite(ledRojo,x);
        analogWrite(ledAzul,x);
        analogWrite(ledVerde,x);
       if(fadeL==1&&x>100){
        delay(30);
        }
        else if(fadeL==1&&x<=100){
          delay(50);
        }
        else if(fadeM==1&&x>100){
          delay(10);
        }
        else if(fadeM==1&&x<=100){
          delay(20);
        }
        else if(fadeR==1&&x>100){
          delay(3);
        }
        else if(fadeR==1&&x<=100){
          delay(5);}
        else{
          delay(10);
          fadeL=0;
          fadeM=0;
          fadeR=0;
      }
    }
    
    r=255;
    g=255;
    b=255;
    analogWrite(ledRojo,r);
    analogWrite(ledAzul,b);
    analogWrite(ledVerde,g);
    if(fadeL==1)
    {
   delay(2000);
    }
    else if(fadeM==1)
    {
    delay(500);
    }

    else if(fadeR==1)
    {
      delay(250);
    }
    else{
    delay(500);
    }
    for(x=255;x>0;x--){
      analogWrite(ledRojo,x);
      analogWrite(ledVerde,x);
      analogWrite(ledAzul,x);
        if(fadeL==1&&x>100){
        delay(50);
        }
        else if(fadeL==1&&x<=100){
          delay(100);
        }
        else if(fadeM==1&&x>100){
          delay(10);
        }
        else if(fadeM==1&&x<=100){
          delay(20);
        }
        else if(fadeR==1&&x>100){
          delay(3);
        }
        else if(fadeR==1&&x<=100){
          delay(5);}
        else{
          delay(10);
          fadeL=0;
          fadeM=0;
          fadeR=0;
     }
    }
    
    r=0;
    g=0;
    b=0;
    analogWrite(ledRojo,r);
    analogWrite(ledAzul,b);
    analogWrite(ledVerde,g);
    if(fadeL==1)
    {
   delay(2000);
    }
    else if(fadeM==1)
    {
    delay(500);
    }

    else if(fadeR==1)
    {
      delay(250);
    }
    else{
    delay(500);
    }
    }
    else if(Letra=='H')
    {
      numRand = random(1, 9);
      if(numRand==9){
        analogWrite(ledRojo,255);
      }
      else if(numRand==1){
        
        analogWrite(ledAzul,255);
      }
      else if(numRand==2){
        
        analogWrite(ledVerde,255);
      }
      else if(numRand==3){
        analogWrite(ledRojo,255);
        analogWrite(ledVerde,70);
      }
      else if(numRand==4){
        analogWrite(ledRojo,255);
        analogWrite(ledVerde,20);
      }
     else  if(numRand==5){
        analogWrite(ledRojo,255);
      analogWrite(ledAzul,255);}
     else if(numRand==6){
        analogWrite(ledAzul,255);
        analogWrite(ledRojo,40);
      }
      else if(numRand==7){
        analogWrite(ledVerde,255);
        analogWrite(ledAzul,255);
      }
      else if(numRand==8){
analogWrite(ledRojo,255);
analogWrite(ledAzul,255);
analogWrite(ledVerde,255);

      } 
      delay(75);
      analogWrite(ledRojo,0);
analogWrite(ledAzul,0);
analogWrite(ledVerde,0);
delay(75);
      }

      else if(Letra=='2')
    {
            switch (cont2)
            {
            case 0:
              delays2();   
                     
              for (r = 0 ; r < 255 ; r++)
              {
                analogWrite(ledRojo, r);
                delays();
                cont2++;
              }
            break;
            case 1: 
            delays2();

            for (b = 255 ; b > 0 ; b--)
              {
                analogWrite(ledAzul, b);
                delays();
                cont2++;
              }
            break;
            case 2:
            delays2();

            for (g = 0 ; g < 255 ; g++)
              {
                analogWrite(ledVerde, g);
                delays();
                cont2++;
              }
            break;
            case 3:
            delays2();

            for (r = 255 ; r > 0 ; r--)
             {
                analogWrite(ledRojo, r);
                delays();
                cont2++;
              }
            break;
            case 4:
            delays2();

            for (b = 0 ; b < 255 ; b++)
             {
                analogWrite(ledAzul, b);
                delays();
                cont2++;
             }
            break;
            case 5:
            delays2();

            for (g = 255 ; g > 0 ; g--)
              {
                analogWrite(ledVerde, g);
                delays();
                cont2 = 0;
              }
              break;
            }
    }





      
}
