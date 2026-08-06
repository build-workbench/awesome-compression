#include "common.hpp"

#include <limits>
#include <stdexcept>

#include <lz4.h>

using awesome_compression::Bytes;

int main(int argc, char** argv) {
  return awesome_compression::run("lz4_example", argc, argv, [](int ac, char** av) {
    if (ac != 2) {
      throw std::runtime_error("usage: lz4_example <input-file>");
    }

    const Bytes input = awesome_compression::read_file(av[1]);
    if (input.size() > static_cast<std::size_t>(std::numeric_limits<int>::max())) {
      throw std::runtime_error("input is too large for this simple LZ4 example");
    }

    const int input_size = static_cast<int>(input.size());
    Bytes compressed(static_cast<std::size_t>(LZ4_compressBound(input_size)));
    const int compressed_size = LZ4_compress_default(
      reinterpret_cast<const char*>(input.data()),
      reinterpret_cast<char*>(compressed.data()),
      input_size,
      static_cast<int>(compressed.size())
    );
    if (compressed_size <= 0) {
      throw std::runtime_error("LZ4_compress_default failed");
    }
    compressed.resize(static_cast<std::size_t>(compressed_size));

    Bytes restored(input.size());
    const int restored_size = LZ4_decompress_safe(
      reinterpret_cast<const char*>(compressed.data()),
      reinterpret_cast<char*>(restored.data()),
      compressed_size,
      input_size
    );
    if (restored_size < 0) {
      throw std::runtime_error("LZ4_decompress_safe failed");
    }
    restored.resize(static_cast<std::size_t>(restored_size));

    awesome_compression::require_round_trip(input, restored);
    awesome_compression::print_stats("lz4", input.size(), compressed.size());
    return 0;
  });
}
