#include <iostream>
#include <fstream>
using namespace std;
ifstream fin("euclid2.in");
ofstream fout("euclid2.out");
 unsigned t,a,b,i;
void cmd(int a,int b)
{
    if(b==0)
        {fout<<a;
        fout<<"\n";}
    else if(a>b)
    cmd(b,a%b);
    else
    cmd(a,b%a);
}
int main()
{
fin>>t;
for(i=1;i<=t;i++)
{
    fin>>a>>b;
    cmd(a,b);
}
fin.close();
fout.close();
    return 0;
}
