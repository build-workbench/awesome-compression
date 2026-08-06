#include "common.hpp"

#include <stdexcept>

#include <brotli/decode.h>
#include <brotli/encode.h>

using awesome_compression::Bytes;

int main(int argc, char** argv) {
  return awesome_compression::run("brotli_example", argc, argv, [](int ac, char** av) {
    if (ac != 2) {
      throw std::runtime_error("usage: brotli_example <input-file>");
    }

    const Bytes input = awesome_compression::read_file(av[1]);
    std::size_t compressed_size = BrotliEncoderMaxCompressedSize(input.size());
    if (compressed_size == 0) {
      throw std::runtime_error("BrotliEncoderMaxCompressedSize returned 0");
    }
    Bytes compressed(compressed_size);

    const auto encoded = BrotliEncoderCompress(
      BROTLI_DEFAULT_QUALITY,
      BROTLI_DEFAULT_WINDOW,
      BROTLI_MODE_GENERIC,
      input.size(),
      input.data(),
      &compressed_size,
      compressed.data()
    );
    if (encoded == BROTLI_FALSE) {
      throw std::runtime_error("BrotliEncoderCompress failed");
    }
    compressed.resize(compressed_size);

    std::size_t restored_size = input.size();
    Bytes restored(restored_size);
    const auto decoded = BrotliDecoderDecompress(
      compressed.size(),
      compressed.data(),
      &restored_size,
      restored.data()
    );
    if (decoded != BROTLI_DECODER_RESULT_SUCCESS) {
      throw std::runtime_error("BrotliDecoderDecompress failed");
    }
    restored.resize(restored_size);

    awesome_compression::require_round_trip(input, restored);
    awesome_compression::print_stats("brotli", input.size(), compressed.size());
    return 0;
  });
}
