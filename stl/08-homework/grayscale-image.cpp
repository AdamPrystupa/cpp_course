#include "grayscale-image.hpp"

CompressedData compressGrayscale(const Bitmap &bitmap) {
  CompressedData result;

  int8_t current = bitmap[0][0];
  int8_t numberOfRepetitions = 0;

  if (height == 0 || width == 0) {
    return result;
  }
  for (size_t i = 0; i < height; ++i) {
    for (size_t j = 0; j < width; ++j) {
      uint8_t pixel = bitmap[i][j];

      if (pixel == current) {
        numberOfRepetitions++;
      } else {
        if (numberOfRepetitions > 0)
          result.push_back({current, numberOfRepetitions});
        current = pixel;
        numberOfRepetitions = 1;
      }
    }
    if (numberOfRepetitions > 0)
      result.push_back({current, numberOfRepetitions});
    numberOfRepetitions = 0;
  }
  return result;
}

Bitmap decompressGrayscale(const CompressedData &compressed) {
  Bitmap result;
  size_t lineElements = 0;
  size_t rows = 0;

  for (const auto &element : compressed) {
    uint8_t color = element.first;
    uint8_t count = element.second;
    for (size_t i = 0; i < count; ++i) {
      if (lineElements >= width) {
        break;
      }
      result[rows][lineElements] = color;
      lineElements++;
      if (lineElements == width) {
        rows++;
        lineElements = 0;
      }
    }
    if (rows >= height) {
      break;
    }
  }

  return result;
}

void printCompressed(CompressedData &output) {
  std::cout << "{";
  for (auto element : output) {
    std::cout << "{" << static_cast<int>(element.first) << " "
              << static_cast<int>(element.second) << "}";
  }
  std::cout << "}\n";
};

void printDecompressed(Bitmap &output) {
  std::cout << "{\n";
  for (size_t i = 0; i < height; ++i) {
    std::cout << "{";
    for (size_t j = 0; j < width; ++j) {
      std::cout << static_cast<int>(output[i][j]) << " ";
    }
    std::cout << "}\n";
  }
  std::cout << "{";
};