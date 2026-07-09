program Euclid2;
var i,o:text;a,b,j,r,n,v:integer;
begin
 assign(i,'euclid2.in');
 assign(o,'euclid2.out');
 reset(i);
 rewrite(o);
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
    r := b;
    b := a mod b;
    a := r;
    end;
    writeln(o,a);
  end;
close(i);
close(o);
end.
