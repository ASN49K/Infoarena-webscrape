type matrice=array [0..1025,0..1025]of integer;
     tablou=array [1..1025]of integer;
var t,a,rez:tablou;
    c:matrice;
    i,j,k,m,n,max:integer;
    f,g:text;
begin
assign(f,'cmlsc.in');
assign(g,'cmlsc.out');
reset(f);
rewrite(g);
read(f,n,m);
for i:=1 to n do
 read(f,t[i]);
for i:=1 to m do
 read(f,a[i]);
for i:=1 to n do
 for j:=1 to m do
  begin
   if t[i]=a[j] then c[i,j]:=c[i-1,j-1]+1
   else if c[i-1,j]>c[i,j-1] then c[i,j]:=c[i-1,j]
           else c[i,j]:=c[i,j-1];
  end;
i:=n;
j:=m;
while (i>0)and(j>0) do
  if t[i]=a[j] then begin
                    k:=k+1;
                    rez[k]:=a[j];
                    i:=i-1;
                    j:=j-1;
                    end
  else if c[i-1,j]<c[i,j-1] then j:=j-1
                  else i:=i-1;

writeln(g,k);
for i:=k downto 1 do
 write(g,rez[i],' ');
close(f);
close(g);
end.
