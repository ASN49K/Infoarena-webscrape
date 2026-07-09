#include<fstream>

using namespace std;
ifstream fin("nim.in");
ofstream fout("nim.out");

int N, T, xorsum, a;

void read()
{
    fin>>T;
    while(T)
    {
        T--;
        xorsum = 0;
        fin>>N;
        for(int i = 1; i <= N; i++)
        {

            fin>>a;
            xorsum = xorsum ^ a;

        }
        if(xorsum)
            fout<<"DA\n";
            else
            fout<<"NU\n";
    }
}
int main()
{
    read();
    fin.close();
    return 0;

}
