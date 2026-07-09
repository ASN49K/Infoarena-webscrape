#include<fstream>
#include<vector>
using namespace std;
short sirM[257], sirN[257];
int M, N;

int main()
{
    ifstream fin("cmlsc.in");
    fin>>M>>N;
    for(int i = 0; i < M; i++)
    {
        short c; fin>>c;
        sirM[i] = c;
    }
    for(int i = 0; i < N; i++)
    {
        short c; fin>>c;
        sirN[i] = c;
    }

    int max = 0;
vector<int> o;
    for(int i = 0; i < N; i ++)
    {
        for(int j = 0; j < M; j ++)
        {
            if(sirN[i] == sirM[j] && sirM[j] != -1)
            {
                o.push_back(sirM[j]);
                sirM[j] = -1;
                max++;
            }
        }
    }
    ofstream fout("cmlsc.out");
    fout<<max<<endl;
    for(int i = 0; i < o.size(); i++)
    {
        fout<<o[i]<<" ";
    }
    return 0;
}
