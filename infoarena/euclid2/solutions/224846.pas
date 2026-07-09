   program euclid;  
   var a,b,c,d,i,r:integer;  
       f,g:text;  
   begin  
    assign(f,'cmmdc.in'); reset(f);  
    assign(g,'cmmdc.out'); rewrite(g);  
    read (f,a,b);  
    d:=a;  
    i:=b;  
    r:=d mod i;  
    while r>0 do  
                begin  
                d:=i;  
                i:=r;  
                r:=d mod i;  
                end;  
    if i=1 then write(g,0)  
           else write(g,i);  
    close(f);  
    close(g);  
   end.  