// by EmrahGK (notalar falan)


#include "pitches.h"



/*
#define NOTE_DO_5  523
#define NOTE_DO_DIYEZ_5 554
#define NOTE_RE_5  587
#define NOTE_RE_DIYEZ_5 622
#define NOTE_MI_5  659
#define NOTE_FA_5  698
#define NOTE_FA_DIYEZ_5 740
#define NOTE_SOL_5  784
#define NOTE_SOL_DIYEZ_5 831
#define NOTE_LA_5  880
#define NOTE_LA_DIYEZ_5 932
#define NOTE_SI_5  988
*/

// The melody zımbırtısı 
int melody[] = {
  NOTE_DO_5,
  NOTE_DO_5, NOTE_RE_DIYEZ_5, NOTE_FA_5, NOTE_FA_DIYEZ_5, NOTE_FA_5, NOTE_RE_DIYEZ_5, NOTE_DO_5,
  NOTE_WAIT,
  NOTE_DO_5, NOTE_RE_DIYEZ_5, NOTE_DO_5,
  NOTE_WAIT,
  NOTE_C4, NOTE_C4,
  NOTE_WAIT,
  NOTE_DO_5, NOTE_RE_DIYEZ_5, NOTE_FA_5, NOTE_FA_DIYEZ_5, NOTE_FA_5, NOTE_RE_DIYEZ_5, NOTE_FA_DIYEZ_5,
  NOTE_FA_DIYEZ_5, NOTE_FA_5, NOTE_RE_DIYEZ_5,
  NOTE_FA_DIYEZ_5, NOTE_FA_5, NOTE_RE_DIYEZ_5
};

// notaların çalma uzunlukları.
int durations[] = {
  4,
  4, 4, 4, 4, 4, 4, 4,
  4,
  7, 7, 7,
  4,
  4, 4,
  6,
  4, 4, 4, 4, 4, 4, 2,
  6, 6, 6,
  6, 6, 6
};



int loopDelay = 500;





int songLength = sizeof(melody)/sizeof(melody[0]);
void setup() {
 //hiçbişe yabmıoz
}

void loop() {

  for (int thisNote = 0; thisNote < songLength; thisNote++){
    
    
    int duration = 1000/ durations[thisNote];
    tone(8, melody[thisNote], duration);
    
    int pause = duration * 1.3;
    delay(pause);
    
    noTone(8);
  }

  delay(loopDelay);

  digitalWrite(10, LOW);
}