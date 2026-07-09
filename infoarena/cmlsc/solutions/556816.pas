type vek=array[1..1024] of integer;
     mat=array[1..1024,1..1024] of integer;
var  x:mat;
     v1,v2,v3:vek;
     f,g:text;
     n,i,j,m,k,p:integer;
function max(a,b:integer):integer;
 var i,j,d:integer;
  begin
   d:=0;
    for i:=1 to a do
     for j:=1 to b do
      if d<x[i,j] then d:=x[i,j];
     max:=d;
  end;

begin
     assign(f,'cmlsc.in');
     reset(f);
     assign(g,'cmlsc.out');
     rewrite(g);
     readln(f,n);
     readln(f,m);

 for i:=1 to n do
  read(f,v1[i]);

 for i:=1 to m do
  read(f,v2[i]);

     close(f);

  k:=0;
  for i:=1 to n do
   for j:=1 to m do
     if v1[i]=v2[j] then x[i,j]:=max(i-1,j-1)+1;
     k:=max(n,m);
  p:=1;
  for i:=n downto 1 do
   for j:=1 to n do
    if(x[i,j]=k) and (x[i,j]<>0) then begin
                                       v3[p]:=v1[i];
                                       inc(p); dec(k);
                                       end;

 for i:=p-1 downto 1 do
  write(g,v3[i],' ');
close(g);

end.

