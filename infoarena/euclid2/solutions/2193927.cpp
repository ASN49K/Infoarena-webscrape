    #include <fstream>

    using namespace std;

    ifstream fin;
    ofstream fout;

       int main()

{
        fin.open("euclid2.in");
        fout.open("euclid2.out");
       long long n, a, i, r, b;
       fin >> n;
       for(i=1; i<=n; i++)
       {
           fin >> a >> b;
           while(a%b>0)
           {
               r = a%b;
               a = b;
               b = r;
           }
           fout << b << "\n";
       }
       fout.close();
}



