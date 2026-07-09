#include<iostream>
#include<fstream>
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
    for(int i=1;i<=N;N++){
                 in>>a>>b;
                 out<<cmmdc(a,b)<<endl;
                 }
    in.close();
    out.close();
    return 0;
}
