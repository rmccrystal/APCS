# Questions

## What's `stdint.h`?

A header file containing integer types of different sizes

## What's the point of using `uint8_t`, `uint32_t`, `int32_t`, and `uint16_t` in a program?

It allows you to have different sized integer types

## How many bytes is a `BYTE`, a `DWORD`, a `LONG`, and a `WORD`, respectively?

1, 4, 8, 2

## What (in ASCII, decimal, or hexadecimal) must the first two bytes of any BMP file be? Leading bytes used to identify file formats (with high probability) are generally called "magic numbers."

0xBM

## What's the difference between `bfSize` and `biSize`?

`bfSize` is the size of `BITMAPFILEHEADER` while biSize is the size of `BITMAPINFOHEADER`

## What does it mean if `biHeight` is negative?

from Microsoft docs: If biHeight is negative, the bitmap is a top-down DIB and its origin is the upper-left corner.

## What field in `BITMAPINFOHEADER` specifies the BMP's color depth (i.e., bits per pixel)?

`biBitCount`

## Why might `fopen` return `NULL` in lines 24 and 32 of `copy.c`?

If the file does not exist or otherwise could not be opened

## Why is the third argument to `fread` always `1` in our code?

We are always reading only 1 item

## What value does line 65 of `copy.c` assign to `padding` if `bi.biWidth` is `3`?

`3`

## What does `fseek` do?

From `man fseek`:
> The fseek() function sets the file position indicator for the stream
       pointed to by stream.  The new position, measured in bytes, is obtained
       by adding offset bytes to the position specified by whence.  If whence is
       set to SEEK_SET, SEEK_CUR, or SEEK_END, the offset is relative to the
       start of the file, the current position indicator, or end-of-file,
       respectively.  A successful call to the fseek() function clears the end-
       of-file indicator for the stream and undoes any effects of the ungetc(3)
       and ungetwc(3) functions on the same stream.

## What is `SEEK_CUR`?

The offset will be set to the current position indicator

## Whodunit?

It was Professor Plum with the candlestick in the library.

