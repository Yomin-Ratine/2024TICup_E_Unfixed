#define TJC Serial3
#define FRAME_LENGTH 6
#include <Servo.h>  //调用舵机库
Servo myservo;  // 定义舵机对象 7 号
Servo myservo1;  // 定义舵机对象 8 号
Servo myservo2;  // 定义舵机对象 9 号
int pos = 0;    // 定义舵机转动位置
int ledPin=2;//定义数字2接口
int h;
int a,c=0;
int sta;
int d=0;
char str[100];
unsigned long nowtime;
void MoveDuoji(int x,int delay1, int y,int delay2, int z,int delay3){
    myservo.writeMicroseconds(x);
    delay(delay1);
    myservo1.writeMicroseconds(y);
    delay(delay2);
    myservo2.writeMicroseconds(z);
    delay(delay3);
}

#define Ini() MoveDuoji(650,50,2450,50,1300,50);

//黑0白1
void Chess(int color,int x){
    if(color==0){
        switch(x){//五个棋子的位置
            case 1:MoveDuoji(500,50,1550,50,2300,50); break;
            case 2:MoveDuoji(900,50,2450,50,0,50); break;
            /*case 3:MoveDuoji(); break;
            case 4:MoveDuoji(); break;
            case 5:MoveDuoji(); break;*/
            default:break;
        }
    }else if(color==1){
        switch(x){//五个棋子的位置
            //case 1:MoveDuoji(); break;
            case 2:MoveDuoji(1290,50,2400,50,1500,50); break;
            case 3:MoveDuoji(1000,50,2080,50,1300,50); break;
            case 4:MoveDuoji(1090,50,2500,50,1400,50); break;
            //case 5:MoveDuoji(); break;
            default:break;
        }
    }else{}
}
void Site(int x){
    switch(x){
        case 1:MoveDuoji(650,50,1750,50,1900,50); break;
        case 2:MoveDuoji(720,50,1650,50,1500,50); break;
        case 3:MoveDuoji(860,50,1660,50,975,50); break;

        case 4:MoveDuoji(554,50,1750,50,1840,50); break;
        case 5:MoveDuoji(650,50,1700,50,1470,50); break;
        case 6:MoveDuoji(815,50,1900,50,1420,50); break;
        case 7:MoveDuoji(584,50,2000,50,2020,50); break;
        case 8:MoveDuoji(630,50,1900,50,1650,50); break;
        case 9:MoveDuoji(790,50,2000,50,1420,50); break;
        default:break;
    }//544-2000 最右边是越小越往右 中间是越大越往右 最左边是越大越往外
}

void Task1(){
  
    Ini();
    delay(2500);
    Chess(0,1);//黑色第一个棋子
    delay(2500);
    digitalWrite(ledPin,HIGH);//打开
    
    delay(500);
    Site(5);
    delay(2500);
    digitalWrite(ledPin,LOW);//关闭
    delay(500);
    Ini();2
    
}

void Task2(){
    
}
void setup() {
    // put your setup code here, to run once:
    //初始化串口
    pinMode(ledPin,OUTPUT);//定义小灯接口为输出接口
    digitalWrite(ledPin,LOW);//关闭
    TJC.begin(9600);
    myservo.attach(7);
     myservo1.attach(8);
      myservo2.attach(9);
    //因为串口屏开机会发送88 ff ff ff,所以要清空串口缓冲区
    while (TJC.read() >= 0); //清空串口缓冲区
    TJC.print("page main\xff\xff\xff"); //发送命令让屏幕跳转到main页面
    nowtime = millis(); //获取当前已经运行的时间
    d=1;
}
void SendEnd(){
  TJC.write(0xff);
  TJC.write(0xff);
  TJC.write(0xff);
}

void duoji(int angle){
  //这也写 case 10 到28  再写case 30到38 case 40到48
  // switch(sta)
  // {
  //   case 10:   myservo.writeMicroseconds(2450); break;
  //   case 11:   myservo.writeMicroseconds(2450); break;



  // }

   // 1 号舵机 0 到2450 2号舵机 2450 到 800 3 号舵机 2450 到 0

}



void chuankou(){
  while (TJC.available() >= FRAME_LENGTH) {
     unsigned char ubuffer[FRAME_LENGTH];
     //从串口缓冲读取1个字节但不删除
     unsigned char frame_header = TJC.peek();
     //当获取的数据是包头(0x55)时
    switch (frame_header) {  
        case 0x10:  while (TJC.read() >= 0);  sta=10;Task1();Serial3.write("\xff\xff\xff"); sprintf(str, "n15.val++", h);   TJC.print(str); SendEnd();
        break;   // 题目一    10 
        case 0x11: while (TJC.read() >= 0);  sta=11;  Serial3.write("\xff\xff\xff"); sprintf(str, "n15.val++", h);   TJC.print(str); SendEnd();  
        Chess(0,1); digitalWrite(ledPin,HIGH); delay(2500); Site(1); digitalWrite(ledPin,LOW); delay(2500); break;// 黑一 1  黑一从 11到19
        case 0x12: while (TJC.read() >= 0);  sta=12;  Serial3.write("\xff\xff\xff"); sprintf(str, "n15.val++", h);   TJC.print(str); SendEnd();
        Chess(0,1); digitalWrite(ledPin,HIGH); delay(2500); Site(2); digitalWrite(ledPin,LOW); delay(2500); break;// 黑一 2  
        case 0x13: while (TJC.read() >= 0);  sta=13; Serial3.write("\xff\xff\xff");  sprintf(str, "n15.val++", h);   TJC.print(str); SendEnd(); 
        Chess(0,1); digitalWrite(ledPin,HIGH); delay(2500); Site(3); digitalWrite(ledPin,LOW); delay(2500); break;// 黑一 3  
        case 0x14: while (TJC.read() >= 0);  sta=14;Serial3.write("\xff\xff\xff");   sprintf(str, "n15.val++", h);   TJC.print(str); SendEnd();  
        Chess(0,1); digitalWrite(ledPin,HIGH); delay(2500); Site(4); digitalWrite(ledPin,LOW); delay(2500); break;// 黑一 4  
        case 0x15: while (TJC.read() >= 0);  sta=15;Serial3.write("\xff\xff\xff");   sprintf(str, "n15.val++", h);   TJC.print(str); SendEnd();  
        Chess(0,1); digitalWrite(ledPin,HIGH); delay(2500); Site(5); digitalWrite(ledPin,LOW); delay(2500); break;// 黑一 5  
        case 0x16: while (TJC.read() >= 0);  sta=16;Serial3.write("\xff\xff\xff");   sprintf(str, "n15.val++", h);   TJC.print(str); SendEnd();  
        Chess(0,1); digitalWrite(ledPin,HIGH); delay(2500); Site(6); digitalWrite(ledPin,LOW); delay(2500); break;// 黑一 6  
        case 0x17: while (TJC.read() >= 0);  sta=17;Serial3.write("\xff\xff\xff");   sprintf(str, "n15.val++", h);   TJC.print(str); SendEnd();  
        Chess(0,1); digitalWrite(ledPin,HIGH); delay(2500); Site(7); digitalWrite(ledPin,LOW); delay(2500); break;// 黑一 7  
        case 0x18: while (TJC.read() >= 0);  sta=18;Serial3.write("\xff\xff\xff");   sprintf(str, "n15.val++", h);   TJC.print(str); SendEnd();  
        Chess(0,1); digitalWrite(ledPin,HIGH); delay(2500); Site(8); digitalWrite(ledPin,LOW); delay(2500); break;// 黑一 8  
        case 0x19: while (TJC.read() >= 0);  sta=19;Serial3.write("\xff\xff\xff");   sprintf(str, "n15.val++", h);   TJC.print(str); SendEnd();  
        Chess(0,1); digitalWrite(ledPin,HIGH); delay(2500); Site(9); digitalWrite(ledPin,LOW); delay(2500); break;// 黑一 9  

        case 0x20: while (TJC.read() >= 0);  sta=20;Serial3.write("\xff\xff\xff");   sprintf(str, "n15.val++", h);   TJC.print(str); SendEnd();  
        Chess(0,2); digitalWrite(ledPin,HIGH); delay(2500); Site(1); digitalWrite(ledPin,LOW); delay(2500); break;// 黑二 1 黑二从 20 到29
        case 0x21: while (TJC.read() >= 0);  sta=21;Serial3.write("\xff\xff\xff");   sprintf(str, "n15.val++", h);   TJC.print(str); SendEnd();  
        Chess(0,2); digitalWrite(ledPin,HIGH); delay(2500); Site(2); digitalWrite(ledPin,LOW); delay(2500); break;// 黑二 2  
        case 0x22: while (TJC.read() >= 0);  sta=22;Serial3.write("\xff\xff\xff");   sprintf(str, "n15.val++", h);   TJC.print(str); SendEnd();  
        Chess(0,2); digitalWrite(ledPin,HIGH); delay(2500); Site(3); digitalWrite(ledPin,LOW); delay(2500); break;// 黑二 3
        case 0x23: while (TJC.read() >= 0);  sta=23;Serial3.write("\xff\xff\xff");   sprintf(str, "n15.val++", h);   TJC.print(str); SendEnd();  
        Chess(0,2); digitalWrite(ledPin,HIGH); delay(2500); Site(4); digitalWrite(ledPin,LOW); delay(2500); break;// 黑二 4
        case 0x24: while (TJC.read() >= 0);  sta=24;Serial3.write("\xff\xff\xff");   sprintf(str, "n15.val++", h);   TJC.print(str); SendEnd();  
        Chess(0,2); digitalWrite(ledPin,HIGH); delay(2500); Site(5); digitalWrite(ledPin,LOW); delay(2500); break;// 黑二 5
        case 0x25: while (TJC.read() >= 0);  sta=25;Serial3.write("\xff\xff\xff");   sprintf(str, "n15.val++", h);   TJC.print(str); SendEnd();  
        Chess(0,2); digitalWrite(ledPin,HIGH); delay(2500); Site(6); digitalWrite(ledPin,LOW); delay(2500); break;// 黑二 6
        case 0x26: while (TJC.read() >= 0);  sta=26;Serial3.write("\xff\xff\xff");   sprintf(str, "n15.val++", h);   TJC.print(str); SendEnd();  
        Chess(0,2); digitalWrite(ledPin,HIGH); delay(2500); Site(7); digitalWrite(ledPin,LOW); delay(2500); break;// 黑二 7
        case 0x27: while (TJC.read() >= 0);  sta=27;Serial3.write("\xff\xff\xff");   sprintf(str, "n15.val++", h);   TJC.print(str); SendEnd();  
        Chess(0,2); digitalWrite(ledPin,HIGH); delay(2500); Site(8); digitalWrite(ledPin,LOW); delay(2500); break;// 黑二 8        
        case 0x28: while (TJC.read() >= 0);  sta=28;Serial3.write("\xff\xff\xff");   sprintf(str, "n15.val++", h);   TJC.print(str); SendEnd();  
        Chess(0,2); digitalWrite(ledPin,HIGH); delay(2500); Site(9); digitalWrite(ledPin,LOW); delay(2500); break;// 黑二 9
//从这开始写
        case 0x50:while (TJC.read() >= 0);   sta=50;Serial3.write("\xff\xff\xff");  sprintf(str, "n15.val++", h);   TJC.print(str); SendEnd();  
        Chess(0,3); digitalWrite(ledPin,HIGH); delay(2500); Site(1); digitalWrite(ledPin,LOW); delay(2500); break; // 黑一 1  
        case 0x51:while (TJC.read() >= 0);   sta=51;Serial3.write("\xff\xff\xff");  sprintf(str, "n15.val++", h);   TJC.print(str); SendEnd();  
        Chess(0,3); digitalWrite(ledPin,HIGH); delay(2500); Site(2); digitalWrite(ledPin,LOW); delay(2500); break; // 黑一 2  
        case 0x52:while (TJC.read() >= 0);   sta=52;Serial3.write("\xff\xff\xff");  sprintf(str, "n15.val++", h);   TJC.print(str); SendEnd();  
        Chess(0,3); digitalWrite(ledPin,HIGH); delay(2500); Site(3); digitalWrite(ledPin,LOW); delay(2500); break; // 黑一 3  
        case 0x53:while (TJC.read() >= 0);   sta=53;Serial3.write("\xff\xff\xff");  sprintf(str, "n15.val++", h);   TJC.print(str); SendEnd();  
        Chess(0,3); digitalWrite(ledPin,HIGH); delay(2500); Site(4); digitalWrite(ledPin,LOW); delay(2500); break; // 黑一 4  
        case 0x54:while (TJC.read() >= 0);   sta=54;Serial3.write("\xff\xff\xff");  sprintf(str, "n15.val++", h);   TJC.print(str); SendEnd();  
        Chess(0,3); digitalWrite(ledPin,HIGH); delay(2500); Site(5); digitalWrite(ledPin,LOW); delay(2500); break; // 黑一 5  
        case 0x55:while (TJC.read() >= 0);   sta=55;Serial3.write("\xff\xff\xff");  sprintf(str, "n15.val++", h);   TJC.print(str); SendEnd();  
        Chess(0,3); digitalWrite(ledPin,HIGH); delay(2500); Site(6); digitalWrite(ledPin,LOW); delay(2500); break; // 黑一 6  
        case 0x56:while (TJC.read() >= 0);   sta=56;Serial3.write("\xff\xff\xff");  sprintf(str, "n15.val++", h);   TJC.print(str); SendEnd();  
        Chess(0,3); digitalWrite(ledPin,HIGH); delay(2500); Site(7); digitalWrite(ledPin,LOW); delay(2500); break; // 黑一 7  
        case 0x57:while (TJC.read() >= 0);   sta=57;Serial3.write("\xff\xff\xff");  sprintf(str, "n15.val++", h);   TJC.print(str); SendEnd();  
        Chess(0,3); digitalWrite(ledPin,HIGH); delay(2500); Site(8); digitalWrite(ledPin,LOW); delay(2500); break; // 黑一 8  
        case 0x58:while (TJC.read() >= 0);   sta=58;Serial3.write("\xff\xff\xff");  sprintf(str, "n15.val++", h);   TJC.print(str); SendEnd();  
        Chess(0,3); digitalWrite(ledPin,HIGH); delay(2500); Site(1); digitalWrite(ledPin,LOW); delay(2500); break; // 黑一 9  
        case 0x59:while (TJC.read() >= 0);   sta=57;Serial3.write("\xff\xff\xff");  sprintf(str, "n15.val++", h);   TJC.print(str); SendEnd();  
        Chess(0,3); digitalWrite(ledPin,HIGH); delay(2500); Site(9); digitalWrite(ledPin,LOW); delay(2500); break; // 黑一 10  
        
        case 0x60: while (TJC.read() >= 0);  sta=60; Serial3.write("\xff\xff\xff");   sprintf(str, "n15.val++", h);  TJC.print(str); SendEnd();  
        break;// 黑二 1   
        case 0x61: while (TJC.read() >= 0);  sta=61;Serial3.write("\xff\xff\xff");   sprintf(str, "n15.val++", h);  TJC.print(str); SendEnd();  
        Chess(0,4); digitalWrite(ledPin,HIGH); delay(2500); Site(1); digitalWrite(ledPin,LOW); delay(2500); break;// 黑二 2 
        case 0x62:while (TJC.read() >= 0);   sta=62;Serial3.write("\xff\xff\xff");  sprintf(str, "n15.val++", h);   TJC.print(str); SendEnd();  
        Chess(0,4); digitalWrite(ledPin,HIGH); delay(2500); Site(2); digitalWrite(ledPin,LOW); delay(2500); break; // 黑二 3  
        case 0x63:while (TJC.read() >= 0);   sta=63;Serial3.write("\xff\xff\xff");  sprintf(str, "n15.val++", h);   TJC.print(str); SendEnd();  
        Chess(0,4); digitalWrite(ledPin,HIGH); delay(2500); Site(3); digitalWrite(ledPin,LOW); delay(2500); break; // 黑二 4  
        case 0x64:while (TJC.read() >= 0);   sta=64;Serial3.write("\xff\xff\xff");  sprintf(str, "n15.val++", h);   TJC.print(str); SendEnd();  
        Chess(0,4); digitalWrite(ledPin,HIGH); delay(2500); Site(4); digitalWrite(ledPin,LOW); delay(2500); break; // 黑二 5  
        case 0x65:while (TJC.read() >= 0);   sta=65;Serial3.write("\xff\xff\xff");  sprintf(str, "n15.val++", h);   TJC.print(str); SendEnd();  
        Chess(0,4); digitalWrite(ledPin,HIGH); delay(2500); Site(5); digitalWrite(ledPin,LOW); delay(2500); break; // 黑二 6  
        case 0x66:while (TJC.read() >= 0);   sta=66;Serial3.write("\xff\xff\xff");  sprintf(str, "n15.val++", h);   TJC.print(str); SendEnd();  
        Chess(0,4); digitalWrite(ledPin,HIGH); delay(2500); Site(6); digitalWrite(ledPin,LOW); delay(2500); break; // 黑二 7  
        case 0x67:while (TJC.read() >= 0);   sta=67;Serial3.write("\xff\xff\xff");  sprintf(str, "n15.val++", h);   TJC.print(str); SendEnd();  
        Chess(0,4); digitalWrite(ledPin,HIGH); delay(2500); Site(7); digitalWrite(ledPin,LOW); delay(2500); break; // 黑二 8  
        case 0x68:while (TJC.read() >= 0);   sta=68;Serial3.write("\xff\xff\xff");  sprintf(str, "n15.val++", h);   TJC.print(str); SendEnd();  
        Chess(0,4); digitalWrite(ledPin,HIGH); delay(2500); Site(8); digitalWrite(ledPin,LOW); delay(2500); break; // 黑二 9  
        case 0x69:while (TJC.read() >= 0);   sta=68;Serial3.write("\xff\xff\xff");  sprintf(str, "n15.val++", h);   TJC.print(str); SendEnd();  
        Chess(0,4); digitalWrite(ledPin,HIGH); delay(2500); Site(9); digitalWrite(ledPin,LOW); delay(2500); break; // 黑二 10

        case 0x70: while (TJC.read() >= 0);  sta=70; Serial3.write("\xff\xff\xff");   sprintf(str, "n15.val++", h); TJC.print(str); SendEnd();  
        Chess(0,5); digitalWrite(ledPin,HIGH); delay(2500); Site(1); digitalWrite(ledPin,LOW); delay(2500); break;// 白一 1   
        case 0x71: while (TJC.read() >= 0);  sta=71;Serial3.write("\xff\xff\xff");   sprintf(str, "n15.val++", h);  TJC.print(str); SendEnd();  
        Chess(0,5); digitalWrite(ledPin,HIGH); delay(2500); Site(2); digitalWrite(ledPin,LOW); delay(2500); break;// 白一 2 
        case 0x72:while (TJC.read() >= 0);   sta=72;Serial3.write("\xff\xff\xff");  sprintf(str, "n15.val++", h);   TJC.print(str); SendEnd();  
        Chess(0,5); digitalWrite(ledPin,HIGH); delay(2500); Site(3); digitalWrite(ledPin,LOW); delay(2500); break; // 白一 3  
        case 0x73:while (TJC.read() >= 0);   sta=73;Serial3.write("\xff\xff\xff");  sprintf(str, "n15.val++", h);   TJC.print(str); SendEnd();  
        Chess(0,5); digitalWrite(ledPin,HIGH); delay(2500); Site(4); digitalWrite(ledPin,LOW); delay(2500); break; // 白一 4  
        case 0x74:while (TJC.read() >= 0);   sta=74;Serial3.write("\xff\xff\xff");  sprintf(str, "n15.val++", h);   TJC.print(str); SendEnd();  
        Chess(0,5); digitalWrite(ledPin,HIGH); delay(2500); Site(5); digitalWrite(ledPin,LOW); delay(2500); break; // 白一 5  
        case 0x75:while (TJC.read() >= 0);   sta=75;Serial3.write("\xff\xff\xff");  sprintf(str, "n15.val++", h);   TJC.print(str); SendEnd();  
        Chess(0,5); digitalWrite(ledPin,HIGH); delay(2500); Site(6); digitalWrite(ledPin,LOW); delay(2500); break; // 白一 6  
        case 0x76:while (TJC.read() >= 0);   sta=76;Serial3.write("\xff\xff\xff");  sprintf(str, "n15.val++", h);   TJC.print(str); SendEnd();  
        Chess(0,5); digitalWrite(ledPin,HIGH); delay(2500); Site(7); digitalWrite(ledPin,LOW); delay(2500); break; // 白一 7  
        case 0x77:while (TJC.read() >= 0);   sta=77;Serial3.write("\xff\xff\xff");  sprintf(str, "n15.val++", h);   TJC.print(str); SendEnd();  
        Chess(0,5); digitalWrite(ledPin,HIGH); delay(2500); Site(8); digitalWrite(ledPin,LOW); delay(2500); break; // 白一 8  
        case 0x78:while (TJC.read() >= 0);   sta=78;Serial3.write("\xff\xff\xff");  sprintf(str, "n15.val++", h);   TJC.print(str); SendEnd();  
        Chess(0,5); digitalWrite(ledPin,HIGH); delay(2500); Site(9); digitalWrite(ledPin,LOW); delay(2500); break; // 白一 9  
        case 0x79:while (TJC.read() >= 0);   sta=79;Serial3.write("\xff\xff\xff");  sprintf(str, "n15.val++", h);   TJC.print(str); SendEnd();  
        Chess(0,5); digitalWrite(ledPin,HIGH); delay(2500); Site(9); digitalWrite(ledPin,LOW); delay(2500); break; // 白一 10

        case 0x80: while (TJC.read() >= 0);  sta=80; Serial3.write("\xff\xff\xff");   sprintf(str, "n15.val++", h);   TJC.print(str); SendEnd();  break;// 白二 1   
        case 0x81: while (TJC.read() >= 0);  sta=81;Serial3.write("\xff\xff\xff");   sprintf(str, "n15.val++", h);   TJC.print(str); SendEnd();  break;// 白二 2 
        case 0x82:while (TJC.read() >= 0);   sta=82;Serial3.write("\xff\xff\xff");  sprintf(str, "n15.val++", h);   TJC.print(str); SendEnd();  break; // 白二 3  
        case 0x83:while (TJC.read() >= 0);   sta=83;Serial3.write("\xff\xff\xff");  sprintf(str, "n15.val++", h);   TJC.print(str); SendEnd();  break; // 白二 4  
        case 0x84:while (TJC.read() >= 0);   sta=84;Serial3.write("\xff\xff\xff");  sprintf(str, "n15.val++", h);   TJC.print(str); SendEnd();  break; // 白二 5  
        case 0x85:while (TJC.read() >= 0);   sta=85;Serial3.write("\xff\xff\xff");  sprintf(str, "n15.val++", h);   TJC.print(str); SendEnd();  break; // 白二 6  
        case 0x86:while (TJC.read() >= 0);   sta=86;Serial3.write("\xff\xff\xff");  sprintf(str, "n15.val++", h);   TJC.print(str); SendEnd();  break; // 白二 7  
        case 0x87:while (TJC.read() >= 0);   sta=87;Serial3.write("\xff\xff\xff");  sprintf(str, "n15.val++", h);   TJC.print(str); SendEnd();  break; // 白二 8  
        case 0x88:while (TJC.read() >= 0);   sta=88;Serial3.write("\xff\xff\xff");  sprintf(str, "n15.val++", h);   TJC.print(str); SendEnd();  break; // 白二 9  
        case 0x89:while (TJC.read() >= 0);   sta=88;Serial3.write("\xff\xff\xff");  sprintf(str, "n15.val++", h);   TJC.print(str); SendEnd();  break; // 白二 10

        case 0x90: while (TJC.read() >= 0);  sta=90; Serial3.write("\xff\xff\xff");   sprintf(str, "n15.val++", h);  TJC.print(str); SendEnd();  break;// 黑一 1   
        case 0x91: while (TJC.read() >= 0);  sta=91;Serial3.write("\xff\xff\xff");   sprintf(str, "n15.val++", h);   TJC.print(str); SendEnd();  break;// 黑一 2 
        case 0x92:while (TJC.read() >= 0);   sta=92;Serial3.write("\xff\xff\xff");  sprintf(str, "n15.val++", h);   TJC.print(str); SendEnd();  break; // 黑一 3  
        case 0x93:while (TJC.read() >= 0);   sta=93;Serial3.write("\xff\xff\xff");  sprintf(str, "n15.val++", h);   TJC.print(str); SendEnd();  break; // 黑一 4  
        case 0x94:while (TJC.read() >= 0);   sta=94;Serial3.write("\xff\xff\xff");  sprintf(str, "n15.val++", h);   TJC.print(str); SendEnd();  break; // 黑一 5  
        case 0x95:while (TJC.read() >= 0);   sta=95;Serial3.write("\xff\xff\xff");  sprintf(str, "n15.val++", h);   TJC.print(str); SendEnd();  break; // 黑一 6  
        case 0x96:while (TJC.read() >= 0);   sta=96;Serial3.write("\xff\xff\xff");  sprintf(str, "n15.val++", h);   TJC.print(str); SendEnd();  break; // 黑一 7  
        case 0x97:while (TJC.read() >= 0);   sta=97;Serial3.write("\xff\xff\xff");  sprintf(str, "n15.val++", h);   TJC.print(str); SendEnd();  break; // 黑一 8  
        case 0x98:while (TJC.read() >= 0);   sta=98;Serial3.write("\xff\xff\xff");  sprintf(str, "n15.val++", h);   TJC.print(str); SendEnd();  break; // 黑一 9  
        case 0x99:while (TJC.read() >= 0);   sta=98;Serial3.write("\xff\xff\xff");  sprintf(str, "n15.val++", h);   TJC.print(str); SendEnd();  break; // 黑一 10
       
        case 0x100: while (TJC.read() >= 0);  sta=100; Serial3.write("\xff\xff\xff");   sprintf(str, "n15.val++", h);  TJC.print(str); SendEnd();  break;// 黑二 1   
        case 0x101: while (TJC.read() >= 0);  sta=101;Serial3.write("\xff\xff\xff");   sprintf(str, "n15.val++", h);   TJC.print(str); SendEnd();  break;// 黑二 2 
        case 0x102:while (TJC.read() >= 0);   sta=102;Serial3.write("\xff\xff\xff");  sprintf(str, "n15.val++", h);   TJC.print(str); SendEnd();  break; // 黑二 3  
        case 0x103:while (TJC.read() >= 0);   sta=103;Serial3.write("\xff\xff\xff");  sprintf(str, "n15.val++", h);   TJC.print(str); SendEnd();  break; // 黑二 4  
        case 0x104:while (TJC.read() >= 0);   sta=104;Serial3.write("\xff\xff\xff");  sprintf(str, "n15.val++", h);   TJC.print(str); SendEnd();  break; // 黑二 5  
        case 0x105:while (TJC.read() >= 0);   sta=105;Serial3.write("\xff\xff\xff");  sprintf(str, "n15.val++", h);   TJC.print(str); SendEnd();  break; // 黑二 6  
        case 0x106:while (TJC.read() >= 0);   sta=106;Serial3.write("\xff\xff\xff");  sprintf(str, "n15.val++", h);   TJC.print(str); SendEnd();  break; // 黑二 7  
        case 0x107:while (TJC.read() >= 0);   sta=107;Serial3.write("\xff\xff\xff");  sprintf(str, "n15.val++", h);   TJC.print(str); SendEnd();  break; // 黑二 8  
        case 0x108:while (TJC.read() >= 0);   sta=108;Serial3.write("\xff\xff\xff");  sprintf(str, "n15.val++", h);   TJC.print(str); SendEnd();  break; // 黑二 9  
        case 0x109:while (TJC.read() >= 0);   sta=109;Serial3.write("\xff\xff\xff");  sprintf(str, "n15.val++", h);   TJC.print(str); SendEnd();  break; // 黑二 10

        case 0x110: while (TJC.read() >= 0);  sta=110; Serial3.write("\xff\xff\xff");   sprintf(str, "n15.val++", h);  TJC.print(str); SendEnd();  break;// 白一 1   
        case 0x111: while (TJC.read() >= 0);  sta=111;Serial3.write("\xff\xff\xff");   sprintf(str, "n15.val++", h);   TJC.print(str); SendEnd();  break;// 白一 2 
        case 0x112:while (TJC.read() >= 0);   sta=112;Serial3.write("\xff\xff\xff");  sprintf(str, "n15.val++", h);   TJC.print(str); SendEnd();  break; // 白一 3  
        case 0x113:while (TJC.read() >= 0);   sta=113;Serial3.write("\xff\xff\xff");  sprintf(str, "n15.val++", h);   TJC.print(str); SendEnd();  break; // 白一 4  
        case 0x114:while (TJC.read() >= 0);   sta=114;Serial3.write("\xff\xff\xff");  sprintf(str, "n15.val++", h);   TJC.print(str); SendEnd();  break; // 白一 5  
        case 0x115:while (TJC.read() >= 0);   sta=115;Serial3.write("\xff\xff\xff");  sprintf(str, "n15.val++", h);   TJC.print(str); SendEnd();  break; // 白一 6  
        case 0x116:while (TJC.read() >= 0);   sta=116;Serial3.write("\xff\xff\xff");  sprintf(str, "n15.val++", h);   TJC.print(str); SendEnd();  break; // 白一 7  
        case 0x117:while (TJC.read() >= 0);   sta=117;Serial3.write("\xff\xff\xff");  sprintf(str, "n15.val++", h);   TJC.print(str); SendEnd();  break; // 白一 8  
        case 0x118:while (TJC.read() >= 0);   sta=118;Serial3.write("\xff\xff\xff");  sprintf(str, "n15.val++", h);   TJC.print(str); SendEnd();  break; // 白一 9  
        case 0x119:while (TJC.read() >= 0);   sta=119;Serial3.write("\xff\xff\xff");  sprintf(str, "n15.val++", h);   TJC.print(str); SendEnd();  break; // 白一 10

        case 0x120: while (TJC.read() >= 0);  sta=120; Serial3.write("\xff\xff\xff");   sprintf(str, "n15.val++", h);   TJC.print(str); SendEnd();  break;// 白二 1   
        case 0x121: while (TJC.read() >= 0);  sta=121;Serial3.write("\xff\xff\xff");   sprintf(str, "n15.val++", h);   TJC.print(str); SendEnd();  break;// 白二 2 
        case 0x122:while (TJC.read() >= 0);   sta=122;Serial3.write("\xff\xff\xff");  sprintf(str, "n15.val++", h);   TJC.print(str); SendEnd();  break; // 白二 3  
        case 0x123:while (TJC.read() >= 0);   sta=123;Serial3.write("\xff\xff\xff");  sprintf(str, "n15.val++", h);   TJC.print(str); SendEnd();  break; // 白二 4  
        case 0x124:while (TJC.read() >= 0);   sta=124;Serial3.write("\xff\xff\xff");  sprintf(str, "n15.val++", h);   TJC.print(str); SendEnd();  break; // 白二 5  
        case 0x125:while (TJC.read() >= 0);   sta=125;Serial3.write("\xff\xff\xff");  sprintf(str, "n15.val++", h);   TJC.print(str); SendEnd();  break; // 白二 6  
        case 0x126:while (TJC.read() >= 0);   sta=126;Serial3.write("\xff\xff\xff");  sprintf(str, "n15.val++", h);   TJC.print(str); SendEnd();  break; // 白二 7  
        case 0x127:while (TJC.read() >= 0);   sta=127;Serial3.write("\xff\xff\xff");  sprintf(str, "n15.val++", h);   TJC.print(str); SendEnd();  break; // 白二 8  
        case 0x128:while (TJC.read() >= 0);   sta=128;Serial3.write("\xff\xff\xff");  sprintf(str, "n15.val++", h);   TJC.print(str); SendEnd();  break; // 白二 9  
        case 0x129:while (TJC.read() >= 0);   sta=129;Serial3.write("\xff\xff\xff");  sprintf(str, "n15.val++", h);   TJC.print(str); SendEnd();  break; // 白二 10

        case 0x130: while (TJC.read() >= 0);  sta=130; Serial3.write("\xff\xff\xff");   sprintf(str, "n15.val++", h);  TJC.print(str); SendEnd();  break;// 黑一 1   
        case 0x131: while (TJC.read() >= 0);  sta=131;Serial3.write("\xff\xff\xff");   sprintf(str, "n15.val++", h);   TJC.print(str); SendEnd();  break;// 黑一 2 
        case 0x132:while (TJC.read() >= 0);   sta=132;Serial3.write("\xff\xff\xff");  sprintf(str, "n15.val++", h);   TJC.print(str); SendEnd();  break; // 黑一 3  
        case 0x133:while (TJC.read() >= 0);   sta=133;Serial3.write("\xff\xff\xff");  sprintf(str, "n15.val++", h);   TJC.print(str); SendEnd();  break; // 黑一 4  
        case 0x134:while (TJC.read() >= 0);   sta=134;Serial3.write("\xff\xff\xff");  sprintf(str, "n15.val++", h);   TJC.print(str); SendEnd();  break; // 黑一 5  
        case 0x135:while (TJC.read() >= 0);   sta=135;Serial3.write("\xff\xff\xff");  sprintf(str, "n15.val++", h);   TJC.print(str); SendEnd();  break; // 黑一 6  
        case 0x136:while (TJC.read() >= 0);   sta=136;Serial3.write("\xff\xff\xff");  sprintf(str, "n15.val++", h);   TJC.print(str); SendEnd();  break; // 黑一 7  
        case 0x137:while (TJC.read() >= 0);   sta=137;Serial3.write("\xff\xff\xff");  sprintf(str, "n15.val++", h);   TJC.print(str); SendEnd();  break; // 黑一 8  
        case 0x138:while (TJC.read() >= 0);   sta=138;Serial3.write("\xff\xff\xff");  sprintf(str, "n15.val++", h);   TJC.print(str); SendEnd();  break; // 黑一 9  
        case 0x139:while (TJC.read() >= 0);   sta=139;Serial3.write("\xff\xff\xff");  sprintf(str, "n15.val++", h);   TJC.print(str); SendEnd();  break; // 黑一 10

        case 0x140: while (TJC.read() >= 0);  sta=140; Serial3.write("\xff\xff\xff");   sprintf(str, "n15.val++", h);  TJC.print(str); SendEnd();  break;// 黑二 1   
        case 0x141: while (TJC.read() >= 0);  sta=141;Serial3.write("\xff\xff\xff");   sprintf(str, "n15.val++", h);   TJC.print(str); SendEnd();  break;// 黑二 2 
        case 0x142:while (TJC.read() >= 0);   sta=142;Serial3.write("\xff\xff\xff");  sprintf(str, "n15.val++", h);   TJC.print(str); SendEnd();  break; // 黑二 3  
        case 0x143:while (TJC.read() >= 0);   sta=143;Serial3.write("\xff\xff\xff");  sprintf(str, "n15.val++", h);   TJC.print(str); SendEnd();  break; // 黑二 4  
        case 0x144:while (TJC.read() >= 0);   sta=144;Serial3.write("\xff\xff\xff");  sprintf(str, "n15.val++", h);   TJC.print(str); SendEnd();  break; // 黑二 5  
        case 0x145:while (TJC.read() >= 0);   sta=145;Serial3.write("\xff\xff\xff");  sprintf(str, "n15.val++", h);   TJC.print(str); SendEnd();  break; // 黑二 6  
        case 0x146:while (TJC.read() >= 0);   sta=146;Serial3.write("\xff\xff\xff");  sprintf(str, "n15.val++", h);   TJC.print(str); SendEnd();  break; // 黑二 7  
        case 0x147:while (TJC.read() >= 0);   sta=147;Serial3.write("\xff\xff\xff");  sprintf(str, "n15.val++", h);   TJC.print(str); SendEnd();  break; // 黑二 8  
        case 0x148:while (TJC.read() >= 0);   sta=148;Serial3.write("\xff\xff\xff");  sprintf(str, "n15.val++", h);   TJC.print(str); SendEnd();  break; // 黑二 9  
        case 0x149:while (TJC.read() >= 0);   sta=149;Serial3.write("\xff\xff\xff");  sprintf(str, "n15.val++", h);   TJC.print(str); SendEnd();  break; // 黑二 10

        case 0x150: while (TJC.read() >= 0);  sta=150; Serial3.write("\xff\xff\xff");   sprintf(str, "n15.val++", h);  TJC.print(str); SendEnd();  break;// 白一 1   
        case 0x151: while (TJC.read() >= 0);  sta=151;Serial3.write("\xff\xff\xff");   sprintf(str, "n15.val++", h);   TJC.print(str); SendEnd();  break;// 白一 2 
        case 0x152:while (TJC.read() >= 0);   sta=152;Serial3.write("\xff\xff\xff");  sprintf(str, "n15.val++", h);   TJC.print(str); SendEnd();  break; // 白一 3  
        case 0x153:while (TJC.read() >= 0);   sta=153;Serial3.write("\xff\xff\xff");  sprintf(str, "n15.val++", h);   TJC.print(str); SendEnd();  break; // 白一 4  
        case 0x154:while (TJC.read() >= 0);   sta=154;Serial3.write("\xff\xff\xff");  sprintf(str, "n15.val++", h);   TJC.print(str); SendEnd();  break; // 白一 5  
        case 0x155:while (TJC.read() >= 0);   sta=155;Serial3.write("\xff\xff\xff");  sprintf(str, "n15.val++", h);   TJC.print(str); SendEnd();  break; // 白一 6  
        case 0x156:while (TJC.read() >= 0);   sta=156;Serial3.write("\xff\xff\xff");  sprintf(str, "n15.val++", h);   TJC.print(str); SendEnd();  break; // 白一 7  
        case 0x157:while (TJC.read() >= 0);   sta=157;Serial3.write("\xff\xff\xff");  sprintf(str, "n15.val++", h);   TJC.print(str); SendEnd();  break; // 白一 8  
        case 0x158:while (TJC.read() >= 0);   sta=158;Serial3.write("\xff\xff\xff");  sprintf(str, "n15.val++", h);   TJC.print(str); SendEnd();  break; // 白一 9  
        case 0x159:while (TJC.read() >= 0);   sta=159;Serial3.write("\xff\xff\xff");  sprintf(str, "n15.val++", h);   TJC.print(str); SendEnd();  break; // 白一 10

        case 0x160: while (TJC.read() >= 0);  sta=160; Serial3.write("\xff\xff\xff");   sprintf(str, "n15.val++", h);   TJC.print(str); SendEnd();  break;// 白二 1   
        case 0x161: while (TJC.read() >= 0);  sta=161;Serial3.write("\xff\xff\xff");   sprintf(str, "n15.val++", h);   TJC.print(str); SendEnd();  break;// 白二 2 
        case 0x162:while (TJC.read() >= 0);   sta=162;Serial3.write("\xff\xff\xff");  sprintf(str, "n15.val++", h);   TJC.print(str); SendEnd();  break; // 白二 3  
        case 0x163:while (TJC.read() >= 0);   sta=163;Serial3.write("\xff\xff\xff");  sprintf(str, "n15.val++", h);   TJC.print(str); SendEnd();  break; // 白二 4  
        case 0x164:while (TJC.read() >= 0);   sta=164;Serial3.write("\xff\xff\xff");  sprintf(str, "n15.val++", h);   TJC.print(str); SendEnd();  break; // 白二 5  
        case 0x165:while (TJC.read() >= 0);   sta=165;Serial3.write("\xff\xff\xff");  sprintf(str, "n15.val++", h);   TJC.print(str); SendEnd();  break; // 白二 6  
        case 0x166:while (TJC.read() >= 0);   sta=166;Serial3.write("\xff\xff\xff");  sprintf(str, "n15.val++", h);   TJC.print(str); SendEnd();  break; // 白二 7  
        case 0x167:while (TJC.read() >= 0);   sta=167;Serial3.write("\xff\xff\xff");  sprintf(str, "n15.val++", h);   TJC.print(str); SendEnd();  break; // 白二 8  
        case 0x168:while (TJC.read() >= 0);   sta=168;Serial3.write("\xff\xff\xff");  sprintf(str, "n15.val++", h);   TJC.print(str); SendEnd();  break; // 白二 9  
        case 0x169:while (TJC.read() >= 0);   sta=169;Serial3.write("\xff\xff\xff");  sprintf(str, "n15.val++", h);   TJC.print(str); SendEnd();  break; // 白二 10

        case 0x170: while (TJC.read() >= 0);  sta=170; Serial3.write("\xff\xff\xff");   sprintf(str, "n15.val++", h);  TJC.print(str); SendEnd();  break;// 黑一 1   
        case 0x171: while (TJC.read() >= 0);  sta=171;Serial3.write("\xff\xff\xff");   sprintf(str, "n15.val++", h);   TJC.print(str); SendEnd();  break;// 黑一 2 
        case 0x172:while (TJC.read() >= 0);   sta=172;Serial3.write("\xff\xff\xff");  sprintf(str, "n15.val++", h);   TJC.print(str); SendEnd();  break; // 黑一 3  
        case 0x173:while (TJC.read() >= 0);   sta=173;Serial3.write("\xff\xff\xff");  sprintf(str, "n15.val++", h);   TJC.print(str); SendEnd();  break; // 黑一 4  
        case 0x174:while (TJC.read() >= 0);   sta=174;Serial3.write("\xff\xff\xff");  sprintf(str, "n15.val++", h);   TJC.print(str); SendEnd();  break; // 黑一 5  
        case 0x175:while (TJC.read() >= 0);   sta=175;Serial3.write("\xff\xff\xff");  sprintf(str, "n15.val++", h);   TJC.print(str); SendEnd();  break; // 黑一 6  
        case 0x176:while (TJC.read() >= 0);   sta=176;Serial3.write("\xff\xff\xff");  sprintf(str, "n15.val++", h);   TJC.print(str); SendEnd();  break; // 黑一 7  
        case 0x177:while (TJC.read() >= 0);   sta=177;Serial3.write("\xff\xff\xff");  sprintf(str, "n15.val++", h);   TJC.print(str); SendEnd();  break; // 黑一 8  
        case 0x178:while (TJC.read() >= 0);   sta=178;Serial3.write("\xff\xff\xff");  sprintf(str, "n15.val++", h);   TJC.print(str); SendEnd();  break; // 黑一 9  
        case 0x179:while (TJC.read() >= 0);   sta=179;Serial3.write("\xff\xff\xff");  sprintf(str, "n15.val++", h);   TJC.print(str); SendEnd();  break; // 黑一 10

        case 0x180: while (TJC.read() >= 0);  sta=180; Serial3.write("\xff\xff\xff");   sprintf(str, "n15.val++", h);  TJC.print(str); SendEnd();  break;// 黑二 1   
        case 0x181: while (TJC.read() >= 0);  sta=181;Serial3.write("\xff\xff\xff");   sprintf(str, "n15.val++", h);   TJC.print(str); SendEnd();  break;// 黑二 2 
        case 0x182:while (TJC.read() >= 0);   sta=182;Serial3.write("\xff\xff\xff");  sprintf(str, "n15.val++", h);   TJC.print(str); SendEnd();  break; // 黑二 3  
        case 0x183:while (TJC.read() >= 0);   sta=183;Serial3.write("\xff\xff\xff");  sprintf(str, "n15.val++", h);   TJC.print(str); SendEnd();  break; // 黑二 4  
        case 0x184:while (TJC.read() >= 0);   sta=184;Serial3.write("\xff\xff\xff");  sprintf(str, "n15.val++", h);   TJC.print(str); SendEnd();  break; // 黑二 5  
        case 0x185:while (TJC.read() >= 0);   sta=185;Serial3.write("\xff\xff\xff");  sprintf(str, "n15.val++", h);   TJC.print(str); SendEnd();  break; // 黑二 6  
        case 0x186:while (TJC.read() >= 0);   sta=186;Serial3.write("\xff\xff\xff");  sprintf(str, "n15.val++", h);   TJC.print(str); SendEnd();  break; // 黑二 7  
        case 0x187:while (TJC.read() >= 0);   sta=187;Serial3.write("\xff\xff\xff");  sprintf(str, "n15.val++", h);   TJC.print(str); SendEnd();  break; // 黑二 8  
        case 0x188:while (TJC.read() >= 0);   sta=188;Serial3.write("\xff\xff\xff");  sprintf(str, "n15.val++", h);   TJC.print(str); SendEnd();  break; // 黑二 9  
        case 0x189:while (TJC.read() >= 0);   sta=189;Serial3.write("\xff\xff\xff");  sprintf(str, "n15.val++", h);   TJC.print(str); SendEnd();  break; // 黑二 10

        case 0x190: while (TJC.read() >= 0);  sta=190; Serial3.write("\xff\xff\xff");   sprintf(str, "n15.val++", h);  TJC.print(str); SendEnd();  break;// 白一 1   
        case 0x191: while (TJC.read() >= 0);  sta=191;Serial3.write("\xff\xff\xff");   sprintf(str, "n15.val++", h);   TJC.print(str); SendEnd();  break;// 白一 2 
        case 0x192:while (TJC.read() >= 0);   sta=192;Serial3.write("\xff\xff\xff");  sprintf(str, "n15.val++", h);   TJC.print(str); SendEnd();  break; // 白一 3  
        case 0x193:while (TJC.read() >= 0);   sta=193;Serial3.write("\xff\xff\xff");  sprintf(str, "n15.val++", h);   TJC.print(str); SendEnd();  break; // 白一 4  
        case 0x194:while (TJC.read() >= 0);   sta=194;Serial3.write("\xff\xff\xff");  sprintf(str, "n15.val++", h);   TJC.print(str); SendEnd();  break; // 白一 5  
        case 0x195:while (TJC.read() >= 0);   sta=195;Serial3.write("\xff\xff\xff");  sprintf(str, "n15.val++", h);   TJC.print(str); SendEnd();  break; // 白一 6  
        case 0x196:while (TJC.read() >= 0);   sta=196;Serial3.write("\xff\xff\xff");  sprintf(str, "n15.val++", h);   TJC.print(str); SendEnd();  break; // 白一 7  
        case 0x197:while (TJC.read() >= 0);   sta=197;Serial3.write("\xff\xff\xff");  sprintf(str, "n15.val++", h);   TJC.print(str); SendEnd();  break; // 白一 8  
        case 0x198:while (TJC.read() >= 0);   sta=198;Serial3.write("\xff\xff\xff");  sprintf(str, "n15.val++", h);   TJC.print(str); SendEnd();  break; // 白一 9  
        case 0x199:while (TJC.read() >= 0);   sta=199;Serial3.write("\xff\xff\xff");  sprintf(str, "n15.val++", h);   TJC.print(str); SendEnd();  break; // 白一 10

        case 0x200: while (TJC.read() >= 0);  sta=200; Serial3.write("\xff\xff\xff");   sprintf(str, "n15.val++", h);   TJC.print(str); SendEnd();  break;// 白二 1   
        case 0x201: while (TJC.read() >= 0);  sta=201;Serial3.write("\xff\xff\xff");   sprintf(str, "n15.val++", h);   TJC.print(str); SendEnd();  break;// 白二 2 
        case 0x202:while (TJC.read() >= 0);   sta=202;Serial3.write("\xff\xff\xff");  sprintf(str, "n15.val++", h);   TJC.print(str); SendEnd();  break; // 白二 3  
        case 0x203:while (TJC.read() >= 0);   sta=203;Serial3.write("\xff\xff\xff");  sprintf(str, "n15.val++", h);   TJC.print(str); SendEnd();  break; // 白二 4  
        case 0x204:while (TJC.read() >= 0);   sta=204;Serial3.write("\xff\xff\xff");  sprintf(str, "n15.val++", h);   TJC.print(str); SendEnd();  break; // 白二 5  
        case 0x205:while (TJC.read() >= 0);   sta=205;Serial3.write("\xff\xff\xff");  sprintf(str, "n15.val++", h);   TJC.print(str); SendEnd();  break; // 白二 6  
        case 0x206:while (TJC.read() >= 0);   sta=206;Serial3.write("\xff\xff\xff");  sprintf(str, "n15.val++", h);   TJC.print(str); SendEnd();  break; // 白二 7  
        case 0x207:while (TJC.read() >= 0);   sta=207;Serial3.write("\xff\xff\xff");  sprintf(str, "n15.val++", h);   TJC.print(str); SendEnd();  break; // 白二 8  
        case 0x208:while (TJC.read() >= 0);   sta=208;Serial3.write("\xff\xff\xff");  sprintf(str, "n15.val++", h);   TJC.print(str); SendEnd();  break; // 白二 9  
        case 0x209:while (TJC.read() >= 0);   sta=209;Serial3.write("\xff\xff\xff");  sprintf(str, "n15.val++", h);   TJC.print(str); SendEnd();  break; // 白二 10


        default:  
              TJC.read();
            break;  
    }   
}  
  
// 假设SendEnd是一个已经定义的函数，用于发送结束信号  
  }
void loop() {
    Ini();
    chuankou();
   //digitalWrite(ledPin,HIGH);
  //  if(d==1)
  //  {
  //   d=0;
    // Task1();
  //  }
   
}