import java.util.Scanner;
import java.io.*;

public class Main{
    public static void main(String[] args) throws Exception {
        Scanner scanner = new Scanner(new FileInputStream("cmlsc.in"));
        PrintWriter writer = new PrintWriter(new FileOutputStream("cmlsc.out"));
        int m = scanner.nextInt();
        int n = scanner.nextInt();

        int[] a = new int[m+1];
        int[] b = new int[n+1];
        int[][] d = new int[m + 1][n + 1];
        int[] sir = new int[Math.max(m, n)+1];
        int bst=0;
        
        for (int i=1;i<=m;i++) a[i] = scanner.nextInt();
        for (int i=1;i<=n;i++) b[i] = scanner.nextInt();
        scanner.close();

        for (int i=1;i<=m;i++)
            for (int j=1;j<=n;j++)
                if (a[i]==b[j]) d[i][j]=d[i-1][j-1]+1;
                else d[i][j]=(Math.max(d[i - 1][j], d[i][j - 1]));


        for(int i=m,j=n; i*j>0 ;)
            if(a[i]==b[j]){sir[bst++]=a[i]; i--; j--;}
            else if(d[i-1][j] < d[i][j-1]) j--;
                 else i--;

        writer.println(bst);
        for (int i=bst-1;i>=0;i--) writer.print(sir[i]+" ");
        writer.close();
    }
}