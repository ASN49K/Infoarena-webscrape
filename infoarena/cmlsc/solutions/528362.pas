const
    VMAX=1024;

var
    a,b,rez:array[0..VMAX]of longint;
    c:array[0..VMAX,0..VMAX]of longint;
    m,n:longint;


procedure citire;
    var
        i:longint;
    begin
        assign(input,'cmlsc.in');reset(input);
        readln(n,m);
            for i:=1 to n do
                read(a[i]);
            for i:=1 to m do
                read(b[i]);
        close(input);
    end;

function max(x,y:longint):longint;
    begin
        if x>y then
            max:=x
        else max:=y;
    end;

procedure cmlsc;
    var
        i,j,k:longint;
    begin
        c[0,0]:=0;
        for i:=1 to n do
            for j:=1 to m do
                if a[i]=b[j] then
                    c[i,j]:=c[i-1,j-1]+1
                else
                    c[i,j]:=max(c[i-1,j],c[i,j-1]);

        i:=n; j:=m; k:=0;
        while (i>0) and (j>0) do
            if a[i]=b[j] then
                begin
                    inc(k);
                    rez[k]:=a[i];
                    dec(i); dec(j);
                end
            else if (c[i-1,j]>c[i,j-1]) then dec(i) else dec(j);
    end;

procedure afisare;
    var
        i:longint;
    begin
        assign(output,'cmlsc.out');rewrite(output);
        writeln(c[n,m]);
        for i:=c[n,m] downto 1 do
            write(rez[i],' ');
        close(output);
    end;

begin
    citire;
    cmlsc;
    afisare;
end.
