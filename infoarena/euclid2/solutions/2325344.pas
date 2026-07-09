program Ex1;

var
  f, g: text;
  T, a, b, i:uint64 ;

function cmmdc(x, y: uint64): uint64;
begin
  while x <> y do
  if x>y then x:=x-y else y:=y-x;
  cmmdc:=x;
end;

begin
  assign(f, 'euclid2.in'); reset(f);
  readln(f, t);
  assign(g, 'euclid2.out'); rewrite(g);
  for i := 1 to t do
  begin
    Readln(f, a, b);
    writeln(g, cmmdc(a, b));
  end;
  close(f);
  close(g);
end.


