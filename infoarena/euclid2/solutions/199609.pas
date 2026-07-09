VAR F,G:text;
    r,i,im,d,n:longint;
function eu(a,b:longint):longint;
var aux,r:longint;
begin
if a<b then
begin
 aux:=a;
 a:=b;
 b:=aux;
end;
if b=0 then eu:=a
else
begin
while a mod b <>0 do
 begin
  r:=a mod b;
  a:=b;
  b:=r;
 end;
eu:=b;
end;
end;

begin
 assign(f,'euclid2.in');reset(f);
 assign(g,'euclid2.out');rewrite(g);
 readln(f,n);
 for i:=1 to n do
 begin
  readln(f,d,im);
  writeln(g,eu(d,im));
 end;
close(f);close(g);
end.