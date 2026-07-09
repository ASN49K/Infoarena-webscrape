import java.io.File;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;

public class Main {

    public static int euclidRecurisv(int x, int y) {
        if (y == 0) {
            return x;
        }

        return euclidRecurisv(y, x % y);
    }

    public static void main(String[] args) throws Exception {

        List<String> inputData = new ArrayList<>();


        Scanner sc = new Scanner(new File("euclid2.in"));
        PrintWriter writer = new PrintWriter("euclid2.out");
        Integer n = Integer.valueOf(sc.nextLine());
        for (int index = 0; index < n; index++) {
            String[] numbers = sc.nextLine().split(" ");
            writer.println(euclidRecurisv(Integer.valueOf(numbers[0]), Integer.valueOf(numbers[1])));
        }
        sc.close();
        writer.close();
    }
}
