program Ex1;

var
  f, g: text;
  T, a, b, i: integer;

function cmmdc(x, y: longint): longint;
begin
if y=0 then cmmdc:=x else cmmdc :=cmmdc(y,x mod y );
end;

begin
  assign(f, 'euclid2.in'); reset(f);
  readln(f, t);
  assign(g,'euclid2.out'); rewrite(g);
  for i := 1 to t do
  begin
    Readln(f, a, b);
    writeln(g,cmmdc(a,b));
  end;
  close(f);
  close(g);
end.


