program t1;
var s,s1:string;
i,j:integer;c:byte;
a:array[0..100,0..100] of integer;
begin
     assign(input,'cmlsc.in');
    reset(input);
    assign(output,'cmlsc.out');
    rewrite(output);
          readln(s);
          readln(s1);
          for i:=0 to length(s)+1 do a[0,i] := 0;
          for i:=0 to length(s1)+1 do a[i,0] := 0;
         for i:=1 to length(s)+1 do
          for j:=1 to length(s1)+1 do
           if(s[i-1]=s1[j-1]) then begin
            if(a[i-1,j]>a[i,j-1]) then a[i,j]:=a[i-1,j]+1
              else a[i,j]:=a[i,j-1] +1 ; end
             else        begin
             if(a[i-1,j]>a[i,j-1]) then a[i,j]:=a[i-1,j]
              else a[i,j]:=a[i,j-1] ;  end;

               if a[length(s)+1,length(s1)+1] <> 0 then begin
 writeln('Lungimea celui mai lung subsir comun=',a[length(s)+1,length(s1)+1]);

 end
 else writeln('nu exista caractere comune');
                            c:=0;
         for i:=length(s)+1 downto 1 do  begin
           for j:=length(s1)+1 downto 1 do
           begin
               if ((a[i,j]>a[i-1,j]) and (a[i,j]>a[i,j-1])) then
               begin
                   write(s[i-1],' ');
               end;
           end;

            end;


    close(input);close(output);
end.