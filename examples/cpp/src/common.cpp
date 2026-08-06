#include "common.hpp"

#include <exception>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <stdexcept>
#include <string>

namespace awesome_compression {

Bytes read_file(std::string_view path) {
  std::ifstream input(std::string(path), std::ios::binary);
  if (!input) {
    throw std::runtime_error("failed to open input file: " + std::string(path));
  }

  input.seekg(0, std::ios::end);
  const auto size = input.tellg();
  if (size < 0) {
    throw std::runtime_error("failed to determine input file size: " + std::string(path));
  }

  Bytes bytes(static_cast<std::size_t>(size));
  input.seekg(0, std::ios::beg);
  if (!bytes.empty()) {
    input.read(reinterpret_cast<char*>(bytes.data()), static_cast<std::streamsize>(bytes.size()));
    if (static_cast<std::size_t>(input.gcount()) != bytes.size()) {
      throw std::runtime_error("failed to read input file: " + std::string(path));
    }
  }

  return bytes;
}

void require_round_trip(const Bytes& original, const Bytes& restored) {
  if (original != restored) {
    throw std::runtime_error("decompressed output does not match input");
  }
}

void print_stats(std::string_view name, std::size_t input_size, std::size_t compressed_size) {
  const double ratio = input_size == 0
    ? 0.0
    : static_cast<double>(compressed_size) / static_cast<double>(input_size);

  std::cout << name << '\n'
            << "input_bytes=" << input_size << '\n'
            << "compressed_bytes=" << compressed_size << '\n'
            << "ratio=" << std::fixed << std::setprecision(3) << ratio << '\n'
            << "verified=true" << '\n';
}

int run(std::string_view name, int argc, char** argv, const std::function<int(int, char**)>& body) {
  try {
    return body(argc, argv);
  } catch (const std::exception& e) {
    std::cerr << name << ": " << e.what() << '\n';
    return 1;
  } catch (...) {
    std::cerr << name << ": unknown error\n";
    return 1;
  }
}

} // namespace awesome_compression
