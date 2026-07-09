
use::std::{fs, io};
use::std::fs::File;
use std::io::{BufWriter, Write};
macro_rules! parse_line{
    ($iter:expr, $($t:ty),+)=>{{
        let line=$iter.next().unwrap();
        let mut parts = line.split_whitespace();
        ($(parts.next().unwrap().parse::<$t>().unwrap()),+)
    }};
}
fn gcd(mut x : i32, mut y : i32) -> i32 {
    loop {
        if y == 0 {
            break;
        }
        let r = x % y;
        x = y;
        y = r; 
    }
    x
}
fn main()->Result<(),io::Error> {
    let content=fs::read_to_string("euclid1.in")?;
    let mut lines = content.lines();
    let testcases = parse_line!(lines,usize);
    let outfile = File::create("euclid1.out")?;
    let mut writer = BufWriter::new(outfile);
    for _ in 0..testcases
    {
        let (x,y) = parse_line!(lines,i32,i32);
        writeln!(writer,"{}",gcd(x,y)).unwrap();
    }
    Ok(())
}
