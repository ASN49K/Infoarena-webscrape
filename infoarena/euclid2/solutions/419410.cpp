


#include<iostream>
using namespace std;
#include<fstream>
ifstream f("euclid2.in.txt");
ofstream g("euclid2.out.txt");
int cmmdc(int a, int b)
{  int r;
    r = a % b;
      while(r != 0)
       {
         a = b;
         b = r;
         r = a % b;
      }
	  return b;
}

int main()
{ int n,i,a,b;
f>>n;
cout<<n;
for(i=0;i<n;i++)
{
f>>a;f>>b;
cout<<a<<" ,"<<b;
g<<cmmdc(a,b);
g<<endl;
}
f.close();
g.close();
	return 0;
}

