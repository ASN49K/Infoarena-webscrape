program pascal;
var t,i,a,b:longint;
    f,g:text;

function cmmdc(a,b:longint):longint;
var c:longint;
begin
   while b>0 do
      begin
         c:=a mod b;
         a:=b;
         b:=c;
      end;
   cmmdc:=a;
end;

begin
   assign(f,'euclid2.in');reset(f);
   assign(g,'euclid2.out');rewrite(g);
   readln(f,t);
   for i:=1 to t do
      begin
         readln(f,a,b);
         writeln(g,cmmdc(a,b));
      end;
   close(f);
   close(g);
end.