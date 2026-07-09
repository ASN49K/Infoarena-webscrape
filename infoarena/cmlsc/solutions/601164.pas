Program P2;

        var fi,fo : text;
            a,b,s : array[1..256] of char;
            c : array[1..100,1..100] of integer;
            i,j,is,js,ls : integer;
            m,n : byte;
            ch : char;


        Procedure subsir(i,j,nr_el : integer);
        var i1,j1 : integer;
        begin
        s[nr_el]:=a[i];
        if c[i,j]>0 then
                        for i1:=1 to i-1 do
                                           for j1:=1 to j-1 do
                                                              if c[i1,j1] = nr_el-1 then
                                                              begin
                                                              subsir(i1,j1,nr_el-1);
                                                              exit;
                                                              end;
        end;

        Procedure calc(i,j : integer);
        var i1,j1,k : integer;
        begin
             c[i,j]:=0;
             if a[i]<>b[j] then exit;
             k:=0;
             for i1:=1 to i-1 do
                               for j1:=1 to j-1 do
                                                  if c[i1,j1] > k then k:=c[i1,j1];
             c[i,j]:=k+1;
             if c[i,j]>ls then begin
                               is:=i;
                               js:=j;
                               ls:=c[i,j]
                               end;
        end;

begin
      assign(fi,'cmlsc.in');
      reset(fi);
      n:=0; m:=0;

      while not eoln(fi) do begin
                            read(fi,ch);
                            if ch<>' ' then begin
                                               inc(n);
                                                a[n]:=ch;
                                            end;
                            end;
      readln(fi);

      while not eoln(fi) do begin
                            read(fi,ch);
                            if ch<>' ' then begin
                                               inc(m);
                                               b[m]:=ch;
                                            end;
                            end;

      ls:=0;

      for i:=1 to n do
                      for j:=1 to m do calc(i,j);

      if ls>0 then subsir(is,js,ls);
      assign(fo,'cmlsc.out'); rewrite(fo);
      writeln(fo,ls);
      for i:=1 to ls do write(fo,s[i],' ');
      close(fi);
      close(fo);
end.
