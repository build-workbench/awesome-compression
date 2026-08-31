# C++ 压缩示例

每个示例都读取输入文件，执行压缩、解压并校验解压结果与原始输入一致。

## 构建

```bash
cmake -S examples/cpp -B examples/cpp/build -DCMAKE_BUILD_TYPE=Release
cmake --build examples/cpp/build
```

## 运行冒烟测试

```bash
ctest --test-dir examples/cpp/build --output-on-failure
```

## 可选：BSC

BSC 默认关闭，因为上游构建集成在不同平台上可能不一致。如需启用：

```bash
cmake -S examples/cpp -B examples/cpp/build -DAWESOME_COMPRESSION_ENABLE_BSC=ON
```
