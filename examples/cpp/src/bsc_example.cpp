#include "common.hpp"

#include <limits>
#include <stdexcept>
#include <string>
#include <libbsc.h>

using awesome_compression::Bytes;

int main(int argc, char** argv) {
  return awesome_compression::run("bsc_example", argc, argv, [](int ac, char** av) {
    if (ac != 2) {
      throw std::runtime_error("usage: bsc_example <input-file>");
    }

    if (bsc_init(LIBBSC_DEFAULT_FEATURES) != LIBBSC_NO_ERROR) {
      throw std::runtime_error("bsc_init failed");
    }

    const Bytes input = awesome_compression::read_file(av[1]);
    if (input.size() > static_cast<std::size_t>(std::numeric_limits<int>::max())) {
      throw std::runtime_error("input is too large for this simple BSC example");
    }

    // Compress: output buffer needs n + LIBBSC_HEADER_SIZE bytes
    Bytes compressed(input.size() + LIBBSC_HEADER_SIZE);
    const auto compressed_size = bsc_compress(
      input.data(), compressed.data(), static_cast<int>(input.size()),
      LIBBSC_DEFAULT_LZPHASHSIZE, LIBBSC_DEFAULT_LZPMINLEN,
      LIBBSC_DEFAULT_BLOCKSORTER, LIBBSC_DEFAULT_CODER,
      LIBBSC_DEFAULT_FEATURES
    );
    if (compressed_size < 0) {
      throw std::runtime_error("bsc_compress failed with error code " + std::to_string(compressed_size));
    }
    compressed.resize(static_cast<std::size_t>(compressed_size));

    // Get block info to determine output size for decompression
    int block_size = 0;
    int data_size = 0;
    if (bsc_block_info(compressed.data(), LIBBSC_HEADER_SIZE, &block_size, &data_size, LIBBSC_DEFAULT_FEATURES) != LIBBSC_NO_ERROR) {
      throw std::runtime_error("bsc_block_info failed");
    }

    // Decompress
    Bytes restored(static_cast<std::size_t>(data_size));
    if (bsc_decompress(compressed.data(), static_cast<int>(compressed.size()), restored.data(), data_size, LIBBSC_DEFAULT_FEATURES) != LIBBSC_NO_ERROR) {
      throw std::runtime_error("bsc_decompress failed");
    }

    awesome_compression::require_round_trip(input, restored);
    awesome_compression::print_stats("bsc", input.size(), compressed.size());
    return 0;
  });
}
