USE school
UPDATE E
SET pscj = ROUND(
    CASE
        WHEN pscj <= 75 THEN pscj * 1.05
        ELSE pscj * 1.04
    END, 0)
WHERE kh = '08305001' AND pscj IS NOT NULL