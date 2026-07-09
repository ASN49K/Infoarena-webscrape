var a,b,x,y,i,n,c:longint;
    f,g:text;
function cmmdc(x,y:integer):integer;
begin
     while y<>0 do begin
           c:=x mod y;
           x:=y;
           y:=c;
           end;
     cmmdc:=x;
end;
begin
assign(f,'euclid2.in');
reset(f);
read(f,n);
assign(g,'euclid2.out');
rewrite(g);
for i:=1 to n do begin
    readln(f,a,b);
    writeln(g,cmmdc(a,b));
    end;
close(f);
close(g);
end.