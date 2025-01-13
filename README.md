# Dumb printf implementation

## About
Just because I was borring.

## How to compile

```sh
nasm -g -f elf64 write.asm
ld write.o -o write
gcc write.o printf.c
```

## Usability

It just support %d xd. (It is easy to expand thought)

## Note

Those who dont understand why I reverse the number to print it
to the screen is just to avoid creating a buffer and fill it
from right to left. This way I can print the digits directly.
