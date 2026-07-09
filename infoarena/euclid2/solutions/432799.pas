program euclid;
var be,ki:text;
    n,x,y:longint;


function lnko(a,b:longint):longint;inline;
var r:longint;
begin
 while b <> 0 do
  begin
   r:=b;
   b:=a mod b;
   a:=r;
  end;
 lnko:=a;
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
