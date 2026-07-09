var n,m:word;
    i,j,k,max,hx,hy,v:integer;
    t,t2,kir:array[1..1025]of byte;
    s:array[1..1025,1..1025]of word;
    b,ki:text;
    talal:boolean;

begin
        assign(b,'cmlsc.in');
        assign(ki,'cmlsc.out');

        reset(b);
        rewrite(ki);

        readln(b,n,m);

        for i:=1 to n do begin
                read(b,t[i]);
                s[1,i+1]:=t[i];

                        end;
        readln(b);

        for i:=1 to m do begin
                read(b,t2[i]);
                s[i+1,1]:=t2[i];

                        end;

        for i:=2 to m+1 do
                for j:=2 to n+1 do

                        if s[1,j]=s[i,1] then begin
                                max:=0;
                                for k:=j downto 2 do
                                        if (s[1,j]>=s[1,k]) AND (s[i,k]>max) then
                                                max:=s[i,k];

                                s[i,j]:=max+1;
                                for k:=i+1 to m+1 do s[k,j]:=max+1;
                                hx:=i;
                                hy:=j;
                                        end;

       { for i:=1 to m+1 do begin
                for j:=1 to n+1 do write(s[i,j]);
                writeln;
                        end;}

        writeln(ki,s[hx,hy]);

        kir[1]:=s[1,hy];
        v:=2;

        for i:=hx-1 downto 2 do
                if (s[m+1,i]=max) AND (max>0) then begin kir[v]:=s[1,i]; dec(max);inc(v); end;

        for i:=v-1 downto 1 do write(ki,kir[i],' ');

        close(b);
        close(ki);

end.
