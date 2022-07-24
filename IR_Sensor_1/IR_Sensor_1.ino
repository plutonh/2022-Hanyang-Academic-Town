char Sensor1 = A0; //A0에 센서연결
int Sensor1_val; //센서 ADC값 저장 변수
char Sensor2 = A1; //A1에 센서연결
int Sensor2_val; //센서 ADC값 저장 변수

#define VOLTS_PER_UNIT .0049F // (.0049 for 10 bit A-D)

float volts1;
float cm1;
float volts2;
float cm2;

int m1=90;

void setup() // 초기화
{
  Serial.begin(9600);
}

void loop() // 무한루프
{
  Sensor1_val = analogRead(Sensor1); // 센서저장변수에 아날로그값을 저장
  Sensor2_val = analogRead(Sensor2);
  volts1 = (float)Sensor1_val * VOLTS_PER_UNIT; // 아날로그값을 volt 단위로 변환
  volts2 = (float)Sensor2_val * VOLTS_PER_UNIT;
  cm1 = 60.495 * pow(volts1,-1.1904); // 측정전압에 따른 cm단위 거리 계산
  cm2 = 60.495 * pow(volts2,-1.1904);

  /*Serial.println("cm1");
  Serial.println(cm1);
  Serial.println("cm2");
  Serial.println(cm2);*/

  if(cm1<cm2 && cm1>10 && cm1<m1)
  {
    Serial.println("Left to Right");
    while(1)
    {
      Sensor1_val = analogRead(Sensor1); // 센서저장변수에 아날로그값을 저장
      Sensor2_val = analogRead(Sensor2);
      volts1 = (float)Sensor1_val * VOLTS_PER_UNIT; // 아날로그값을 volt 단위로 변환
      volts2 = (float)Sensor2_val * VOLTS_PER_UNIT;
      cm1 = 60.495 * pow(volts1,-1.1904); // 측정전압에 따른 cm단위 거리 계산
      cm2 = 60.495 * pow(volts2,-1.1904);
      if(cm1>=100 && cm2>=100) break;
    }
  }
  else if(cm1>cm2 && cm2>10 && cm2<m1)
  {
    Serial.println("Right to Left");
    while(1)
    {
      Sensor1_val = analogRead(Sensor1); // 센서저장변수에 아날로그값을 저장
      Sensor2_val = analogRead(Sensor2);
      volts1 = (float)Sensor1_val * VOLTS_PER_UNIT; // 아날로그값을 volt 단위로 변환
      volts2 = (float)Sensor2_val * VOLTS_PER_UNIT;
      cm1 = 60.495 * pow(volts1,-1.1904); // 측정전압에 따른 cm단위 거리 계산
      cm2 = 60.495 * pow(volts2,-1.1904);
      if(cm1>=100 && cm2>=100) break;
    }
  }

  delay(50);
  
  /*if(cm1<cm2 && cm1>10)
  {
    if(cm1 < 60 && Sum1 > 40) Serial.println("Left to Right, Two");
    else if(Sum1 < m1 && Sum1 >= 60) Serial.println("Left to Right, One");
    //else Serial.println("No Person");
    while(1)
    {
      Sensor1_val = analogRead(Sensor1); // 센서저장변수에 아날로그값을 저장
      Sensor2_val = analogRead(Sensor2);
      Sensor3_val = analogRead(Sensor3);
      Sensor4_val = analogRead(Sensor4);
      volts1 = (float)Sensor1_val * VOLTS_PER_UNIT; // 아날로그값을 volt 단위로 변환
      volts2 = (float)Sensor2_val * VOLTS_PER_UNIT;
      volts3 = (float)Sensor3_val * VOLTS_PER_UNIT;
      volts4 = (float)Sensor4_val * VOLTS_PER_UNIT;
      cm1 = 60.495 * pow(volts1,-1.1904); // 측정전압에 따른 cm단위 거리 계산
      cm2 = 60.495 * pow(volts2,-1.1904);
      cm3 = 60.495 * pow(volts3,-1.1904);
      cm4 = 60.495 * pow(volts4,-1.1904);
      
      Sensor1_val = analogRead(Sensor1); // 센서저장변수에 아날로그값을 저장
      volts1 = (float)Sensor1_val * VOLTS_PER_UNIT; // 아날로그값을 volt 단위로 변환
      cm1 = 60.495 * pow(volts1,-1.1904); // 측정전압에 따른 cm단위 거리 계산
      Sensor3_val = analogRead(Sensor3); // 센서저장변수에 아날로그값을 저장
      volts3 = (float)Sensor3_val * VOLTS_PER_UNIT; // 아날로그값을 volt 단위로 변환
      cm3 = 60.495 * pow(volts3,-1.1904); // 측정전압에 따른 cm단위 거리 계산
      Sum1 = cm1 + cm3;
      Sum2 = cm2 + cm4;

      Serial.println("1-Sum1");
      Serial.println(Sum1);
      Serial.println("1-Sum2");
      Serial.println(Sum2);
      
      if(Sum1>=m1 && Sum2>=m1) break;
    }
  }
  else if(Sum1>Sum2 && Sum2>10)
  {
    if(Sum2 < 60 && Sum2 > 40) Serial.println("Right to Left, Two");
    else if(Sum2 < m1 && Sum2 >= 60) Serial.println("Right to Left, One");
    //else Serial.println("No Person");
    while(1)
    {
      Sensor1_val = analogRead(Sensor1); // 센서저장변수에 아날로그값을 저장
      Sensor2_val = analogRead(Sensor2);
      Sensor3_val = analogRead(Sensor3);
      Sensor4_val = analogRead(Sensor4);
      volts1 = (float)Sensor1_val * VOLTS_PER_UNIT; // 아날로그값을 volt 단위로 변환
      volts2 = (float)Sensor2_val * VOLTS_PER_UNIT;
      volts3 = (float)Sensor3_val * VOLTS_PER_UNIT;
      volts4 = (float)Sensor4_val * VOLTS_PER_UNIT;
      cm1 = 60.495 * pow(volts1,-1.1904); // 측정전압에 따른 cm단위 거리 계산
      cm2 = 60.495 * pow(volts2,-1.1904);
      cm3 = 60.495 * pow(volts3,-1.1904);
      cm4 = 60.495 * pow(volts4,-1.1904);
      
      Sensor2_val = analogRead(Sensor2); // 센서저장변수에 아날로그값을 저장
      volts2 = (float)Sensor2_val * VOLTS_PER_UNIT; // 아날로그값을 volt 단위로 변환
      cm3 = 60.495 * pow(volts2,-1.1904); // 측정전압에 따른 cm단위 거리 계산
      Sensor4_val = analogRead(Sensor4); // 센서저장변수에 아날로그값을 저장
      volts4 = (float)Sensor4_val * VOLTS_PER_UNIT; // 아날로그값을 volt 단위로 변환
      cm4 = 60.495 * pow(volts4,-1.1904); // 측정전압에 따른 cm단위 거리 계산
      Sum1 = cm1 + cm3;
      Sum2 = cm2 + cm4;

      Serial.println("2-Sum1");
      Serial.println(Sum1);
      Serial.println("2-Sum2");
      Serial.println(Sum2);
      
      if(Sum1>=m1 && Sum2>=m1) break;
    }
  }
  else
  {
   Serial.println(" ");
  }*/
  delay(10);
  
  /*if(cm2<cm1)
  {
    delay(100);
    Sensor1_val = analogRead(Sensor1);
    volts1 = (float)Sensor2_val * VOLTS_PER_UNIT;
    cm1 = 60.495 * pow(volts2,-1.1904);
    if(cm1<30 && cm3>70) Serial.println("output one");// one
    else if(cm1<30 && cm3<30) Serial.println("output two");// two
    else if(cm1>70 && cm3<30) Serial.println("output one");// one
    else if((cm1>40 && cm1<80) || (cm3>40 && cm3<80)) Serial.println("output one");// one
    else Serial.println("no one");
  }
  else if(cm3<cm4)
  {
    delay(100);
    Sensor4_val = analogRead(Sensor4);
    volts4 = (float)Sensor4_val * VOLTS_PER_UNIT;
    cm4 = 60.495 * pow(volts4,-1.1904);
    if(cm2<30 && cm4>70) Serial.println("input one");// one
    else if(cm2<30 && cm4<30) Serial.println("input two");// two
    else if(cm2>70 && cm4<30) Serial.println("input one");// one
    else if((cm2>40 && cm2<80) || (cm4>40 && cm4<80)) Serial.println("input one");// one
    else Serial.println("no one");
  }
  else Serial.println("no one");
  
  if(cm1>cm2) // input
  {
    if(cm2<30 && cm4>70) Serial.println("input one");// one
    else if(cm2<30 && cm4<30) Serial.println("input two");// two
    else if(cm2>70 && cm4<30) Serial.println("input one");// one
    else if((cm2>40 && cm2<80) || (cm4>40 && cm4<80)) Serial.println("input one");// one
    else Serial.println("no one");
    while(1)
    {
      Sensor2_val = analogRead(Sensor2);
      volts2 = (float)Sensor2_val * VOLTS_PER_UNIT;
      cm2 = 60.495 * pow(volts2,-1.1904);
      if(cm2>30) break;
    }
  }
  else // output
  {
    if(cm1<30 && cm3>70) Serial.println("output one");// one
    else if(cm1<30 && cm3<30) Serial.println("output two");// two
    else if(cm1>70 && cm3<30) Serial.println("output one");// one
    else if((cm1>40 && cm1<80) || (cm3>40 && cm3<80)) Serial.println("output one");// one
    else Serial.println("no one");
    while(1)
    {
      Sensor4_val = analogRead(Sensor2);
      volts4 = (float)Sensor2_val * VOLTS_PER_UNIT;
      cm4 = 60.495 * pow(volts2,-1.1904);
      if(cm4>30) break;
    }
  }
  
  /*else if(
  {
    Serial.println("Left to Right");
    while(1)
    {
      Sensor2_val = analogRead(Sensor2); // 센서저장변수에 아날로그값을 저장
      volts2 = (float)Sensor2_val * VOLTS_PER_UNIT; // 아날로그값을 volt 단위로 변환
      cm2 = 60.495 * pow(volts2,-1.1904); // 측정전압에 따른 cm단위 거리 계산
      if(cm2>30) break;
    }
    cnt++;
  }
  else if(cm1<cm2 && cm1<30) 
  {
    Serial.println("Right to Left");
    while(1)
    {
      Sensor1_val = analogRead(Sensor1); // 센서저장변수에 아날로그값을 저장
      volts1 = (float)Sensor1_val * VOLTS_PER_UNIT; // 아날로그값을 volt 단위로 변환
      cm1 = 60.495 * pow(volts1,-1.1904); // 측정전압에 따른 cm단위 거리 계산
      if(cm1>30) break;
    }
    cnt++;
  }
  else Serial.println("no one");
  
  /*Serial.print("the distance1 is ");
  Serial.println(cm1);
  Serial.print("the distance2 is ");
  Serial.println(cm2);
  Serial.print("Count is  ");
  Serial.println(cnt);*/
}
