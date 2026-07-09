var a:array[1..100000,1..3] of longint;
    i, j, n:integer;
    r:longint;
begin
 assign(input,'euclid2.in');
 assign(output,'euclid2.out');
 reset(input);
 rewrite(output);
 readln(n);
 for i:=1 to n do
  for j:=1 to 2 do
   read(a[i,j]);
    for i:=1 to n do
     begin
     r:=a[i,1] mod a[i,2];
      while r<>0 do
       begin
        a[i,1]:=a[i,2];
        a[i,2]:=r;
        r:=a[i,1] mod a[i,2];
       end;
                      if a[i,2]=1 then a[i,2]:=0;
                      writeln(a[i,2]);
      end;
    close(input);
    close(output);
end.