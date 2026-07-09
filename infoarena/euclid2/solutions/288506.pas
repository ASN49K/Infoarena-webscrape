var f,g:text;a,b:array[1..100]of longint;t,i,r:longint;
begin
assign(f,'euclid2.in');reset(f);
assign(g,'euclid2.out');rewrite(g);
readln(f,t);
for i:=1 to t do  readln(f,a[i],b[i]);
for i:=1 to t do begin
r:=a[i] mod b[i];
while r<>0 do begin
a[i]:=b[i];b[i]:=r;
r:=a[i] mod b[i];
end;
writeln(g,b[i]);
end;
close(f);
close(g);
end.
