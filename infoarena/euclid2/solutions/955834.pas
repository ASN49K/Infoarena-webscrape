var a:array[1..100000,1..3] of longint;
    i, j, n, r:integer;
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
     r:=a[i,j] mod a[i,j+1];
      while r<>0 do begin
       begin
        a[i,j]:=a[i,j+1];
        a[i,j+1]:=r;
        r:=a[i,j] mod a[i,j+1];
       end;
                      if a[i,j+1]=1 then a[i,j+1]:=0;
                      writeln(a[i,j+1]);
                    end;
    close(input);
    close(output);
end.