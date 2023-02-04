#define phaseA 2
#define phaseB 3
#define pin_inter 0 //chan ngat 0 la chan so 2
int phaseEncoder = 200; // vong/phut
float count = 0;
int time_pre = millis();
int count_print = 0;

void count_phase()
{
  
  if (digitalRead(phaseB) == LOW)
  {
    count++; // quay cung chieu
  }
  else count--; //quay nguoc chieu
}

void setup() {
  Serial.begin(9600);
  attachInterrupt(0, count_phase, RISING); // ngat theo suon len o chan 2
  pinMode( 2, INPUT); // su dung dien tro keo len chan ngat 0
  pinMode( 3, INPUT);

}



void loop() {
  int time_now = millis();
  if (time_now - time_pre > 1000)
  {
    float count_print = 60*(count/phaseEncoder);
    count = 0;
    time_pre = time_now;
    Serial.print(count_print);
    Serial.println(" rpm");
  }
}
