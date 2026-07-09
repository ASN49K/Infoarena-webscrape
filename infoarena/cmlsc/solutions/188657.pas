var n,m,z,i,j : longint;
    a,b,v : array[0..1025] of integer;
    c : array[0..1025,0..1025] of integer;
begin
assign(input,'cmlsc.in');reset(input);
assign(output,'cmlsc.out');rewrite(output);
read(n,m);
 for i:=1 to n do read(a[i]);
 for i:=1 to m do read(b[i]);
 for i:=1 to n do
  for j:=1 to m do
   if a[i]=b[j] then c[i,j]:=c[i-1,j-1]+1
                else
    if c[i-1,j]>c[i,j-1] then c[i,j]:=c[i-1,j]
                         else c[i,j]:=c[i,j-1];
 writeln(c[n,m]);
  i:=n; j:=m;
  repeat
   if a[i]=b[j] then begin
    inc(z);v[z]:=a[i]; dec(i);dec(j);dec(c[n,m]);
   end
    else
     if c[i-1,j]>c[i,j-1]then dec(i)
                         else dec(j);
  until (i<=0)or(j<=0)or(c[n,m]=0);
 for i:=z downto 1 do write(v[i],' ');
close(input);close(output);
end.