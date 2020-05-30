PROGRAM stmtTest;
VAR
    a, b, c, d : INTEGER;

BEGIN
    READ(a);
    b := 1;
    c := 0;
    1: IF a = 1 THEN BEGIN
        FOR d:= 1 TO 10 DO BEGIN 
            c := c + 1;
        END;
    END  
    ELSE 
    BEGIN 
        d := 0;
    END;
    WRITELN(d);
    
    CASE b + 1 OF 
		0: c := 1; 
		1: c := 2; 
		2: c := 3; 
		3: c := 4; 
	END;

    WRITELN(c);
END.
