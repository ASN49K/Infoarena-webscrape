use std::fs;
use std::fs::File;
use std::io::{BufRead, BufReader, BufWriter, Write};

fn myGcd(mut a: i32, mut b: i32) -> i32{
    if b == 0
    {
        return a;
    }

    return myGcd(b, (a % b));
}

fn main() {
    let mut FIN = BufReader::new(File::open("euclid2.in").unwrap());
    let mut FOUT = BufWriter::new(File::create("euclid2.out").unwrap());

    let mut line = String::new();
    FIN.read_line(&mut line).unwrap();

    let n = line.trim().parse::<i32>().unwrap();

    for i in 0..n
    {
        line.clear();
        FIN.read_line(&mut line).unwrap();
        let mut arr:Vec <i32> = line.split_whitespace().map(|x| x.parse().unwrap()).collect();
        let mut ans = myGcd(arr[0], arr[1]);

        FOUT.write(format!("{}\n", ans).as_bytes()).unwrap();
    }
}