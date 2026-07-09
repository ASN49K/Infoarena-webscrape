#include <fstream>

using namespace std;

ifstream in("euclid2.in");
ofstream out("euclid2.out");

int main()
{
    int n,a,b,i;
    in>>n;
    for(i=0;i<n;i++)
    {
        in>>a;
        in>>b;
        while(a!=b)
            if(a>b) a-=b;
                else b-=a;
        out<<a<<"\n";
    }
    return 0;
}
