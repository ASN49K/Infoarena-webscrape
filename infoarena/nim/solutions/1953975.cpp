#include <iostream>
#include <fstream>

using namespace std;

ifstream fin("nim.in");
ofstream fout("nim.out");

int T,N,win;

int main()
{
    fin>>T;

    while(T--)
    {
        fin>>N;
        win=0;

        for(int i=1;i<=N;i++)
          {
            int x;
            fin>>x;

            win=win^x;
          }
        if(win!=0)
           fout<<"DA";
        else
           fout<<"NU";
        fout<<"\n";
    }

    return 0;
}
