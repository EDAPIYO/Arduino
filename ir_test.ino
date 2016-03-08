#include <MIDI.h>
MIDI_CREATE_DEFAULT_INSTANCE();
 
void setup() {
    MIDI.begin(1);
    MIDI.turnThruOff();
    //Serial.begin(31250) ;  //MIDI no default    
}
int note = 0;
 
void loop() {
        
     int ans;
     ans = IDMread(0);   
     ans = map(ans,0,1023,0,500);
     ans = map(ans,50,220,50,4);
     if(ans< 39 && ans == note){
      //Serial.print("keep duration");
      }else if(ans <39 && ans != note){
      //Serial.print("change note");
        MIDI.sendNoteOff(note+55,0,1);
        MIDI.sendNoteOn(ans+55,100,1);
     }else{
      //Serial.print("release note");
      MIDI.sendNoteOff(note+55,0,1);
     }

     note = ans;     
     delay(50);
 }

 int IDMread(int PinNo){
  long ans;
  int i;
  ans = 0;
  for(i=0;i<100;i++){
    ans = ans + analogRead(PinNo); //gp3y0e03
  }
  return ans/100;
 }

