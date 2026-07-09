program ciur_eratostene;
var f,g:text;
    n:longint;
    i,j,nr:longint;
    ciur:array[1..64300]of byte;
begin
     assign(f,'ciur.in');
     assign(g,'ciur.out');
     reset(f);
     rewrite(g);
     read(f,n);
     nr:=0;
     for i:=1 to n do
         ciur[i]:=1;
     for i:=2 to(n div 2)do
         for j:=2 to(n div i)do
             ciur[i*j]:=0;
     for i:=3 to n do
         if (ciur[i]=1)then
            inc(nr);
     write(g,nr+1);
     close(f);
     close(g);
end.