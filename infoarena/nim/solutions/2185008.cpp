#include <fstream>
using namespace std;
ifstream in("nim.in");
ofstream out("nim.out");
int main()
{
    int n,nr_gram,i,success,aux;
    in>>n;//nr jocuri
    for(i=0;i<n;i++)
    {
        in>>nr_gram;//nr gramezi in jocu curent.
        success=0;
        for(int j=0;j<nr_gram;j++)
        {
            in>>aux;//gramada curenta;
            success=success^aux;
        }
        if(success==0)
            out<<"NU\n";
        else
            out<<"DA\n";
    }
    return 0;
}
