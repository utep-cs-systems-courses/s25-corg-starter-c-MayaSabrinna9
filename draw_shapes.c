#include <stdio.h>
#include "draw.h"


/* Prints a size x size square whose left col is at startCol */
void print_square(int leftCol, int size)
{
  int i, j;
  int endCol = leftCol + size;
  for (int row = 0; row < size; row++){
    int col;
    for (col = 0; col < leftCol; col++) putchar(' ');
    for (       ; col < endCol;  col++) putchar('*');
    putchar('\n');
  }
}

// Prints a triangle of specified height whose left edge is at col leftCol.
void print_triangle(int leftCol, int size)
{
  for (int row = 0; row <= size; row++) {
    int minCol = leftCol + size - row, maxCol = leftCol + size + row;
    int col;
    for (col = 0; col < minCol; col++) putchar(' ');
    for (       ; col <= maxCol; col++) putchar('*');
    putchar('\n');
  }
}
/* Prints an arrow of specified size whose left edge is at col leftCol */
void print_arrow(int leftCol, int size)
{
  unsigned char arrow_bitmap[7] = {
    0b00100,  //   *
    0b01110,  //  ***
    0b10101,  // * * *
    0b00100,  //   *
    0b00100,  //   *
    0b00100,  //   *
    0b00100   //   *
  };

  for (int row = 0; row < 7 * size; row++) {  // Scale height
    int col;
    int bitmap_row = arrow_bitmap[row / size];  // Adjust row scaling
    int minCol = leftCol, maxCol = leftCol + (5 * size);

    for (col = 0; col < minCol; col++) putchar(' ');  // Left padding

    for (int bit = 4; bit >= 0; bit--) {  // Process each bit in the 5x7 pattern
      int pixel = (bitmap_row >> bit) & 1;  // Extract pixel
      for (int scale_x = 0; scale_x < size; scale_x++) {  // Scale width
	putchar(pixel ? '*' : ' ');  // Print '*' for 1, space for 0
      }
    }
    putchar('\n');
  }
}
