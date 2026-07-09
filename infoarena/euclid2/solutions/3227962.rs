use std::io::prelude::*;


fn cmmmdc(mut a: i32, mut b:i32) -> i32 {
    while b != 0 {
        let r = a % b;
        a = b;
        b = r;
    }
    a
}


fn main() {
    let mut fin = std::fs::File::open("euclid2.in").unwrap();

    let mut fout = std::fs::File::create("euclid2.out").unwrap();
    
    let mut buffer = String::new();
    fin.read_to_string(&mut buffer).unwrap();
    let vec: Vec<i32> = buffer.trim().split_whitespace().map(|x| x.parse::<i32>().unwrap()).collect();
    let t = vec[0];
    let mut index: usize = 0;
    for _ in 0..t {
        index += 1;
        let a = vec[index];
        index += 1;
        let b = vec[index];
        writeln!(fout, "{}", cmmmdc(a, b)).unwrap();
    }
}