
import java.io.*;
import java.util.ArrayList;
import java.util.Collection;
import java.util.Collections;
import java.util.Scanner;

public class Main {

    public static void main(String[] args) throws IOException {
        File file = new File("cmlsc.in");
        Scanner scanner = new Scanner(file);

        int na = scanner.nextInt();
        int nb = scanner.nextInt();
        ArrayList<Integer> a = new ArrayList<>();
        ArrayList<Integer> b = new ArrayList<>();
        a.add(0);
        b.add(0);
        int f;
        for (int i = 0; i < na; i++) {
            f = scanner.nextInt();
            a.add(f);
        }
        for (int i = 0; i < nb; i++) {
            f = scanner.nextInt();
            b.add(f);
        }
        ArrayList<Integer> res = LonComSubStr.LonComSubStrCalc(a, b);

        FileWriter fileWriter = new FileWriter("cmlsc.out");
        PrintWriter printWriter = new PrintWriter("cmlsc.out");

        printWriter.print(res.size() + "\n");
        for (int e : res)
            printWriter.print(e + " ");

        printWriter.close();

    }
}

class LonComSubStr {
    public static ArrayList<Integer> LonComSubStrCalc(ArrayList<Integer> a, ArrayList<Integer> b) {
        ArrayList<ArrayList<Integer>> x = new ArrayList<>();
        for (int i = 0; i < b.size(); i++) {
            x.add(new ArrayList<>(Collections.nCopies(a.size(), 0)));
        }

        for (int i = 1; i < b.size(); i++) {
            for (int j = 1; j < a.size(); j++) {

                if (b.get(i).equals(a.get(j))) {
                    x.get(i).set(j, x.get(i - 1).get(j - 1) + 1);
                } else {
                    x.get(i).set(j, Math.max(x.get(i - 1).get(j), x.get(i).get(j - 1)));
                }
            }
        }
        ArrayList<Integer> sol = new ArrayList<>();
        int i = b.size() - 1, j = a.size() - 1;
        while (x.get(i).get(j) != 0) {
            if (!b.get(i).equals(a.get(j))) {
                if (x.get(i).get(j).equals(x.get(i - 1).get(j))) i--;
                else j--;
            } else {
                sol.add(b.get(i));
                i--;
                j--;
            }
        }
        Collections.reverse(sol);
        return sol;
    }
}
