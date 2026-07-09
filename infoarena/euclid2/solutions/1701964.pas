var i,a,b,x:longint;

procedure dc(a,b:longint);
begin
  if b=0 then writeln(a) else dc(b, a mod b);
end;

begin
  assign(input,'euclid2.in');
  reset(input);
  assign(output,'euclid2.out');
  rewrite(output);
  readln(x);
  for i:=1 to x do
  begin
    readln(a,b);
    dc(a,b);
  end;
end.