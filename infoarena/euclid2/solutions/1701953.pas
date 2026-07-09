var a,b,x:longint;

function dc(a,b:longint):longint;
begin
  if b=0 then dc:=a else dc:=dc(b, a mod b);
end;

begin
  assign(input,'euclid2.in');
  reset(input);
  assign(output,'euclid2.out');
  rewrite(output);
  readln(x);
  while x>1 do
  begin
    readln(a,b);
    writeln(dc(a,b));
    x:=x-1;
  end;
  read(a,b);
  write(dc(a,b));
end.