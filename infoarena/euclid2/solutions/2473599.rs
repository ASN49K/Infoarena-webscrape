use std::fs::File;
use std::io::{self, BufReader, Error, ErrorKind, Write, BufRead};

fn cmmdc(a: i64, b: i64) -> i64 {
    let mut a = a;
    let mut b = b;
    while b != 0 {
        let r = a % b;
        a = b;
        b = r;
    }
    a
}

fn read(path: &str) -> Result<Vec<i64>, io::Error> {
    let file = File::open(path)?;
    let br = BufReader::new(file);

    let mut v = Vec::new();
    for line in br.lines() {
        let line = line?;

        for number_as_string in line.split_whitespace() {
            let n = number_as_string
                .parse()
                .map_err(|e| Error::new(ErrorKind::InvalidData, e))?;
            v.push(n);
        }
    }

    Ok(v)
}

fn main() {
    let v = read("euclid2.in");
    let mut fileout = File::create("euclid2.out").expect("Not being able to create file");

    match v {
        Ok(v) => {
            let iterator = v.iter().skip(1);
            for slice in iterator.collect::<Vec<&i64>>().chunks(2) {
//                println!("{}, {}", slice[0],slice[1]);
                write!(fileout, "{}", cmmdc(*slice[0], *slice[1]));
            }
        }
        Err(err) => { panic!("{}", err); }
    }
}