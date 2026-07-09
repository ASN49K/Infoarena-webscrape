#include <iostream>
#include <fstream>
using namespace std;
ifstream f("euclid2.in");
ofstream g("euclid2.out");
void rezolvare()
{
    int n,a,b;
    f>>n;
    for(int i=0;i<n;i++)
    {
        f>>a>>b;
        while(a!=b)
            if(a>b)
                a=a-b;
            else
                b=b-a;
        g<<"cmmdc este :"<<a<<endl;
    }

}
int main()
{
    ifstream f("euclid2.in");
    ofstream g("euclid2.out");
    rezolvare();
    return 0;
}
