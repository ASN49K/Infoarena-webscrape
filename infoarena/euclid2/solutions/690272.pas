program info;
var f,g:text;
    n,i:longint;
    x,y,r:int64;
begin
  assign(f,'euclid2.in');  reset(f);
  assign(g,'euclid2.out');  rewrite(g);
  readln(f,n);
  for i:=1 to n do
    begin
      readln(f,x,y);
      repeat
        r:=x mod y;
        x:=y;
        y:=r;
      until  y=0;
      writeln(g,x);
    end;
  close(f);
  close(g);
end.