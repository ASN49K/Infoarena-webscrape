var buf1:array[1..1 shl 17] of char;
    t, a, b: longint;
begin
  Assign(input,'euclid2.in');
   reset(input);
  Assign(output,'euclid2.out');
   Rewrite(output);
   settextbuf(input,buf1);
   readln(t);
     while t>0 do
     begin
       readln(a,b);
        while A<>b do
         begin
           if a<b then
                     B:=b-a
                    else
                     a:=A-b;
         end;
          Writeln(a);
         dec(t);
     end;
 Close(input);
 Close(output);
End.