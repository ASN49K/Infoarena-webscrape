program submultimi;
var a,b,ec,ord1,ord2:array[1..1024]of integer;
    m,n,i,j,c,max,l1,l2:0..1024;
    f,g:text;
begin
assign(f,'cmlsc.in');
reset(f);
assign(g,'cmlsc.out');
rewrite(g);
read(f,n,m);
for i:=1 to n do
  read(f,a[i]);
for i:=1 to m do
  read(f,b[i]);
for i:=1 to n do
  begin
    j:=0;
    while (b[j]<>a[i])and(j<m) do inc(j);
    if a[i]=b[j] then begin
                        inc(c);
                        ec[c]:=a[i];
                        ord1[c]:=i;
                        ord2[c]:=j;
                      end;
  end;
max:=0;
for i:=1 to c do
  begin
    j:=i;
    while (ord1[i]<=ord1[j])and(ord2[i]<=ord2[j]) do inc(j);
    if (j-i+1)>max then begin max:=j-i+1;
                              l1:=i;
                              l2:=j;
                        end;
  end;
writeln(g,max-1);
if max>0 then
  for i:=l1 to l2-1 do write(g,ec[i],' ');
close(f);
close(g);
end.