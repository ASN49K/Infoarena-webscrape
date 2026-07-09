var f,g:text;
    a,a1,a2,a3,b,v:array[1..1024]of integer;
    i,j,n,m,l1,l2,l3,max:longint;
begin
assign(f,'cmlsc.in');reset(f);
assign(g,'cmlsc.out');rewrite(g);
read(f,n,m);
for i:=1 to n do begin
 read(f,a[i]);
 inc(v[a[i]]);
 if max<v[a[i]] then max:=v[a[i]];
end;
for i:=1 to m do begin
 read(f,b[i]);
 inc(v[b[i]]);
 if max<v[b[i]] then max:=v[b[i]];
end;
for i:=1 to n do
 if v[a[i]]=max then begin
  inc(l1);
  a1[l1]:=a[i];
 end;
for i:=1 to m do
 if v[b[i]]=max then begin
  inc(l2);
  a2[l2]:=b[i];
 end;
for i:=1 to l1 do
 for j:=1 to l2 do
  if a1[i]=a2[j] then begin
   inc(l3);
   a3[l3]:=a1[i];
  end;
writeln(g,l3);
for i:=1 to l3 do write(g,a3[i],' ');
writeln(g);
close(f);
close(g);
end.