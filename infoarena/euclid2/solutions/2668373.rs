use std::fs::File;
use std::io::{BufRead, BufReader, Write};

fn gcd(mut x: i32, mut y: i32) -> i32 {

   //assert!(x != 0 && y != 0);

   while y != 0 {

         let t = x % y;

         x = y;

         y = t;
   }

   x
}

fn _gcd(x: i32,y: i32) -> i32 {
   
       if y == 0 {

          x.abs()

       } else {

        _gcd(y , x % y)

       }

}

fn main() {

    let f = File::open("euclid2.in").expect("Unable to open file");

    let f = BufReader::new(f);
    
    let mut file_out = std::fs::File::create("euclid2.out").expect("create failed");
    
    for line in f.lines() {

        let line = line.expect("Unable to read line");

        let _numbers: Vec<i32> = line

        .split_whitespace()

        .map(|s| s.parse().expect("parse error"))

        .collect();

        let len = _numbers.len();

        if len == 2 { 

            let a = _numbers[0];

            let b = _numbers[1];

            let mut _c:i32 = _gcd(a, b);

            let s: String = _c.to_string() + "\n";
            
            file_out.write_all(s.as_bytes()).expect("write failed");   

            //println!("{:?} {:?} -> {:?}", _numbers[0], _numbers[1], _c);                       
        }    
    }
}