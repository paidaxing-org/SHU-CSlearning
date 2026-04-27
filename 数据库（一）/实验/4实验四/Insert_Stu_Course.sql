USE school
INSERT INTO E (xh, xq, kh, gh)
SELECT S.xh, O.xq, C.kh, O.gh
FROM S
CROSS JOIN C
JOIN O ON C.kh = O.kh 
WHERE NOT EXISTS (
    SELECT * FROM E
    WHERE E.xh = S.xh AND E.kh = C.kh
)