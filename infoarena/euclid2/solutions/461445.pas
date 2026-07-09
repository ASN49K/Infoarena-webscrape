program euclid;
var a,b,i,n:longint;
    fin,fout:text;
begin
    assign(fin,'euclid2.in'); reset(fin);
    assign(fout,'euclid2.out'); rewrite(fout);
    readln(fin,n);
    for i:= 1 to n do begin
        readln(fin,a,b);
        while a<>b do
              if a < b then
                  b:= b - a
              else
                  a:= a - b;
        writeln(fout,a);
    end;
    close(fin);
    close(fout);
end.