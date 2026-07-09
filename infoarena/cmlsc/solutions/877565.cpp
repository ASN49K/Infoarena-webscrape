#include <fstream>
#include <vector>

using std::endl;
using std::vector;



int main()
{
    std::ifstream in("cmlsc.in");
    std::ofstream out("cmlsc.out");

    int N,M;
    vector <int> a,b;
    in >> N >> M;
    a.resize(N); b.resize(M);
    for (int i = 0; i < N; ++i)
        in >> a[i];
    for (int i = 0; i < M; ++i)
        in >> b[i];

    vector <int> x;
    int j = 0;
    for ( j = 0; j < M; ++j ){
    for (int i = 0; i < N; i++)
        if (a[N - 1 - i] == b[M - 1 - j])
        {
            x.push_back(a[N - 1 - i]);
            a.erase(a.begin() + N - i - 1);
            ++j;
        }
    }

 /*   for (int i = 0; i < a.size(); ++i)
        out << a[i] << " ";
    out << endl;
    for (int j = 0; j < b.size(); ++j)
        out << b[j] << " ";
    out << endl; */
    out << x.size() << endl;
    for (int i = x.size() - 1; i >= 0; --i)
        out << x[i] << " ";

    return 0;
}
