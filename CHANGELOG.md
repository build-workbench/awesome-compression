# Changelog

All notable changes to this project will be documented in this file.

The format is based on [Keep a Changelog](https://keepachangelog.com/en/1.1.0/),
and this project adheres to [Semantic Versioning](https://semver.org/spec/v2.0.0.html).

## [Unreleased]

_(暂无)_

## [v1.1.0] - 2026-09-28
### Added

- README 转型为面向中文社区的精选列表（awesome list）：收录 70+ 条经过链接验证的压缩库、工具与学习资源
- 新增 `CONTRIBUTING.md`（中文贡献指南）、`.editorconfig`、`.gitattributes`
- 新增 issue 模板（bug report / feature request）与 PR 模板
- 新增 `awesome-lint` CI 工作流，自动检查列表格式与链接有效性
- Real BSC compression example using libbsc block sorting
- CI now builds and tests the BSC example (`-DAWESOME_COMPRESSION_ENABLE_BSC=ON`)
- ccache caching in CI for faster incremental builds
- `CMAKE_EXPORT_COMPILE_COMMANDS` enabled for editor/LSP integration
- Uniform error handling across all C++ examples via a shared `run` helper

### Changed

- README 由英文项目介绍改为中文精选列表，含目录、分类（算法库/学习资源/工具/基准/格式规范/中文资源等）与配套内容指引
- 许可证由 MIT 切换为 CC0-1.0（与 awesome 社区惯例一致）
- 文档站 GitHub 链接从 AICL-Lab 更新为当前仓库地址
- C++ examples now exit with a friendly stderr message and code 1 on failure instead of `std::terminate`
- `read_file` accepts `std::string_view`; `print_stats` accepts `std::string_view`
- Pinned libbsc to a fixed commit (`5e5c2ef`, bsc 3.3.12) instead of the floating `master` tag for reproducible builds
- Lowered `cmake_minimum_required` from 3.24 to 3.16 for broader toolchain support
- Simplified `.gitignore` (consolidated build-directory patterns)
- Documentation site is now Chinese-only; the incomplete English locale was removed

### Fixed

- 修正 BSC 仓库链接为 `IlyaGrebnov/libbsc`（原路径已失效）
- Stale "BSC placeholder" wording in the Chinese overview updated to reflect the real example
- BSC example now compiles: upstream libbsc target was missing its header include directory
- BSC example now guards against inputs larger than `INT_MAX` (consistent with LZ4)
- LZMA example uses `std::numeric_limits` instead of the C `UINT64_MAX` macro
- ZSTD example uses `ZSTD_CLEVEL_DEFAULT` instead of a hardcoded level
- Brotli example checks `BrotliEncoderMaxCompressedSize` for failure (returns 0)
- `read_file` validates the number of bytes actually read via `gcount()`

## [1.0.0] - 2026-05-22

### Added

- VitePress documentation site with Chinese-first content
- Compression learning guides:
  - Compression basics
  - Coding models (Huffman, LZ77, BWT)
  - Algorithm selection guide
- Algorithm notes for 6 compression libraries:
  - ZSTD
  - LZMA
  - BSC
  - LZ4
  - zlib
  - Brotli
- Comparison matrix and scenario-based algorithm selection
- C++17 compression examples with CMake build system
- GitHub Actions CI/CD workflows:
  - Documentation deployment to GitHub Pages
  - C++ build and test automation

### Changed

- Enriched algorithm notes with engineering insights and practical learning paths

### Fixed

- Optional BSC linking for cross-platform compatibility
- Temporary CMake build directories now properly gitignored

### Documentation

- Added C++ example usage documentation
- Clarified BSC example placeholder status

## [0.1.0] - 2026-05-19

### Added

- Initial project structure
- VitePress documentation scaffold
- C++ example project skeleton
- Basic compression examples for ZSTD, LZMA, LZ4, zlib, Brotli
- BSC placeholder example

[Unreleased]: https://github.com/build-workbench/awesome-compression/compare/v1.0.0...HEAD
[1.0.0]: https://github.com/build-workbench/awesome-compression/compare/v0.1.0...v1.0.0
[0.1.0]: https://github.com/build-workbench/awesome-compression/releases/tag/v0.1.0
