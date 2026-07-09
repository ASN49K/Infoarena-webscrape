// CEL MAI LUNG SUBSIR COMUN

    # include <cstdio>
      using namespace std;

      int a,b;

      short A[1030][1030];
      short M[1030];
      short N[1030];

      int main()
      {

          FILE * f = fopen ("cmlsc.in","r");
          FILE * g = fopen ("cmlsc.out","w");

          fscanf (f, "%d %d", &a, &b);

          for(int i=1;i<=a;++i) fscanf(f, "%d", &M[i]);
          for(int i=1;i<=b;++i) fscanf(f, "%d", &N[i]);

          int T=0;

          for(int i=1;i<=a;++i)
          {

            for(int j=1;j<=b;++j)
            {
              if(M[i] == N[j])
                  A[i][j]=A[i-1][j-1]+1,++T;
              else
                if (A[i-1][j] > A[i][j-1])
                      A[i][j]=A[i-1][j];

                else A[i][j]=A[i][j-1];

            }
          }

          printf("%d\n", T);

          T=0;

          for(int i=1;i<=a;++i)
            for(int j=1;j<=b;++j)
                if(T<A[i][j])
                {
                    T=A[i][j];
                    printf("%d ", M[i]);
                }


      }
