program alg_Euclid;

var
  f, g: text;
  n, i: integer;
  a, b, rez: int64;

function cmmdc(x, y: int64): int64;
begin
 { if (y = 0) then cmmdc := x
  else
     cmmdc := cmmdc(y, x mod y);}
     
     while(x<>0) and( y<>0)
     do
     if x>y then x:=x mod y
     else
     y:=y mod x;
     cmmdc:=y+x;
end;

begin
assign(f,'euclid2.in');
reset(f);
assign(g,'euclid2.out');
rewrite(g);
readln(f,n);
for i:=1 to n do
  begin
  readln(f,a,b);
  writeln(g,cmmdc(a,b));
  
  end;
  close(f);
  close(g);
end.