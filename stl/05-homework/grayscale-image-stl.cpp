#include "grayscale-image-stl.hpp"

CompressedData compressGrayscaleAlgo(const Bitmap &bitmap) {
  CompressedData result;
  if (height == 0 || width == 0) {
    return result;
  }

  auto begin = &bitmap[0][0];
  auto const &end = begin + (height * width);
  size_t it = 1;
  while (begin != end) {
    size_t currentValue = *begin;

    auto currentPosition = std::find_if_not(
        begin, end, [currentValue, end, &it](size_t pixel) mutable {
          auto result = (pixel == currentValue && it % (width + 1) != 0);
          if (it % (width + 1) != 0) {
            it += result;
          } else
            it++;
          return result;
        });
    auto count = std::distance(begin, currentPosition);

    result.push_back({currentValue, count});
    begin = currentPosition;
  }
  return result;
}

// Bitmap decompressGrayscale(const CompressedData &compressed) {
//   Bitmap result;
//   size_t lineElements = 0;
//   size_t rows = 0;

//   for (const auto &element : compressed) {
//     uint8_t color = element.first;
//     uint8_t count = element.second;
//     for (size_t i = 0; i < count; ++i) {
//       if (lineElements >= width) {
//         break;
//       }
//       result[rows][lineElements] = color;
//       lineElements++;
//       if (lineElements == width) {
//         rows++;
//         lineElements = 0;
//       }
//     }
//     if (rows >= height) {
//       break;
//     }
//   }

//   return result;
// }

Bitmap decompressGrayscaleAlgo(const CompressedData &compressed) {
  Bitmap result;
  auto begin = &result[0][0];
  auto const &end = begin + (height * width);

  std::for_each(compressed.begin(), compressed.end(),
                [begin](Pair data) mutable {
                  auto count = data.second;
                  auto value = data.first;
                  std::fill_n(begin, count, value);
                  std::advance(begin, count);
                });
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