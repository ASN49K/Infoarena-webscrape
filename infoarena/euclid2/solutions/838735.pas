var x,y:int64;
    f,fo:text;
    t:longint;
    i:longint;

begin


assign(f,'euclid2.in');reset(f);
readln(f,t);
assign(fo,'euclid2.out');
rewrite(fo);

for i := 1 to t do
begin
readln(f,x,y);

if (x=0)or (y=0) then writeln(fo,'0')
else
begin

if x <> y then
repeat
  if x<y then
    y := y -x
  else
    x := x - y;
until x=y ;
writeln(fo,x);


end;
end;



close(fo);close(f);


end.
