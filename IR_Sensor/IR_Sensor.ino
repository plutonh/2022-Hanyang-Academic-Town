char Sensor1 = A0; //A0에 센서연결
int Sensor1_val; //센서 ADC값 저장 변수
char Sensor2 = A1; //A0에 센서연결
int Sensor2_val; //센서 ADC값 저장 변수

#define VOLTS_PER_UNIT .0049F // (.0049 for 10 bit A-D) 
float volts1;
float cm1;
float volts2;
float cm2;
int cnt=0;

void setup() // 초기화
{
  Serial.begin(9600);
}

void loop() // 무한루프
{
  Sensor1_val = analogRead(Sensor1); // 센서저장변수에 아날로그값을 저장
  Sensor2_val = analogRead(Sensor2); // 센서저장변수에 아날로그값을 저장
  volts1 = (float)Sensor1_val * VOLTS_PER_UNIT; // 아날로그값을 volt 단위로 변환
  volts2 = (float)Sensor2_val * VOLTS_PER_UNIT; // 아날로그값을 volt 단위로 변환
  cm1 = 60.495 * pow(volts1,-1.1904); // 측정전압에 따른 cm단위 거리 계산
  cm2 = 60.495 * pow(volts2,-1.1904); // 측정전압에 따른 cm단위 거리 계산
  
  //if (volts < .2) inches = -1.0; // 측정범위 미만일때

  if(cm1>cm2 && cm2<30) 
  {
    Serial.println("LLLLLLLLLLLLLLLLLLLL to RRRRRRRRRRRRRRRRRRRR");
    cnt++;
  }
  else if(cm1<cm2 && cm1<30) 
  {
    Serial.println("RRRRRRRRRRRRRRRRRRRR to LLLLLLLLLLLLLLLLLLLL");
    cnt++;
  }
  else Serial.println("no one");
  
  Serial.print("the distance1 is ");
  Serial.println(cm1);
  Serial.print("the distance2 is ");
  Serial.println(cm2);
  Serial.print("Count is  ");
  Serial.println(cnt);
  
  delay(100); //2초간 지연
}
