#include "grayscale-image-stl.hpp"
#include <array>
#include <iostream>
#include <vector>

int main() {
  Bitmap bitmap = {{{0, 0, 0, 1, 1, 2, 3, 0, 0, 0},
                    {0, 0, 4, 4, 4, 1, 1, 1, 1, 1},
                    {2, 2, 2, 2, 2, 1, 2, 2, 2, 2}}};

  CompressedData compressed = compressGrayscaleAlgo(bitmap);
  printCompressed(compressed);
  Bitmap decompressed = decompressGrayscaleAlgo(compressed);
  printDecompressed(decompressed);

  return 0;
}