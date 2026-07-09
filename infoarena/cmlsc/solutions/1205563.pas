var f, g: text;
    m : array[0..1026,0..1026] of integer;
    a,b: array[1..1026] of integer;
    i, j, n, l : integer;
    buf1:array[1..1 shl 17] of char;
begin
 Assign(input,'cmlsc.in');
   reset(input);
 settextbuf(input,buf1);
 Assign(output,'cmlsc.out');
 rewrite(output);

  Readln(n,l);
  For i:=1 to n do
    read(a[i]);
  readln;
  for i :=1 to l do
  begin
     read(b[i]);
      for j:=1 to n do
        if a[j]=b[i] then
                       m[i,j]:=m[i-1,j-1]+1
                     else
                       if m[i-1,j]>m[i,j-1] then
                                             m[i,j]:=m[i-1,j]
                                            else
                                             m[i,j]:=m[i,j-1];
   end;



  writeln(m[l,n]);

 for i:=0 to n-1 do
   if m[l,i]<>m[l,i+1] then
   write(a[i+1],' ');
 close(input);
 close(output);
end.
