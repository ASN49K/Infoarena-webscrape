#include<iostream>
#include<fstream.h>

using namespace std;

int main()
{int A,B,R,N,I;
 ifstream F("euclid2.in");
 ofstream G("euclid2.out");
 F>>N;
 for(I=1;I<=N;I++)
 {F>>A;
  F>>B;
  while(B!=0)
	 {R=A%B;A=B;B=R;}
    G<<A<<endl;
 }
  
return 0;
}