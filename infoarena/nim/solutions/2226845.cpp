#import<fstream>
std::ifstream f("nim.in");std::ofstream g("nim.out");
main()
{
    int T,N,x,S;

    for(f>>T;T--;puts(S?"DA":"NU"))
    {
        f>>N;

        for(S=0;N--;S^=x)f>>x;
    }
}
