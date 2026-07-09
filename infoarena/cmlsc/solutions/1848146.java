import java.io.BufferedWriter;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.util.LinkedList;
import java.util.List;
import java.util.Scanner;

class Main {

	public static void main(String[] args) throws IOException {
		try(FileReader freader = new FileReader("cmlsc.in");
			Scanner scanner = new Scanner(freader)){
			int M = scanner.nextInt();
			int N = scanner.nextInt();
			int X[] = new int[M];
			int Y[] = new int[N];
			
			for(int i=0;i<M;i++) {
				X[i] = scanner.nextInt();
			}
			
			for(int i=0;i<N;i++) {
				Y[i] = scanner.nextInt();
			}
			
			int [][] lcs = new int[M][N];
			for(int i=0;i<M;i++) {
				for(int j=0;j<N;j++) {
					if(X[i] == Y[j]) {
						lcs[i][j] = i == 0 || j == 0? 1: lcs[i-1][j-1] + 1;
					} else {
						lcs[i][j] = Math.max(i == 0? 0: lcs[i-1][j], j == 0? 0: lcs[i][j-1]);
					}
				}
			}
			
			List<Integer> road = new LinkedList<>();
			int currentX = M-1,
				currentY = N-1,
				length = lcs[currentX][currentY];
			
			while(length > 0) {
				if(X[currentX] == Y[currentY]) {
					road.add(currentX);
					--currentX;--currentY;
					--length;
				} else {
					if((currentX == 0? 0 : lcs[currentX-1][currentY]) > (currentY == 0? 0: lcs[currentX][currentY-1])) {
							--currentX;
					} else {
						if(currentY > 0) {
							--currentY;
						}
					}
				}
			}
			
			try(FileWriter fwriter = new FileWriter("cmlsc.out");
				BufferedWriter bwriter = new BufferedWriter(fwriter)) {
				bwriter.write(String.valueOf(lcs[M-1][N-1]));
				bwriter.newLine();
				for(int i=road.size()-1;i>=0;--i) {
					bwriter.write(String.valueOf(X[road.get(i)]));
					if(i!=0) {
						bwriter.write(" ");
					}
				}
				bwriter.newLine();
			}
			
		}
		
	}

}
