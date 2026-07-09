var a,b,d:array[0..1025] of byte;
    c:array[0..1025,0..1025] of longint;
    f,g:text;
    i,j,n,m,nr:longint;

function max(a,b:longint):longint;
 begin
  if a>b then max:=a
  else max:=b
 end;

begin
 assign(f,'cmlsc.in'); reset(f);
 assign(g,'cmlsc.out'); rewrite(g);
 read(f,n,m);
 for i:=1 to n do
  read(f,a[i]);
 for i:=1 to m do
  read(f,b[i]);
 for i:=1 to n do
  for j:=1 to m do
   if a[i]=b[j] then
    c[i,j]:=c[i-1,j-1]+1
   else
    c[i,j]:=max(c[i-1,j],c[i,j-1]);
 i:=n; j:=m; nr:=0;
 while (i>=1) and (j>=1) do begin
  if a[i]=b[j] then begin
   inc(nr);
   d[nr]:=b[j];
   dec(i); dec(j);
  end
  else
   if c[i-1,j]>c[i,j-1] then
    i:=i-1
   else
    j:=j-1;
 end;
 writeln(g,c[n,m]);
 for i:=nr downto 1 do
  write(g,d[i],' ');
 close(f); close(g);
end.