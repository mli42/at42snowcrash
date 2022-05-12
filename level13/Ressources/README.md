# level13

The program want the UID 4242, but we have 2013.
We can change the variable value with gdb to pass through the check

```
b main
r
set disassembly-flavor intel
disas main
b * <address after the first call of getuid, `cmp eax, 0x1092`>
c
i r
set $eax=4242
i r
c
# Continuing.
# your token is 2A31L79asukciNyi8uppkEuSx
```
