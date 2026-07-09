program euclid;
var a,b,i,n,r:longint;
    fin,fout:text;
begin
    assign(fin,'euclid2.in'); reset(fin);
    assign(fout,'euclid2.out'); rewrite(fout);
    readln(fin,n);
    for i:= 1 to n do begin
        readln(fin,a,b);
        repeat
              r:= a mod b;
              a:= b;
              b:= r;
       until r=0;
        writeln(fout,a);
    end;
    close(fin);
    close(fout);
end.