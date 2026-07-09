#include<iostream>
#include<fstream>
#include<math.h>
using namespace std;
ifstream f("euclid2.in");
ofstream fout("euclid2.out");
int minim(int a, int b)
{
    int i,j;
    for(i=a/2; i>=2; i--)
    {
        for(j=b/2; j>=2; j--)
        {
            if(a%i==0 && a%j==0)
                return i;
        }
    }
}
int gbf(int a, int b)
{
    if(!b) return a;
    else return gbf(b,a%b);

}
int main()
{
    int T, a[100],i,ok=0,j;
    f>>T;
    for(i=1; i<=T*2; i++)
    {
        f>>a[i];
    }
    for(i=1; i<=T*2; i=i+2)
    {
        fout<<gbf(a[i],a[i+1])<<" ";
    }
    cout<<111%20991;




}
