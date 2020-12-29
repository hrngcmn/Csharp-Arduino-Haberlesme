#define trig 2 // trig sensörün ses dalgası gönderen kısmı.D2 pinine bağlı.
#define echo 7 // echo sensörün ses dalgasını alan kısmıdır.D7 pinine bağlı.
#define buzzer 8 // buzzer 8. pine bağlı
long uzaklik ;
long sure;
float dly;
void setup() {
  pinMode(trig,OUTPUT); // ses dalgasını gönderdiği için output.
  pinMode(echo,INPUT); // ses dalgasını aldığı için input.
  pinMode(buzzer,OUTPUT);  // sinyal çıkışı olduğu için output.
  Serial.begin(9600); // serial okuma yapılacak. 
}
void loop() {
  digitalWrite(trig,HIGH);
  delayMicroseconds(10);
  digitalWrite(trig, LOW);
  sure = pulseIn(echo,HIGH); //echo pin Hıgh oluncaya kadar geçen zaman.
  uzaklik =(sure/2)/29.1;// ölçülen süre uzaklığa çevirildi.
  if(uzaklik >= 200) // uzaklığı ölçmesi için bir sınır koyuyorum.
    uzaklik = 200;
//  Serial.print("uzaklık: ");
  Serial.println(uzaklik);
//  Serial.println("cm");
  delay(500); // ....yarım saniyede bir portta çıkış okumak için

  dly = 5000/uzaklik; // yakşaştıkça daha uzun ses çıkaracak.
  if(uzaklik>=2 and uzaklik<=20)
   {
    tone(buzzer,700); // 
    delay(dly);
    noTone(buzzer);
    delay(10);
   }
}
