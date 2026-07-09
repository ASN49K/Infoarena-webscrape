#include<fstream>
using namespace std;

int n,x,y;

inline void Rezolva()
{int i;
 ifstream fin("euclid2.in");
 ofstream fout("euclid2.out");
 fin>>n;
 for (i=1;i<=n;i++)
    {fin>>x>>y;
     int c;
     while (y)
        {c=x%y;
         x=y;
         y=c;
        }
     fout<<x<<"\n";
    }
 fin.close();
 fout.close();
}

int main()
{
    Rezolva();
    return 0;
}
