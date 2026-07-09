program euclid;
var be,ki:text;
    n,x,y:longint;


function lnko(a,b:longint):longint;
begin
 if b=0 then
     lnko:=a
    else
     lnko:= lnko(b, a mod b);
end;

begin
 assign(be,'euclid2.in');
 assign(ki,'euclid2.out');
 reset(be);
 rewrite(ki);
 readln(be,n);
 for n:=n downto 1 do
   begin
     readln(be,x,y);
     writeln(ki,lnko(x,y));
   end;
 close(ki);
end.