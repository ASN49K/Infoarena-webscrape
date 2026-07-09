program gcd;
var a,b,t:longint;
    f,g:text;

function gcd(a,b:longint):longint;
begin
 if b=0 then gcd:=a
        else gcd:=gcd(b,a mod b);
end;


begin
 assign(f,'euclid2.in');
 assign(g,'euclid2.out');
 rewrite(g);
 reset(f);
 readln(f,t);
 while t<>0 do
  begin
   readln(f,a,b);
   writeln(g,gcd(a,b));
   t:=t-1;
  end;
 close(f);
 close(g);
end.
