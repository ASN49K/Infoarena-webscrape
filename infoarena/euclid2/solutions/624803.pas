var x,y,cmmdc,n,i:integer;
    f,g:text;

function gcd(a:integer;b:integer):integer;
var r:integer;

 begin
  r:=a mod b;
  if r<>0 then
     gcd:=gcd(b,r)
    else
     gcd:=b;
 end;

begin
assign(f,'euclid2.in');assign(g,'euclid2.out');
reset(f);rewrite(g);
read(f,n);
  for i:=1 to n do
  begin
  read(f,x,y);
  cmmdc:=gcd(x,y);
  writeln(g,cmmdc);
  end;
close(f);close(g);
end.