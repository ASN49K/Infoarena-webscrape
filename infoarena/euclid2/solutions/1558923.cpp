#include <iostream>
#include<fstream>
using namespace std;
ifstream fin("euclid2.in");
ofstream fout("euclid2.out");
int cmmdc(int a,int b)
{if(b==0) return a;
while(a!=b)
    {if(a>b) a=a-b;
else
    b=b-a;}
    return a;

}
int main()
{int T,x,y,i;
fin>>T;
for(i=1;i<=T;i++)
{fin>>x>>y;
fout<<cmmdc(x,y)<<endl;

}

    return 0;
}
