use std::fs;
use std::cmp;

fn main() {
    fn read() -> (Vec<i32>, Vec<i32>) {
        let text = fs::read_to_string("cmlsc.in").unwrap();
        let mut crt_line = text.lines().skip(1);
        (
            crt_line
                .next()
                .unwrap()
                .split_whitespace()
                .map(|x| x.parse::<i32>().unwrap())
                .collect(),
            crt_line
                .next()
                .unwrap()
                .split_whitespace()
                .map(|x| x.parse::<i32>().unwrap())
                .collect(),
        )
    }

    let (a, b) = read();

    let mut dp: Vec<Vec<usize>> = vec![vec![0; b.len()]; a.len()];
    for i in 0..a.len() {
        for j in 0..b.len() {
            if a[i] == b[j] {
                dp[i][j] = 1;
                if i > 0 && j > 0 {
                    dp[i][j] = cmp::max(dp[i][j], dp[i - 1][j - 1] + 1);
                }
            }
            if i > 0 {
                dp[i][j] = cmp::max(dp[i][j], dp[i - 1][j]);
            }
            if j > 0 {
                dp[i][j] = cmp::max(dp[i][j], dp[i][j - 1]);
            }
        }
    }

    let mut r: Vec<i32> = vec![0; dp[a.len() - 1][b.len() - 1]]; 
    let mut ri = dp[a.len() - 1][b.len() - 1];

    let (mut i, mut j) = (a.len() - 1, b.len() - 1); 
    loop {
        let mut max = 0;
        if i > 1 { max = cmp::max(max, dp[i - 1][j]); }
        if j > 1 { max = cmp::max(max, dp[i][j - 1]); }
        if i > 1 && j > 1 { max = cmp::max(max, dp[i - 1][j - 1]); }

        if dp[i][j] > max {
            ri -= 1;
            r[ri] = a[i];
            if ri == 0 { break; }

            i -= 1;
            j -= 1;
        }
        else if i == 0 { j -= 1; }
        else if j == 0 { i -= 1 }
        else if dp[i - 1][j] >= dp[i][j - 1] { i -= 1; }
        else { j -= 1; }
    }

    fn write(r: &Vec<i32>) {
        fs::write("cmlsc.out", r.len().to_string() + "\n" +
                  &r
                  .iter()
                  .map(|x| x.to_string())
                  .collect::<Vec<String>>()
                  .join(" ")).unwrap();
    }

    write(&r);
}
