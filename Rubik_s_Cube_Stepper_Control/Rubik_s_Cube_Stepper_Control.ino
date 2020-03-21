#include <Rubiks_Cube_Algo.h>
rcalgo rcalgo;

int S1 = 7;  // 6 Stepper Motors
int S2 = 6;
int S3 = 5;
int S4 = 4;
int S5 = 3;
int S6 = 2;

int dir = 8; // Direction pin for all steppers at one pin=8
int i = 0, j = 0,k = 0;
int tot_moves = 0;
char input[100],out[300];

/*
  Stepper Motor Configurations -
  S1 - R,Ri
  S2 - F,Fi
  S3 - U,Ui
  S4 - L,Li
  S5 - B,Bi
  S6 - D,Di
*/

void setup() {
  // put your setup code here, to run once:
  pinMode(S1, OUTPUT);
  pinMode(S2, OUTPUT);
  pinMode(S3, OUTPUT);
  pinMode(S4, OUTPUT);
  pinMode(S5, OUTPUT);
  pinMode(S6, OUTPUT);
  pinMode(dir, OUTPUT);

  pinMode(A0, OUTPUT);
  pinMode(A1, OUTPUT);
  pinMode(A2, OUTPUT);
  pinMode(A3, OUTPUT);
  pinMode(A4, OUTPUT);
  pinMode(A5, OUTPUT);

  digitalWrite(A0, 1);
  digitalWrite(A1, 1);
  digitalWrite(A2, 1);
  digitalWrite(A3, 1);
  digitalWrite(A4, 1);
  digitalWrite(A5, 1);
  digitalWrite(dir, 0);

  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  if (Serial.available())
  {
    input[j] = Serial.read();
    Serial.println(input[j]);
    switch (input[j])
    {
      case 'R' : move_R();  break;
      case 'r' : move_r();  break;
      case 'L' : move_L();  break;
      case 'l' : move_l();  break;
      case 'B' : move_B();  break;
      case 'b' : move_b();  break;
      case 'F' : move_F();  break;
      case 'f' : move_f();  break;
      case 'U' : move_U();  break;
      case 'u' : move_u();  break;
      case 'D' : move_D();  break;
      case 'd' : move_d();  break;
      case 's' : solve();
                 while(j+1)
                 {
                   input[j]='\0';
                   j--;
                 }
                 break;
      case 'S' : solve();
                 while(j+1)
                 {
                   input[j]='\0';
                   j--;
                 }
                 /*
                 for(k=0;k<tot_moves;k++)
                 {
                   Serial.print(out[k]);
                   Serial.println(k);
                 }
                 */
                 break;
      default : j--; break;
    }
    //Serial.println(input[j]);
    j++;
    delay(50);
  }
}

void move_R()
{
  i = 0;
  digitalWrite(A0, 0);
  digitalWrite(dir, 1);
  //delayMicroseconds(1000);
  while (i < 50)
  {
    digitalWrite(S1, 1);
    delayMicroseconds(1600);
    digitalWrite(S1, 0);
    i++;
  }
  //delayMicroseconds(1000);
  digitalWrite(dir, 0);
  digitalWrite(A0, 1);
}

void move_r()
{
  i = 0;
  digitalWrite(A0, 0);
  digitalWrite(dir, 0);
  //delayMicroseconds(1000);
  while (i < 50)
  {
    digitalWrite(S1, 1);
    delayMicroseconds(1600);
    digitalWrite(S1, 0);
    i++;
  }
  //delayMicroseconds(1000);
  digitalWrite(dir, 0);
  digitalWrite(A0, 1);
}

void move_F()
{
  i = 0;
  digitalWrite(A1, 0);
  digitalWrite(dir, 1);
  //delayMicroseconds(1000);
  while (i < 50)
  {
    digitalWrite(S2, 1);
    delayMicroseconds(1600);
    digitalWrite(S2, 0);
    i++;
  }
  //delayMicroseconds(1000);
  digitalWrite(dir, 0);
  digitalWrite(A1, 1);
}

void move_f()
{
  int i = 0;
  digitalWrite(A1, 0);
  digitalWrite(dir, 0);
  //delayMicroseconds(1000);
  while (i < 50)
  {
    digitalWrite(S2, 1);
    delayMicroseconds(1600);
    digitalWrite(S2, 0);
    i++;
  }
  //delayMicroseconds(1000);
  digitalWrite(dir, 0);
  digitalWrite(A1, 1);
}

void move_U()
{
  int i = 0;
  digitalWrite(A2, 0);
  digitalWrite(dir, 1);
  //delayMicroseconds(1000);
  while (i < 50)
  {
    digitalWrite(S3, 1);
    delayMicroseconds(1600);
    digitalWrite(S3, 0);
    i++;
  }
  //delayMicroseconds(1000);
  digitalWrite(dir, 0);
  digitalWrite(A2, 1);
}

void move_u()
{
  int i = 0;
  digitalWrite(A2, 0);
  digitalWrite(dir, 0);
  //delayMicroseconds(100);
  while (i < 50)
  {
    digitalWrite(S3, 1);
    delayMicroseconds(1600);
    digitalWrite(S3, 0);
    i++;
  }
  //delayMicroseconds(1000);
  digitalWrite(dir, 0);
  digitalWrite(A2, 1);
}

void move_L()
{
  int i = 0;
  digitalWrite(A3, 0);
  digitalWrite(dir, 1);
  //delayMicroseconds(1000);
  while (i < 50)
  {
    digitalWrite(S4, 1);
    delayMicroseconds(1600);
    digitalWrite(S4, 0);
    i++;
  }
  //delayMicroseconds(1000);
  digitalWrite(dir, 0);
  digitalWrite(A3, 1);
}

void move_l()
{
  int i = 0;
  digitalWrite(A3, 0);
  digitalWrite(dir, 0);
  //delayMicroseconds(100);
  while (i < 50)
  {
    digitalWrite(S4, 1);
    delayMicroseconds(1600);
    digitalWrite(S4, 0);
    i++;
  }
  //delayMicroseconds(1000);
  digitalWrite(dir, 0);
  digitalWrite(A3, 1);
}

void move_B()
{
  int i = 0;
  digitalWrite(A4, 0);
  digitalWrite(dir, 1);
  //delayMicroseconds(1000);
  while (i < 50)
  {
    digitalWrite(S5, 1);
    delayMicroseconds(1600);
    digitalWrite(S5, 0);
    i++;
  }
  //delayMicroseconds(1000);
  digitalWrite(dir, 0);
  digitalWrite(A4, 1);
}

void move_b()
{
  int i = 0;
  digitalWrite(A4, 0);
  digitalWrite(dir, 0);
  //delayMicroseconds(1000);
  while (i < 50)
  {
    digitalWrite(S5, 1);
    delayMicroseconds(1600);
    digitalWrite(S5, 0);
    i++;
  }
  //delayMicroseconds(1000);
  digitalWrite(dir, 0);
  digitalWrite(A4, 1);
}

void move_D()
{
  int i = 0;
  digitalWrite(A5, 0);
  digitalWrite(dir, 1);
  //delayMicroseconds(1000);
  while (i < 50)
  {
    digitalWrite(S6, 1);
    delayMicroseconds(1600);
    digitalWrite(S6, 0);
    i++;
  }
  //delayMicroseconds(1000);
  digitalWrite(dir, 0);
  digitalWrite(A5, 1);
}

void move_d()
{
  int i = 0;
  digitalWrite(A5, 0);
  digitalWrite(dir, 0);
  //delayMicroseconds(1000);
  while (i < 50)
  {
    digitalWrite(S6, 1);
    delayMicroseconds(1600);
    digitalWrite(S6, 0);
    i++;
  }
  //delayMicroseconds(1000);
  digitalWrite(dir, 0);
  digitalWrite(A5, 1);
}

void solve()
{
  int i = 0;
  tot_moves = rcalgo.solve(j,input,out);
  Serial.println(out);
  Serial.println(tot_moves);
  for(i=0;i<tot_moves;i++)
  {
    switch (out[i])
    {
      case 'R' : move_R();  break;
      case 'r' : move_r();  break;
      case 'L' : move_L();  break;
      case 'l' : move_l();  break;
      case 'B' : move_B();  break;
      case 'b' : move_b();  break;
      case 'F' : move_F();  break;
      case 'f' : move_f();  break;
      case 'U' : move_U();  break;
      case 'u' : move_u();  break;
      case 'D' : move_D();  break;
      case 'd' : move_d();  break;
    }
    delay(50);
  }
}
