#include<iostream>
#include<fstream>
using namespace std;
ifstream in("cmmdc.in");
ofstream out("cmmdc.out");
int main(void)
{
    int a,b,c;
    in>>a;
    in>>b;
    while(b!=0)
    {
        c=a%b;
        a=b;
        b=c;
    }
    out<<a;
    in.close();
    out.close();
    return 0;
}
