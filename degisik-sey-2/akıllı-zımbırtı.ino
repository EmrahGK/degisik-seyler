String voice;

#define kirmizi 4
#define sari 5
#define yesil 6
#define buzzer 7
#define do_ 1000
#define re 1122
#define mi 1260
#define fa 1335
#define sol 1498
#define la 1681
#define si 1750
#define dom 2000
#define none 0


void RedOn(){
  digitalWrite (kirmizi, HIGH);
  digitalWrite (buzzer, HIGH);
  delay(500);
  digitalWrite (buzzer, LOW);
}
void RedOff(){
  digitalWrite (kirmizi, LOW);
  digitalWrite (buzzer, LOW);
}
void GreenOn(){
  digitalWrite (sari, HIGH);
  digitalWrite (buzzer, HIGH);
  delay(500);
  digitalWrite (buzzer, LOW);
}
void GreenOff(){
  digitalWrite (sari, LOW);
  digitalWrite (buzzer, LOW);
}
void BlueOn(){
  digitalWrite (yesil, HIGH);
  digitalWrite (buzzer, HIGH);
  delay(500);
  digitalWrite (buzzer, LOW);
}
void BlueOff(){
  digitalWrite (yesil, LOW);
  digitalWrite (buzzer, LOW);
}
void allon() {
  digitalWrite (kirmizi, HIGH);
  digitalWrite (sari, HIGH);
  digitalWrite (yesil, HIGH);
  digitalWrite (buzzer, HIGH);
  delay(500);
  digitalWrite (buzzer, LOW);
  Serial.print("Bütün ledler yakıldı.");  
}
void alloff() {
  digitalWrite (kirmizi, LOW);
  digitalWrite (sari, LOW);
  digitalWrite (yesil, LOW);
  digitalWrite (buzzer, LOW);
}

void pianoMode() {
  int sarki[] = {
    do_,mi,re,none,do_,none,si,none,none,none,none,
    do_,mi,re,none,do_,none,fa,none,fa,none,none,none,none,
    do_,mi,re,none,do_,none,si,none,sol,fa,none,none,none,none,
    
    sol,la,none,sol,fa,none,sol,la,none,sol,fa,none,sol,fa,none,sol,mi,none,none,none

  };
 
  for (int i = 0; i < sizeof(sarki)/sizeof(int); i++) {
    tone(buzzer, sarki[i]);
    delay(350);
    }
    
    noTone(buzzer);
    delay(500);
}

void setup() {
  Serial.begin(9600);
  pinMode(kirmizi, OUTPUT);
  pinMode(sari, OUTPUT);
  pinMode(yesil, OUTPUT);
  pinMode(buzzer, OUTPUT);
}
void loop() {
  while(Serial.available()) {
    delay(10);
    char c=Serial.read();
      if(c=='#')
        {break; }
      voice += c;
}
  if (voice.length() > 0) {
  if (voice == "Hepsini yak" || voice == "Yak" || voice =="hepsini yak" || voice =="yak"){
    allon();
  }
  else if (voice == "Kapat" || voice=="Hepsini kapat" || voice =="hepsini kapat" || voice =="kapat"){
    alloff() ;
    Serial.print("Bütün ledler kapatıldı.");
  }
  else if(voice =="Kırmızı" || voice =="Kırmızıyı yak" || voice =="kırmızı" || voice =="kırmızıyı yak") {
    RedOn();
    Serial.print("Kırmızı led yakıldı.");
  }
  else if(voice =="Kırmızıyı kapat" || voice =="kırmızıyı kapat"){
    RedOff();
    Serial.print("Kırmızı led kapatıldı.");
  }
  else if(voice =="Sarı" || voice =="Sarıyı yak" || voice =="sarıyı yak" || voice =="sarı"){
    GreenOn();
    Serial.print("Sarı led yakıldı.");
  }
  else if(voice =="Sarıyı kapat" || voice =="sarıyı kapat"){
    GreenOff();
    Serial.print("Sarı led kapatıldı");
  }
  else if(voice =="Yeşil" || voice =="Yeşili yak" || voice =="yeşil" || voice =="yeşili yak"){
    BlueOn();
    Serial.print("Yeşil led yakıldı");
  }
  else if( voice =="Yeşili kapat" || voice =="yeşili kapat" ){
    BlueOff();
    Serial.print("Yeşil led kapatıldı.");
  }
  else if( voice == "Şarkı çal" || voice == "şarkı çal" ){
    pianoMode();
  }
  voice="";
}
}