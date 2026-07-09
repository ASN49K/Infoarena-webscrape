var a,b,n,i:longint;
f,g:text;
function cmmdc(a,b:longint):longint;
begin
if b=0 then cmmdc:=a
else cmmdc:=cmmdc(b,a mod b);
end;
begin
assign(f,'euclid2.in');reset(f);
assign(g,'euclid2.out');rewrite(g);
read(f,n);
for i:=1 to n do begin
        readln(f,a,b);
        writeln(g,cmmdc(a,b));
        end;
close(f);
close(g);
end.  
