#include "common.hpp"

#include <stdexcept>
#include <string>

#include <zlib.h>

using awesome_compression::Bytes;

int main(int argc, char** argv) {
  return awesome_compression::run("zlib_example", argc, argv, [](int ac, char** av) {
    if (ac != 2) {
      throw std::runtime_error("usage: zlib_example <input-file>");
    }

    const Bytes input = awesome_compression::read_file(av[1]);
    uLongf compressed_bound = compressBound(static_cast<uLong>(input.size()));
    Bytes compressed(static_cast<std::size_t>(compressed_bound));

    int status = compress2(
      compressed.data(),
      &compressed_bound,
      input.data(),
      static_cast<uLong>(input.size()),
      Z_BEST_COMPRESSION
    );
    if (status != Z_OK) {
      throw std::runtime_error("compress2 failed with zlib status " + std::to_string(status));
    }
    compressed.resize(static_cast<std::size_t>(compressed_bound));

    uLongf restored_size = static_cast<uLongf>(input.size());
    Bytes restored(input.size());
    status = uncompress(restored.data(), &restored_size, compressed.data(), static_cast<uLong>(compressed.size()));
    if (status != Z_OK) {
      throw std::runtime_error("uncompress failed with zlib status " + std::to_string(status));
    }
    restored.resize(static_cast<std::size_t>(restored_size));

    awesome_compression::require_round_trip(input, restored);
    awesome_compression::print_stats("zlib", input.size(), compressed.size());
    return 0;
  });
}
