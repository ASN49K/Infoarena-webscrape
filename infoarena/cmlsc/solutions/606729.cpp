#include<fstream>
#include<vector>
using namespace std;
#define fileIn "cmlsc.in"
#define fileOut "cmlsc.out"
int n, m;
struct number
{
    int value, slot1, slot2;
};
vector<int> N, M, S;
//vector<number> S;
int read()
{
    ifstream fin(fileIn);
    fin>>n>>m;
    N.reserve(n);
    M.reserve(m);
    for(int i = 0; i < n; i++)
    {
        int num;
        fin>>num;
        N.push_back(num);
    }
    for(int i = 0; i < m; i++)
    {
        int num;
        fin>>num;
        M.push_back(num);
    }
    fin.close();
    return 0;
}

int dinamica()
{
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < m; j++)
        {
            if(N[i] == M[j] && M[j] != -1)
            {
                /*number n;
                n.value = M[j];
                n.slot1 = i;
                n.slot2 = j;

                S.push_back(n);*/
                S.push_back(M[j]);
                M[j] = -1;
                break;
            }
        }
    }
    return 0;
}
int verify()
{

}
int save()
{
    ofstream fout(fileOut);
    fout<<S.size()<<"\n";
    for(int i = 0; i < S.size(); i++)
        fout<<S[i]<<" ";
        //fout<<S[i].value<<" ";
    fout<<endl;
    return 0;
}
int main()
{
    read();
    dinamica();
    save();
    return 0;
}
