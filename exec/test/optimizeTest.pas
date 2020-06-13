PROGRAM stmtTest;
CONST
    a = 1;
    b = 1;
VAR
    c: INTEGER;

BEGIN
    
    IF a = 1 THEN BEGIN
        WRITELN('a=1');
    END  
    ELSE BEGIN 
        WRITELN('a!=1');
    END;
    
    CASE b + 1 OF 
		0: c := 1+2;
		1: c := 2+3;
		2: c := 3+4;
	END;
    WRITELN(c);
END.
