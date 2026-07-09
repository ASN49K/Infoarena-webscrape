#include <iostream>
#include <fstream>

using namespace std;

static inline unsigned gcd(unsigned x, unsigned y)
{
    if(!y) return x;
    return gcd(y, x%y);
}

char* allocFileSizeBuffer(ifstream &in)
{
    in.open("euclid2.in");
    filebuf *pbuf = in.rdbuf();
    long size = pbuf->pubseekoff(0, ios::end, ios::in);
    pbuf->pubseekpos(0, ios::in);
    char *buffer = new char[size];
    pbuf->pubsetbuf(buffer, size);
    return buffer;
}

int main()
{
    ifstream in;
    in.sync_with_stdio(false);
    ofstream out("euclid2.out");
    int n;
    in >> n;
    unsigned x, y;
    for(int i = 0; i < n; ++i)
    {
        in >> x >> y;
        out << gcd(x, y) << endl;
    }

    return 0;
}
