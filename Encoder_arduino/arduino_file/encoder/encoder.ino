#define phaseA 2
#define phaseB 3
//#define pin_inter0 2 //chan ngat la 2
int phaseEncoder = 2000; // vong/phut
int count = 0;



void setup() {
  Serial.begin(9600);
  pinMode( 2, INPUT_PULLUP); // su dung dien tro keo len chan ngat 0
  pinMode( 3, INPUT);
}

void count_phase()
{
  if (digitalRead(phaseB) == HIGH)
  {
    count++; // quay cung chieu
  }
  else count--; //quay nguoc chieu
}

void loop() {
  
  attachInterrupt(0, count_phase, RISING); // ngat theo suon len o chan 2

}
