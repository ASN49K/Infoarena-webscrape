var f,fo:text;
    i,k,a,b,d:longint;
function cmmdc(a,b:longint):longint;
var r:longint;
begin
{if b=0 then cmmdc:=a
       else cmmdc:=cmmdc(b,a mod b)		}
repeat
 r:=a mod b;
 if r<>0 then
  begin
   a:=b;
   b:=r
  end;
until r=0;
cmmdc:=b;
end;
begin
assign(f,'euclid2.in');
assign(fo,'euclid2.out');
rewrite(fo);
reset(f);
readln(f,k);
for i:=1 to k do
 begin
  readln(f,a,b);
  d:=cmmdc(a,b);
  writeln(fo,d); 
 end;
close(f);
close(fo);
end.	
