#include <SCoop.h>     //包含SCoop頭文件
#include <Servo.h>
Servo myservo1; // 建立Servo物件，控制伺服馬達
Servo myservo2; // 建立Servo物件，控制伺服馬達
int photocellPin_1 = 1; // 光敏電阻 (photocell) 接在 anallog pin 1
int photocellPin_2 = 2; // 光敏電阻 (photocell) 接在 anallog pin 2
int photocellVal_1 = 0; // photocell variable 1
int photocellVal_2 = 0; // photocell variable 2
defineTaskLoop(myTask1)    //創建線程myTask1
{

  Serial.println("hello from task1");
  sleepSync(1000);
}

defineTask(myTask2);   //創建線程myTask2

void myTask2::setup() { //設定線程myTask2
  trace("task2setup");
  Serial.begin(9600);
  myservo1.attach(9); // 連接數位腳位9，伺服馬達的訊號線
  myservo1.write(0); // 一開始先置中0度
}

void myTask2::loop()  { //設定線程myTask2循環
  //  sleepSync(500);
  //  sleepSync(500);
  // 讀取光敏電阻並輸出到 Serial Port
  photocellVal_1 = analogRead(photocellPin_1);
  Serial.println(photocellVal_1);
  if (photocellVal_1 < 450) {
    myservo1.write(30); // 使用write，傳入角度，從0度轉到180度
    sleepSync(0);
  } else {
    myservo1.write(0);// 使用write，傳入角度，從180度轉到0度
    sleepSync(0);
  }
}


defineTask(myTask3);   //創建線程myTask3

void myTask3::setup() { //設定線程myTask3
  trace("task2setup");
  Serial.begin(9600);
  myservo2.attach(8); // 連接數位腳位8，伺服馬達的訊號線
  myservo2.write(0); // 一開始先置中0度
}

void myTask3::loop()  { //設定線程myTask3循環
  //  sleepSync(500);
  //  sleepSync(500);
  // 讀取光敏電阻並輸出到 Serial Port
  photocellVal_2 = analogRead(photocellPin_2);
  Serial.println(photocellVal_2);
  if (photocellVal_2 < 450) {
    myservo2.write(30); // 使用write，傳入角度，從0度轉到180度
    sleepSync(0);
  } else {
    myservo2.write(0);// 使用write，傳入角度，從180度轉到0度
    sleepSync(0);
  }
}

defineTimerRun(Timer1, 100)
{ if (Serial.available()) {
    char c = Serial.read();
    Serial.print(c); Serial.println(" key pressed");
    if (c == 'a') myTask1.pause();
    if (c == 'b') myTask1.resume();
  }
}
void setup() {
  // put your setup code here, to run once:
  mySCoop.start();
}

void loop() {
  // put your main code here, to run repeatedly:
  yield();
}
