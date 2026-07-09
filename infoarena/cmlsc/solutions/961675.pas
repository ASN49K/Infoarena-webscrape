 var a:array[0..1024,0..1024] of integer;
     b, c, t:array[0..1024] of integer;
     i, j, m, n, k:integer;
begin
assign(input,'cmlsc.in');
assign(output,'cmlsc.out');
reset(input);
rewrite(output);
 readln(m,n);
 for i:=1 to m do
  read(b[i]);
 for i:=1 to n do
  read(c[i]);
   for i:=1 to n do
    for j:=1 to m do
     if b[j]=c[i] then a[j,i]:=a[j-1,i-1]+1
                  else if a[j-1,i]>a[j,i-1] then a[j,i]:=a[j-1,i]
                                            else a[j,i]:=a[j,i-1];
       i:=n; j:=m; k:=1;
      repeat
       if b[j]=c[i] then begin
                          t[k]:=b[j];
                          inc(k);
                          i:=i-1;
                          j:=j-1;
                         end
                    else if a[j-1,i]<a[j,i-1] then i:=i-1
                                              else j:=j-1;
      until (i=0) or (j=0);
      writeln(a[m,n]);
      for i:=k-1 downto 1 do
       write(t[i]);
close(input);
close(output);
end.