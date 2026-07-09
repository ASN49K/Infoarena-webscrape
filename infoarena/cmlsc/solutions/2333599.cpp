#include <iostream>
#include <fstream>
using namespace std;
ifstream fin("cmlsc.in");
ofstream fout("cmlsc.out");

int main()
{
    int m,n;
    fin>>m>>n;
    if(m>=1 && n<=1024)
    {
        int arr[m];
        for(int i=0; i<m; i++)
        {
            fin>>arr[i];
            if(arr[i]>256)
                return 0;
        }
        int art[n];
        for(int c=0; c<n; c++)
        {
            fin>>art[c];
            if(art[c]>256)
                return 0;
        }
        int d=0;
        int you[d];
        for(int a=0;a<m;a++)
        {
            for(int b=0;b<n;b++)
            {
                if(arr[a]==art[b])
                {
                 d++;
                 you[d-1]=arr[a];
                }
            }
        }
        fout<<d<<"\n";
        for(int g=0;g<d;g++)
        {
            fout<<you[g]<<" ";
        }
    }

    return 0;
}
