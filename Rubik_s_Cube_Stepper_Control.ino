int S1 = 2;  // 6 Stepper Motors
int S2 = 3;
int S3 = 4;
int S4 = 5;
int S5 = 6;
int S6 = 7;

int dir = 12; // Direction pin for all steppers at one pin=12
int i = 0, j = 0;
char input[150];

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
  
  pinMode(A0,OUTPUT);
  pinMode(A1,OUTPUT);
  pinMode(A2,OUTPUT);
  pinMode(A3,OUTPUT);
  pinMode(A4,OUTPUT);
  pinMode(A5,OUTPUT);

  digitalWrite(A0,1);
  digitalWrite(A1,1);
  digitalWrite(A2,1);
  digitalWrite(A3,1);
  digitalWrite(A4,1);
  digitalWrite(A5,1);
  
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  if (Serial.available())
  {
    input[j] = Serial.read();
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
      default : break;
    }
    //Serial.println(input[j]);
    j++;
    delay(500);
  }
}

void move_R()
{
  i = 0;
  digitalWrite(A0,0);
  digitalWrite(dir, 0);
  while (i < 50)
  {
    digitalWrite(S1, 1);
    delay(2);
    digitalWrite(S1, 0);
    i++;
  }
  digitalWrite(dir,0);
  digitalWrite(A0,1);
}

void move_r()
{
  i = 0;
  digitalWrite(A0,0);
  digitalWrite(dir, 1);
  while (i < 50)
  {
    digitalWrite(S1, 1);
    delay(2);
    digitalWrite(S1, 0);
    i++;
  }
  digitalWrite(dir, 0);
  digitalWrite(A0,1);
}

void move_F()
{
  i = 0;
  digitalWrite(A1,0);
  digitalWrite(dir, 0);
  while (i < 50)
  {
    digitalWrite(S2, 1);
    delay(2);
    digitalWrite(S2, 0);
    i++;
  }
  digitalWrite(dir, 0);
  digitalWrite(A1,1);
}

void move_f()
{
  int i = 0;
  digitalWrite(A1,0);
  digitalWrite(dir, 1);
  while (i < 50)
  {
    digitalWrite(S2, 1);
    delay(2);
    digitalWrite(S2, 0);
    i++;
  }
  digitalWrite(dir, 0);
  digitalWrite(A1,1);
}

void move_U()
{
  int i = 0;
  digitalWrite(A2,0);
  digitalWrite(dir, 0);
  while (i < 50)
  {
    digitalWrite(S3, 1);
    delay(2);
    digitalWrite(S3, 0);
    i++;
  }
  digitalWrite(dir, 0);
  digitalWrite(A2,1);
}

void move_u()
{
  int i = 0;
  digitalWrite(A2,0);
  digitalWrite(dir, 1);
  while (i < 50)
  {
    digitalWrite(S3, 1);
    delay(2);
    digitalWrite(S3, 0);
    i++;
  }
  digitalWrite(dir, 0);
  digitalWrite(A2,1);
}

void move_L()
{
  int i = 0;
  digitalWrite(A3,0);
  digitalWrite(dir, 0);
  while (i < 50)
  {
    digitalWrite(S4, 1);
    delay(2);
    digitalWrite(S4, 0);
    i++;
  }
  digitalWrite(dir, 0);
  digitalWrite(A3,1);
}

void move_l()
{
  int i = 0;
  digitalWrite(A3,0);
  digitalWrite(dir, 1);
  while (i < 50)
  {
    digitalWrite(S4, 1);
    delay(2);
    digitalWrite(S4, 0);
    i++;
  }
  digitalWrite(dir, 0);
  digitalWrite(A3,1);
}

void move_B()
{
  int i = 0;
  digitalWrite(A4,0);
  digitalWrite(dir, 0);
  while (i < 50)
  {
    digitalWrite(S5, 1);
    delay(2);
    digitalWrite(S5, 0);
    i++;
  }
  digitalWrite(dir, 0);
  digitalWrite(A4,1);
}

void move_b()
{
  int i = 0;
  digitalWrite(A4,0);
  digitalWrite(dir, 1);
  while (i < 50)
  {
    digitalWrite(S5, 1);
    delay(2);
    digitalWrite(S5, 0);
    i++;
  }
  digitalWrite(dir, 0);
  digitalWrite(A4,1);
}

void move_D()
{
  int i = 0;
  digitalWrite(A5,0);
  digitalWrite(dir, 0);
  while (i < 50)
  {
    digitalWrite(S6, 1);
    delay(5);
    digitalWrite(S6, 0);
    i++;
  }
  digitalWrite(dir, 0);
  digitalWrite(A5,1);
}

void move_d()
{
  int i = 0;
  digitalWrite(A5,0);
  digitalWrite(dir, 1);
  while (i < 50)
  {
    digitalWrite(S6, 1);
    delay(2);
    digitalWrite(S6, 0);
    i++;
  }
  digitalWrite(dir, 0);
  digitalWrite(A5,1);
}
