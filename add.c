#include "data.h"

const unsigned int WIDTH = 1000;
const unsigned int HEIGHT = 325;

unsigned int iteration = 0;
unsigned int ImageBuffer[WIDTH * HEIGHT];

unsigned int rgb(int r, int g, int b);

int add(int a, int b) { return a + b; }

void draw() {
  int x, y = 0;
  int color = iteration % 10000;
  for (x = 0; x < WIDTH; x++) {
    for (y = 0; y < HEIGHT; y++) {
      int pixelColor = ((x * y + color) % 300);
      unsigned int c = rgb(pixelColor, 0, 0);
      ImageBuffer[x + y * HEIGHT] = c;
    }
  }

  iteration++;
}

void drawImage() {
  int x, y = 0;
  int position = 0;
  for (x = 0; x < WIDTH; x++) {
    for (y = 0; y < HEIGHT; y++) {
      ImageBuffer[x * HEIGHT + y] = (data[position + 3] << 24) +
                                    (data[position + 2] << 16) +
                                    (data[position + 1] << 8) + data[position];
      position += 4;
    }
  }
}

unsigned int rgb(int r, int g, int b) {
  return ((r & 0xff) << 24) + ((g & 0xff) << 16) + ((b & 0xff) << 8) +
         (255 & 0xff);
}
