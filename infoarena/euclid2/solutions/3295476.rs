use std::fs::File;
use std::io::{BufRead, BufReader, Write};

fn gcd(mut a: i32, mut b: i32) -> i32 {
    while b != 0 {
        let temp = b;
        b = a % b;
        a = temp;
    }
    a.abs()
}

fn main() {
    let file = File::open("euclid2.in").unwrap();
    let mut lines = BufReader::new(file).lines();

    let n: usize = lines.next().unwrap().unwrap().trim().parse().unwrap();
    let mut output = File::create("euclid2.out").unwrap();

    for _ in 0..n {
        let line = lines.next().unwrap().unwrap();
        let nums: Vec<i32> = line
            .split_whitespace()
            .map(|s| s.parse().unwrap())
            .collect();

        let (a, b) = (nums[0], nums[1]);
        writeln!(output, "{}", gcd(a, b)).unwrap();
    }
}