#include <fstream>
using namespace std;

fstream fin("euclid2.in",ios::in);
fstream fout("euclid2.out",ios::out);

  int x,y,r,n,i;

int cmmdc(int a, int b)
{
    int r;
    while(b)
    {
        r=a%b;
        a=b;
        b=r;
    }
    fout<<a<<"\n";
    return 1;
}

int main()
{
    fin>>n;
    for(i=1;i<=n;i++){
    fin>>x>>y;
    cmmdc(x,y);
    }
return 0;

fin.close();
fout.close();

}
