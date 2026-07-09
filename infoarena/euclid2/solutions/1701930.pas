var i,a,b,x:integer;

function dc(a,b:integer):integer;
begin
  if b=0 then dc:=a else dc:=dc(b, a mod b);
end;

begin
  assign(input,'euclid2.in');
  reset(input);
  assign(output,'euclid2.out');
  rewrite(output);
  readln(x);
  x:=x-1;
  for i:=1 to x do
  begin
    readln(a,b);
    writeln(dc(a,b));
  end;
  read(a,b);
  write(dc(a,b));
end.