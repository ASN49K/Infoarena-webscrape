#include <fstream>
int main ()
{
    std::ifstream fin("euclid2.in");
    std::ofstream fout("euclid2.out");
    int n,a,b,r,i;
    fin>>n;
    for(i=0;i<n;i++)
    {
        fin>>a>>b;
        while(r=a%b)
        {
            a=b;
            b=r;
        }
        fout<<b<<std::endl;     
    }
    fout.close(); 

    return 0;
}
