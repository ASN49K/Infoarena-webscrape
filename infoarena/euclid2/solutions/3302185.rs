use std::fs::File;
use std::io::{BufReader, BufWriter, BufRead, Write};

fn gcd(mut a: u64, mut b: u64) -> u64 {
    while b != 0 {
        let r = a % b;
        a = b;
        b = r;
    }
    a
}

fn main() {
    let input = File::open("euclid2.in").expect("Failed to open input");
    let output = File::create("euclid2.out").expect("Failed to create output");

    let reader = BufReader::new(input);
    let mut writer = BufWriter::new(output);

    let mut lines = reader.lines();
    let t = lines.next().unwrap().unwrap().trim().parse::<usize>().unwrap();

    for _ in 0..t {
        let line = lines.next().unwrap().unwrap();
        let parts: Vec<u64> = line
            .split_whitespace()
            .map(|x| x.parse::<u64>().unwrap())
            .collect();

        let result = gcd(parts[0], parts[1]);
        writeln!(writer, "{}", result).expect("Write failed");
    }
}
