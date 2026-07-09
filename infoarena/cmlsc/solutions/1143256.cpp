#include<fstream>
using namespace std;
int main()
{
    ifstream intrare("cmlsc.in");
    ofstream iesire("cmlsc.out");
    int M,N,i,sir[1025],nre[1025],i2,max=0,nr_bune[1024],index=0;
    intrare>>M>>N;
    for(i=1;i<=M;i++)
        intrare>>sir[i];
    for(i=1;i<=N;i++)
        intrare>>nre[i];
    for(i2=1;i2<=N;i2++)
    {
        for(i=1;i<=M;i++)
        {
            if(sir[i]==nre[i2])
            {
                index++;
                max++;
                nr_bune[index]=sir[i];
            }
        }
    }
    iesire<<max<<endl;
    if(index!=0)
    {
    for(i=1;i<=index;i++)
        iesire<<nr_bune[i]<<" ";
    }
    intrare.close();
    iesire.close();
    return 0;
}
