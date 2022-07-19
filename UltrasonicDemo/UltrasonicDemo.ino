#include <Ultrasonic.h>
//Ultrasonic ultrasonic3(6,7);//Init an Ultrasonic object y
//Ultrasonic ultrasonic4(8,9);//Init an Ultrasonic object
Ultrasonic ultrasonic1(10,11);//Init an Ultrasonic object y
Ultrasonic ultrasonic3(12,13);//Init an Ultrasonic object
int Distance1;
//int Distance2;
int Distance3;
//int Distance4;

int timer=20;
int geori=50;

void setup() {
  Serial.begin(9600);
}

void loop()
{
 Distance1=ultrasonic1.Ranging(CM);
 Distance3=ultrasonic3.Ranging(CM);
 if(Distance1<Distance3 && Distance1<geori)
 {
  delay(timer);
  Distance3=ultrasonic3.Ranging(CM);
  if(Distance1 - 5 <= Distance3 && Distance3 <= Distance1 + 5) Serial.println("left to right");
 }
 else if(Distance1>Distance3 && Distance3<geori)
 {
  delay(timer);
  Distance1=ultrasonic1.Ranging(CM);
  if(Distance3 - 5 <= Distance1 && Distance1 <= Distance3 + 5) Serial.println("right to left");
 }
 else Serial.println("no one");
}

/*#include <Ultrasonic.h>
//Ultrasonic ultrasonic3(6,7);//Init an Ultrasonic object y
//Ultrasonic ultrasonic4(8,9);//Init an Ultrasonic object
Ultrasonic ultrasonic1(10,11);//Init an Ultrasonic object y
Ultrasonic ultrasonic3(12,13);//Init an Ultrasonic object
int Distance1;
//int Distance2;
int Distance3;
//int Distance4;

int timer=10;
int num=1000;
int total=20;
int count=0;
int sum1=0;
int sum3=0;

void setup() {
  Serial.begin(9600);
}

void loop()
{
 Distance1=ultrasonic1.Ranging(CM);
 Distance3=ultrasonic3.Ranging(CM);
 sum1+=Distance1;
 sum3+=Distance3;
 count++;
 if(count>=total)
 {
  if(sum1<sum3 && sum1<num && sum3<num)
  {
    Serial.println(sum1);
    Serial.println(sum3);
    Serial.println("left to right");
  
    //Serial.print("the distance1 is ");
    //Serial.println(Distance1);
    //delay(timer);
    //if(Distance2<num) Serial.println("left to right");
    //Serial.print("the distance2 is ");
    //Serial.println(Distance2);
  }
  else if(sum1>sum3 && sum1<num && sum3<num)
  {
    Serial.println(sum1);
    Serial.println(sum3);
    Serial.println("right to left");
  
    //Serial.print("the distance3 is ");
    //Serial.println(Distance3);
    //delay(timer);
    //Distance4=ultrasonic4.Ranging(CM);
    //if(Distance4<num) Serial.println("right to left");
    //Serial.print("the distance4 is ");
    //Serial.println(Distance4);
  }
  else Serial.println("no one");

  count=0;
  sum1=0;
  sum3=0;

  delay(timer);
 }
}*/
