String odebraneDane = ""; //Pusty string

void setup() {
  Serial.begin(9600); //Odpalanie komunikacji
}

void loop() {
  if(Serial.available()>0){
    //Czy arduino odebrało dane
    odebraneDane = Serial.readStringUntil('\n');
    Serial.println("Hello "+odebraneDane +"!");
  }

}
