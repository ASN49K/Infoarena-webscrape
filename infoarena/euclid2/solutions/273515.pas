program euclid2222;
var x,y,n,i:longint;
    f,g:text;

function lnko(a,b:longint):longint;
var m:longint;
begin
  if a>b then
    begin
      m:=a;
      a:=b;
      b:=m;
    end;
  while b<>0 do
    begin
     m:=a mod b;
     a:=b;
     b:=m;
    end;
lnko:=a;
end;


begin
assign(f,'euclid2.in');   assign(g,'euclid2.out');
reset(f);                 rewrite(g);
readln(f,n);
for i:=1 to n do
  begin
    readln(f,x,y);        writeln(g,lnko(x,y));
  end;
close(f);                 close(g);
end.