program cmlsc;
var f,g:text;
    m,n:1..1024;
    i,j,k,k1,l,l1,nr,x:word;
    a,b,v,v1:array[1..1024]of 1..256;
begin
     assign(f,'cmlsc.in');
     assign(g,'cmlsc.out');
     reset(f);
     rewrite(g);
     read(f,n,m);
     k:=0;
     k1:=0;
     for i:=1 to n do
         read(f,a[i]);
     for j:=1 to m do
         read(f,b[j]);
     for i:=1 to n do
         for j:=1 to m do
         begin                          {A:12345
                                         B:22395
                                         V:2235
                                         v1:222235}
              if(a[i]=b[j]) then
              begin
                   inc(k);
                   v[k]:=a[i];
              end;
         end;
         for j:=1 to m do
             for l:=1 to k do
                 if b[j]=v[l] then
                 begin
                      inc(k1);
                      v1[k1]:=b[j];
                 end;
         for l1:=1 to k1 do
             if (v1[l1]=v1[l1+1]) then
               for x:=l1 to k1-1 do
               begin
                  v1[l1]:=v1[l1+1];
                  dec(k1);
               end;
     nr:=0;
     for l1:=1 to k1 do
         inc(nr);
     write(g,nr);
     writeln(g);
     for l1:=1 to k1 do
            write(g,v1[l1],' ');
     close(f);
     close(g);
end.




