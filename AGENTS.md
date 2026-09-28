# AGENTS.md — Awesome Compression

精选无损数据压缩算法、库、工具与学习资源的 awesome list（面向中文社区），附 VitePress 中文文档站与可运行的 C++17 示例。仓库本体是清单而非库：改动以 README 条目、文档站内容与示例代码为主。

## 常用命令

- `npx awesome-lint`（仓库根目录）：校验 README 列表格式与链接有效性，必须无 error（CI 工作流 `awesome-lint.yml` 用 `npx --yes awesome-lint` 强制执行）。
- `cmake -S examples/cpp -B examples/cpp/build -DCMAKE_BUILD_TYPE=Release`：配置 C++ 示例；依赖经 FetchContent 自动拉取（首次需网络）。
- `cmake --build examples/cpp/build`：构建全部示例可执行文件。
- `ctest --test-dir examples/cpp/build --output-on-failure`：运行冒烟测试（每个示例对 `examples/cpp/data/sample.txt` 做压缩-解压-校验）。
- CI（`cpp-examples.yml`）的构建变体：`cmake -S examples/cpp -B examples/cpp/build -G Ninja -DCMAKE_BUILD_TYPE=Release -DCMAKE_CXX_COMPILER_LAUNCHER=ccache -DCMAKE_C_COMPILER_LAUNCHER=ccache -DAWESOME_COMPRESSION_ENABLE_BSC=ON`。
- 文档站（在 `docs/` 下执行）：`npm ci` 安装依赖 → `npm run dev` 本地开发 → `npm run build` 产出 `docs/.vitepress/dist` → `npm run preview` 预览。
- 模拟 GitHub Pages 部署构建时需设 base：`VITEPRESS_BASE=/awesome-compression/ npm run build`（CI `pages.yml` 同样如此）。

## 代码结构

- `README.md`：核心内容，70+ 条目按「算法库 / 高压缩率与研究实现 / 学习资源 / 中文资源 / 工具 / 基准测试 / 格式与规范」分类。
- `CONTRIBUTING.md`：中文贡献指南，定义条目规范与 PR 流程。
- `CHANGELOG.md`：Keep a Changelog 1.1.0 格式，遵循 Semantic Versioning。
- `docs/`：VitePress 文档站，唯一 npm 工程（根目录无 package.json）；配置在 `docs/.vitepress/config.ts`（nav/sidebar 在此维护）。
- `docs/zh/`：全部中文内容，分 `guide/`（基础）、`algorithms/`（6 个算法笔记）、`examples/`（C++ 示例说明）、`comparisons/`（对比矩阵与场景选型）。
- `examples/cpp/`：C++17 示例工程，每个示例演示一个库的压缩-解压-校验闭环。
- `examples/cpp/src/common.{hpp,cpp}`：共享工具（`read_file`、`require_round_trip`、`print_stats`、统一错误处理的 `run`），命名空间 `awesome_compression`。
- `examples/cpp/src/*_example.cpp`：zstd / lzma / lz4 / zlib / brotli / bsc 六个示例，各自经 `add_compression_example` 注册为 CTest 测试。
- `examples/cpp/cmake/Dependencies.cmake`：FetchContent 固定版本拉取 zstd v1.5.6、lz4 v1.9.4、zlib v1.3.1、brotli v1.1.0；可选 libbsc（固定 commit `5e5c2ef`，bsc 3.3.12，并在该文件内补头文件目录）。
- `.github/workflows/`：`awesome-lint.yml`（列表校验）、`cpp-examples.yml`（示例构建+测试，装 `liblzma-dev`）、`pages.yml`（文档部署到 GitHub Pages）。
- `.github/PULL_REQUEST_TEMPLATE.md` 与 `.github/ISSUE_TEMPLATE/`：PR/Issue 模板，含条目格式检查清单。

## 关键约束

- 仓库整体以 CC0-1.0 发布（LICENSE）；无根级构建清单，入口只有 `docs/`（npm + VitePress ^1.5.0）与 `examples/cpp/`（CMake >= 3.16，CI 用 Ninja）。
- C++ 示例统一 C++17（`CMAKE_CXX_EXTENSIONS OFF`）；lzma 示例依赖系统 `liblzma-dev`，未找到 LibLZMA 时自动跳过；bsc 示例默认关闭，需 `-DAWESOME_COMPRESSION_ENABLE_BSC=ON` 显式启用。
- 每个示例的 `main` 应委托共享 `run`：失败时输出友好 stderr 信息并以非零码退出，不得 `std::terminate`（CHANGELOG 记录了这一统一约定）。
- 新增示例需在 `examples/cpp/CMakeLists.txt` 用 `add_compression_example` 注册，自动获得 CTest 测试（输入为 `data/sample.txt`）。
- README 条目格式固定为 `- [名称](链接) - 中文描述`：链接指向项目主页（优先 GitHub），描述说明「是什么」与「适合什么场景」，不夸大、不重复收录；新增小节须同步更新 README 顶部 Contents 目录。
- 缩进遵循 `.editorconfig`：默认 2 空格，C/C++ 源码 4 空格，LF，UTF-8（Markdown 不去行尾空白）。
- 文档站仅中文（`lang: zh-CN`），英文 locale 已移除；Node 版本以 CI 为准（Node 20 + `npm ci`）。

## 文档约定
- CHANGELOG.md：面向用户的变更在合入时写入 [Unreleased]（Keep a Changelog zh-CN 格式）
- 文档全中文
