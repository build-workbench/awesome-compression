#include "common.hpp"

#include <stdexcept>
#include <string>
#include <zstd.h>

using awesome_compression::Bytes;

int main(int argc, char** argv) {
  return awesome_compression::run("zstd_example", argc, argv, [](int ac, char** av) {
    if (ac != 2) {
      throw std::runtime_error("usage: zstd_example <input-file>");
    }

    const Bytes input = awesome_compression::read_file(av[1]);
    const auto bound = ZSTD_compressBound(input.size());
    Bytes compressed(bound);

    const auto compressed_size = ZSTD_compress(
      compressed.data(), compressed.size(), input.data(), input.size(), ZSTD_CLEVEL_DEFAULT);
    if (ZSTD_isError(compressed_size)) {
      throw std::runtime_error(std::string("ZSTD_compress failed: ") + ZSTD_getErrorName(compressed_size));
    }
    compressed.resize(compressed_size);

    const auto restored_size = ZSTD_getFrameContentSize(compressed.data(), compressed.size());
    if (restored_size == ZSTD_CONTENTSIZE_ERROR || restored_size == ZSTD_CONTENTSIZE_UNKNOWN) {
      throw std::runtime_error("ZSTD frame does not contain a known decompressed size");
    }

    Bytes restored(static_cast<std::size_t>(restored_size));
    const auto decompressed_size = ZSTD_decompress(restored.data(), restored.size(), compressed.data(), compressed.size());
    if (ZSTD_isError(decompressed_size)) {
      throw std::runtime_error(std::string("ZSTD_decompress failed: ") + ZSTD_getErrorName(decompressed_size));
    }
    restored.resize(decompressed_size);

    awesome_compression::require_round_trip(input, restored);
    awesome_compression::print_stats("zstd", input.size(), compressed.size());
    return 0;
  });
}
