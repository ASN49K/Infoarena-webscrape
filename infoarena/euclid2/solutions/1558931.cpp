#include <iostream>
#include<fstream>
using namespace std;
ifstream fin("euclid2.in");
ofstream fout("euclid2.out");
int cmmdc(long int a,long int b)
{if(b==0) return a;
return cmmdc(b, a % b);
}
int main()
{int T,i;
long int x,y;
fin>>T;
for(i=1;i<=T;i++)
{fin>>x>>y;
fout<<cmmdc(x,y)<<endl;

}

    return 0;
}
