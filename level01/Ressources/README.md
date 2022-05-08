# level01

```bash
cat /etc/passwd
# Output: flag01:42hDRfypTqqnw:3001:3001::/home/flag/flag01:/bin/bash
```

How could it be encrypted?

> how linux /etc/passwd password encrypted

[What methods are used to encrypt passwords in /etc/passwd and /etc/shadow?](https://unix.stackexchange.com/questions/8229/what-methods-are-used-to-encrypt-passwords-in-etc-passwd-and-etc-shadow)

=> man 3 crypt
=> The password is a hash created by "42" as the salt

> crack hash password /etc/passwd

[How to use John](https://tzusec.com/crack-password-hashes-from-linux-with-john-the-ripper/)
Output: abcedfg
