use std::fs::File;
use std::io::{BufWriter, Write};
use std::{fs, io};

macro_rules! parse_line {
    ($iter : expr, $($t:ty),+)=>{{
        let line = $iter.next().unwrap();
        let mut parts = line.split_whitespace();
        ($(parts.next().unwrap().parse::<$t>().unwrap()),+)
    }};

}
macro_rules! parse_vector {
    ($iter : expr, $t:ty) => {{
        $iter
            .next()
            .unwrap()
            .split_whitespace()
            .map(|x| x.parse::<$t>().unwrap())
            .collect::<Vec<$t>>()
    }};
}
fn main() -> Result<(), io::Error> {
    let content = fs::read_to_string("cmlsc.in")?;
    let mut lines = content.lines();
    let (n, m) = parse_line!(lines, usize, usize);
    let a = parse_vector!(lines, i32);
    let b = parse_vector!(lines, i32);
    let mut dp: Vec<Vec<i32>> = vec![vec![0; m + 1]; n + 1];
    for i in 1..n + 1 {
        for j in 1..m + 1 {
            dp[i][j] = std::cmp::max(dp[i][j - 1], dp[i - 1][j]);
            if a[i - 1] == b[j - 1] {
                dp[i][j] = std::cmp::max(dp[i][j], dp[i - 1][j - 1] + 1);
            }
        }
    }
    let file = File::create("cmlsc.out")?;
    let mut writer = BufWriter::new(file);
    writeln!(writer, "{}", dp[n][m]).unwrap();
    let (mut finx, mut finy) = (n, m);
    let mut vecans: Vec<i32> = vec![];
    while finx > 0 && finy > 0 {
        if a[finx - 1] == b[finy - 1] {
            vecans.push(a[finx - 1]);
            finx -= 1;
            finy -= 1;
        } else if dp[finx - 1][finy] == dp[finx][finy] {
            finx -= 1;
        } else {
            finy -= 1;
        }
    }
    let mut i = vecans.iter();
    while let Some(val) = i.next_back() {
        write!(writer, "{} ", val).unwrap();
    }
    Ok(())
}
