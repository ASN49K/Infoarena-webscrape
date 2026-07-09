program loc;
var a,b,c,n,i,j,m:uint64;
    f,g:text;
begin
assign(g,'euclid2.in');
assign(f,'euclid2.out');
reset(g);
rewrite(f);
readln(g,n);
for j:=1 to n do begin
readln(g,a,b);
if (a=0) or (b=0) then writeln(f,'0') else begin
if a>b then c:=b else c:=a;
i:=c;
while i>=1 do begin
if (a mod i=0) and (b mod i=0) then begin writeln(f,i); break; end;
i:=i-1;
end;
end;
end;
close(f);
close(g);
end.
