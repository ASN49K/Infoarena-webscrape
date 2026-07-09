import java.util.Scanner;
import java.io.*;
public class Main{
    public static void main(String[] args) throws Exception {
        Scanner scanner = new Scanner(new FileInputStream(new File("cmlsc.in")));
        PrintWriter writer = new PrintWriter(new FileOutputStream(new File("cmlsc.out")));
        int m = scanner.nextInt();
        int n = scanner.nextInt();
        int a[] = new int[1024];
        int b[] = new int[1024];
        int d[][] = new int[1024][1024];
        int sir[] = new int[1024];
        int bst=0;
        
        for (int i=1;i<=m;i++){
            a[i] = scanner.nextInt();
        }
        for (int i=1;i<=n;i++){
            b[i] = scanner.nextInt();
        }

        for (int i=1;i<=m;i++){
            for (int j=1;j<=n;j++){
                if (a[i]==b[j]) d[i][j]=d[i-1][j-1]+1;
            else d[i][j]=Math.max(d[i-1][j],d[i][j-1]);
            }
        }

        while (n>0&m>0){
            if (a[m]==b[n]) {sir[bst++]=a[m]; m--;n--;}
            else if(d[m-1][n]<d[m][n-1]) n--;
            else m--;
        }
        writer.println(bst);
        for (int i=bst-1;i>=0;i--){
            writer.print(sir[i]+" ");

        }

        scanner.close();
        writer.close();
    }
}