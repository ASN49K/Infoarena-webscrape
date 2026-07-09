program Euclid2;
var i,o:text;a,b,j,r,n:integer;
begin
 assign(i,'euclid2.in');reset(i);
 assign(o,'euclid2.out');rewrite(o);
 readln(i,n);
 for j := 1 to n do
  begin
    readln(i,a,b);
    if b > a then
    begin
      r := a;
      a := b;
      b := r;
    end;
    while b <> 0 do
    begin
    r := a mod b;
    a := b;
    b := r;
    end;
    writeln(o,a);
  end;
close(i);
close(o);
end.
