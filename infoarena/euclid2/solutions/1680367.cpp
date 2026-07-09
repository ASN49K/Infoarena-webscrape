#include<iostream>
#include<fstream>
#include<math.h>
using namespace std;
ifstream f("euclid2.in");
ofstream fout("euclid2.out");
int gbf(int a, int b)
{
    if(!b) return a;
    else return gbf(b,a%b);

}
int main()
{
    int T,i,a,b;
    f>>T;
    for(; T; --T)
    {
        f>>a>>b;
        fout<<gbf(a,b)<<" ";
    }





}
