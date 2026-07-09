#include<fstream>
#include<stdio.h>
using namespace std;
int a,b,N;
int cmmdc(int a,int b)
{
    if(!b) return a;
    return cmmdc(b,a%b);
}
int main()
{
    ifstream in("euclid2.in");
    ofstream out("euclid2.out");
    in>>N;
    for(int i=1;i<=N;i++){
                 in>>a>>b;
                 out<<cmmdc(a,b);
                 printf("\n");
                 }
    return 0;
}
