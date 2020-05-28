PROGRAM stmtTest;
CONST
    a = 1;
VAR
    b, c, d : INTEGER;
    str : STRING;

BEGIN
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
	WRITE(d);
    
    CASE b + 1 OF 
		0: BEGIN str := 'A1'; c := 1; END;
		1: str := 'B2';
		2: str := 'C3';
		3: str := 'D4';
	END;

    WRITE(c);
    WRITELN(str);
END.
