#include<iostream>
#include<fstream>
using namespace std;
int main()
{int a,b,nr;
ifstream f("euclid2.in");
ofstream t("euclid2.out");
f>>nr; 
while(nr!=0){ f>>a; f>>b;
while(a!=b)
	if(a>b)a=a-b; else b=b-a;
t<<a<<endl; nr--;
}
return 0;
}
