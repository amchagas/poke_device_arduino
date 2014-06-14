/* this is a piece of code to demonstrate the 3D printed nose poke 
device. It turns the color LED on the end of the nose poke 
device and also the IR LED at the (top/bottom).
It waits until the IR beam is interrupted by the "animal nose" and 
emits a sound while the beam is interrupted. Once the animal remove
its nose, a pause takes place, where everything is off. After the
pause, the color LED turns on again restarting the whole process */
//created by Andre M Chagas on May 18th 2014.
//distributed under a creative commons 3.0 license.

//bits used
int colorLedBit = 10;
int IRLedBit = 11;
int IRReceiverBit = 7;
int speakerBit = 8;
//frequency of the tone waveform
int waveFreq = 440;
//variables to store time
unsigned long time1;
unsigned long time2;
unsigned long timePoking = 0;
unsigned long timeUntillPoke = 0;

//set whether the bits are input or output
void setup(){

  pinMode(colorLedBit,OUTPUT);
  pinMode(IRLedBit,OUTPUT);
  pinMode(IRReceiverBit,INPUT);
  pinMode(speakerBit,OUTPUT);

}

//main code

void loop(){
  //turn everything off
  digitalWrite(colorLedBit,LOW);
  digitalWrite(IRLedBit,LOW);
  noTone(speakerBit);
  
  //wait for 1 sec
  delay(1000);
  //turn colored Led on
  digitalWrite(colorLedBit,HIGH);
  digitalWrite(IRLedBit,HIGH);
  //start a while loop that will wait for the nose poke
  //while no nose poke, measure time in milliseconds.
  time1= millis();
  while (digitalRead(IRReceiverBit) == 1){
    time2=millis();
  }
  //start playing the tone;
  tone(speakerBit,waveFreq);
  //measure time in between turning on the colorLed and the nose poke
  timeUntillPoke = time2-time1;
  //"reset" the timer
  time1 = time2;
  //the code only leaves the while loop if the animal inserted the
  //nose in the nose poke device, therefore in the next step, we turn
  //off the colorLed.
  digitalWrite(colorLedBit,LOW);
  //and start counting how much time the animal stays with the nose in
  //the poke device
  while (digitalRead(IRReceiverBit) == 0){
    time2=millis();
  }
  //turn off sound
  noTone(speakerBit);
  //measure how much time the animal had its nose in the poke device
  timePoking = time2 - time1; 
 
/*at this part, one could send serial data via the usb port (if
the arduino is connected to a PC or such) to send the timing data 
*/  
}



