var buf1: array[1..1 shl 10] of char;
    fi: text;
    r, i, n, j, k, a, b:longint;
begin
assign(fi,'euclid2.in');
assign(output,'euclid2.out');
reset(fi);
rewrite(output);
settextbuf(fi,buf1);
 readln(fi, n);
 for k:=1 to n do
 begin
  readln(a,b);
  for i:=1 to n do
   begin
    r:=a mod b;
     while r<>0 do
      begin
       a:=b;
       a:=r;
       r:=a mod b;
      end;
    writeln(b);
   end;
   end;
close(input);
close(output);
end.