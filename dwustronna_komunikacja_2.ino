#define red 9
#define green 8
String odebraneDane = "";
bool stan_red = false;
bool stan_green = false;

void setup() {
  Serial.begin(9600);
  pinMode(red, OUTPUT);
  pinMode(green, OUTPUT);

  digitalWrite(red, LOW);
  digitalWrite(green, LOW);
}

void loop() {
  // put your main code here, to run repeatedly:
  if(Serial.available()>0){
    odebraneDane = Serial.readStringUntil('\n');

    if(odebraneDane == "green"){
      if(stan_green==false)
      {
        stan_green=true;
        digitalWrite(green, HIGH);
      }
      else{
        stan_green=false;
        digitalWrite(green, LOW);
      }
    }
    if(odebraneDane=="red"){
      if(stan_red==false){
        stan_red=true;
        digitalWrite(red, HIGH);
      }
      else{
        stan_red = false;
        digitalWrite(red, LOW);
      }
      
    }
    else{
      Serial.println("Something went wrong");
    }
  }
}
