#include "lcdutils.h"
#include "lcddraw.h"

void drawPiano(int y, u_int colorBGR) { // add params for max_x and max_y
  clearScreen(COLOR_WHITE); // change background color
  u_char width = screenWidth, height = screenHeight;
  for (int row = 0; row < screenHeight; row++) {
    for (int col = 32; col < screenWidth; col += 32) {
      drawPixel(col, row, COLOR_BLACK);
    }
  }
  
  // make double for loop to fill key using max_x and max_y
  // if x and y are within that range, draw pixel of color gray, otherwise skip
  for (int r = 0; r < screenHeight; r++) {
    for (int c = y + 1; c < y + 32; c++) {
      drawPixel(c, r, colorBGR);
    }
  }
}

void drawC4_C5() {
  clearScreen(COLOR_GREEN);
  u_char width = screenWidth, height = screenHeight;
  for (int row = 0; row < screenHeight; row++) {
    for (int col = 40; col < screenWidth - 40; col += 40) {
      drawPixel(col, row, COLOR_GOLD);
    }
  }
}
