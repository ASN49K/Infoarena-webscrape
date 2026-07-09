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
        while (sc.hasNextLine()) {
            inputData.add(sc.nextLine());
        }
        sc.close();

        int numOfPairs = Integer.valueOf(inputData.get(0));


        PrintWriter writer = new PrintWriter("euclid2.out");
        for (int i = 1; i <= numOfPairs; i++) {
            String[] splited = inputData.get(i).split("\\s+");
            writer.println(euclidRecurisv(Integer.valueOf(splited[0]), Integer.valueOf(splited[1])));
        }
        writer.close();
    }
}
