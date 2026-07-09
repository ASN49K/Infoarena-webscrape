program Euclid2;
var i,o:text;a,b,j,r,T:integer;
begin
 assign(i,'euclid2.in');reset(i);
 assign(o,'euclid2.out');rewrite(o);
 readln(i,T);
 for j := 1 to T do
  begin
    readln(i,a,b);
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
