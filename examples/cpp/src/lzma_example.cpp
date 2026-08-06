#include "common.hpp"

#include <cstdint>
#include <limits>
#include <stdexcept>

#include <lzma.h>

using awesome_compression::Bytes;

int main(int argc, char** argv) {
  return awesome_compression::run("lzma_example", argc, argv, [](int ac, char** av) {
    if (ac != 2) {
      throw std::runtime_error("usage: lzma_example <input-file>");
    }

    const Bytes input = awesome_compression::read_file(av[1]);
    std::size_t compressed_bound = lzma_stream_buffer_bound(input.size());
    Bytes compressed(compressed_bound);
    std::size_t compressed_pos = 0;

    lzma_ret ret = lzma_easy_buffer_encode(
      6,
      LZMA_CHECK_CRC64,
      nullptr,
      input.data(),
      input.size(),
      compressed.data(),
      &compressed_pos,
      compressed.size()
    );
    if (ret != LZMA_OK) {
      throw std::runtime_error("lzma_easy_buffer_encode failed");
    }
    compressed.resize(compressed_pos);

    Bytes restored(input.size());
    std::uint64_t memory_limit = std::numeric_limits<std::uint64_t>::max();
    std::size_t compressed_read = 0;
    std::size_t restored_written = 0;
    ret = lzma_stream_buffer_decode(
      &memory_limit,
      0,
      nullptr,
      compressed.data(),
      &compressed_read,
      compressed.size(),
      restored.data(),
      &restored_written,
      restored.size()
    );
    if (ret != LZMA_OK) {
      throw std::runtime_error("lzma_stream_buffer_decode failed");
    }
    restored.resize(restored_written);

    awesome_compression::require_round_trip(input, restored);
    awesome_compression::print_stats("lzma", input.size(), compressed.size());
    return 0;
  });
}
