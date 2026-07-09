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
        if(a<b){r=a;a=b;b=r;}

        do
        {
            r=a-b;
            if(r>b)
            {   r=a%b;
            }
            a=b;
            b=r;
        }
        while(b);
        fout<<a<<std::endl;     
    }
    fout.close(); 

    return 0;
}
