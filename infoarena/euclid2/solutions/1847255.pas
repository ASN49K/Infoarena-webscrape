var a,b,n,aux,i:longint;
   begin
   assign(input,'euclid2.in');
   assign(output,'euclid2.out');
   reset(input);
   rewrite(output);

   readln(n);
   for i:=1 to n do
   begin
    readln(a,b);
     aux:=a; a:=b; b:=aux;
     while b<>0 do
      begin
      aux:=a mod b;
      a:=b;
      b:=aux;
     end;
    writeln(a);
    end;
    close(input);
    close(output);
   end.




