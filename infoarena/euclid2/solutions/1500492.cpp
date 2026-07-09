#include <iostream>
#include <fstream>
using namespace std;
int a, b;
int euclid(int a,int b)
{
    if(!b)
        return a;
    return euclid(b, a%b);
}
int main()
{
    int len=0;
    ifstream in("euclid2.in");
    ofstream out("euclid2.out");
    in>>len;
    for(int i = 0;i<len;i++) {
        in>>a>>b;
        out <<euclid(a,b);
        out<< endl;
    }
    in.close();
    out.close();
    return 0;
}

/*
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
*/
