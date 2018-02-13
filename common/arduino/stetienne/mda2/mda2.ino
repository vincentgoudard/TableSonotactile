
void setup(){
  Serial.begin(9600);
  pinMode(A0, INPUT);
  pinMode(A1, INPUT);
  pinMode(A2, INPUT);
  pinMode(A3, INPUT);
  pinMode(A4, INPUT);
  pinMode(A5, INPUT);
  Serial.print("Hello world.");
  Serial.println();
}

void loop(){
  Serial.print(analogRead(A0));//bouton pression 1
  delay(1);
  Serial.print("|");
  delay(10);
    
  Serial.print(analogRead(A1));//bouton pression 2
  delay(1);
  Serial.print("|");
  delay(10);
    
  Serial.print(analogRead(A2));//bouton pression 3
  delay(1);
  Serial.print("|");
  delay(10);
    
  Serial.print(analogRead(A3));//bouton pression 4
  delay(1);
  Serial.print("|");
  delay(10);
    
  Serial.print(analogRead(A4));//slider 1
  delay(1);
  Serial.print("|");
  delay(10);
    
  Serial.print(analogRead(A5));//slider 3
  delay(1);
  Serial.println();
  delay(10);
}
