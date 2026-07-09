var
 a,b,d:array[1..100] of byte;
 i,j,k,m,n:byte;
 c:array[0..100,0..100] of byte;
 f,g:text;
procedure citire;
var
 i:byte;
begin
   assign(f,'cmlsc.in');reset(f);
   readln(f,m,n);
   for I:=1 to m do
   read(f,a[i]);
   readln(f);
   for I:=1 to n do
    read(f,b[i]);
end;
procedure comun;
var
 i,j:byte;
begin
 for I:=1 to m do
  for J:=1 to n do
   if a[i]=b[j]
    then
     c[i,j]:=1+c[i-1,j-1]
    else
     if c[i-1,j]>c[i,j-1]
      then
       c[i,j]:=c[i-1,j]
      else
       c[i,j]:=c[i,j-1];
end;
procedure sir;
var
 i,j:byte;
begin
 writeln('Sir comun maximal:');
 k:=0;
 i:=m;
 j:=n;
 while (c[i,j]<>0) do
  if a[i]=b[j]
   then
    begin
     inc(K);
     d[k]:=a[i];
     dec(i);
     dec(j);
    end
   else
    if c[i,j]=c[i-1,j]
     then
      dec(i)
     else
      dec(j);
 assign(g,'cmlsc.out');
 rewrite(g);
 writeln(g,k);
 for I:=k downto 1 do
  write(g,d[i],' ');
 close(g);
 writeln;
end;
begin
 citire;
 comun;
 sir;
end.

