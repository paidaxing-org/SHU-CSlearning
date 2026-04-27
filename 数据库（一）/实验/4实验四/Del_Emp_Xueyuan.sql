DELETE FROM D
WHERE yxh NOT IN (
    SELECT DISTINCT C.yxh FROM C
    WHERE EXISTS (
        SELECT * FROM O
        WHERE O.kh = C.kh
    )
);