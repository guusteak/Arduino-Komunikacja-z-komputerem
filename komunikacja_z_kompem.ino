#define redled 12
#define greenled 11
#define iswindowopen 13


void setup() {
  Serial.begin(9600); //Ustawienie prędkosci transmisji
  Serial.println("siema");
  pinMode(redled, OUTPUT); //czewona
  pinMode(greenled,OUTPUT); //zielona
  pinMode(iswindowopen, INPUT_PULLUP); //przycisk

  //Wylaczam obie diody
  digitalWrite(redled, LOW);
  digitalWrite(greenled, LOW);
}

void loop() {
  if(digitalRead(iswindowopen)==LOW){
    //Jezeli przycisk jest wcisniety
    digitalWrite(greenled, HIGH); //zielona ON
    digitalWrite(redled, LOW); //czerwona OF
  }
  else{
    //Jezeli przycisk nie jest wcisniety
    digitalWrite(greenled, LOW);
    digitalWrite(redled, HIGH);
    Serial.println("Uwaga! Okno nie jest zamkniete!");
    while (digitalRead(iswindowopen)==HIGH){
      //zatrzymujemy sie w pustej pętli do czasu ponownego otwarcia okna
      delay(25); //Niewielkie opoznienie aby niwelowac opoznienie bo wiadomo iles tam milionow operacji na sekunde
      
    }
  }
}
