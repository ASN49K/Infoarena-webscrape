var c:array[0..1025,0..1025]of integer; a,b:array[1..1024]of integer; s,s2,n,m,i,j:integer;
begin
assign(input,'cmlsc.in'); reset(input);
read(n,m);
for i:=1 to n do read(a[i]);
for i:=1 to m do read(b[i]);
for i:=1 to n do for j:=1 to m do
  begin
    if a[i]=b[j] then c[i,j]:=c[i-1,j-1]+1;
    if a[i]<>b[j] then if c[i-1,j]>c[i,j-1] then c[i,j]:=c[i-1,j] else c[i,j]:=c[i,j-1];
  end;
i:=n; j:=m; s:=c[n,m]; s2:=s;
assign(output,'cmlsc.out'); rewrite(output);
writeln(s);
while s>=1 do begin
while c[i-1,j]=s do i:=i-1;
while c[i,j-1]=s do j:=j-1;
a[s]:=b[j]; s:=s-1; i:=i-1; j:=j-1;
end;
for i:=1 to  s2 do write(a[i],' ');
close(output);
end.