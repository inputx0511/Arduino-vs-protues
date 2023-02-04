#define trig 3     // chân trig của HC-SR04
#define echo 2    // chân echo của HC-SR04
 
void setup()
{
    Serial.begin(9600);
    pinMode(trig, OUTPUT);
    pinMode(echo, INPUT);
}
 
void loop()
{
    unsigned long duration;
    int distance;
    digitalWrite(trig, LOW);
    delayMicroseconds(2);
    digitalWrite(trig, HIGH);  // phát xung từ chân trig
    delayMicroseconds(15);    //datasheet cua srf04 thi trigger pulse min = 10us
    digitalWrite(trig, LOW);
    
    duration = pulseIn(echo, HIGH);
    distance = duration/2/2.9;    //datasheet noi ve viec tinh toan khoang cach
    Serial.print(distance);
    Serial.println(" mm");
    delay(20);
}
