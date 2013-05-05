/*
Clapper Circuit
Intro to Electrical Engineering 1201 Final Project

Detects sequences of claps and turns on switch for 5 seconds
if correct sequence is identified.
*/

int in = 2;
int out = 4;
int count = 0;
int clap_flag = 0;
int switch_flag = 0;
int start = 0;
int ending = 0;
int time = 0;

void setup()
{
  Serial.begin(9600);
  pinMode(in, INPUT);
  digitalWrite(out, LOW);
  pinMode(out, OUTPUT);
}

void loop()
{
  if(count == 3 && switch_flag == 0)
  {
    ending = millis();
    Serial.print("ending: ");
    Serial.println(ending);
    switch_flag = 1;
    time = ending - start;
    Serial.print("time: ");
    Serial.println(time);
    if(time < 2000)
    {
      digitalWrite(out, HIGH);
      delay(5000);
      digitalWrite(out, LOW);
    }
    count = 0;
    clap_flag = 0;
    switch_flag = 0;
  }
  
  if(digitalRead(in) == 1 && clap_flag == 0)
  {
    if(count == 0)
    {
      start = millis();
      Serial.print("start: ");
      Serial.println(start);
    }
    
    Serial.println("clap detected");
    count++;
    clap_flag = 1;
  }
  if(digitalRead(in) == 0 && clap_flag == 1)
  {
    clap_flag = 0;
  }
}
