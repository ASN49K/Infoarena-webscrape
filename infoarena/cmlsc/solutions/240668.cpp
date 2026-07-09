#include<fstream>
using namespace std;

#define d 1999999973

ifstream fin("lgput.in");
ofstream fout("lgput.out");

long long e;
int p;

long long pow(long long x,int n);

int main()
{
     fin>>e>>p;
     fout<<pow(e,p);
             
     fout.close();
     return 0;
}

long long pow(long long x, int n)
{
    long long result = 1;
    while ( n ) 
    {
        if ( n%2 ) 
            (result *= x)%=d;
        
        (x *= x)%=d;
        n /= 2;
    }
    return result;
}
