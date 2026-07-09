program euclid2;
var i,o:text;
    t:longint;
    a,b,f,r:longint;
begin
  assign(i,'euclid2.in');
  reset(i);
  readln(i,t);
  assign(o,'euclid2.out');
  rewrite(o);
  for f:=1 to t do
    begin
      read(i,a,b);
      while b>0 do
        begin
          r:=a mod b;
          a:=b;
          b:=r
        end;
      writeln(o,a)
    end;
  close(o)
end.




