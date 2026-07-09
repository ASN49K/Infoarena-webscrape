import java.io.*;
import java.util.Scanner;


public final class Main {

    public static void main(String[] args) throws IOException {
        int m,n;
        int[] a,b,rez;
        int[][] s;
        Scanner in = new Scanner(new FileReader("cmlsc.in"));
        FileWriter out = new FileWriter("cmlsc.out");
        m = in.nextInt();
        a = new int[m+1];
        n = in.nextInt();
        b = new int[n+1];
        s = new int[m+1][n+1];
        for(int i=1; i<=m; i++)
            a[i] = in.nextInt();
        for(int i=1; i<=n; i++)
            b[i] = in.nextInt();

        for(int i=1; i<=m; i++)
            for(int j=1; j<=n; j++)
                if(a[i]==b[j])
                    s[i][j] = 1+s[i-1][j-1];
                else
                    s[i][j] = (Math.max(s[i - 1][j], s[i][j - 1]));

        int count=0;
        rez = new int[(Math.max(m, n))];
        for(int i=m,j=n; i*j>0 ;)
            if(a[i]==b[j])
            {
                rez[count++]=a[i];
                i--;
                j--;
            }
            else
            if(s[i-1][j] < s[i][j-1])
                j--;
            else
                i--;
        out.write(String.valueOf(count) + '\n');
        for(int i=count-1; i>=0; i--)
            out.write(String.valueOf(rez[i]) + ' ');

        in.close();
        out.close();
    }

}