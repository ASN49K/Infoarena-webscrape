#include<iostream>
#include<fstream>
using namespace std;
int main()
{int a,b,nr,r=1;
ifstream f("euclid2.in");
ofstream t("euclid2.out");
f>>nr; 
while(nr!=0){ f>>a; f>>b; r=1;
while(r!=0){
	r=a%b; cout<<r<<" "; a=b;  b=r;
}cout<<endl;
t<<a<<endl; nr--;
}
return 0;
}
