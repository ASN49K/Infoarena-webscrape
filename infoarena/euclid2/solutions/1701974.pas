var a,b,x:longint;

function dc(a,b:longint):longint;
var x:longint;
begin
  while b<>0 do
  begin
    x:=a;
    a:=b;
    b:=x mod a;
  end;
  dc:=a;
end;

begin
  assign(input,'euclid2.in');
  reset(input);
  assign(output,'euclid2.out');
  rewrite(output);
  readln(x);
  while x>0 do
  begin
    readln(a,b);
    writeln(dc(a,b));
    x:=x-1;
  end;
end.