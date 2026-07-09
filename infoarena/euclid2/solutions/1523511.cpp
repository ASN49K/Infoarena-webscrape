#include<iostream>
#include<fstream>
using namespace std;
ifstream fin("cmmdc.in");
ofstream fout("cmmdc.out");
int a,b;
void citire ()
{
    fin>>a>>b;
}
int prelucrare (int a,int b)
{
    while(a!=b)
    {
        if (a>b)
            a=a-b;
        if (a<b)
            b=b-a;
        if (a==b)
        {
            break;
        }
    }
    if (a==1)
        return 0;
    else
        return a;
}
int main()
{
    citire();
    fout<<prelucrare(a,b);
}
