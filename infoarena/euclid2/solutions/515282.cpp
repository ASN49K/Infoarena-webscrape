#include <fstream>

using namespace std;

int CMMDC(int , int );

int main(int argc, char *argv[])
{
    
    ofstream fout; fout.open("euclid2.out");
    ifstream fin; fin.open("euclid2.in");
    int *p,*a,*b;
    fin>>*p;
    for(int i=0;i<*p;i++)
    {
     fin>>*a>>*b;
     fout<<CMMDC(*a,*b)<<endl;
    }
    fout.close();
    fin.close();
    return 0;
}


int CMMDC(int a, int b)
{
if (b==0) return a;
return CMMDC(b,a%b);
}