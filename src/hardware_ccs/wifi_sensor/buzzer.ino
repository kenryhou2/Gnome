#define buzzerPin 40
//Set Buzzer thresholds for each sensor here.

#define soundThreshold 100
int length = 15;         /* the number of notes */
char notes[] = "ccggaagffeeddc "; //notes in the song
int beats[] = { 1, 1, 1, 1, 1, 1, 2, 1, 1, 1, 1, 1, 1, 2, 4 }; //length of each note
int tempo = 100;

void setupBuzzer(){
     pinMode(buzzerPin, OUTPUT);
     digitalWrite(buzzerPin, LOW);
}
void loopBuzzer(){
    if(moisture > 150 && moisture < 300)
    {
        for(int i = 0; i < length; i++) 
          {
            //space indicates a pause
            if(notes[i] == ' ') 
            {
              delay(beats[i] * tempo);
            } 
            else 
            {
              playNote(notes[i], beats[i] * tempo);
            }
            delay(tempo / 2);    /* delay between notes */
          }
    }
     
    
}

/* play tone */
void playTone(int tone, int duration) 
{
  for (long i = 0; i < duration * 1000L; i += tone * 2) 
  {
    digitalWrite(buzzerPin, HIGH);
    delayMicroseconds(tone/5);
    digitalWrite(buzzerPin, LOW);
    delayMicroseconds(tone/5);
  }
}

char names[] = { 'c', 'd', 'e', 'f', 'g', 'a', 'b', 'C' };
int tones[] = { 1915, 1700, 1519, 1432, 1275, 1136, 1014, 956 };

void playNote(char note, int duration) 
{
  
  
  // play the tone corresponding to the note name
  for (int i = 0; i < 8; i++) 
  {
    if (names[i] == note) 
    {
      playTone(tones[i], duration);
    }
  }
}