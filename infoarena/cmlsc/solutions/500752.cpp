type vect=array[1..1024] of integer;
mat=array[0..1024,0..1024] of integer;
var v1,v2:vect;
        ma:mat;
        n,i,j,m,k,p:integer;
        s:vect;
f,g:text;
begin
assign(f,'cmlsc.in');
reset(f);
read(f,n,m);
for i:=1 to n do read(f,v1[i]);
for i:=1 to m do read (f,v2[i]);
close(f);
for i:=1 to n do
   for j:=1 to m do
     if v1[i]=v2[j] then ma[i,j]:=1+ma[i-1,j-1]
     else if (ma[i-1,j]>ma[i,j-1]) then ma[i,j]:=ma[i-1,j]
     else ma[i,j]:=ma[i,j-1];
i:=n;
j:=m;
k:=0;
while ((i>=1) and (j>=1)) do
        if (v1[i]=v2[j]) then begin
                                k:=k+1;
                                s[k]:=v1[i];
                                i:=i-1;
                                j:=j-1;
                                end
        else if (ma[i-1,j]>ma[i,j-1]) then i:=i-1
        else j:=j-1;
assign(g,'cmlsc.out');
rewrite(g);
writeln(g,ma[n,m]);
for i:=k downto 1 do write(g,s[i],' ');
close(g);
end.
