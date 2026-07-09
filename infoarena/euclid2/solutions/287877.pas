var f,g:text;a,b:array[1..100]of longint;t,i:longint;
begin
assign(f,'euclid2.in');reset(f);
assign(g,'euclid2.out');reset(g);
readln(f,t);
for i:=1 to t do readln(f,a[i],b[i]);
for i:=1 to t do begin
while a[i]<>b[i] do begin
if a[i]>b[i] then a[i]:=a[i]-b[i]
             else b[i]:=b[i]-a[i];
             end;
writeln(g,a[i]);
end;
close(f);
close(g);
end.
