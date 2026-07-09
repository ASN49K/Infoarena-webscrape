var a,b,x:array[0..1024] of byte;
    i,j,n,nx,m:integer;
    f,g:text;
    lung:array[0..1024,0..1024] of integer;
begin
 assign(f,'cmlsc.in');reset(f);
 assign(g,'cmlsc.out');rewrite(g);
 readln(f,n,m);
 for i:=1 to n do
  read(f,a[i]);
 for j:=1 to m do
  read(f,b[j]);
 if a[1]=b[1] then lung[1,1]:=1
              else lung[1,1]:=0;
 for i:=2 to n do
  if a[i]=b[1] then lung[i,1]:=1
               else lung[i,1]:=lung[i-1,1];
 for j:=2 to m do
  if a[1]=b[j] then lung[1,j]:=1
               else lung[1,j]:=lung[1,j-1];
 for i:=2 to n do
  for j:=2 to m do
   if a[i]=b[j] then lung[i,j]:=lung[i-1,j-1] +1
                else if lung[i-1,j]>lung[i,j-1] then lung[i,j]:=lung[i-1,j]
                                                else lung[i,j]:=lung[i,j-1];
 writeln(g,lung[n,m]);
 i:=n;
 j:=m;
 nx:=0;
 while (i>=1) and (j>=1) do
  if a[i]=b[j] then begin
                     nx:=nx+1;
                     x[nx]:=a[i];
                     i:=i-1;
                     j:=j-1;
                    end
               else if (i-1>=1) and (lung[i,j]=lung[i-1,j]) then i:=i-1
                                                            else j:=j-1;
 for i:= nx downto 1 do
  write(g,x[i],' ');
 close(f);
 close(g);
end.


