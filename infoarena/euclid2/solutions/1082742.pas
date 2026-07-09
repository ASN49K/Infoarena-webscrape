var T,i,j,a,b:integer;
    f,g:text;
    gasit:boolean;
begin
assign(f,'euclid2.in');reset(f);
assign(g,'euclid2.out');rewrite(g);
readln(f,T);
for i:=1 to T do begin
    gasit:=false;
    readln(f,a,b);
    if(a>b) then j:=b else j:=a;
    while(j>0) AND (gasit=false) do begin
              if (a MOD j=0) AND (b MOD j=0) then begin gasit:=true; writeln(g,j);end;
              j:=j-1;
              end;
end;
close(g);
end.