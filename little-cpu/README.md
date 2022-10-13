# little-cpu

There are 3 programs:

1)casm - assembles txt files into '.lcpu' files.

2)dasm - performs the reverse operation.

3)lcpu - runs assembled files.

## lcpu commands

psh [value] - add value on top of the stack

add - add two values from top of the stack

sub - substract two values from top of the stack

mul - multiply two values from top of the stack

div - divide two values from top of the stack

out - write value from top of the stack

inp - read value and push it to the stack

## Download 

You can download source code here.

## Building 

You can build the program using the make utility.

## Usage

### Firstly you should assemble program with casm.

$casm [src] [dst]

Then you can run assembled file with lcpu.

$lcpu [file]

Also you can disassemble assembled files with dasm.

$dasm [src] [dst]