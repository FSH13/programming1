# Questions

## What's `stdint.h`?

a headerfile that comes with the compiler

## What's the point of using `uint8_t`, `uint32_t`, `int32_t`, and `uint16_t` in a program?

unsigned variables as uint8_t can contain a larger magnitude of numbers than the signed version i.e. int and char. 
The reason being that signed variables need one bit to confirm if it's a positive or a negative
Unsigned variables are always positive

## How many bytes is a `BYTE`, a `DWORD`, a `LONG`, and a `WORD`, respectively?

BYTE: 1 byte 8 bits unsigned
DWORD: 4 byte 32 bits unsigned
LONG: 4 byte 32 bits signed with first being the signing bit
WORD: 2 byte 8 bits unsigned

## What (in ASCII, decimal, or hexadecimal) must the first two bytes of any BMP file be? Leading bytes used to identify file formats (with high probability) are generally called "magic numbers."

BM The first 54 are filled with metadata

## What's the difference between `bfSize` and `biSize`?

biSize > the size of the BITMAPINFOHEADER It is 40 bytes.
bfSize > the size of the full BMP including both the size of the BITMAPFILEHEADER(14bytes) and BITMAPINFOHEADER(40bytes).

## What does it mean if `biHeight` is negative?

If biHeight is negative, the bitmap is a top-down DIB with the origin at the upper left corner. 
it 'reads' from top to bottom. if biHeight is positive, it starts from the bottom up.

## What field in `BITMAPINFOHEADER` specifies the BMP's color depth (i.e., bits per pixel)?

biBitCount

## Why might `fopen` return `NULL` in lines 24 and 32 of `copy.c`?

fopen opens a file from the provided path name
it might return NULL if the filepath isn't found.

## Why is the third argument to `fread` always `1` in our code?

this represents the number of types to read at once. Entering 1 makes sure you read 1 byte at a time

## What value does line 63 of `copy.c` assign to `padding` if `bi.biWidth` is `3`?

int padding = (4 - (bi.biWidth * sizeof(RGBTRIPLE)) % 4) % 4;
int padding = (4-(3*3))% 4) %4)
int padding = (4-9%4)%4
int padding = (-5%4)%4
int padding = 1%4
int padding = 1 byte

## What does `fseek` do?

provides the file position indicator to remember at which point in the file we are, then allows us te tell how far we want to move the curser,
next if we move relative to the current position, top or bottom of the file.

## What is `SEEK_CUR`?

Current position in the file
