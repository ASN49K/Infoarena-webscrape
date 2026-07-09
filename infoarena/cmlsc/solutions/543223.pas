var     a,b,sir:array[1..1024]of byte;
        d:array[0..1024,0..1024] of integer;
        m,n,i,j,poz:integer;
        f1,f2:text;
function max(a,b:integer):integer;
begin
  if a>b then max:=a else max:=b;
end;

begin
  assign(f1,'cmlsc.in');
  assign(f2,'cmlsc.out');
  reset(f1);
  rewrite(f2);
  readln(f1,m,n);

  for i:=1 to m do
    read(f1,a[i]);
  for i:=1 to n do
    read(f1,b[i]);

  for i:=1 to m do
  for j:=1 to n do
    if a[i]=b[j] then d[i,j]:=d[i-1,j-1]+1
    else d[i,j]:=max(d[i-1,j],d[i,j-1]);

  i:=m;
  j:=n;
  poz:=0;
  while (i>0)and(j>0) do
    if a[i]=b[j] then
      begin
        inc(poz);
        sir[poz]:=a[i];
        dec(i);
        dec(j);
      end
    else if d[i-1,j]>d[i,j-1] then dec(i) else dec(j);

  writeln(f2,poz);
  for i:=poz downto 1 do
    write(f2,sir[i],' ');
  close(f1);
  close(f2);
end.