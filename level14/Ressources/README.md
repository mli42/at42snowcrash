# level14

```
gdb getflag

b main
r
set disassembly-flavor intel
disas main
# continue disas until one see a lot of cmp/jump
# find the `cmp eax, 0xbc6` (=3014, the UID of flag14)
# Jump on the address after that line

jump * <address>

# Outputs: 7QiHafiNa3HVozsaXkawuYrTstxbpABHD8CPnHJ
su flag14
```

Why does it work? \
This is because the program just compare the UID, \
We can jump to where the UID for flag14 leads to
