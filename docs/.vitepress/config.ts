import { defineConfig } from 'vitepress'

const rawBase = process.env.VITEPRESS_BASE
const base = rawBase
  ? rawBase.startsWith('/')
    ? rawBase.endsWith('/') ? rawBase : `${rawBase}/`
    : `/${rawBase}/`
  : '/'

export default defineConfig({
  base,
  title: 'Awesome Compression',
  description: '压缩算法学习笔记与 C++ 示例',
  cleanUrls: true,
  lang: 'zh-CN',
  themeConfig: {
    nav: [
      { text: '基础', link: '/zh/guide/compression-basics', activeMatch: '/zh/guide/' },
      { text: '算法', link: '/zh/algorithms/zstd', activeMatch: '/zh/algorithms/' },
      { text: '示例', link: '/zh/examples/cpp-overview', activeMatch: '/zh/examples/' },
      { text: '对比', link: '/zh/comparisons/matrix', activeMatch: '/zh/comparisons/' }
    ],
    sidebar: {
      '/zh/guide/': [
        {
          text: '基础指南',
          items: [
            { text: '压缩基础', link: '/zh/guide/compression-basics' },
            { text: '编码模型', link: '/zh/guide/coding-models' },
            { text: '如何选择算法', link: '/zh/guide/choosing-algorithms' }
          ]
        }
      ],
      '/zh/algorithms/': [
        {
          text: '算法笔记',
          items: [
            { text: 'ZSTD', link: '/zh/algorithms/zstd' },
            { text: 'LZMA', link: '/zh/algorithms/lzma' },
            { text: 'BSC', link: '/zh/algorithms/bsc' },
            { text: 'LZ4', link: '/zh/algorithms/lz4' },
            { text: 'zlib', link: '/zh/algorithms/zlib' },
            { text: 'Brotli', link: '/zh/algorithms/brotli' }
          ]
        }
      ],
      '/zh/examples/': [
        {
          text: 'C++ 示例',
          items: [
            { text: '总览', link: '/zh/examples/cpp-overview' },
            { text: 'ZSTD 示例', link: '/zh/examples/zstd' },
            { text: 'LZMA 示例', link: '/zh/examples/lzma' },
            { text: 'BSC 示例', link: '/zh/examples/bsc' },
            { text: 'LZ4 示例', link: '/zh/examples/lz4' },
            { text: 'zlib 示例', link: '/zh/examples/zlib' },
            { text: 'Brotli 示例', link: '/zh/examples/brotli' }
          ]
        }
      ],
      '/zh/comparisons/': [
        {
          text: '对比与选型',
          items: [
            { text: '对比矩阵', link: '/zh/comparisons/matrix' },
            { text: '场景选型', link: '/zh/comparisons/scenarios' }
          ]
        }
      ]
    },
    outline: [2, 3],
    search: { provider: 'local' },
    socialLinks: [
      { icon: 'github', link: 'https://github.com/AICL-Lab/awesome-compression' }
    ]
  }
})
