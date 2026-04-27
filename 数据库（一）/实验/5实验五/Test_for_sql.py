import pyodbc

conn = pyodbc.connect(
    "DRIVER={ODBC Driver 17 for SQL Server};"
    "SERVER=localhost;"
    "DATABASE=school;"
    "Trusted_Connection=yes;"
)

cursor = conn.cursor()
kh = '08305001'

print('修改前：')
cursor.execute("""
    SELECT TOP 5 xh, kh, pscj
    FROM E
    WHERE kh = ?
    ORDER BY xh
""", kh)
for row in cursor.fetchall():
    print(row)

cursor.execute("""
    UPDATE E
    SET pscj = pscj + 2
    WHERE kh = ? AND pscj IS NOT NULL
""", kh)
conn.commit()

print('修改后：')
cursor.execute("""
    SELECT TOP 5 xh, kh, pscj
    FROM E
    WHERE kh = ?
    ORDER BY xh
""", kh)
for row in cursor.fetchall():
    print(row)

cursor.close()
conn.close()
