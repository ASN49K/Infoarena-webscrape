use std::fs::File;
use std::io::{BufWriter, Write, BufRead, BufReader};

fn gcd(mut a: i64, mut b: i64) -> i64 {
    while b != 0 {
        let r = a % b;
        a = b;
        b = r;
    }
    a
}

fn read(path: &str) -> impl Iterator<Item=i64> {
    let br = BufReader::new(File::open(path).expect(&format!("Couldn't open file {}", path)));

    br.lines()
        .map(|line| line.expect("couldn't read file"))
        .flat_map(|line| {
            line
                .split_whitespace()
                .map(|num| num.parse().expect("not a number"))
                .collect::<Vec<i64>>()
        })
}

fn main() {
    let mut iter = read("euclid2.in");
    let mut bw = BufWriter::new(File::create("euclid2.out").expect("Not being able to create output file"));

    iter.next();
while let (Some(first),Some(second))=(iter.next(),iter.next()){
    writeln!(bw,"{}",gcd(first,second)).expect("couldn't write to file");
}
}


