var a:array[1..100000,1..3] of longint;
    i, j, n:longint;
begin
 assign(input,'euclid2.in');
 assign(output,'euclid2.out');
 reset(input);
 rewrite(output);
 readln(n);
 for i:=1 to n do
  for j:=1 to 2 do
   read(a[i,j]);
    j:=1;
    for i:=1 to n do
    begin
     repeat
      if a[i,j]>a[i,j+1] then a[i,j]:=a[i,j]-a[i,j+1]
                         else a[i,j+1]:=a[i,j+1]-a[i,j];
     until  a[i,j]=a[i,j+1];
      writeln(a[i,j]);
    end;
    close(input);
    close(output);
end.