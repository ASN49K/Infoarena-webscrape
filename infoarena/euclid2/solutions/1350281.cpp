#include <fstream>

using namespace std;
//ifstream fin("euclid2.in");
FILE*fin=fopen("euclid.in","r");
//ofstream fout("euclid2.out");
FILE*fout=fopen("euclid.out","w");
int main()
{
    long n,i,a,b,r;
    //fin>>n;
    fscanf(fin,"%d",&n);
    for(i=1;i<=n;i++)
    {
        //fin>>a>>b;
        fscanf(fin,"%d %d",&a,&b);
        r=a%b;
        while(r!=0)
        {
            a=b;
            b=r;
            r=a%b;

        }
        //fout<<b<<endl;
        fprintf(fout,"%d\n",b);
    }
    return 0;
}
