var a,b,x:integer;

function dc(x,y:integer):integer;
begin
  if y=0 then dc:=x else dc:=dc(y, x mod y);
end;

begin
  assign(input,'euclid2.in');
  reset(input);
  assign(output,'euclid2.out');
  rewrite(output);
  read(x);
  while x>0 do
  begin
    read(a,b);
    writeln(dc(a,b));
    x:=x-1;
  end;
end.