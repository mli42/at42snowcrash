# level09

```bash
ls -l
# -rwsr-sr-x 1 flag09 level09 7640 Mar  5  2016 level09
# ----r--r-- 1 flag09 level09   26 Mar  5  2016 token

cat token | hexdump -C
# 00000000  66 34 6b 6d 6d 36 70 7c  3d 82 7f 70 82 6e 83 82  |f4kmm6p|=..p.n..|
# 00000010  44 42 83 44 75 7b 7f 8c  89 0a                    |DB.Du{....|
# 0000001a

ltrace ./level09
# ptrace(0, 0, 1, 0, 0xb7e2fe38)
# puts("You should not reverse this")
# => We can't debug this program

./level09 abcdefghijklmnopqrstuvwxyz
# acegikmoqsuwy{}..........
./level09 123456
# 13579;

# => It make (char + i), we have to reverse the token!!
```

Run this python2 script in `/tmp/py` which does the inverse:
```python
#!/usr/bin/env python
import sys

token = sys.argv[1]
res = []
print "Token:", token
for i, char in enumerate(token):
  res.append(chr(ord(char) - i))
print "".join(res)
```

```bash
chmod 777 /tmp/py && /tmp/py "$(cat ~/token)"
# Token: f4kmm6p|=..............
# f3iji1ju5yuevaus41q1afiuq

su flag09
```
