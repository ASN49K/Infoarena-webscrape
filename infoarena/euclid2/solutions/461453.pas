program euclid;
var a,b,i,n,r:longint;
    fin,fout:text;
begin
    assign(fin,'euclid2.in'); reset(fin);
    assign(fout,'euclid2.out'); rewrite(fout);
    readln(fin,n);
    for i:= 1 to n do begin
        readln(fin,a,b);
        while r<>0 do
              r:= a div b;
              a:= b;
              b:= r;
        writeln(fout,b);
    end;
    close(fin);
    close(fout);
end.