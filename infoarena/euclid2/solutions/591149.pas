var  f,g:text;
     n,i,a,b:longint;


{function lnko(a,b:longint):longint;
begin
  while a<>b do
  if a>b then a:=a-b
         else b:=b-a;
  lnko:=a;
end;}


function lnko(a,b:longint):longint;
var m:longint;
begin
 m:=1;
 while m<>0 do
  begin
  m:=a mod b;
  a:=b;
  b:=m;
  end;
  lnko:=a;
end;


begin
 assign(f,'euclid2.in');
 reset(f);
 assign(g,'euclid2.out');
 rewrite(g);
 readln(f,n);
 for i:=1 to n do
  begin
   readln(f,a,b);
   writeln(g,lnko(a,b));
  end;


 close(f);
 close(g);
end.
