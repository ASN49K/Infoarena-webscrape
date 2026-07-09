var n,m:word;
    i,j,k,max,v,h:integer;
    s:array[1..1026,1..1026]of word;
    kir:array[1..1026]of word;
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

        for i:=2 to m+1 do
                for j:=2 to n+1 do

                        if s[1,j]=s[i,1] then begin
                                max:=0;
                                for k:=j downto 2 do
                                        if (s[1,j]>=s[1,k]) AND (s[i,k]>max) then
                                                max:=s[i,k];

                                s[i,j]:=max+1;
                                for k:=i+1 to m+1 do if s[k,j]<max+1 then s[k,j]:=max+1;
                                        end;

       { for i:=1 to m+1 do begin
                for j:=1 to n+1 do write(s[i,j]);
                writeln;
                        end; }

        max:=0;

        for i:= 2 to n+1 do if s[m+1,i]>max then begin max:=s[m+1,i]; h:=i; end;

        writeln(ki,max);

        kir[1]:=s[1,h];
        v:=2;
        max:=max-1;

        for i:=h-1 downto 2 do if (s[m+1,i]=max) AND (max>0) then begin dec(max);
                                                                        kir[v]:=s[1,i];
                                                                        inc(v);
                                                                  end;

       for i:=v-1 downto 1 do write(ki,kir[i],' ');

        close(b);
        close(ki);

end.
