# Awesome Compression [![Awesome](https://awesome.re/badge.svg)](https://awesome.re)

精选数据压缩（无损）算法、库、工具与学习资源，主要面向中文社区。

本仓库同时提供配套的中文文档站与可运行的 C++ 示例，见「本仓库配套内容」一节。

## Contents

- [算法库](#算法库)
  - [C / C++](#c--c)
  - [Rust](#rust)
  - [Go](#go)
  - [Java](#java)
  - [Python](#python)
  - [JavaScript / Web](#javascript--web)
- [高压缩率与研究实现](#高压缩率与研究实现)
- [学习资源](#学习资源)
- [中文资源](#中文资源)
- [工具](#工具)
- [基准测试](#基准测试)
- [格式与规范](#格式与规范)
- [本仓库配套内容](#本仓库配套内容)
- [相关精选列表](#相关精选列表)
- [贡献](#贡献)
- [许可证](#许可证)

## 算法库

### C / C++

- [Zstandard (zstd)](https://github.com/facebook/zstd) - 工业级无损压缩算法（RFC 8878），压缩率与速度覆盖 1-22 级宽光谱调节，附命令行工具，被 Linux 内核、MySQL、RocksDB 等广泛集成.
- [LZ4](https://github.com/lz4/lz4) - 以极致解压速度著称的块压缩算法，广泛用于实时场景（Kafka、ClickHouse、RocksDB 等）.
- [zlib](https://github.com/madler/zlib) - DEFLATE 的事实标准实现，gzip/zlib 格式的基础.
- [zlib-ng](https://github.com/zlib-ng/zlib-ng) - 采用 SIMD 指令的现代化分支，大幅提升性能.
- [zlib (Cloudflare fork)](https://github.com/cloudflare/zlib) - Cloudflare 维护的 zlib 优化分支，针对 Web 场景优化.
- [Brotli](https://github.com/google/brotli) - 谷歌推出的高压缩率算法（RFC 7932），内置预训练字典，适合 Web 内容.
- [Snappy](https://github.com/google/snappy) - 谷歌出品的高吞吐压缩库，压缩率低但极快，广泛用于大数据生态（Kafka、Parquet 等）.
- [XZ Utils / liblzma](https://github.com/tukaani-project/xz) - LZMA2 参考实现，.xz 格式与极高压缩率的代表.
- [bzip2](https://github.com/libarchive/bzip2) - 基于 Burrows-Wheeler 变换的经典压缩库.
- [libdeflate](https://github.com/ebiggers/libdeflate) - 高度优化的 DEFLATE/zlib/gzip 实现，压缩率与速度均优于 zlib.
- [miniz](https://github.com/richgel999/miniz) - 单文件、零依赖的 DEFLATE 实现，适合嵌入式场景.
- [Zopfli](https://github.com/google/zopfli) - 以更慢的压缩时间换取最高 DEFLATE 压缩率，常用于静态资源发布.
- [LZFSE](https://github.com/lzfse/lzfse) - Apple 的 LZ77+ANS 压缩算法，iOS/macOS 系统自带.
- [LZHAM](https://github.com/richgel999/lzham_codec) - 压缩率接近 LZMA、解压更快的变形算法.
- [BSC](https://github.com/IlyaGrebnov/libbsc) - 基于 BWT + 上下文混合的高压缩率算法，本仓库示例之一.
- [LZMA SDK](https://github.com/jljusten/LZMA-SDK) - 官方 LZMA SDK 的 GitHub 镜像（与 7-Zip 同源）.
- [7-Zip](https://github.com/ip7z/7zip) - 7z 格式官方源码镜像，支持 7z/xz/zstd 等多种格式.
- [FastLZ](https://github.com/ariya/FastLZ) - 极简轻量的快速压缩库.
- [zling](https://github.com/richox/zling) - 追求高压缩率与快速解压的通用压缩库.
- [FiniteStateEntropy (FSE)](https://github.com/Cyan4973/FiniteStateEntropy) - ANS 熵编码（tANS）的参考实现，zstd 的核心组件.

### Rust

- [fastalp](https://github.com/webc-site/wedb_embed/tree/main/fastalp) - 纯 Rust 实现的自适应无损浮点压缩（ALP）算法库，单核解压吞吐 55~77 GB/s，压缩 6.5 GB/s，平均压缩比 2.29x 且防负压缩膨胀.
- [zstd-rs](https://github.com/gyscos/zstd-rs) - 为 zstd 提供 Rust 绑定.
- [flate2](https://github.com/rust-lang/flate2-rs) - DEFLATE/gzip/zlib 的实现与绑定，Cargo 生态默认选择.
- [lz4_flex](https://github.com/PSeitz/lz4_flex) - 纯 Rust 的 LZ4 实现，含帧格式支持.
- [snap](https://github.com/BurntSushi/rust-snappy) - 纯 Rust 的 Snappy 实现，含流式帧格式.
- [zlib-rs](https://github.com/memorysafety/zlib-rs) - ISRG 的 Prossimo 项目发起、用 Rust 重写的 zlib，性能与 zlib-ng 相当.
- [rust-brotli](https://github.com/dropbox/rust-brotli) - Brotli 的纯 Rust 实现（Dropbox 维护）.
- [lzma-rs](https://github.com/gendx/lzma-rs) - 纯 Rust 的 LZMA/LZMA2 解码实现.
- [miniz_oxide](https://github.com/Frommi/miniz_oxide) - 纯 Rust 的 DEFLATE 实现，flate2 的默认后端.

### Go

- [klauspost/compress](https://github.com/klauspost/compress) - Go 压缩算法集（zstd/snappy/gzip/brotli 等），注重性能.
- [pierrec/lz4](https://github.com/pierrec/lz4) - LZ4 的 Go 实现（含帧格式）.
- [snappy](https://github.com/golang/snappy) - 官方 Go 实现（标准库 compress/snappy 同源）.
- [dsnet/compress](https://github.com/dsnet/compress) - 纯 Go 的 brotli/bzip2/flate 实现.

### Java

- [lz4-java](https://github.com/lz4/lz4-java) - LZ4 的 Java 实现（含 JNI 加速与纯 Java 版本）.
- [zstd-jni](https://github.com/luben/zstd-jni) - 为 zstd 提供 JNI 绑定.
- [snappy-java](https://github.com/xerial/snappy-java) - Snappy 的 JNI 绑定，Hadoop/Spark 生态常用.

### Python

- [python-lz4](https://github.com/python-lz4/python-lz4) - LZ4 的 Python 绑定（块与帧格式）.
- [python-zstandard](https://github.com/indygreg/python-zstandard) - 为 zstd 提供功能完整的 Python 绑定（含字典训练）.

### JavaScript / Web

- [fflate](https://github.com/101arrowz/fflate) - 快速、小体积的浏览器/Node 压缩库（gzip/deflate/zlib，支持 ZIP）.
- [pako](https://github.com/nodeca/pako) - 为 zlib 提供 JavaScript 移植，最经典的浏览器方案.
- [brotli.js](https://github.com/devongovett/brotli.js) - 纯 JS 的 Brotli 实现.

## 高压缩率与研究实现

- [cmix](https://github.com/byronknoll/cmix) - 目前压缩率最高的通用压缩器之一（上下文混合 + 神经网络模型）.
- [paq8px](https://github.com/hxim/paq8px) - PAQ 系列的高压缩率实现.
- [zpaq](https://github.com/zpaq/zpaq) - 面向归档与增量备份的上下文混合压缩器.
- [ryg_rans](https://github.com/rygorous/ryg_rans) - Fabian Giesen 的 rANS 教学实现（非库，学习用）.

## 学习资源

- [Data Compression Explained](https://mattmahoney.net/dc/dce.html) - Matt Mahoney 免费电子书：从信息论到上下文混合的完整体系.
- [Data Compression Programs](https://mattmahoney.net/dc/) - Matt Mahoney 主页：压缩程序、基准与参考资料合集.
- [The ryg blog: rANS notes](https://fgiesen.wordpress.com/2014/02/02/rans-notes/) - Fabian Giesen 的 rANS 原理与流式实现讲解.
- [RealTime Data Compression](https://fastcompression.blogspot.com) - Yann Collet（zstd/LZ4 作者）的博客.
- [cbloom rants](https://cbloomrants.blogspot.com) - Charles Bloom 的压缩算法深度博客.
- [ENCODE.SU Forum](https://encode.su) - 数据压缩社区论坛，算法讨论与基准交流.
- [Hutter Prize](https://hutter1.net) - 面向 1GB 英文文本压缩的竞赛，奖金 50 万欧元.
- [Asymmetric numeral systems (arXiv)](https://arxiv.org/abs/1311.2540) - Jarek Duda 的 ANS 论文，现代熵编码的理论基础.
- [Introducing a New Video Series: Compressor Head](https://developers.googleblog.com/introducing-a-new-video-series-compressor-head/) - Colt McAnlis 的压缩算法视频系列（信息论、LZ 家族、马尔可夫链等）.

## 中文资源

- [压缩算法综述（博客园）](https://www.cnblogs.com/johnnyzen/p/18324406) - 压缩/归档格式全景综述，含大数据场景选型对照表.
- [程序员需要了解的硬核知识之压缩算法（阿里云开发者社区）](https://developer.aliyun.com/article/997216) - 压缩算法的入门科普.
- [zstd 深度解剖：FSE 与字典训练（土法炼钢）](https://quant67.com/post/algorithms/82-zstd-internals/zstd-internals.html) - 从帧结构到 FSE 编码器实现的中文深度解析.
- [LZ77/LZ78/LZW：字典压缩的两条路线（土法炼钢）](https://quant67.com/post/algorithms/81-lz-family/lz-family.html) - 从原始论文出发讲解字典压缩家族，含 C 实现.
- [Zstandard（中文维基百科）](https://zh.wikipedia.org/wiki/Zstandard) - 中文维基百科条目，介绍 zstd 的发展与特性.

## 工具

- [7-Zip](https://www.7-zip.org) - 最流行的开源归档工具，支持 7z/xz/zstd 等格式.
- [pigz](https://github.com/madler/pigz) - 并行 gzip 实现，充分利用多核.
- [lzip](https://lzip.nongnu.org/) - 面向数据恢复的 LZMA 压缩工具（含 lziprecover）.
- [Efficient Compression Tool (ECT)](https://github.com/fhanau/Efficient-Compression-Tool) - 高性能文件优化器（PNG/JPEG/ZIP 等）.
- [oxipng](https://github.com/shssoichiro/oxipng) - Rust 编写的高效 PNG 优化器.
- [precomp](https://github.com/schnaader/precomp-cpp) - 对已压缩文件（ZIP/JPEG/PDF 等）进行再压缩.
- [UPX](https://github.com/upx/upx) - 可执行文件压缩器.
- [bsdiff](https://github.com/mendsley/bsdiff) - 二进制差分压缩，常用于软件增量更新.
- [xdelta](https://github.com/jmacd/xdelta) - 基于 VCDIFF 的差分压缩工具.

## 基准测试

- [lzbench](https://github.com/inikep/lzbench) - 内存内压缩器基准测试框架，收录 40+ 个开源压缩器.
- [Squash](https://github.com/quixdb/squash) - 压缩抽象层与统一基准.
- [TurboBench](https://github.com/powturbo/TurboBench) - 编码器与压缩器评测框架.
- [Large Text Compression Benchmark](https://mattmahoney.net/dc/text.html) - Matt Mahoney 维护的大文本压缩基准.

## 格式与规范

- [RFC 1950 (zlib)](https://www.rfc-editor.org/rfc/rfc1950.html) - 定义 zlib 流格式的规范.
- [RFC 1951 (DEFLATE)](https://www.rfc-editor.org/rfc/rfc1951.html) - DEFLATE 压缩数据格式规范.
- [RFC 1952 (gzip)](https://www.rfc-editor.org/rfc/rfc1952.html) - 定义 gzip 文件格式的规范.
- [RFC 7932 (Brotli)](https://www.rfc-editor.org/rfc/rfc7932.txt) - Brotli 压缩数据格式规范.
- [RFC 8878 (Zstandard)](https://www.rfc-editor.org/rfc/rfc8878.html) - Zstandard 压缩格式规范.
- [XZ 格式规范](https://tukaani.org/xz/xz-file-format.txt) - XZ 容器格式的官方规范.
- [7z 格式说明](https://www.7-zip.org/7z.html) - 7z 归档格式结构说明.
- [LZ4 帧格式](https://github.com/lz4/lz4/blob/dev/doc/lz4_Frame_format.md) - LZ4 帧格式规范.
- [Snappy 格式说明](https://github.com/google/snappy/blob/main/format_description.txt) - Snappy 压缩格式描述.

## 本仓库配套内容

- [文档站（docs/）](https://github.com/build-workbench/awesome-compression/blob/main/docs/zh/index.md) - VitePress 中文文档：压缩基础、算法笔记、选型对比.
- [C++ 示例（examples/cpp/）](https://github.com/build-workbench/awesome-compression/blob/main/examples/cpp/README.md) - 可运行的 C++17 示例：zstd/LZMA/BSC/LZ4/zlib/Brotli 的压缩-解压-校验闭环.

## 相关精选列表

- [Awesome](https://github.com/sindresorhus/awesome) - 所有 awesome 列表的母列表与规范所在.
- [awesome-compopt](https://github.com/MartinEesmaa/awesome-compopt) - 归档压缩器与优化工具精选.
- [awesome-cpp](https://github.com/fffaraz/awesome-cpp) - C++ 资源精选（含压缩库分类）.
- [awesome-compression（datawhalechina）](https://github.com/datawhalechina/awesome-compression) - 中文社区同名项目，主题为神经网络模型压缩（与本列表的数据压缩不同）.

## 贡献

欢迎通过 issue 或 PR 贡献新的条目、修正错误或补充中文资料。请先阅读 [CONTRIBUTING.md](./CONTRIBUTING.md)。

## 许可证

本仓库（精选列表、文档与示例代码）以 [CC0-1.0](./LICENSE) 发布。
