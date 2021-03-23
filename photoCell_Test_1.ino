// LAB8 - 讀取光敏電阻 (v1)
#include <Servo.h>
#include <SCoop.h>     //包含SCoop頭文件
int photocellPin = 2; // 光敏電阻 (photocell) 接在 anallog pin 2
int photocellVal = 0; // photocell variable
Servo myservo; // 建立Servo物件，控制伺服馬達
void setup() {
  Serial.begin(9600);
  myservo.attach(9); // 連接數位腳位9，伺服馬達的訊號線
  myservo.write(90); // 一開始先置中90度
}

void loop() {
  // 讀取光敏電阻並輸出到 Serial Port
  photocellVal = analogRead(photocellPin);
  Serial.println(photocellVal);
  if (photocellVal < 450) {
      myservo.write(30); // 使用write，傳入角度，從0度轉到180度
      sleep(0);
  }else{
      myservo.write(0);// 使用write，傳入角度，從180度轉到0度
      sleep(0);
    
  }

}
