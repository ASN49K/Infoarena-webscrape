#define trig_pin 12
#define echo_pin 11
#define dist_max 200
float time_out=dist_max*60;
int v=340;

void setup()
{
  pinMode(trig_pin, OUTPUT);
  pinMode(echo_pin, INPUT);
  Serial.begin(9600);
}

void loop()
{
  delay(1000);
  Serial.print("Ping: ");
  Serial.print(distanta());
  Serial.println("cm");
}

float distanta()
{
  unsigned long ping;
  float dist;
  digitalWrite(trig_pin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trig_pin, LOW);
  ping=pulseIn(echo_pin, HIGH, time_out);
  dist=(float)ping*v/2/10000;
  return dist; 
}
