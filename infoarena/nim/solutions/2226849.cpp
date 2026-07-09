#import<fstream>
std::ifstream f("nim.in");std::ofstream g("nim.out");
main()
{
    int T,N,x,S;

    for(f>>N;f>>N;g<<(S?"DA\n":"NU\n"))
    {
        for(S=0;N--;S^=x)f>>x;
    }
}
