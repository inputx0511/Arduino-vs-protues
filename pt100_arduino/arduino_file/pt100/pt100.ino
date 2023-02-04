#include <LiquidCrystal.h>

int PTD_in = A0;
LiquidCrystal lcd (12,11,5,4,3,2);
int res0 = 100; //dien tro cua ptd tai 100 doC
double A = 3.9083*1e-3;
double B = -5.775*1e-7;

void setup() {
  // put your setup code here, to run once:
  lcd.begin(16,2);
  Serial.begin(9600);
}

void loop() {
  float analog_in = analogRead(PTD_in);
  float dien_ap = (5./1023.)*analog_in;
  
  lcd.setCursor(0,1);
  lcd.print("u=");
  lcd.setCursor(3,1);
  lcd.print(dien_ap);
  
  double res_ptd = dien_ap/(10e-3);
//  lcd.setCursor(6,1);
//  lcd.print(res_ptd);

  double c = (1 - res_ptd/res0);
  double a = B;
  double b = A;
  double nhietdo = (-b+sqrt(pow(b,2)-4*a*c))/(2*a);
  
  lcd.setCursor(0,0);
  lcd.print("nhiet do:");
  Serial.println(nhietdo);
  lcd.setCursor(9,0);
  lcd.print(nhietdo);
  delay(5);
  Serial.println("------------------------");
}
