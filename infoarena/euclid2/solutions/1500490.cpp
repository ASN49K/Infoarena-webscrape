#include <iostream>
#include <stdio.h>
#include <fstream>
using namespace std;
int a, b, euclid=0;
int euclid2(int a, int b);
int main()
{
    int len=0;
    ifstream in("euclid2.in");
    ofstream out("euclid2.out");
    in>>len;
    for(int i = 0;i<len;i++) {
        in>>a>>b;
        euclid = euclid2(a, b);
        out <<euclid<<endl;
    }
    in.close();
    out.close();
    return 0;
}
int euclid2(int a, int b)
{
    int temp=1;
    if(a<b)
    {
        temp = a;
        a=b;
        b=temp;
    }
    while(temp!=0)
    {
        temp = a%b;
        a=b;
        b=temp;
    }
    return a;
}
