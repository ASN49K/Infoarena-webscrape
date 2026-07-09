#include <fstream>

using namespace std;
long long int euclid(long long int a, long long int b)
{
    long long int c;
    while (b) {
        c = a % b;
        a = b;
        b = c;
    }
    return a;
}
int main()
{   long long int i=0,n,x,y;
ifstream fin("euclid2.in");
ofstream fout("euclid2.out");
      fin>>n;
       while(i<n)
       {
           i++;
           fin>>x>>y;
            fout<<euclid(x,y)<<endl;
       }

    return 0;
}
