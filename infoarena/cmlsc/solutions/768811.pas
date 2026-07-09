program cmlsc;
var fi,fo:text;
  x,y:array[0..1024] of integer;
  c:array[0..1024,0..1024]of integer;
  n,m,i,j:integer;
  k:array[0..1024] of integer;
begin
assign(fi,'cmlsc.in');reset(fi);read(fi,n,m);
assign(fo,'cmlsc.out');rewrite(fo);
for i:=1 to n do read(fi,x[i]);
 for i:=1 to m do read(fi,y[i]);
close(fi);
for i:=0 to n do
   for j:=0 to m do c[i,j]:=0;
for i:=1 to n do
  for j:=1 to m do if x[i]=y[j] then c[i,j]:=c[i-1,j-1]+1
                                 else if c[i-1,j]>c[i,j-1] then c[i,j]:=c[i-1,j]
                                                            else c[i,j]:=c[i,j-1];
 for i:=1 to c[n,m] do k[i]:=0;
 i:=n;j:=m; writeln(fo,c[n,m]);
 while c[i,j]<> 0 do begin
                     if x[i]=y[j] then begin k[c[i,j]]:=x[i];i:=i-1;j:=j-1;end
                                   else if c[i,j-1]>c[i-1,j] then j:=j-1
                                                               else i:=i-1;
                     end;
 for i:=1 to c[n,m] do write(fo,k[i],' ');
 close(fo);
 end.
