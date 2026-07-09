program euclid2;
var nr,i:longint;
     a,b,r:longint;
     f,g:text;

begin
  assign(f,'euclid2.in');
  assign(g,'euclid2.out');
  reset(f);
  rewrite(g);
  readln(f,nr);
  for i:=1 to nr do
    begin
      readln(f,a,b);
      r := a mod b;
      while (r<>0) do
        begin
          a:=b;
          b:=r;
          r:=a mod b;
        end;
      writeln(g,b);
    end;
  close(f);
  close(g);
end.