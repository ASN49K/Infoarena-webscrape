#include <fstream>

std::ifstream f("nim.in");
std::ofstream g("nim.out");


int main()
{
    int query; f>>query;
    for(int i, N, xOr, x; query; query--) {
    f>>N;

    xOr = 0;
    for(i=0; i<N; i++)
        f>>x, xOr = xOr ^ x;

    if(xOr == 0) g<<"NU\n";
    else g<<"DA\n";
    }


    f.close();
    g.close();

    return 0;
}
