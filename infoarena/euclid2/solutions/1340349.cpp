#include<fstream>
using namespace std;
ifstream fin("euclid2.in");
ofstream fout("euclid2.out");
int Euclid(int a,int b)
{   int c;
    while(b) {c=a%b; a=b; b=c;}
    return a;
}
int main()
{   int i,x,y;
    fin>>i;
    while(i--) { fin>>x>>y;  fout<<Euclid(x,y)<<"\n";}
    fout.close();
    return 0;
}
