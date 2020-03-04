#include "Arduino.h"
#include "Rubiks_Cube_Algo.h"

rcalgo::rcalgo() {}

#define swap(temp_A, temp_B) { int16_t t = temp_A; temp_A = temp_B; temp_B = t; }

int Corner_pcs[8][4]={{1,1,5,2},{2,1,2,3},{3,1,3,4},{4,1,4,5},{5,4,5,6},{6,5,2,6},{7,2,3,6},{8,3,4,6}};
int Edge_pcs[12][3]={{1,1,2},{2,1,3},{3,1,4},{4,1,5},{5,5,2},{6,2,3},{7,3,4},{8,4,5},{9,2,6},{10,3,6},{11,4,6},{12,5,6}};
int count_i,cc=0;
char output[300];
int out_count=0;


void R()
{
    switch(cc%4)
    {
        case 0 : output[out_count]='R'; break;
        case 1 : output[out_count]='B'; break;
        case 2 : output[out_count]='L'; break;
        case 3 : output[out_count]='F'; break;
    }
    out_count++;

    int temp_a;

// Rotation for Corner Pieces...
  for(count_i=0;count_i<8;count_i++)
  {
      if(Corner_pcs[count_i][0]==2)
      {
          swap(Corner_pcs[count_i][2],Corner_pcs[count_i][3]);
        Corner_pcs[count_i][0]=13;
      }
      if(Corner_pcs[count_i][0]==3)
      {
          temp_a=Corner_pcs[count_i][1];
          Corner_pcs[count_i][1]=Corner_pcs[count_i][3];
          Corner_pcs[count_i][3]=Corner_pcs[count_i][2];
          Corner_pcs[count_i][2]=temp_a;
        Corner_pcs[count_i][0]=14;
      }
      if(Corner_pcs[count_i][0]==7)
      {
          temp_a=Corner_pcs[count_i][1];
          Corner_pcs[count_i][1]=Corner_pcs[count_i][2];
          Corner_pcs[count_i][2]=Corner_pcs[count_i][3];
          Corner_pcs[count_i][3]=temp_a;
        Corner_pcs[count_i][0]=15;
      }
      if(Corner_pcs[count_i][0]==8)
      {
          swap(Corner_pcs[count_i][1],Corner_pcs[count_i][2]);
        Corner_pcs[count_i][0]=16;
      }
  }

  for(count_i=0;count_i<8;count_i++)
  {
      if(Corner_pcs[count_i][0]==13)
        Corner_pcs[count_i][0]=7;
      if(Corner_pcs[count_i][0]==14)
        Corner_pcs[count_i][0]=2;
      if(Corner_pcs[count_i][0]==15)
        Corner_pcs[count_i][0]=8;
      if(Corner_pcs[count_i][0]==16)
        Corner_pcs[count_i][0]=3;
  }

// Rotating the Edge Pieces...

  for(count_i=0;count_i<12;count_i++)
  {
     if(Edge_pcs[count_i][0]==2)
     {
         Edge_pcs[count_i][0]=13;
     }
     if(Edge_pcs[count_i][0]==6)
     {
        temp_a=Edge_pcs[count_i][1];
        Edge_pcs[count_i][1]=Edge_pcs[count_i][2];
        Edge_pcs[count_i][2]=temp_a;
         Edge_pcs[count_i][0]=14;
     }
     if(Edge_pcs[count_i][0]==10)
     {
         Edge_pcs[count_i][0]=15;
     }
     if(Edge_pcs[count_i][0]==7)
     {
        temp_a=Edge_pcs[count_i][1];
        Edge_pcs[count_i][1]=Edge_pcs[count_i][2];
        Edge_pcs[count_i][2]=temp_a;
         Edge_pcs[count_i][0]=16;
     }
  }

  for(count_i=0;count_i<12;count_i++)
  {
      if(Edge_pcs[count_i][0]==13)
        Edge_pcs[count_i][0]=6;
      if(Edge_pcs[count_i][0]==14)
        Edge_pcs[count_i][0]=10;
      if(Edge_pcs[count_i][0]==15)
        Edge_pcs[count_i][0]=7;
      if(Edge_pcs[count_i][0]==16)
        Edge_pcs[count_i][0]=2;
  }
}

void Ri()
{
    switch(cc%4)
    {
        case 0 : output[out_count]='r'; break;
        case 1 : output[out_count]='b'; break;
        case 2 : output[out_count]='l'; break;
        case 3 : output[out_count]='f'; break;
    }
    out_count++;

   int temp_a;

// Rotation for Corner Pieces...
  for(count_i=0;count_i<8;count_i++)
  {
      if(Corner_pcs[count_i][0]==2)
      {
          //cout<<"    ";
          temp_a=Corner_pcs[count_i][1];
          Corner_pcs[count_i][1]=Corner_pcs[count_i][2];
          Corner_pcs[count_i][2]=Corner_pcs[count_i][3];
          Corner_pcs[count_i][3]=temp_a;
        Corner_pcs[count_i][0]=13;
      }
      if(Corner_pcs[count_i][0]==3)
      {
          swap(Corner_pcs[count_i][1],Corner_pcs[count_i][2]);
        Corner_pcs[count_i][0]=14;
      }
      if(Corner_pcs[count_i][0]==7)
      {
          swap(Corner_pcs[count_i][2],Corner_pcs[count_i][3]);
        Corner_pcs[count_i][0]=15;
      }
      if(Corner_pcs[count_i][0]==8)
      {
          temp_a=Corner_pcs[count_i][1];
          Corner_pcs[count_i][1]=Corner_pcs[count_i][3];
          Corner_pcs[count_i][3]=Corner_pcs[count_i][2];
          Corner_pcs[count_i][2]=temp_a;
        Corner_pcs[count_i][0]=16;
      }
  }

  for(count_i=0;count_i<8;count_i++)
  {
      if(Corner_pcs[count_i][0]==13)
         Corner_pcs[count_i][0]=3;
      if(Corner_pcs[count_i][0]==14)
        Corner_pcs[count_i][0]=8;
      if(Corner_pcs[count_i][0]==15)
        Corner_pcs[count_i][0]=2;
      if(Corner_pcs[count_i][0]==16)
        Corner_pcs[count_i][0]=7;
  }

// Rotating the Edge Pieces...

  for(count_i=0;count_i<12;count_i++)
  {
     if(Edge_pcs[count_i][0]==2)
     {
        swap(Edge_pcs[count_i][1],Edge_pcs[count_i][2]);
         Edge_pcs[count_i][0]=13;
     }
     if(Edge_pcs[count_i][0]==6)
     {
         Edge_pcs[count_i][0]=14;
     }
     if(Edge_pcs[count_i][0]==10)
     {
        swap(Edge_pcs[count_i][1],Edge_pcs[count_i][2]);
         Edge_pcs[count_i][0]=15;
     }
     if(Edge_pcs[count_i][0]==7)
     {
         Edge_pcs[count_i][0]=16;
     }
  }

  for(count_i=0;count_i<12;count_i++)
  {
      if(Edge_pcs[count_i][0]==13)
        Edge_pcs[count_i][0]=7;
      if(Edge_pcs[count_i][0]==14)
        Edge_pcs[count_i][0]=2;
      if(Edge_pcs[count_i][0]==15)
        Edge_pcs[count_i][0]=6;
      if(Edge_pcs[count_i][0]==16)
        Edge_pcs[count_i][0]=10;
  }
}

void L()
{
    switch(cc%4)
    {
        case 0 : output[out_count]='L'; break;
        case 1 : output[out_count]='F'; break;
        case 2 : output[out_count]='R'; break;
        case 3 : output[out_count]='B'; break;
    }
    out_count++;

    int temp_a;

// Rotation for Corner Pieces...
  for(count_i=0;count_i<8;count_i++)
  {
      if(Corner_pcs[count_i][0]==1)
      {
          temp_a=Corner_pcs[count_i][1];
          Corner_pcs[count_i][1]=Corner_pcs[count_i][3];
          Corner_pcs[count_i][3]=Corner_pcs[count_i][2];
          Corner_pcs[count_i][2]=temp_a;
        Corner_pcs[count_i][0]=13;
      }
      if(Corner_pcs[count_i][0]==4)
      {
          swap(Corner_pcs[count_i][2],Corner_pcs[count_i][3]);
        Corner_pcs[count_i][0]=14;
      }
      if(Corner_pcs[count_i][0]==5)
      {
          temp_a=Corner_pcs[count_i][1];
          Corner_pcs[count_i][1]=Corner_pcs[count_i][2];
          Corner_pcs[count_i][2]=Corner_pcs[count_i][3];
          Corner_pcs[count_i][3]=temp_a;
        Corner_pcs[count_i][0]=15;
      }
      if(Corner_pcs[count_i][0]==6)
      {
          swap(Corner_pcs[count_i][2],Corner_pcs[count_i][1]);
        Corner_pcs[count_i][0]=16;
      }
  }

  for(count_i=0;count_i<8;count_i++)
  {
      if(Corner_pcs[count_i][0]==13)
        Corner_pcs[count_i][0]=4;
      if(Corner_pcs[count_i][0]==14)
        Corner_pcs[count_i][0]=5;
      if(Corner_pcs[count_i][0]==15)
        Corner_pcs[count_i][0]=6;
      if(Corner_pcs[count_i][0]==16)
        Corner_pcs[count_i][0]=1;
  }

// Rotating the Edge Pieces...

  for(count_i=0;count_i<12;count_i++)
  {
     if(Edge_pcs[count_i][0]==4)
     {
         Edge_pcs[count_i][0]=13;
     }
     if(Edge_pcs[count_i][0]==8)
     {
        swap(Edge_pcs[count_i][1],Edge_pcs[count_i][2]);
         Edge_pcs[count_i][0]=14;
     }
     if(Edge_pcs[count_i][0]==12)
     {
         Edge_pcs[count_i][0]=15;
     }
     if(Edge_pcs[count_i][0]==5)
     {
        swap(Edge_pcs[count_i][1],Edge_pcs[count_i][2]);
         Edge_pcs[count_i][0]=16;
     }
  }

  for(count_i=0;count_i<12;count_i++)
  {
      if(Edge_pcs[count_i][0]==13)
        Edge_pcs[count_i][0]=8;
      if(Edge_pcs[count_i][0]==14)
        Edge_pcs[count_i][0]=12;
      if(Edge_pcs[count_i][0]==15)
        Edge_pcs[count_i][0]=5;
      if(Edge_pcs[count_i][0]==16)
        Edge_pcs[count_i][0]=4;
  }
}

void Li()
{
    switch(cc%4)
    {
        case 0 : output[out_count]='l'; break;
        case 1 : output[out_count]='f'; break;
        case 2 : output[out_count]='r'; break;
        case 3 : output[out_count]='b'; break;
    }
    out_count++;

    int temp_a;

// Rotation for Corner Pieces...
  for(count_i=0;count_i<8;count_i++)
  {
      if(Corner_pcs[count_i][0]==1)
      {
          swap(Corner_pcs[count_i][2],Corner_pcs[count_i][1]);
        Corner_pcs[count_i][0]=13;
      }
      if(Corner_pcs[count_i][0]==6)
      {
          temp_a=Corner_pcs[count_i][1];
          Corner_pcs[count_i][1]=Corner_pcs[count_i][3];
          Corner_pcs[count_i][3]=Corner_pcs[count_i][2];
          Corner_pcs[count_i][2]=temp_a;
        Corner_pcs[count_i][0]=14;
      }
      if(Corner_pcs[count_i][0]==5)
      {
          swap(Corner_pcs[count_i][3],Corner_pcs[count_i][2]);
        Corner_pcs[count_i][0]=15;
      }
      if(Corner_pcs[count_i][0]==4)
      {
          temp_a=Corner_pcs[count_i][1];
          Corner_pcs[count_i][1]=Corner_pcs[count_i][2];
          Corner_pcs[count_i][2]=Corner_pcs[count_i][3];
          Corner_pcs[count_i][3]=temp_a;
        Corner_pcs[count_i][0]=16;
      }
  }

  for(count_i=0;count_i<8;count_i++)
  {
      if(Corner_pcs[count_i][0]==13)
        Corner_pcs[count_i][0]=6;
      if(Corner_pcs[count_i][0]==14)
        Corner_pcs[count_i][0]=5;
      if(Corner_pcs[count_i][0]==15)
        Corner_pcs[count_i][0]=4;
      if(Corner_pcs[count_i][0]==16)
        Corner_pcs[count_i][0]=1;
  }

// Rotating the Edge Pieces...

  for(count_i=0;count_i<12;count_i++)
  {
     if(Edge_pcs[count_i][0]==4)
     {
        swap(Edge_pcs[count_i][1],Edge_pcs[count_i][2]);
         Edge_pcs[count_i][0]=13;
     }
     if(Edge_pcs[count_i][0]==5)
     {
         Edge_pcs[count_i][0]=14;
     }
     if(Edge_pcs[count_i][0]==12)
     {
        swap(Edge_pcs[count_i][1],Edge_pcs[count_i][2]);
         Edge_pcs[count_i][0]=15;
     }
     if(Edge_pcs[count_i][0]==8)
     {
         Edge_pcs[count_i][0]=16;
     }
  }

  for(count_i=0;count_i<12;count_i++)
  {
      if(Edge_pcs[count_i][0]==13)
        Edge_pcs[count_i][0]=5;
      if(Edge_pcs[count_i][0]==14)
        Edge_pcs[count_i][0]=12;
      if(Edge_pcs[count_i][0]==15)
        Edge_pcs[count_i][0]=8;
      if(Edge_pcs[count_i][0]==16)
        Edge_pcs[count_i][0]=4;
  }
}

void U()
{
    output[out_count]='U';
    out_count++;

// Rotation for Corner Pieces...
  for(count_i=0;count_i<8;count_i++)
  {
      if(Corner_pcs[count_i][0]==5)
      {
        Corner_pcs[count_i][0]=13;
      }
      if(Corner_pcs[count_i][0]==8)
      {
        Corner_pcs[count_i][0]=14;
      }
      if(Corner_pcs[count_i][0]==7)
      {
        Corner_pcs[count_i][0]=15;
      }
      if(Corner_pcs[count_i][0]==6)
      {
        Corner_pcs[count_i][0]=16;
      }
  }

  for(count_i=0;count_i<8;count_i++)
  {
      if(Corner_pcs[count_i][0]==13)
        Corner_pcs[count_i][0]=8;
      if(Corner_pcs[count_i][0]==14)
        Corner_pcs[count_i][0]=7;
      if(Corner_pcs[count_i][0]==15)
        Corner_pcs[count_i][0]=6;
      if(Corner_pcs[count_i][0]==16)
        Corner_pcs[count_i][0]=5;
  }

// Rotating the Edge Pieces...

  for(count_i=0;count_i<12;count_i++)
  {
     if(Edge_pcs[count_i][0]==12)
     {
         Edge_pcs[count_i][0]=13;
     }
     if(Edge_pcs[count_i][0]==11)
     {
         Edge_pcs[count_i][0]=14;
     }
     if(Edge_pcs[count_i][0]==10)
     {
         Edge_pcs[count_i][0]=15;
     }
     if(Edge_pcs[count_i][0]==9)
     {
         Edge_pcs[count_i][0]=16;
     }
  }

  for(count_i=0;count_i<12;count_i++)
  {
      if(Edge_pcs[count_i][0]==13)
        Edge_pcs[count_i][0]=11;
      if(Edge_pcs[count_i][0]==14)
        Edge_pcs[count_i][0]=10;
      if(Edge_pcs[count_i][0]==15)
        Edge_pcs[count_i][0]=9;
      if(Edge_pcs[count_i][0]==16)
        Edge_pcs[count_i][0]=12;
  }
}

void Ui()
{
    output[out_count]='u';
    out_count++;

// Rotation for Corner Pieces...
  for(count_i=0;count_i<8;count_i++)
  {
      if(Corner_pcs[count_i][0]==5)
      {
        Corner_pcs[count_i][0]=13;
      }
      if(Corner_pcs[count_i][0]==6)
      {
        Corner_pcs[count_i][0]=14;
      }
      if(Corner_pcs[count_i][0]==7)
      {
        Corner_pcs[count_i][0]=15;
      }
      if(Corner_pcs[count_i][0]==8)
      {
        Corner_pcs[count_i][0]=16;
      }
  }

  for(count_i=0;count_i<8;count_i++)
  {
      if(Corner_pcs[count_i][0]==13)
        Corner_pcs[count_i][0]=6;
      if(Corner_pcs[count_i][0]==14)
        Corner_pcs[count_i][0]=7;
      if(Corner_pcs[count_i][0]==15)
        Corner_pcs[count_i][0]=8;
      if(Corner_pcs[count_i][0]==16)
        Corner_pcs[count_i][0]=5;
  }

// Rotating the Edge Pieces...

  for(count_i=0;count_i<12;count_i++)
  {
     if(Edge_pcs[count_i][0]==9)
     {
         Edge_pcs[count_i][0]=13;
     }
     if(Edge_pcs[count_i][0]==10)
     {
         Edge_pcs[count_i][0]=14;
     }
     if(Edge_pcs[count_i][0]==11)
     {
         Edge_pcs[count_i][0]=15;
     }
     if(Edge_pcs[count_i][0]==12)
     {
         Edge_pcs[count_i][0]=16;
     }
  }

  for(count_i=0;count_i<12;count_i++)
  {
      if(Edge_pcs[count_i][0]==13)
        Edge_pcs[count_i][0]=10;
      if(Edge_pcs[count_i][0]==14)
        Edge_pcs[count_i][0]=11;
      if(Edge_pcs[count_i][0]==15)
        Edge_pcs[count_i][0]=12;
      if(Edge_pcs[count_i][0]==16)
        Edge_pcs[count_i][0]=9;
  }
}

void f()
{
    switch(cc%4)
    {
        case 0 : output[out_count]='F'; break;
        case 1 : output[out_count]='R'; break;
        case 2 : output[out_count]='B'; break;
        case 3 : output[out_count]='L'; break;
    }
    out_count++;

    int temp_a;

// Rotation for Corner Pieces...
  for(count_i=0;count_i<8;count_i++)
  {
      if(Corner_pcs[count_i][0]==2)
      {
          temp_a=Corner_pcs[count_i][1];
          Corner_pcs[count_i][1]=Corner_pcs[count_i][3];
          Corner_pcs[count_i][3]=Corner_pcs[count_i][2];
          Corner_pcs[count_i][2]=temp_a;
        Corner_pcs[count_i][0]=13;
      }
      if(Corner_pcs[count_i][0]==1)
      {
          swap(Corner_pcs[count_i][2],Corner_pcs[count_i][3]);
        Corner_pcs[count_i][0]=14;
      }
      if(Corner_pcs[count_i][0]==6)
      {
          temp_a=Corner_pcs[count_i][1];
          Corner_pcs[count_i][1]=Corner_pcs[count_i][2];
          Corner_pcs[count_i][2]=Corner_pcs[count_i][3];
          Corner_pcs[count_i][3]=temp_a;
        Corner_pcs[count_i][0]=15;
      }
      if(Corner_pcs[count_i][0]==7)
      {
          swap(Corner_pcs[count_i][1],Corner_pcs[count_i][2]);
        Corner_pcs[count_i][0]=16;
      }
  }

  for(count_i=0;count_i<8;count_i++)
  {
      if(Corner_pcs[count_i][0]==13)
        Corner_pcs[count_i][0]=1;
      if(Corner_pcs[count_i][0]==14)
        Corner_pcs[count_i][0]=6;
      if(Corner_pcs[count_i][0]==15)
        Corner_pcs[count_i][0]=7;
      if(Corner_pcs[count_i][0]==16)
        Corner_pcs[count_i][0]=2;
  }

// Rotating the Edge Pieces...

  for(count_i=0;count_i<12;count_i++)
  {
     if(Edge_pcs[count_i][0]==1)
     {
         Edge_pcs[count_i][0]=13;
     }
     if(Edge_pcs[count_i][0]==5)
     {
        swap(Edge_pcs[count_i][1],Edge_pcs[count_i][2]);
         Edge_pcs[count_i][0]=14;
     }
     if(Edge_pcs[count_i][0]==9)
     {
         Edge_pcs[count_i][0]=15;
     }
     if(Edge_pcs[count_i][0]==6)
     {
        swap(Edge_pcs[count_i][1],Edge_pcs[count_i][2]);
         Edge_pcs[count_i][0]=16;
     }
  }

  for(count_i=0;count_i<12;count_i++)
  {
      if(Edge_pcs[count_i][0]==13)
        Edge_pcs[count_i][0]=5;
      if(Edge_pcs[count_i][0]==14)
        Edge_pcs[count_i][0]=9;
      if(Edge_pcs[count_i][0]==15)
        Edge_pcs[count_i][0]=6;
      if(Edge_pcs[count_i][0]==16)
        Edge_pcs[count_i][0]=1;
  }
}

void Fi()
{
    switch(cc%4)
    {
        case 0 : output[out_count]='f'; break;
        case 1 : output[out_count]='r'; break;
        case 2 : output[out_count]='b'; break;
        case 3 : output[out_count]='l'; break;
    }
    out_count++;

    int temp_a;

// Rotation for Corner Pieces...
  for(count_i=0;count_i<8;count_i++)
  {
      if(Corner_pcs[count_i][0]==1)
      {
          temp_a=Corner_pcs[count_i][1];
          Corner_pcs[count_i][1]=Corner_pcs[count_i][2];
          Corner_pcs[count_i][2]=Corner_pcs[count_i][3];
          Corner_pcs[count_i][3]=temp_a;
        Corner_pcs[count_i][0]=13;
      }
      if(Corner_pcs[count_i][0]==2)
      {
          swap(Corner_pcs[count_i][1],Corner_pcs[count_i][2]);
        Corner_pcs[count_i][0]=14;
      }
      if(Corner_pcs[count_i][0]==7)
      {
          temp_a=Corner_pcs[count_i][1];
          Corner_pcs[count_i][1]=Corner_pcs[count_i][3];
          Corner_pcs[count_i][3]=Corner_pcs[count_i][2];
          Corner_pcs[count_i][2]=temp_a;
        Corner_pcs[count_i][0]=15;
      }
      if(Corner_pcs[count_i][0]==6)
      {
          swap(Corner_pcs[count_i][3],Corner_pcs[count_i][2]);
        Corner_pcs[count_i][0]=16;
      }
  }

  for(count_i=0;count_i<8;count_i++)
  {
      if(Corner_pcs[count_i][0]==13)
        Corner_pcs[count_i][0]=2;
      if(Corner_pcs[count_i][0]==14)
        Corner_pcs[count_i][0]=7;
      if(Corner_pcs[count_i][0]==15)
        Corner_pcs[count_i][0]=6;
      if(Corner_pcs[count_i][0]==16)
        Corner_pcs[count_i][0]=1;
  }

// Rotating the Edge Pieces...

  for(count_i=0;count_i<12;count_i++)
  {
     if(Edge_pcs[count_i][0]==1)
     {
        swap(Edge_pcs[count_i][1],Edge_pcs[count_i][2]);
         Edge_pcs[count_i][0]=13;
     }
     if(Edge_pcs[count_i][0]==6)
     {
         Edge_pcs[count_i][0]=14;
     }
     if(Edge_pcs[count_i][0]==9)
     {
        swap(Edge_pcs[count_i][1],Edge_pcs[count_i][2]);
         Edge_pcs[count_i][0]=15;
     }
     if(Edge_pcs[count_i][0]==5)
     {
         Edge_pcs[count_i][0]=16;
     }
  }

  for(count_i=0;count_i<12;count_i++)
  {
      if(Edge_pcs[count_i][0]==13)
        Edge_pcs[count_i][0]=6;
      if(Edge_pcs[count_i][0]==14)
        Edge_pcs[count_i][0]=9;
      if(Edge_pcs[count_i][0]==15)
        Edge_pcs[count_i][0]=5;
      if(Edge_pcs[count_i][0]==16)
        Edge_pcs[count_i][0]=1;
  }
}

void D()
{
    output[out_count]='D';
    out_count++;
// Rotation for Corner Pieces...
  for(count_i=0;count_i<8;count_i++)
  {
      if(Corner_pcs[count_i][0]==1)
      {
        Corner_pcs[count_i][0]=13;
      }
      if(Corner_pcs[count_i][0]==2)
      {
        Corner_pcs[count_i][0]=14;
      }
      if(Corner_pcs[count_i][0]==3)
      {
        Corner_pcs[count_i][0]=15;
      }
      if(Corner_pcs[count_i][0]==4)
      {
        Corner_pcs[count_i][0]=16;
      }
  }

  for(count_i=0;count_i<8;count_i++)
  {
      if(Corner_pcs[count_i][0]==13)
        Corner_pcs[count_i][0]=2;
      if(Corner_pcs[count_i][0]==14)
        Corner_pcs[count_i][0]=3;
      if(Corner_pcs[count_i][0]==15)
        Corner_pcs[count_i][0]=4;
      if(Corner_pcs[count_i][0]==16)
        Corner_pcs[count_i][0]=1;
  }

// Rotating the Edge Pieces...

  for(count_i=0;count_i<12;count_i++)
  {
     if(Edge_pcs[count_i][0]==1)
     {
         Edge_pcs[count_i][0]=13;
     }
     if(Edge_pcs[count_i][0]==2)
     {
         Edge_pcs[count_i][0]=14;
     }
     if(Edge_pcs[count_i][0]==3)
     {
         Edge_pcs[count_i][0]=15;
     }
     if(Edge_pcs[count_i][0]==4)
     {
         Edge_pcs[count_i][0]=16;
     }
  }

  for(count_i=0;count_i<12;count_i++)
  {
      if(Edge_pcs[count_i][0]==13)
        Edge_pcs[count_i][0]=2;
      if(Edge_pcs[count_i][0]==14)
        Edge_pcs[count_i][0]=3;
      if(Edge_pcs[count_i][0]==15)
        Edge_pcs[count_i][0]=4;
      if(Edge_pcs[count_i][0]==16)
        Edge_pcs[count_i][0]=1;
  }
}

void Di()
{
    output[out_count]='d';
    out_count++;

// Rotation for Corner Pieces...
  for(count_i=0;count_i<8;count_i++)
  {
      if(Corner_pcs[count_i][0]==4)
      {
        Corner_pcs[count_i][0]=13;
      }
      if(Corner_pcs[count_i][0]==3)
      {
        Corner_pcs[count_i][0]=14;
      }
      if(Corner_pcs[count_i][0]==2)
      {
        Corner_pcs[count_i][0]=15;
      }
      if(Corner_pcs[count_i][0]==1)
      {
        Corner_pcs[count_i][0]=16;
      }
  }

  for(count_i=0;count_i<8;count_i++)
  {
      if(Corner_pcs[count_i][0]==13)
        Corner_pcs[count_i][0]=3;
      if(Corner_pcs[count_i][0]==14)
        Corner_pcs[count_i][0]=2;
      if(Corner_pcs[count_i][0]==15)
        Corner_pcs[count_i][0]=1;
      if(Corner_pcs[count_i][0]==16)
        Corner_pcs[count_i][0]=4;
  }

// Rotating the Edge Pieces...

  for(count_i=0;count_i<12;count_i++)
  {
     if(Edge_pcs[count_i][0]==4)
     {
         Edge_pcs[count_i][0]=13;
     }
     if(Edge_pcs[count_i][0]==3)
     {
         Edge_pcs[count_i][0]=14;
     }
     if(Edge_pcs[count_i][0]==2)
     {
         Edge_pcs[count_i][0]=15;
     }
     if(Edge_pcs[count_i][0]==1)
     {
         Edge_pcs[count_i][0]=16;
     }
  }

  for(count_i=0;count_i<12;count_i++)
  {
      if(Edge_pcs[count_i][0]==13)
        Edge_pcs[count_i][0]=3;
      if(Edge_pcs[count_i][0]==14)
        Edge_pcs[count_i][0]=2;
      if(Edge_pcs[count_i][0]==15)
        Edge_pcs[count_i][0]=1;
      if(Edge_pcs[count_i][0]==16)
        Edge_pcs[count_i][0]=4;
  }
}

void B()
{
    switch(cc%4)
    {
        case 0 : output[out_count]='B'; break;
        case 1 : output[out_count]='L'; break;
        case 2 : output[out_count]='F'; break;
        case 3 : output[out_count]='R'; break;
    }
    out_count++;

    int temp_a;

// Rotation for Corner Pieces...
  for(count_i=0;count_i<8;count_i++)
  {
      if(Corner_pcs[count_i][0]==4)
      {
          temp_a=Corner_pcs[count_i][1];
          Corner_pcs[count_i][1]=Corner_pcs[count_i][3];
          Corner_pcs[count_i][3]=Corner_pcs[count_i][2];
          Corner_pcs[count_i][2]=temp_a;
        Corner_pcs[count_i][0]=13;
      }
      if(Corner_pcs[count_i][0]==3)
      {
          swap(Corner_pcs[count_i][2],Corner_pcs[count_i][3]);
        Corner_pcs[count_i][0]=14;
      }
      if(Corner_pcs[count_i][0]==8)
      {
          temp_a=Corner_pcs[count_i][1];
          Corner_pcs[count_i][1]=Corner_pcs[count_i][2];
          Corner_pcs[count_i][2]=Corner_pcs[count_i][3];
          Corner_pcs[count_i][3]=temp_a;
        Corner_pcs[count_i][0]=15;
      }
      if(Corner_pcs[count_i][0]==5)
      {
          swap(Corner_pcs[count_i][1],Corner_pcs[count_i][2]);
        Corner_pcs[count_i][0]=16;
      }
  }

  for(count_i=0;count_i<8;count_i++)
  {
      if(Corner_pcs[count_i][0]==13)
        Corner_pcs[count_i][0]=3;
      if(Corner_pcs[count_i][0]==14)
        Corner_pcs[count_i][0]=8;
      if(Corner_pcs[count_i][0]==15)
        Corner_pcs[count_i][0]=5;
      if(Corner_pcs[count_i][0]==16)
        Corner_pcs[count_i][0]=4;
  }

// Rotating the Edge Pieces...

  for(count_i=0;count_i<12;count_i++)
  {
     if(Edge_pcs[count_i][0]==3)
     {
         Edge_pcs[count_i][0]=13;
     }
     if(Edge_pcs[count_i][0]==7)
     {
        swap(Edge_pcs[count_i][1],Edge_pcs[count_i][2]);
         Edge_pcs[count_i][0]=14;
     }
     if(Edge_pcs[count_i][0]==11)
     {
         Edge_pcs[count_i][0]=15;
     }
     if(Edge_pcs[count_i][0]==8)
     {
        swap(Edge_pcs[count_i][1],Edge_pcs[count_i][2]);
         Edge_pcs[count_i][0]=16;
     }
  }

  for(count_i=0;count_i<12;count_i++)
  {
      if(Edge_pcs[count_i][0]==13)
        Edge_pcs[count_i][0]=7;
      if(Edge_pcs[count_i][0]==14)
        Edge_pcs[count_i][0]=11;
      if(Edge_pcs[count_i][0]==15)
        Edge_pcs[count_i][0]=8;
      if(Edge_pcs[count_i][0]==16)
        Edge_pcs[count_i][0]=3;
  }
}

void Bi()
{
    switch(cc%4)
    {
        case 0 : output[out_count]='b'; break;
        case 1 : output[out_count]='l'; break;
        case 2 : output[out_count]='f'; break;
        case 3 : output[out_count]='r'; break;
    }
    out_count++;

    int temp_a;

// Rotation for Corner Pieces...
  for(count_i=0;count_i<8;count_i++)
  {
      if(Corner_pcs[count_i][0]==3)
      {
          temp_a=Corner_pcs[count_i][1];
          Corner_pcs[count_i][1]=Corner_pcs[count_i][2];
          Corner_pcs[count_i][2]=Corner_pcs[count_i][3];
          Corner_pcs[count_i][3]=temp_a;
        Corner_pcs[count_i][0]=13;
      }
      if(Corner_pcs[count_i][0]==4)
      {
          swap(Corner_pcs[count_i][1],Corner_pcs[count_i][2]);
        Corner_pcs[count_i][0]=14;
      }
      if(Corner_pcs[count_i][0]==5)
      {
          temp_a=Corner_pcs[count_i][1];
          Corner_pcs[count_i][1]=Corner_pcs[count_i][3];
          Corner_pcs[count_i][3]=Corner_pcs[count_i][2];
          Corner_pcs[count_i][2]=temp_a;
        Corner_pcs[count_i][0]=15;
      }
      if(Corner_pcs[count_i][0]==8)
      {
          swap(Corner_pcs[count_i][2],Corner_pcs[count_i][3]);
        Corner_pcs[count_i][0]=16;
      }
  }

  for(count_i=0;count_i<8;count_i++)
  {
      if(Corner_pcs[count_i][0]==13)
        Corner_pcs[count_i][0]=4;
      if(Corner_pcs[count_i][0]==14)
        Corner_pcs[count_i][0]=5;
      if(Corner_pcs[count_i][0]==15)
        Corner_pcs[count_i][0]=8;
      if(Corner_pcs[count_i][0]==16)
        Corner_pcs[count_i][0]=3;
  }

// Rotating the Edge Pieces...

  for(count_i=0;count_i<12;count_i++)
  {
     if(Edge_pcs[count_i][0]==3)
     {
        swap(Edge_pcs[count_i][1],Edge_pcs[count_i][2]);
         Edge_pcs[count_i][0]=13;
     }
     if(Edge_pcs[count_i][0]==8)
     {
         Edge_pcs[count_i][0]=14;
     }
     if(Edge_pcs[count_i][0]==11)
     {
        swap(Edge_pcs[count_i][1],Edge_pcs[count_i][2]);
         Edge_pcs[count_i][0]=15;
     }
     if(Edge_pcs[count_i][0]==7)
     {
         Edge_pcs[count_i][0]=16;
     }
  }

  for(count_i=0;count_i<12;count_i++)
  {
      if(Edge_pcs[count_i][0]==13)
        Edge_pcs[count_i][0]=8;
      if(Edge_pcs[count_i][0]==14)
        Edge_pcs[count_i][0]=11;
      if(Edge_pcs[count_i][0]==15)
        Edge_pcs[count_i][0]=7;
      if(Edge_pcs[count_i][0]==16)
        Edge_pcs[count_i][0]=3;
  }
}

void CCR ()
{
    cc = cc%4;
    cc+=1;

   for(count_i=0;count_i<8;count_i++)
   {
       switch(Corner_pcs[count_i][0])
       {
           case 1 : Corner_pcs[count_i][0]=9; break;
           case 2 : Corner_pcs[count_i][0]=10; break;
           case 3 : Corner_pcs[count_i][0]=11; break;
           case 4 : Corner_pcs[count_i][0]=12; break;
           case 5 : Corner_pcs[count_i][0]=13; break;
           case 6 : Corner_pcs[count_i][0]=14; break;
           case 7 : Corner_pcs[count_i][0]=15; break;
           case 8 : Corner_pcs[count_i][0]=16; break;
       }
   }

   for(count_i=0;count_i<12;count_i++)
   {
       switch(Edge_pcs[count_i][0])
       {
           case 1 : Edge_pcs[count_i][0]=13; break;
           case 2 : Edge_pcs[count_i][0]=14; break;
           case 3 : Edge_pcs[count_i][0]=15; break;
           case 4 : Edge_pcs[count_i][0]=16; break;
           case 5 : Edge_pcs[count_i][0]=17; break;
           case 6 : Edge_pcs[count_i][0]=18; break;
           case 7 : Edge_pcs[count_i][0]=19; break;
           case 8 : Edge_pcs[count_i][0]=20; break;
           case 9 : Edge_pcs[count_i][0]=21; break;
           case 10 : Edge_pcs[count_i][0]=22; break;
           case 11 : Edge_pcs[count_i][0]=23; break;
           case 12 : Edge_pcs[count_i][0]=24; break;
       }
   }
   for(count_i=0;count_i<12;count_i++)
   {
       switch(Edge_pcs[count_i][0])
       {
           case 13 : Edge_pcs[count_i][0]=4; break;
           case 14 : Edge_pcs[count_i][0]=1; break;
           case 15 : Edge_pcs[count_i][0]=2; break;
           case 16 : Edge_pcs[count_i][0]=3; break;
           case 17 : Edge_pcs[count_i][0]=8; break;
           case 18 : Edge_pcs[count_i][0]=5; break;
           case 19 : Edge_pcs[count_i][0]=6; break;
           case 20 : Edge_pcs[count_i][0]=7; break;
           case 21 : Edge_pcs[count_i][0]=12; break;
           case 22 : Edge_pcs[count_i][0]=9; break;
           case 23 : Edge_pcs[count_i][0]=10; break;
           case 24 : Edge_pcs[count_i][0]=11; break;
       }
   }

   for(count_i=0;count_i<8;count_i++)
   {
       switch(Corner_pcs[count_i][0])
       {
           case 9 : Corner_pcs[count_i][0]=4; break;
           case 10 : Corner_pcs[count_i][0]=1; break;
           case 11 : Corner_pcs[count_i][0]=2; break;
           case 12 : Corner_pcs[count_i][0]=3; break;
           case 13 : Corner_pcs[count_i][0]=8; break;
           case 14 : Corner_pcs[count_i][0]=5; break;
           case 15 : Corner_pcs[count_i][0]=6; break;
           case 16 : Corner_pcs[count_i][0]=7; break;
       }
   }
}

void CCL ()
{
    cc = cc%4;
    cc+=3;

   for(count_i=0;count_i<8;count_i++)
   {
       switch(Corner_pcs[count_i][0])
       {
           case 1 : Corner_pcs[count_i][0]=9; break;
           case 2 : Corner_pcs[count_i][0]=10; break;
           case 3 : Corner_pcs[count_i][0]=11; break;
           case 4 : Corner_pcs[count_i][0]=12; break;
           case 5 : Corner_pcs[count_i][0]=13; break;
           case 6 : Corner_pcs[count_i][0]=14; break;
           case 7 : Corner_pcs[count_i][0]=15; break;
           case 8 : Corner_pcs[count_i][0]=16; break;
       }
   }

   for(count_i=0;count_i<12;count_i++)
   {
       switch(Edge_pcs[count_i][0])
       {
           case 1 : Edge_pcs[count_i][0]=13; break;
           case 2 : Edge_pcs[count_i][0]=14; break;
           case 3 : Edge_pcs[count_i][0]=15; break;
           case 4 : Edge_pcs[count_i][0]=16; break;
           case 5 : Edge_pcs[count_i][0]=17; break;
           case 6 : Edge_pcs[count_i][0]=18; break;
           case 7 : Edge_pcs[count_i][0]=19; break;
           case 8 : Edge_pcs[count_i][0]=20; break;
           case 9 : Edge_pcs[count_i][0]=21; break;
           case 10 : Edge_pcs[count_i][0]=22; break;
           case 11 : Edge_pcs[count_i][0]=23; break;
           case 12 : Edge_pcs[count_i][0]=24; break;
       }
   }
   for(count_i=0;count_i<12;count_i++)
   {
       switch(Edge_pcs[count_i][0])
       {
           case 13 : Edge_pcs[count_i][0]=2; break;
           case 14 : Edge_pcs[count_i][0]=3; break;
           case 15 : Edge_pcs[count_i][0]=4; break;
           case 16 : Edge_pcs[count_i][0]=1; break;
           case 17 : Edge_pcs[count_i][0]=6; break;
           case 18 : Edge_pcs[count_i][0]=7; break;
           case 19 : Edge_pcs[count_i][0]=8; break;
           case 20 : Edge_pcs[count_i][0]=5; break;
           case 21 : Edge_pcs[count_i][0]=10; break;
           case 22 : Edge_pcs[count_i][0]=11; break;
           case 23 : Edge_pcs[count_i][0]=12; break;
           case 24 : Edge_pcs[count_i][0]=9; break;
       }
   }

   for(count_i=0;count_i<8;count_i++)
   {
       switch(Corner_pcs[count_i][0])
       {
           case 9 : Corner_pcs[count_i][0]=2; break;
           case 10 : Corner_pcs[count_i][0]=3; break;
           case 11 : Corner_pcs[count_i][0]=4; break;
           case 12 : Corner_pcs[count_i][0]=1; break;
           case 13 : Corner_pcs[count_i][0]=6; break;
           case 14 : Corner_pcs[count_i][0]=7; break;
           case 15 : Corner_pcs[count_i][0]=8; break;
           case 16 : Corner_pcs[count_i][0]=5; break;
       }
   }

}


int rcalgo::solve(int inpsize,char *scramble,char *in)
{
  int count_j=300,count_k=0,count_I,count_size=0;

// Resetting the Output Array to Blank...
 {
  for(int k=0;k<299;k++)
  {
    output[k]='\0';
  }
  out_count=0;
 }
  // Random Backwards Input for Testing...
  // U(); Di(); R(); Li(); f(); B(); Ri(); Di(); Ui(); Fi(); R(); D(); D(); Li();
  // R(); U(); R(); D(); Fi(); L(); L(); D(); Ui(); U();
  // B(); B(); B(); B();

// Scrambling the cube according to given input...
  while(count_size<inpsize)
  {
    switch(scramble[count_size])
    {
       case 'R': R(); break;
       case 'r': Ri(); break;
       case 'L': L(); break;
       case 'l': Li(); break;
       case 'f': Fi(); break;
       case 'F': f(); break;
       case 'b': Bi(); break;
       case 'B': B(); break;
       case 'D': D(); break;
       case 'd': Di(); break;
       case 'u': Ui(); break;
       case 'U': U(); break;
    }
    count_size++;
    out_count--;
  }


// Solving First Layer...
// Bottom Layer Edge Pieces : -
  {
    for(count_j=0;count_j<4;count_j++)
    {

      if(Edge_pcs[count_j][1]==1)
      {
        switch(Edge_pcs[count_j][0])
        {
          case 2 : if(!count_j) {CCR();} else { R(); D(); Ri(); CCR(); } break;
          case 3 : if(!count_j) {CCR(); CCR();} else { B(); D(); D(); Bi(); CCR(); CCR(); } break;
          case 4 : CCL(); break;
          case 6 : if(!count_j) { Ri(); CCR(); } else { D(); Ri(); CCR(); } break;
          case 7 : if(!count_j) {Bi(); CCR(); CCR();} else { D(); D(); Bi(); CCR(); CCR(); } break;
          case 8 : if(!count_j) { Li(); CCL(); CCL(); } else { Di(); Li(); CCL(); } break;
          case 5 : Fi(); break;
          case 9 : if(!count_j) { f(); Ri(); CCR(); } else { f(); D(); Ri(); CCR(); } break;
          case 10 : if(!count_j) { Ri(); f(); } else { Ri(); f(); R(); } break;
          case 11 : if(!count_j) { Bi(); R(); CCR(); } else { U(); Ri(); f(); R(); } break;
          case 12 : if(!count_j) { L(); Fi(); } else { L(); Fi(); Li(); } break;
        }
      }
      else
      {
        switch(Edge_pcs[count_j][0])
        {
          case 1 : if(!count_j) { Fi(); Ri(); CCR(); } else { Fi(); D(); Ri(); CCR(); } break;
          case 2 : R(); f(); break;
          case 3 : if(!count_j) { B(); R(); CCR(); } else { B(); D(); R(); CCR(); } break;
          case 4 : Li(); Fi(); break;
          case 6 : f(); break;
          case 7 : if(!count_j) { R(); CCR(); } else { D(); R(); CCR(); } break;
          case 8 : if(!count_j) { B(); CCR(); CCR(); } else { D(); D(); B(); CCR(); CCR(); } break;
          case 5 : if(!count_j) { L(); CCL(); } else { Di(); L(); CCL(); } break;
          case 9 : f(); f(); break;
          case 10 : if(!count_j) { R(); R(); CCR(); } else { D(); R(); R(); CCR(); } break;
          case 11 : if(!count_j) { B(); B(); CCR(); CCR(); } else { U(); U(); f(); f(); } break;
          case 12 : if(!count_j) { L(); L(); CCL(); } else { Ui(); f(); f(); } break;
        }
      }

      CCR();
    }
  }

// Aligning Lower Layer Correctly...
  {
  if(cc%4==1) { Di(); CCL(); }
  else if(cc%4==2) { D(); D(); CCR(); CCR(); }
  else if(cc%4==3) { D(); CCR(); }
  }


// Bottom Layer Corner Pieces and corresponding Edge Pieces (F2L) : -
  {
   int temp=0;
   while(temp<6)
   {
       temp++;
    for(count_j=0;count_j<4;count_j++)
    {
      // When the required corner piece is on the top surface (relatively easier)...
      if(Corner_pcs[count_j][0]==5 || Corner_pcs[count_j][0]==6 || Corner_pcs[count_j][0]==7 || Corner_pcs[count_j][0]==8)
      {
          while(Corner_pcs[count_j][0]!=6)
          {
              U();
          }

        if(Corner_pcs[count_j][1]==1)
        {
            switch(Edge_pcs[count_j+4][0])
            {
               case 5 : if(Edge_pcs[count_j+4][1]==Corner_pcs[count_j][2]) { CCL(); Ui(); R(); U(); Ri(); CCL(); U(); Ri(); Ui(); R(); CCR(); CCR(); }
                        else { CCL(); Ui(); R(); Ui(); Ri(); U(); U(); R(); Ui(); Ri(); CCR(); }
                        break;
               case 9 : if(Edge_pcs[count_j+4][1]==Corner_pcs[count_j][2]) { CCL(); U(); R(); Ui(); Ri(); CCR(); }
                        else { CCL(); Ui(); R(); U(); U(); R(); Ui(); CCL(); Ri(); Ui(); R(); CCR(); CCR(); }
                        break;
               case 10 : if(Edge_pcs[count_j+4][1]==Corner_pcs[count_j][2]) { CCL(); Ui(); R(); U(); Ri(); U(); U(); R(); Ui(); Ri(); CCR(); }
                         else { CCL(); CCL(); U(); Ri(); Ui(); R(); Ui(); Ri(); Ui(); R(); CCR(); CCR(); }
                         break;
               case 11 : if(Edge_pcs[count_j+4][1]==Corner_pcs[count_j][2]) { CCL(); Ui(); R(); U(); U(); Ri(); U(); U(); R(); Ui(); Ri(); CCR(); }
                         else { CCR(); CCR(); Ri(); Ui(); R(); CCR(); CCR(); }
                         break;
               case 12 : if(Edge_pcs[count_j+4][1]==Corner_pcs[count_j][2]) { CCL(); CCL(); Ri(); U(); R(); Ui(); Ui(); CCR(); R(); U(); Ri(); CCR(); }
                         else { CCL(); CCL(); U(); Ri(); U(); R(); Ui(); Ri(); Ui(); R(); CCR(); CCR(); }
                         break;
               default : break;
            }
        }
        else if(Corner_pcs[count_j][2]==1)
        {
            switch(Edge_pcs[count_j+4][0])
            {
               case 5 : if(Edge_pcs[count_j+4][1]==Corner_pcs[count_j][1]) { CCL(); CCL(); U(); Ri(); U(); R(); U(); U(); Ri(); U(); R(); CCR(); CCR(); }
                        else { CCL(); CCL(); U(); Ri(); U(); R(); U(); U(); Ri(); U(); R(); CCR(); CCR(); }
                        break;
               case 9 : if(Edge_pcs[count_j+4][1]==Corner_pcs[count_j][1]) { CCL(); R(); Ui(); Ri(); U(); U(); CCL(); Ri(); Ui(); R(); CCR(); CCR(); }
                        else { CCL(); Ui(); R(); Ui(); Ri(); U(); R(); U(); Ri(); CCR(); }
                        break;
               case 10 : if(Edge_pcs[count_j+4][1]==Corner_pcs[count_j][1]) { CCL(); CCL(); U(); Ri(); U(); U(); R(); U(); U(); Ri(); U(); R(); CCR(); CCR(); }
                         else { CCL(); R(); U(); Ri(); CCR(); }
                         break;
               case 11 : if(Edge_pcs[count_j+4][1]==Corner_pcs[count_j][1]) { CCL(); CCL(); U(); Ri(); Ui(); R(); U(); U(); Ri(); U(); R(); CCR(); CCR(); }
                         else { CCL(); Ui(); R(); U(); Ri(); U(); R(); U(); Ri(); CCR(); }
                         break;
               case 12 : if(Edge_pcs[count_j+4][1]==Corner_pcs[count_j][1]) { CCL(); f(); Ri(); Fi(); R(); CCR(); }
                         else { CCL(); Ri(); U(); U(); R(); R(); U(); R(); R(); U(); R(); CCR(); }
                         break;
               default : break;
            }
        }
        else if(Corner_pcs[count_j][3]==1)
        {
            switch(Edge_pcs[count_j+4][0])
            {
               case 5 : if(Edge_pcs[count_j+4][1]==Corner_pcs[count_j][1]) { CCL(); R(); Ui(); Ri(); CCL(); U(); Ri(); U(); R(); CCR(); CCR(); }
                        else { CCL(); R(); U(); Ri(); Ui(); R(); U(); Ri(); Ui(); R(); U(); Ri(); CCR(); }
                        break;
               case 9 : if(Edge_pcs[count_j+4][1]==Corner_pcs[count_j][1]) { CCL(); R(); U(); U(); Ri(); Ui(); R(); U(); Ri(); CCR(); }
                        else { CCL(); Ui(); R(); U(); U(); Ri(); CCL(); Ri(); U(); U(); R(); Ui(); Ri(); U(); R(); CCR(); CCR(); }
                        break;
               case 10 : if(Edge_pcs[count_j+4][1]==Corner_pcs[count_j][1]) { CCL(); U(); R(); U(); U(); Ri(); U(); R(); Ui(); Ri(); CCR(); }
                         else { CCL(); CCL(); U(); U(); Ri(); Ui(); R(); Ui(); Ri(); U(); R(); CCR(); CCR(); }
                         break;
               case 11 : if(Edge_pcs[count_j+4][1]==Corner_pcs[count_j][1]) { CCL(); U(); U(); R(); U(); Ri(); U(); R(); Ui(); Ri(); CCR(); }
                         else { CCL(); CCL(); Ui(); Ri(); U(); U(); R(); Ui(); Ri(); U(); R(); CCR(); CCR(); }
                         break;
               case 12 : if(Edge_pcs[count_j+4][1]==Corner_pcs[count_j][1]) { CCL(); CCL(); U(); Ri(); U(); U(); R(); CCR(); R(); U(); U(); Ri(); U(); R(); Ui(); Ri(); CCR(); }
                         else { CCL(); CCL(); Ri(); U(); U(); R(); U(); Ri(); Ui(); R(); CCR(); CCR(); }
                         break;
               default : break;
            }
        }
      }

      // When the required corner piece is in the bottom surface...
      else
      {
        if(Corner_pcs[count_j][0]==1)
        {
          if(Corner_pcs[count_j][1]==1)
          {
            switch(Edge_pcs[count_j+4][0])
            {
                case 5 : if(Edge_pcs[count_j+4][2]==Corner_pcs[count_j][2]) { CCL(); R(); Ui(); Ri(); U(); CCL(); Ri(); U(); U(); R(); U(); U(); Ri(); U(); R(); CCR(); CCR(); }
                         break;
                case 9 : if(Edge_pcs[count_j+4][1]==Corner_pcs[count_j][3]==1) { U(); Li(); Ui(); L(); Ui(); f(); U(); Fi(); }
                         else { CCL(); U(); U(); R(); U(); Ri(); U(); Fi(); Ui(); f(); CCR(); }
                         break;
                case 10 : if(Edge_pcs[count_j+4][1]==Corner_pcs[count_j][3]==1) { Li(); Ui(); L(); Ui(); f(); U(); Fi(); }
                          else { CCL(); U(); R(); U(); Ri(); U(); Fi(); Ui(); f(); CCR(); }
                          break;
                case 11 : if(Edge_pcs[count_j+4][1]==Corner_pcs[count_j][3]==1) { Ui(); Li(); Ui(); L(); Ui(); f(); U(); Fi(); }
                          else { CCL(); R(); U(); Ri(); U(); Fi(); Ui(); f(); CCR(); }
                          break;
                case 12 : if(Edge_pcs[count_j+4][1]==Corner_pcs[count_j][3]==1) { U(); U(); Li(); Ui(); L(); Ui(); f(); U(); Fi(); }
                          else { CCL(); Ui(); R(); U(); Ri(); U(); Fi(); Ui(); f(); CCR(); }
                          break;
                default : break;
            }
          }
          else if(Corner_pcs[count_j][2]==1)
          {
            switch(Edge_pcs[count_j+4][0])
            {
                case 5 : if(Edge_pcs[count_j+4][1]==Corner_pcs[count_j][1]) { CCL(); R(); Ui(); Ri(); CCL(); U(); Ri(); Ui(); R(); Ui(); Ri(); Ui(); R(); CCR(); CCR(); }
                         else { CCL(); R(); Ui(); Ri(); Ui(); R(); U(); Ri(); U(); U(); R(); Ui(); Ri(); CCR(); }
                         break;
                case 9 : if(Edge_pcs[count_j+4][1]==Corner_pcs[count_j][1]==1) { CCL(); R(); Ui();Ri(); U(); R(); Ui(); Ri(); CCR(); }
                         else { CCL(); CCL(); U(); Ri(); Ui(); R(); U(); Ri(); Ui(); R(); CCR(); CCR(); }
                         break;
                case 10 : if(Edge_pcs[count_j+4][1]==Corner_pcs[count_j][1]==1) { CCL(); U(); R(); Ui();Ri(); U(); R(); Ui(); Ri(); CCR(); }
                          else { CCL(); CCL(); U(); U(); Ri(); Ui(); R(); U(); Ri(); Ui(); R(); CCR(); CCR(); }
                          break;
                case 11 : if(Edge_pcs[count_j+4][1]==Corner_pcs[count_j][1]==1) { CCL(); U(); U(); R(); Ui();Ri(); U(); R(); Ui(); Ri(); CCR(); }
                          else { CCL(); CCL(); Ui(); Ri(); Ui(); R(); U(); Ri(); Ui(); R(); CCR(); CCR(); }
                          break;
                case 12 : if(Edge_pcs[count_j+4][1]==Corner_pcs[count_j][1]==1) { CCL(); Ui(); R(); Ui();Ri(); U(); R(); Ui(); Ri(); CCR(); }
                          else { CCL(); CCL(); Ri(); Ui(); R(); U(); Ri(); Ui(); R(); CCR(); CCR(); }
                          break;
                default : break;
            }
          }
          else
          {
            switch(Edge_pcs[count_j+4][0])
            {
                case 5 : if(Edge_pcs[count_j+4][1]==Corner_pcs[count_j][1]) { CCL(); R(); U(); Ri(); U(); U(); R(); Ui(); Ri(); U(); R(); U(); Ri(); CCR(); }
                         else { CCL(); R(); U(); Ri(); Ui(); R(); Ui(); Ri(); U(); U(); CCL(); Ri(); Ui(); R(); CCR(); CCR(); }
                         break;
                case 9 : if(Edge_pcs[count_j+4][1]==Corner_pcs[count_j][1]==1) { CCL(); CCL(); U(); Ri(); U(); R(); Ui(); Ri(); U(); R(); CCR(); CCR(); }
                         else { CCL(); R(); U(); Ri(); Ui(); R(); U(); Ri(); CCR(); }
                         break;
                case 10 : if(Edge_pcs[count_j+4][1]==Corner_pcs[count_j][1]==1) { CCL(); CCL(); U(); U(); Ri(); U(); R(); Ui(); Ri(); U(); R(); CCR(); CCR(); }
                          else { CCL(); U(); R(); U(); Ri(); Ui(); R(); U(); Ri(); CCR(); }
                          break;
                case 11 : if(Edge_pcs[count_j+4][1]==Corner_pcs[count_j][1]==1) { CCL(); CCL(); Ui(); Ri(); U(); R(); Ui(); Ri(); U(); R(); CCR(); CCR(); }
                          else { CCL(); U(); U(); R(); U(); Ri(); Ui(); R(); U(); Ri(); CCR(); }
                          break;
                case 12 : if(Edge_pcs[count_j+4][1]==Corner_pcs[count_j][1]==1) { CCL(); CCL(); Ri( ); U(); R(); Ui(); Ri(); U(); R(); CCR(); CCR(); }
                          else { CCL(); Ui(); R(); U(); Ri(); Ui(); R(); U(); Ri(); CCR(); }
                          break;
                default : break;
            }
          }
        }
        else
        {
          switch(Corner_pcs[count_j][0])
          {
              case 2 : R(); U(); Ri(); break;
              case 3 : Ri(); Ui(); R(); break;
              case 4 : Bi(); Ui(); B(); break;
              default : break;
          }
        }
      }
      CCR();
    }
   }
  }


// Changing Centre Back to Home position...
  {
  if(cc%4==1) { CCL(); }
  else if(cc%4==2) { CCR(); CCR(); }
  else if(cc%4==3) { CCR(); }
  }


/*

//Solving the 3rd Layer : -
 {

// Making Top Cross : -
  {

    if(Edge_pcs[8][1]*Edge_pcs[9][1]*Edge_pcs[10][1]*Edge_pcs[11][1] == 1296)
    {
        f(); U(); R(); Ui(); Ri(); Fi();
    }

    if(Edge_pcs[8][2]*Edge_pcs[9][2]*Edge_pcs[10][2]*Edge_pcs[11][2] != 1296)
    {
        for(count_i=8;count_i<12;count_i++)
        {
            if(Edge_pcs[count_i][2]==6)
            {
                for(count_j=count_i+1;count_j<12;count_j++)
                {
                    if(Edge_pcs[count_j][2]==6)
                    {
                        switch(Edge_pcs[count_i][0]*Edge_pcs[count_j][0])
                        {
                            case 90: B(); U(); L(); Ui(); Li(); Bi(); break;
                            case 110: L(); U(); f(); Ui(); Fi(); Li(); break;
                            case 132: f(); U(); R(); Ui(); Ri(); Fi(); break;
                            case 108: R(); U(); B(); Ui(); Bi(); Ri(); break;
                            case 120: f(); R(); U(); Ri(); Ui(); Fi(); break;
                            case 99: R(); B(); U(); Bi(); Ui(); Ri(); break;
                        }
                    }
                }
            }
        }
    }
  }

// Orienting Cross : -
  {
     if(Edge_pcs[9][0]-Edge_pcs[8][0]==1 || Edge_pcs[8][0]-Edge_pcs[9][0]==3)
     {
         while(Edge_pcs[8][0]!=9) { U(); }
         if(Edge_pcs[10][0]==12)
         {
             f(); U(); Fi(); U(); f(); U(); U(); Fi(); U();
         }
     }
     else if(Edge_pcs[9][0]-Edge_pcs[8][0]==2 || Edge_pcs[8][0]-Edge_pcs[9][0]==2)
     {
         while(Edge_pcs[8][0]!=9) { U(); }
         if(Edge_pcs[11][0]==12)
         {
             U(); B(); U(); Bi(); U(); B(); U(); U(); Bi();
         }
         else
         {
             R(); U(); U(); Ri(); Ui(); R(); Ui(); Ri();
         }
     }
     else
     {
         while(Edge_pcs[8][0]!=9) { U(); }
         if(Edge_pcs[11][0]==11)
         {
             R(); U(); Ri(); U(); R(); U(); U(); Ri();
         }
         else
         {
             R(); U(); Ri(); U(); R(); U(); U(); Ri(); f(); U(); Fi(); U(); f(); U(); U(); Fi(); U();
         }
     }
  }

// Orienting Corner Pieces : -
  {
     while(1)
     {
      count_j=0;
      count_k=1;
       for(count_i=4;count_i<8;count_i++)
       {
           if(Corner_pcs[count_i][0]==(count_i+1))
           {
              count_j++; count_k=count_k*(count_i+1);
           }
       }
       if(count_j==1)
       {
          switch(count_k)
          {
              case 6:
               // if(Edge_pcs[6][0]==8)
                    { U(); f(); Ui(); Bi(); U(); Fi(); Ui(); B(); }
               // else { }
                break;
              case 7:
               // if(Edge_pcs[6][0]==8)
                    { U(); R(); Ui(); Li(); U(); Ri(); Ui(); L(); }
               // else { }
                break;
              case 8:
               // if(Edge_pcs[5][0]==8)
                    { U(); B(); Ui(); Fi(); U(); Bi(); Ui(); f(); }
               // else { }
                break;
              case 5:
               // if(Edge_pcs[5][0]==7)
                    { U(); L(); Ui(); Ri(); U(); Li(); Ui(); R(); }
               // else { }
                break;
          }
       }
       else if(count_j==0)
       {
           U(); R(); Ui(); Li(); U(); Ri(); Ui(); L();
       }
       else if(count_j==2)
       {
           switch(count_k)
           {
              case 40: Ui(); Ri(); f(); Ri(); B(); B(); R(); Fi(); Ri(); B(); B(); R(); R(); U();
                       break;
              case 30: Ri(); f(); Ri(); B(); B(); R(); Fi(); Ri(); B(); B(); R(); R();
                       break;
              case 42: U(); Ri(); f(); Ri(); B(); B(); R(); Fi(); Ri(); B(); B(); R(); R(); Ui();
                       break;
              case 56: Li(); B(); Li(); f(); f(); L(); Bi(); Li(); f(); f(); L(); L();
                       break;
              case 48: Ri(); f(); Ri(); B(); B(); R(); Fi(); Ri(); B(); B(); R(); R();
                       break;
              case 35: Ri(); f(); Ri(); B(); B(); R(); Fi(); Ri(); B(); B(); R(); R();
                       break;
           }
       }
       if(count_j==4)
         break;
     }

  }

// Turning of the Corner Pieces : -
  {
    while(1)
    {
     if(Corner_pcs[4][3]*Corner_pcs[5][3]*Corner_pcs[6][3]*Corner_pcs[7][3] != 1296)
     {
        for(count_I=4;count_I<8;count_I++)
        {
            if(Corner_pcs[count_I][3]!=6)
            {
                while(Corner_pcs[count_I][0]!=7) { Ui(); }
                while(1)
                {
                  if(Corner_pcs[count_I][0]==7 && Corner_pcs[count_I][3]==6) break;
                  Ri(); Di(); R(); D();
                }
            }
        }
     }
     else break;
    }
  }

// Final Move!!! : -
  while(Edge_pcs[8][0]!=9) { U(); }

 }

*/

  strcpy(in,output);
  return out_count;


/* Block for Printing the values of final position of cube...
 {
     cout<<endl;
  for(count_i=0;count_i<12;count_i++)
  {
      cout<<Edge_pcs[count_i][0]<<" "<<Edge_pcs[count_i][1]<<" "<<Edge_pcs[count_i][2]<<"\n";
  }
  cout<<endl;
  for(count_i=0;count_i<8;count_i++)
  {
      cout<<Corner_pcs[count_i][0]<<" "<<Corner_pcs[count_i][1]<<" "<<Corner_pcs[count_i][2]<<" "<<Corner_pcs[count_i][3]<<"\n";
  }
 }

cout<<endl<<"\n\nCongratulations Sir!!"<<endl<<"Your Algorithm has solved the Rubik's Cube!\n\n";
*/


}
