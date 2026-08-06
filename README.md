# Awesome Compression

Awesome Compression is a learning-oriented repository for compression and coding algorithms. It combines concise algorithm notes with runnable C++ examples so the concepts can be studied from both theory and API usage.

## Modules

- `docs/` - VitePress GitHub Pages site for compression notes, comparisons, and learning guides.
- `examples/cpp/` - C++17 examples that call common compression libraries and verify round-trip correctness.

## First Algorithm Set

- ZSTD
- LZMA
- BSC
- LZ4
- zlib
- Brotli

## Documentation

Run the documentation locally:

```bash
cd docs
npm install
npm run dev
```

Build the documentation:

```bash
cd docs
npm run build
```

## C++ Examples

Build and run the examples:

```bash
cmake -S examples/cpp -B examples/cpp/build -DCMAKE_BUILD_TYPE=Release
cmake --build examples/cpp/build
ctest --test-dir examples/cpp/build --output-on-failure
```

The examples use CMake FetchContent to fetch supported libraries. BSC is optional and may be disabled automatically when the upstream build is unavailable on the current platform.

## License

Released under the [MIT License](./LICENSE).
