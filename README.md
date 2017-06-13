# Napi101

## Introduction
The N-API is a new and better way for creating native module for NodeJS.
In this repository I tried to create some simple and functional example of N-API.
N-API is in early stage so it may have inconsistent documentation so I create example
based on thing that I can do correctly.

## Issues
1. [N-API Callback Return](https://github.com/nodejs/node/issues/13562)

## Examples
### Hello
This module register hello function on hello module. hello function prints `Hello world` on console
with `printf` and return `1373` from native function into javascript caller.

```
hello.js
src
 |
 \ hello.c
```

### Bye
This module register byeSync and byeASync functions on bye module. ByeSync function waits 1s and do some
work and ByeASync waits 1s asynchronously and do some work. Both functions return `1373` at the end into
javascript caller.

```
bye.js
src
 |
 \ bye.c
```

## Installation
```sh
npm install
# have fun with your native module.
node --napi-modules index.js
```
