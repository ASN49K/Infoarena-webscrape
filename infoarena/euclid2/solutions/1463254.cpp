#include <iostream>
#include<fstream.h>

using namespace std;

int cmmdc(int a, int b){

   if(b==0) return a;
   else return cmmdc(b, a%b);


}

ifstream fin("euclid2.in");
ofstream fout("euclid2.out");
int main()
{
    int a, b, r;
    fin>>a;
    fin>>b;

    while(b){

        r=a%b;

        a=b;
        b=r; }

    fout<<a;

    //cout<<cmmdc(a,b);
    fin.close();
    fout.close();

    return 0;
}
