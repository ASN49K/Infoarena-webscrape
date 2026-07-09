#include <fstream>

using namespace std;

int main()
{   long long int i=0,n,a,b,c;
ifstream fin("euclid2.in");
ofstream fout("euclid2.out");
      fin>>n;
       for(i=1;i<=n;++i)
       {
           fin>>a>>b;
           while (b) {
        c = a % b;
        a = b;
        b = c;
    }
            fout<<a<<endl;
       }

    return 0;
}
