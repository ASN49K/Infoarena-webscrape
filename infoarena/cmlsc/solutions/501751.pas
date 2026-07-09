
type mat=array[0..1024,0..1024] of integer;
        vect=array[1..1024] of integer;
var ma:mat;
   i,j,k,n,m:integer;
   v1,v2,z:vect;
   f,g:text;



procedure matrice(var v1:vect; var v2:vect);
begin
assign(f,'cmlsc.in');
reset(f);
readln(f,n,m);
for i:=1 to n do read(f,v1[i]);
for i:=1 to m do read(f,v2[i]);
for i:=1 to n do
   for j:=1 to m do
      if (v1[i]=v2[j]) then ma[i,j]:=ma[i-1,j-1]+1
      else if (ma[i-1,j]<ma[i,j-1]) then ma[i,j]:=ma[i,j-1]
                                  else ma[i,j]:=ma[i-1,j];



close(f);
end;
begin
matrice(v1,v2);
i:=n;
j:=m;
k:=0;


while (i>=1) and (j>=1) do begin
    if v1[i]=v2[j] then begin
                            k:=k+1;
                            z[k]:=v1[i];
                            i:=i-1;
                            j:=j-1;
                            end
                       else if ma[i-1,j]>ma[i,j-1] then i:=i-1
                                                   else j:=j-1;
end;
assign(g,'cmlsc.out');
rewrite(g);
for i:=k downto 1 do
write(g,z[i],' ');
close(g);

end.


