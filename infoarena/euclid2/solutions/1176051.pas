var buf1:array[1..1 shl 17] of char;
    t, a, b, c: longint;
begin
  Assign(input,'euclid2.in');
   reset(input);
  Assign(output,'euclid2.out');
   Rewrite(output);
   settextbuf(input,buf1);
   readln(t);
     while T>0 do
     begin
       readln(a,b);
        while b<>0 do
         begin
             c:=a mod b;
             a:=b;
             b:=c;
         end;
          Writeln(a);
         dec(t);
     end;
 Close(input);
 Close(output);
End.
