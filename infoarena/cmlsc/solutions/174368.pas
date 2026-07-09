 program cel_mai_lung_subsir_comun;
 var a,b:array[1..1024] of byte;
 l:array[0..1024,0..1024] of integer;
 f,g:text;
sol:array[1..1024] of integer;
n,m,i,k,x,y:integer;

 begin
 assign(f,'cmlsc.in');reset(f);
 assign(g,'cmlsc.out');rewrite(g);

 readln(f,n,m);

 for i:=1 to n do
 read(f,a[i]);
 readln(f);

 for i:=1 to m do
 read(f,b[i]);
 close(F);

  for x:=1 to n do
  for y:=1 to m do
  if a[x]=b[y] then
  l[x,y]:=l[x-1,y-1]+1
  else
  if l[x-1,y]>l[x,y-1] then
  l[x,y]:=l[x-1,y]
  else
  l[x,y]:=l[x,y-1];

  writeln(g,l[n,m]);
  k:=l[n,m];

  x:=n;y:=m;
  while k>0 do   {reconstruiesc sirul}
  if a[x]=b[y] then
  begin
  sol[k]:=a[x];
  k:=k-1;
  x:=x-1;
  y:=y-1;
  end
  else
  if l[x,y]=l[x,y-1] then y:=y-1
  else x:=x-1;

  for i:=1 to l[n,m] do
  write(g,sol[i],' ');
  close(g);
  end.
