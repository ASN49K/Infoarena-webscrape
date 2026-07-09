program pascal;
var f,g:text;    n,m,i,j,maxim,k:longint; a,b,v:array[1..1500] of integer;
                 x:array[0..1024,0..1024] of integer;

  procedure citire;
  begin
  assign(f,'cmlsc.in'); reset(f);
  assign(g,'cmlsc.out'); rewrite(g);
  readln(f,n,m);
  for i:=1 to n do read(f,a[i]);
  readln(f);
  for i:=1 to m do read(f,b[i]);
  end;

  function max(a,b:longint):longint;
  begin
  if a>b then max:=a
         else max:=b;
  end;

  procedure cml;
  begin
  for i:=1 to n do
  for j:=1 to m do
  if a[i]=b[j] then x[i,j]:=x[i-1,j-1]+1
               else x[i,j]:=max(x[i-1,j],x[i,j-1]);
  end;

  procedure construire;
  begin
  writeln(g,x[n,m]);
  i:=n; j:=m;  maxim:=x[n,m]; k:=0;
  while (i<>0) and (j<>0) do
      begin
      if a[i]=b[j] then
              begin
              maxim:=maxim-1;
              inc(k);
              v[k]:=a[i];
              i:=i-1;
              j:=j-1;
              end
         else
         if (x[i-1,j]=maxim-1) and (x[i,j-1]=maxim) then j:=j-1
                    else i:=i-1;
     end;
  for i:=k downto 1 do write(g,v[i],' ');
  end;

begin
citire;
cml;
construire;
close(f);
close(g);
end.