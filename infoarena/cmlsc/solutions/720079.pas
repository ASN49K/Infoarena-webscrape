var n,m:word;
    i,j,h:integer;
    s:array[1..1050,1..1050]of word;
    t:array[1..1050]of word;
    b,ki:text;

begin
        assign(b,'cmlsc.in');
        assign(ki,'cmlsc.out');

        reset(b);
        rewrite(ki);

        readln(b,n,m);

        for i:=1 to n do begin
                read(b,s[1,i+1]);

                        end;
        readln(b);

        for i:=1 to m do begin
                read(b,s[i+1,1]);

                        end;

        for i:=2 to m+1 do if s[2,1]=s[1,i] then s[2,i]:=1
                                            else if i>2 then s[2,i]:=s[2,i-1];

        for i:=2 to n+1 do if s[1,2]=s[i,1] then s[i,2]:=1
                                            else if i>2 then s[i,2]:=s[i-1,2];

        for i:=3 to m+1 do
                for j:=3 to n+1 do

                        if s[1,j]=s[i,1] then s[i,j]:=s[i-1,j-1]+1
                                         else if s[i-1,j]>s[i,j-1] then s[i,j]:=s[i-1,j]
                                                                   else s[i,j]:=s[i,j-1];





        writeln(ki,s[m+1,n+1]);

        h:=1;

        while (i>1) AND (j>1) AND ((s[i-1,j]>0) OR (s[i,j-1]>0)) do begin
               if (s[i-1,j]=s[i,j-1]) AND (s[i-1,j]=s[i,j]-1) AND (s[i-1,j-1]=s[i,j]-1) then begin t[h]:=s[1,j];inc(h);
                                                                         dec(i);
                                                                         dec(j);
                                                                         end
                                 else if s[i,j-1]>0 then dec(j)
                                                    else if s[i-1,j]>0 then dec(i);

               if (i=2) AND (s[i,j]>0) AND (s[i,j-1]=0) then begin dec(i); t[h]:=s[1,j]; inc(h); end;
               if (j=2) AND (s[i,j]>0) AND (s[i-1,j]=0) then begin t[h]:=s[1,j]; inc(h); dec(j); end;


               end;
        for i:=h-1 downto 1 do write(ki,t[i],' ');


        close(b);
        close(ki);

end.
