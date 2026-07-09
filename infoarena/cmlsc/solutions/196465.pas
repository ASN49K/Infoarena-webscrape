var f,g:text;
    c,v:array[1..1024] of longint;
    a:array[1..256]of longint;
    i,max,l,n,m,x:longint;
begin
assign(f,'cmlsc.in');reset(f);
assign(g,'cmlsc.out');rewrite(g);
read(f,n,m);
max:=0;
for i:=1 to n do begin
 read(f,x);
 v[i]:=x;
 inc(a[x]);
 if a[x]>max then max:=a[x];
end;
for i:=1 to m do begin
 read(f,x);
 inc(a[x]);
 if a[x]>max then max:=a[x];
end;
for i:=1 to n do
 if a[i]=max then begin
  inc(l);
  c[l]:=v[i];
 end;
writeln(g,l);
for i:=1 to l do
 write(g,c[i],' ');
writeln(g);
close(f);
close(g);
end.