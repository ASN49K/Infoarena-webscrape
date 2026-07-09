var buf1,buf2: array[1..1 shl 10] of char;
    fi,fo: text;
    r, i, n, k, a, b:longint;
begin
assign(fi,'euclid2.in');
assign(fo,'euclid2.out');
reset(fi);
rewrite(fo);
settextbuf(fi,buf1);
settextbuf(fo,buf2);
 readln(fi, n);
 for k:=1 to n do
 begin
  readln(fi,a,b);
  for i:=1 to n do
   begin
    r:=a mod b;
     while r<>0 do
      begin
       a:=b;
       a:=r;
       r:=a mod b;
      end;
    writeln(fo,b);
   end;
   end;
close(fi);
close(fo);
end.