use std::fs;
use std::fs::File;
use std::io::{BufRead, BufReader, BufWriter, Write, Read};
use std::cmp;

fn main() {
    let mut FIN = BufReader::new(File::open("cmlsc.in").unwrap());
    let mut FOUT = BufWriter::new(File::create("cmlsc.out").unwrap());

    let mut line = String::new();
    FIN.read_line(&mut line).unwrap();

    let mut arr:Vec <usize> = line.trim().split_whitespace().map(|x| x.parse().unwrap()).collect();
    let n = arr[0];
    let m = arr[1];

    let mut v : Vec<Vec<i32>>  = vec![vec![0], vec![0]];

    for i in 0..2 {
        line.clear();
        FIN.read_line(&mut line).unwrap();
        let mut row : Vec<i32> = line.trim().split_whitespace().map(|x| x.parse().unwrap()).collect();
        v[i] = row.clone();
    }

    let mut dp = vec![vec![0i32; m + 1]; n + 1];
    let mut cmlsc : Vec<i32> = vec![];

    for i in 1..(n + 1) {
        for j in 1..(m + 1) {
            if v[0][i - 1] == v[1][j - 1]{
                dp[i][j] = dp[i - 1][j - 1] + 1;
            } else {
                dp[i][j] = cmp::max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
    }

    let mut x : usize = n as usize;
    let mut y : usize = m as usize;

    while dp[x][y] > 0 as i32{
        if v[0][x - 1] == v[1][y - 1]{
            x -= 1;
            y -= 1;
            cmlsc.push(v[0][x]);
            continue;
        }

        if dp[x - 1][y] > dp[x][y - 1] {
            x = x - 1;
        } else {
            y = y - 1;
        }
    }

    FOUT.write(format!("{}\n", dp[n][m]).as_bytes()).unwrap();

    for i in cmlsc.iter().rev(){
        FOUT.write(format!("{} ", i).as_bytes()).unwrap();
    }
}