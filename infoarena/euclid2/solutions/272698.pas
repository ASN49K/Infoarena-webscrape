var a,b,i,n,c:longint;
    f,g:text;
function cmmdc(a,b:integer):integer;
begin
     while b<>0 do begin
           c:=a mod b;
           a:=b;b:=c;
           end;
     writeln(g,a);
end;
begin
assign(f,'euclid2.in');
reset(f);
read(f,n);
assign(g,'euclid2.out');
rewrite(g);
for i:=1 to n do begin
    readln(f,a,b);
    cmmdc(a,b)
    end;
close(f);
close(g);
end.