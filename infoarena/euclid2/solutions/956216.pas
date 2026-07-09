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
   begin
     repeat
       r:=a mod b;
       a:=b;
       b:=r;
     until r=0;
    writeln(fo,a);
   end;
  end;
close(fi);
close(fo);
end.