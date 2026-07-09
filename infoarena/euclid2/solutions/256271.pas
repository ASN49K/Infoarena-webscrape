program euclid2;
var n,a,b,i:longint;
    f,g:text;
function cmmdc(a,b:longint):longint;
begin
if a=0 then cmmdc:=b
       else if b=0 then cmmdc:=a
                   else if (a<>0)and(b<>0) then if a=b then cmmdc:=a
                                                       else cmmdc:=cmmdc(a mod b,b mod a);
end;
begin
assign(f,'euclid2.in');
reset(f);
assign(g,'euclid2.out');
rewrite(g);
read(f,n);
for i:=1 to n do begin
                 read(f,a);
                 read(f,b);
                 writeln(g,cmmdc(a,b));
end;
close(f);
close(g);
end.
