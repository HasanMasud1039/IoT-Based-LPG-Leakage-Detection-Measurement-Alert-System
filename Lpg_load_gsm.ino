#include <LiquidCrystal.h>
#include <HX711.h>
#include <GPRS_Shield_Arduino.h>
#include <Wire.h>

#define PIN_TX    9
#define PIN_RX    8
#define BAUDRATE  9600
#define PHONE_NUMBER "+8801850081945"
#define MESSAGE  "Gas Leakage alert!"
#define MESSAGEload  "Gas Remain 20%. Please, refill the cylinder."

GPRS gprs(PIN_TX,PIN_RX,BAUDRATE);//RX,TX,BaudRate

//LiquidCrystal lcd(3, 2, 4, 5, 6, 7);
const int rs = 12, en = 11, d4 = 5, d5 = 4, d6 = 3, d7 = 2;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);
// HX711.DOUT  - pin #A1
// HX711.PD_SCK - pin #A0
Hx711 scale(A1, A0);
#define lpg_sensor 10
#define buzzer 13
#define fan 7
void setup() 
{
  pinMode(lpg_sensor, INPUT);
  pinMode(buzzer, OUTPUT);
  pinMode(fan, OUTPUT);
  lcd.begin(16, 2);
  lcd.print("LPG Gas Detector");
  lcd.setCursor(0,1);
  
  delay(2000);
}

void loop() 
{
  
//delay(500);
  
  lcd.setCursor(0, 0);
  lcd.print("     ");
  lcd.print(scale.getGram(), 1);  
  lcd.print(" g       ");

  //lcd.setCursor(0,1);
  if(scale.getGram()>150)
  //gprs.sendSMS(PHONE_NUMBER,MESSAGEload);
  delay(900);
 
 
  if(digitalRead(lpg_sensor))
  {
    //digitalWrite(buzzer, LOW);
    lcd.clear();
    lcd.setCursor(0,1);
    lcd.print("No Gas");
    //lcd.setCursor(0,1);
    lcd.print(" Leakage");
    delay(100); 
  }
  
  else 
  {
     //gprs.callUp(PHONE_NUMBER);
    
    buzz();
    //digitalWrite(buzzer, HIGH);
    lcd.clear();
    lcd.print("LPG Gas Leakage");
    lcd.setCursor(0, 1);
    lcd.print("     Alert     ");
    delay(200);
    //digitalWrite(buzzer, LOW);
    //delay(300);
    
    
    //gsm();
    //calls();
   
    //gprs.sendSMS(PHONE_NUMBER,MESSAGE);
  }
  }
void buzz()
{
    digitalWrite(fan, HIGH);
    //delay(2000);
    
    digitalWrite(buzzer, HIGH);
    delay(2000);
    digitalWrite(buzzer, LOW);
    delay(500);
    digitalWrite(buzzer, HIGH);
    delay(3000);
    digitalWrite(buzzer, LOW);
    delay(500);
    digitalWrite(fan, LOW);
    //delay(200);
  
}
/*void fani()
{
  
  digitalWrite(fan, HIGH);
    delay(2000);
    digitalWrite(fan, LOW);
    //delay(200);
}

  

  void gsm() {
  gprs.checkPowerUp();
  Serial.begin(9600);   
  
  while(!gprs.init()) {
      delay(1000);
     // Serial.println("Initialization failed!");
  }  

  while(!gprs.isNetworkRegistered())
  {
    delay(1000);
    //Serial.println("Network has not registered yet!");
  }

  //Serial.println("gprs initialize done!");
  //Serial.println("start to send message ...");
  
  if(gprs.sendSMS(PHONE_NUMBER,MESSAGE)) //define phone number and text
  {
    Serial.print("Send SMS Succeed!\r\n");
  }
  else {
    Serial.print("Send SMS failed!\r\n");
  }
}


void calls() {
  gprs.checkPowerUp();
  Serial.begin(9600);
  while(!gprs.init()) {
      delay(1000);
      //Serial.println("Initialization failed!");
  }  

  while(!gprs.isNetworkRegistered())
  {
    delay(1000);
    //Serial.println("Network has not registered yet!");
  }

  //Serial.println("gprs initialize done");
  //Serial.println("start to call ...");
  gprs.callUp(PHONE_NUMBER);
}
*/
