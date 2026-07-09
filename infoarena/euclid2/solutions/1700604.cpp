#include <iostream>
#include <fstream>
using namespace std;
ifstream fin("euclid2.in");
ofstream fout("euclid2.out");
void cmd(int a,int b)
{
    if(b==0)
        fout<<a<<endl;
    else if(a>b)
    cmd(b,a%b);
    else
    cmd(a,b%a);
}
void citire(int a,int b)
{
    fin>>a>>b;
    cmd(a,b);
}
int main()
{
    unsigned t,a,b,i;
fin>>t;
for(i=1;i<=t;i++)
{
    citire(a,b);
}
fin.close();
fout.close();
    return 0;
}
