import java.io.*;
import java.util.ArrayList;
import java.util.List;
import java.util.stream.Collectors;

/**
 * Created by daniel1.macovei on 3/13/2017.
 */
public class Main {
    public static void main(String[] args) throws IOException {

        List<Integer> results = new ArrayList<>();
        try (BufferedReader reader = new BufferedReader(new FileReader("euclid2.in"))) {
            Integer n = Integer.valueOf(reader.readLine());
            for (int index = 0; index < n; index++) {
                String[] numbers = reader.readLine().split(" ");
                results.add(cmmdc(Integer.valueOf(numbers[0]), Integer.valueOf(numbers[1])));
            }
        }
        try (PrintWriter writer = new PrintWriter(new FileWriter("euclid2.out"))) {
            writer.println(results.stream().map(Object::toString).collect(Collectors.joining("\n")));
        }
    }

    private static int cmmdc(int a, int b) {

        int z;
        while (b != 0) {
            z = a;
            a = b;
            b = z % b;
        }
        return a;
    }
}
