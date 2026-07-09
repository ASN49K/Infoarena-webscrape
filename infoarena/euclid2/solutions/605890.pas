program Euclid2;
var i,o:text;a,b,j,r,n,v:integer;
begin
 assign(i,'C:\Users\Phoenix\Desktop\FP\in.txt');
 assign(o,'C:\Users\Phoenix\Desktop\FP\out.txt');
 reset(i);
 rewrite(o);
 readln(i,n);
 for j := 1 to n do
  begin
    readln(i,a,b);
    while b <> 0 do
    begin
    r := b;
    b := a mod b;
    a := r;
    end;
    writeln(o,a);
  end;
close(i);
close(o);
end.
