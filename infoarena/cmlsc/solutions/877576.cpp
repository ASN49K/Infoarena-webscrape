#include <fstream>
#include <vector>

using std::endl;
using std::vector;

vector <int> a,b,x;
int N,M;

void lcs(int pos)
{
    vector<int> temp;
    for (int j = pos; j < M; ++j)
        for (int i = 0; i < N; ++i)
    if (b[j] == a[i]) {
        temp.push_back(b[j]);
        j++;
    }

    if (temp.size() > x.size() )
    {
        x.clear();
        for (int i = 0; i < temp.size(); ++i)
        x.push_back(temp[i]);
    }
}



int main()
{
    std::ifstream in("cmlsc.in");
    std::ofstream out("cmlsc.out");


    in >> N >> M;
    a.resize(N); b.resize(M);
    for (int i = 0; i < N; ++i)
        in >> a[i];
    for (int i = 0; i < M; ++i)
        in >> b[i];

    for (int i = 0; i < M; ++i)
        lcs(i);

    out << x.size() << endl;
    for (int i = 0; i < x.size(); ++i)
        out << x[i] << " ";

    return 0;
}
