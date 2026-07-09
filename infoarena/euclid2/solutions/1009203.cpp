#include <fstream>
int euclid(int x, int y)
{
    int a=y;
    int b=x%y;
    if(b==0)
    {   return a;
    } 
    else 
    {
        return euclid(a,b);
    }
}
int main ()
{
    std::ifstream fin("euclid.in");
    std::ofstream fout("euclid.out");
    int n,a,b,i;
    fin>>n;
    for(i=0;i<n;i++)
    {
        fin>>a>>b;
        fout<<euclid(a,b)<<std::endl;     
    }
    fout.close(); 

    return 0;
}
