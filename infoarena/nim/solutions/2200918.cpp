#include <fstream>

int main()
{
    std::fstream fin("nim.in",std::ios::in);
    std::fstream fout("nim.out",std::ios::out);
    int t;
    fin>>t;
    while(t--)
    {
        int n;
        fin>>n;

        int s=0;
        for(int i=0;i<n;i++)
        {
            int nr;
            fin>>nr;
            s^=nr;
        }

        if(s!=0)fout<<"DA"<<'\n';
        else fout<<"NU"<<'\n';
    }
}
