var a,b,i,n,c:longint;
    f,g:text;
function cmmdc(a,b:longint):longint;
begin
     while b<>0 do begin
           c:=a mod b;
           a:=b;
           b:=c;
           end;
     cmmdc:=a;    
end;
begin
assign(f,'euclid.in');
reset(f);
read(f,n);
assign(g,'euclid2.out');
rewrite(g);
for i:=1 to n do begin
    read(f,a,b);
    writeln(g,cmmdc(a,b));
    end;
close(f);
close(g);
end.