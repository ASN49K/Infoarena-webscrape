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
   read(b[i]);
 for i:=1 to n do
    for j:=1 to l do
        if a[i]=b[j] then
                       m[i,j]:=m[i-1,j-1]+1
                     else
                       if m[i-1,j]>m[i,j-1] then
                                             m[i,j]:=m[i-1,j]
                                            else
                                             m[i,j]:=m[i,j-1];



  writeln(m[n,l]);



 while m[i,j]<>0 do
  begin
   while m[i,j-1]=m[i,j] do
      dec(j);
   while m[i-1,j]=m[i,j] do
     dec(i);
   write(a[i],' ');
   dec(i);
  end;
 close(input);
 close(output);
end.
