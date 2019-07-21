/*
there are 600 total ticks on this encoder
however, because I am reading rising and falling edges I get twice the resolution
*/


//connect a and b wires of encoder to interrupt pins
//connect a to pin 2, and b to pin 3
const byte interruptA = 2;
const byte interruptB = 3;

volatile int count = 0;

int revCount = 0;

volatile bool ccw = false;
volatile bool cw = false;

//number of radians per tick
float k = (3.1415926535) / 600;

//number of degrees per tick
float d = 180 / 600;


void setup() {

Serial.begin(115200);
Serial.println("Encoder Interrupt test:");

  pinMode(interruptA, INPUT_PULLUP);
  attachInterrupt(digitalPinToInterrupt(interruptA), aFall, FALLING);
    attachInterrupt(digitalPinToInterrupt(interruptA), aRise, RISING);
  
  pinMode(interruptB, INPUT_PULLUP);
  attachInterrupt(digitalPinToInterrupt(interruptB), bFall, FALLING);
  attachInterrupt(digitalPinToInterrupt(interruptB), bRise, RISING);
}

void loop() {

if(count >= 1200){
  count = count - 1200;
  revCount++;  
}
if(count <= -1200){
  count = count + 1200;
  revCount--;  
}

Serial.print("raw: ");
Serial.print(count);
Serial.print(" rad: ");
Serial.print(count * k);
Serial.print(" deg:");
Serial.print(count * d);
Serial.print(" revolutions: ");
Serial.println(revCount);

//delay here will not disrupt the interrupt pins as they will trigger the code even during the delay
delay(100);
  
}

void aRise(){
  if(digitalRead(interruptB)){
    count++;
  }else{
    count--;
  }
}

void aFall(){
  if(digitalRead(interruptB)){
    count--;
  }else{
    count++;
  }
}

void bRise(){
  if(digitalRead(interruptA)){
    count--;
  }else{
    count++;
  }
}

void bFall(){
  if(digitalRead(interruptA)){
    count++;
  }else{
    count--;
  }
}
