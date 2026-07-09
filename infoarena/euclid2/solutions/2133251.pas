Program cmmdc;
              var a,b,min,d:integer;
                  i:byte;
                  fi,fo:text;
begin
     assign(fi,'cmmdc.in');reset(fi);
     assign(fo,'cmmdc.out');rewrite(fo);
     readln(fi,a);
     readln(fi,b);
     min:=a;
     if b<min then min:=b;
     for i:=2 to min do
                       if (a mod i=0)and(b mod i=0) then d:=i;
     writeln(fo,d);
     close(fo);
end.

