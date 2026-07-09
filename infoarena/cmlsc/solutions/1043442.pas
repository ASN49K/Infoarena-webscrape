program t1;
var
i,j,m,n:integer;
x,y:array[1..1025] of integer;
a:array[0..100,0..100] of byte;
begin
     assign(input,'cmlsc.in');
    reset(input);
    assign(output,'cmlsc.out');
    rewrite(output);
          readln(m,n);

          for i:=m downto 1 do begin read(x[i]);  a[0,i] := 0;   end; readln;
          for i:=n downto 1 do begin read(y[i]); a[i,0] := 0;   end;
         for i:=1 to n do
          for j:=1 to m do
           if(y[i]=x[j]) then begin
            if(a[i-1,j]>a[i,j-1]) then a[i,j]:=a[i-1,j]+1
              else a[i,j]:=a[i,j-1] +1 ; end
             else        begin
             if(a[i-1,j]>a[i,j-1]) then a[i,j]:=a[i-1,j]
              else a[i,j]:=a[i,j-1] ;  end;

               if a[n,m] <> 0 then begin
 writeln(a[n,m]);

         for i:=n downto 1 do  begin
           for j:=m downto 1 do
           begin
               if ((a[i,j]>a[i-1,j]) and (a[i,j]>a[i,j-1])) then
               begin
                   write(x[j],' ');
               end;
           end;

            end;
 end
 else writeln('-1');



    close(input);close(output);
end.