import { defineConfig } from 'vitepress'

export default defineConfig({
  base: '/HUST_SFTBME_Courses_Resource/',
  title: 'H.S.B.C.R.',
  description: '课程资源共享平台',
  // 添加网站图标配置
  head: [
    // 基本图标
    ['link', { rel: 'icon', href: '/images/Casumi_Husteru_n5_Ai.svg' }],
    // 苹果设备图标
    ['link', { rel: 'apple-touch-icon', href: '/apple-touch-icon.png', sizes: '180x180' }],
    // 不同尺寸的图标
    ['link', { rel: 'icon', type: 'image/png', href: '/favicon-32x32.png', sizes: '32x32' }],
    ['link', { rel: 'icon', type: 'image/png', href: '/favicon-16x16.png', sizes: '16x16' }],
  ],
  // 配置深色模式
  appearance: true, // 启用深色模式切换
  themeConfig: {
    // 启用导航栏中的深色模式切换按钮
    darkModeSwitchLabel: '外观',
    sidebarMenuLabel: '菜单',
    returnToTopLabel: '返回顶部',

    // 社交链接中也可以添加深色模式适配的图标
    nav: [
      { text: '课程资源', link: '/courses/' },
      { text: '参与贡献', link: 'contributing'},
      { text: '关于我们', link: '/about' },
      // { text: '指南', link: '/guide/introduction' },
      // { text: 'API', link: '/api/' },
    ],

    // 添加底栏配置
    footer: {
      message: '使用 VitePress 构建, Ciallo～(∠・ω< )⌒☆',
      copyright: 'Copyright © 2024-2025 TurkeyC. All Rights Reserved.'
    },

    // 添加社交链接 (可选)
    socialLinks: [
      { icon: 'github', link: 'https://github.com/turkeyc' },
      // 可以添加更多社交链接
      { icon: 'discord', link: 'https://discord.gg/SvVjHSJUQz' },
      { icon: 'bilibili', link: 'https://space.bilibili.com/525362869' },
      { icon: 'reddit', link: 'https://www.reddit.com/user/TurkeyC' },
      { icon: 'tiktok', link: '非常抱歉,我不用这个' },
    ],

    sidebar: {
      '/courses/': [
        {
          text: '大一上学期 (IA)',
          items: [
            { text: '工程制图（一）', link: '/courses/IA/engineering-drawing' },
            { text: '科学思维与研究方法', link: '/courses/IA/scientific-thinking' },
            { text: '软件技术基础', link: '/courses/IA/software-foundation' },
            { text: '思想道德与法治', link: '/courses/IA/moral-law' },
            { text: '微积分A（上）', link: '/courses/IA/calculus-a-1' },
            { text: '线性代数（A）', link: '/courses/IA/linear-algebra' },
            { text: '学术英语读写', link: '/courses/IA/academic-english-rw' },
            { text: '综合英语（一）', link: '/courses/IA/comprehensive-english-1' },
            { text: '中国语文', link: '/courses/IA/chinese-literature' }
          ]
        },
        {
          text: '大一下学期 (IB)',
          items: [
            { text: '大学生批判性思维', link: '/courses/IB/critical-thinking' },
            { text: '大学物理（上）', link: '/courses/IB/university-physics-1' },
            { text: '工程导论', link: '/courses/IB/engineering-intro' },
            { text: '概率论与数理统计', link: '/courses/IB/probability-statistics' },
            { text: '军事理论', link: '/courses/IB/military-theory' },
            { text: '普通化学', link: '/courses/IB/general-chemistry' },
            { text: '微积分A（下）', link: '/courses/IB/calculus-a-2' },
            { text: '物理实验（上）', link: '/courses/IB/physics-experiment-1' },
            { text: '学术英语', link: '/courses/IB/academic-english' },
            { text: '元宇宙导论', link: '/courses/IB/metaverse-intro' },
            { text: '中国近现代史纲要', link: '/courses/IB/modern-chinese-history' }
          ]
        }
      ]
      // ,
      // '/guide/': [
      //   {
      //     text: '指南',
      //     items: [
      //       { text: '项目介绍', link: '/guide/introduction' },
      //       { text: '快速开始', link: '/guide/getting-started' },
      //     ]
      //   }
      // ],
      // '/api/': [
      //   {
      //     text: 'API 参考',
      //     items: [
      //       { text: 'API 概览', link: '/api/' },
      //       { text: '配置', link: '/api/config' },
      //       { text: '主题', link: '/api/theme' },
      //     ]
      //   }
      // ]
    },
    // 编辑此页
    editLink: {
      pattern: 'https://github.com/TurkeyC/HUST_SFTBME_Courses_Resource/edit/main/docs/:path',
      text: '在 GitHub 上编辑此页'
    },    // 最后更新时间
    lastUpdated: {
      text: '最后更新',
      formatOptions: {
        dateStyle: 'short',
        timeStyle: 'medium'
      }
    }
  }
})
