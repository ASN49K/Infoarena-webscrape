var
i,j,k,l,m,n,o,p,r:longint;
a:array[0..1024,0..1024] of integer;
b,c,d:array[1..1024] of integer;
ini,ou:text;
begin
 assign(ini,'cmlsc.in');
 reset(ini);
 read(ini,n,m);
  for i:=1 to n do
  read(ini,b[i]);

  for i:=1 to m do
  read(ini,c[i]);
 close(ini);
  for i:=0 to 1024 do
  begin
  a[i,0]:=0;
  a[0,i]:=0;
  end;
 k:=0;
  for i:=1 to n do
  begin
   for j:=1 to m do
   begin
   if b[i]=c[j] then a[i,j]:=a[i-1,j-1]+1 else
    begin
    if a[i-1,j]>a[i,j-1] then a[i,j]:=a[i-1,j] else a[i,j]:=a[i,j-1];
    end;
   if a[i,j]>k then begin k:=a[i,j]; o:=i; p:=j; end;
   end;
  end;
 r:=0;
  repeat
   if (b[o]=c[p]) then
   begin
   r:=r+1;
   d[r]:=b[o];
   o:=o-1;
   p:=p-1;
   end else
   begin
   if a[o-1,p]>a[o,p-1] then o:=o-1 else p:=p-1;
   end;
  until (o=0) or (p=0);
 assign(ou,'cmlsc.out');
 rewrite(ou);
 writeln(ou,k);
  for i:=r downto 1 do
  write(ou,d[i],' ');
 close(ou);
end.