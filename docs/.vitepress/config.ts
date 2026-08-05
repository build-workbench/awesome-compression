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
  locales: {
    root: {
      label: '简体中文',
      lang: 'zh-CN',
      title: 'Awesome Compression',
      description: '压缩算法学习笔记与 C++ 示例',
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
        }
      }
    },
    en: {
      label: 'English',
      lang: 'en-US',
      link: '/en/',
      title: 'Awesome Compression',
      description: 'Compression algorithm notes and C++ examples',
      themeConfig: {
        nav: [
          { text: 'Basics', link: '/en/guide/compression-basics', activeMatch: '/en/guide/' },
          { text: 'Algorithms', link: '/en/algorithms/zstd', activeMatch: '/en/algorithms/' },
          { text: 'Examples', link: '/en/examples/cpp-overview', activeMatch: '/en/examples/' },
          { text: '中文', link: '/zh/' }
        ],
        sidebar: {
          '/en/guide/': [
            {
              text: 'Guide',
              items: [
                { text: 'Compression Basics', link: '/en/guide/compression-basics' }
              ]
            }
          ],
          '/en/algorithms/': [
            {
              text: 'Algorithm Notes',
              items: [
                { text: 'ZSTD', link: '/en/algorithms/zstd' }
              ]
            }
          ],
          '/en/examples/': [
            {
              text: 'C++ Examples',
              items: [
                { text: 'Overview', link: '/en/examples/cpp-overview' },
                { text: 'ZSTD Example', link: '/en/examples/zstd' },
                { text: 'LZMA Example', link: '/en/examples/lzma' },
                { text: 'BSC Example', link: '/en/examples/bsc' },
                { text: 'LZ4 Example', link: '/en/examples/lz4' },
                { text: 'zlib Example', link: '/en/examples/zlib' },
                { text: 'Brotli Example', link: '/en/examples/brotli' }
              ]
            }
          ]
        }
      }
    }
  },
  themeConfig: {
    outline: [2, 3],
    search: { provider: 'local' },
    socialLinks: [
      { icon: 'github', link: 'https://github.com/AICL-Lab/awesome-compression' }
    ]
  }
})
