const int switchPin =2;
const int bellPin =7;
int bellState=LOW;
int switchState=LOW;
int lastswitchState=LOW;
  unsigned long lastDebounceTime =0;
unsigned long debounceDelay = 10;
void setup()
{
  pinMode(switchPin, INPUT);
  pinMode(bellPin, OUTPUT);
  digitalWrite(bellPin,bellState);
}

void loop()
{
  int reading= digitalRead(switchPin);
  if(reading!=lastswitchState){
    lastDebounceTime=millis();
  }
  if((millis()- lastDebounceTime)>debounceDelay){
    if(reading!=switchState){
      switchState=reading;
      if(switchState==HIGH){
        bellState=!bellState;
      }
    }
  }
  digitalWrite(bellPin,bellState);
  lastswitchState:
  lastswitchState = reading;
}