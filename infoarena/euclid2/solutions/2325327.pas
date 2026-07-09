program alg_Euclid;

var
  f, g: text;
  n, i: integer;
  a, b, rez: longint;

function cmmdc(x, y: longint): integer;
begin
  if (y = 0) then cmmdc := x
  else
  if (x = 0) then cmmdc := y
  else
    cmmdc := cmmdc(y, x mod y);
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
  rez:=cmmdc(a,b);
  writeln(g,rez);
  //writeln(a,' ', b);
  end;
  close(f);
  close(g);
end.