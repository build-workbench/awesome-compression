#pragma once

#include <cstddef>
#include <cstdint>
#include <functional>
#include <string_view>
#include <vector>

namespace awesome_compression {

using Bytes = std::vector<std::uint8_t>;

Bytes read_file(std::string_view path);
void require_round_trip(const Bytes& original, const Bytes& restored);
void print_stats(std::string_view name, std::size_t input_size, std::size_t compressed_size);

// Runs an example entry point, translating thrown exceptions into a stderr
// message and a non-zero exit code. Each example's `main` should delegate to
// `run` so failure paths stay uniform and friendly.
int run(std::string_view name, int argc, char** argv, const std::function<int(int, char**)>& body);

} // namespace awesome_compression
