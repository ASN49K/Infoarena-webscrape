const
 tfi='euclid2.in';
 tfo='euclid2.out';
var
 p,a,b,res,task:longint;
 fi,fo:text;

function        gcd(a,b:longint):longint;
var
 r:longint;
begin
 while b>0 do
  begin
   r:=a mod b;
   a:=b;
   b:=r;
  end;
 gcd:=a;
end;

begin
 assign(fi,tfi);reset(fi);
 assign(fo,tfo);rewrite(fo);
  read(fi,task);
  for p:= 1 to task do
   begin
    read(fi,a,b);
    res:=gcd(a,b);
    writeln(fo,res);
   end;
 close(fo);
 close(fi);
end.