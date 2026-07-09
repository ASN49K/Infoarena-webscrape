import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;
import java.io.*;
class cmlsc{
    public static void main(String[] args) throws Exception {
        Scanner scanner = new Scanner(new FileInputStream(new File("cmlsc.in")));
        PrintWriter writer = new PrintWriter(new FileOutputStream(new File("cmlsc.out")));
        int m = scanner.nextInt();
        int n = scanner.nextInt();
        int a[] = new int[m];
        List<Integer> b = new ArrayList<>();
        int x=0;
        int y=0;
        
        for (int i=0;i<m;i++){
            a[i] = scanner.nextInt();
        }

        for (int i=0;i<n;i++){
            x = scanner.nextInt();
            for (int j=y;j<m;j++){
                if (x==a[j]) b.add(x); y=i+1;
            }
        }

        System.out.println(b.size());
        for (int i : b) {
        System.out.print(i+" ");}

        scanner.close();
        writer.close();
    }
}