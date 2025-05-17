import { useState, useEffect } from 'react';

export default function App() {
  const [currentPage, setCurrentPage] = useState('cover');
  const [bookOpen, setBookOpen] = useState(false);
  const [scrollPosition, setScrollPosition] = useState(0);
  const [showBackToTop, setShowBackToTop] = useState(false);

  // 页面内容数据
  const pages = {
    cover: {
      title: "武汉红色寻访的体会与思考",
      subtitle: "穿越时空的红色记忆之旅",
      buttonText: "翻开书页"
    },
    intro: {
      title: "前言",
      content: "这是一次穿越历史的旅程，从辛亥革命博物馆到中共五大会址，再到毛泽东故居。通过这次红色寻访，我不仅重温了那段波澜壮阔的历史，更深刻理解了今日中国发展的根源。",
      image: "https://picsum.photos/seed/book1/800/600 "
    },
    museum: {
      title: "辛亥革命博物馆",
      content: "走进辛亥革命博物馆，仿佛置身于1911年的武昌街头。这里用先进的声光电技术重现了起义当晚的情景：夜色中，革命军高举火把冲向总督府，枪声打破了沉寂的夜空。\n\n站在孙中山先生手书的《礼运·大同篇》真迹前，我忽然明白，辛亥革命不仅是推翻帝制的胜利，更是中国人对现代国家制度的初次探索。这种探索精神，在今天依然激励着我们不断前进。",
      image: "https://picsum.photos/seed/book2/800/600 "
    },
    conference: {
      title: "中共五大会议旧址",
      content: "在武昌都府堤20号的会议厅里，一切都保持着1927年4月的原貌。当年，毛泽东、刘少奇等共产党人正是在这里，面对白色恐怖，提出了建立农民武装的重要主张。\n\n看着那些泛黄的会议记录和代表们的手稿，我深深感受到理想主义的力量。那个年代的年轻人，他们放弃优渥生活，投身革命，不是为了个人得失，而是为了一个更美好的社会愿景。这种精神，在今天依然具有现实意义。",
      image: "https://picsum.photos/seed/book3/800/600 "
    },
    residence: {
      title: "毛泽东故居",
      content: "走进毛泽东同志1927年居住过的房间，一张简陋的木床、一盏煤油灯、几张旧书桌，这就是一代伟人曾经的生活环境。\n\n就是在这样艰苦的条件下，毛泽东写下了《湖南农民运动考察报告》，为中国革命指明了方向。这种艰苦奋斗的精神，在今天依然值得我们学习。特别是在这个物质丰富的时代，我们更需要保持清醒的头脑，不忘来时路。",
      image: "https://picsum.photos/seed/book4/800/600 "
    },
    reflection: {
      title: "反思与展望",
      content: "这次红色寻访让我意识到，历史并不是遥不可及的故事，而是活生生地存在于我们的现实之中。辛亥革命的民主思想、中共五大确立的群众路线、毛泽东倡导的实事求是原则，这些都是我们今天社会发展的重要基石。\n\n站在新的历史起点上，我们既要缅怀先烈，更要继承他们的精神。面对复杂的国际形势和国内发展挑战，我们需要更多脚踏实地的实干家，也需要更多敢于创新的思想者。",
      image: "https://picsum.photos/seed/book5/800/600 "
    }
  };

  // 模拟时间跟踪
  useEffect(() => {
    let startTime = Date.now();
    let timer;

    if (currentPage !== 'cover') {
      timer = setInterval(() => {
        const elapsed = Math.floor((Date.now() - startTime) / 1000);
        if (elapsed >= 420) { // 7分钟 = 420秒
          clearInterval(timer);
          alert("您已阅读超过7分钟，感谢您的认真阅读！");
        }
      }, 1000);
    }

    return () => {
      if (timer) clearInterval(timer);
    };
  }, [currentPage]);

  // 监听滚动位置
  useEffect(() => {
    const handleScroll = () => {
      const position = window.scrollY;
      setScrollPosition(position);
      setShowBackToTop(position > 300);
    };

    window.addEventListener('scroll', handleScroll);
    return () => window.removeEventListener('scroll', handleScroll);
  }, []);

  // 返回顶部
  const scrollToTop = () => {
    window.scrollTo({ top: 0, behavior: 'smooth' });
  };

  // 翻页动画
  const flipPage = (page) => {
    setBookOpen(true);
    setTimeout(() => {
      setCurrentPage(page);
      setBookOpen(false);
    }, 800);
  };

  // 书本翻页SVG组件
  const BookFlipIcon = () => (
    <svg className="w-6 h-6" viewBox="0 0 24 24" fill="currentColor">
      <path d="M12 4L4 12H9V20L12 18L15 20V12H20L12 4Z" />
    </svg>
  );

  // 返回顶部SVG组件
  const ArrowUpIcon = () => (
    <svg className="w-5 h-5" viewBox="0 0 24 24" fill="none" stroke="currentColor" strokeWidth="2">
      <path d="M12 19V5M5 12l7-7 7 7" strokeLinecap="round" strokeLinejoin="round" />
    </svg>
  );

  // 首页封面
  const CoverPage = () => (
    <div className="relative min-h-screen flex items-center justify-center bg-gradient-to-br from-gray-900 via-black to-gray-800 text-white overflow-hidden">
      {/* 背景动态效果 */}
      <div className="absolute inset-0 z-0 opacity-30">
        {[...Array(30)].map((_, i) => (
          <div
            key={i}
            className="absolute rounded-full bg-white mix-blend-screen filter blur-xl animate-pulse"
            style={{
              width: `${Math.random() * 20 + 10}px`,
              height: `${Math.random() * 20 + 10}px`,
              top: `${Math.random() * 100}%`,
              left: `${Math.random() * 100}%`,
              animationDuration: `${Math.random() * 5 + 3}s`
            }}
          ></div>
        ))}
      </div>

      {/* 封面内容 */}
      <div className="relative z-10 text-center px-6 max-w-3xl">
        <h1 className="text-5xl md:text-6xl font-bold mb-6 tracking-wider leading-tight font-serif italic">
          {pages.cover.title}
        </h1>
        <p className="text-xl md:text-2xl mb-10 text-gray-300">{pages.cover.subtitle}</p>
        <button
          onClick={() => flipPage('intro')}
          className="px-8 py-3 bg-transparent border-2 border-white text-white rounded-full hover:bg-white hover:text-gray-900 transition-all duration-300 transform hover:scale-105 focus:outline-none focus:ring-2 focus:ring-white focus:ring-opacity-50"
        >
          {pages.cover.buttonText} <BookFlipIcon />
        </button>
      </div>

      {/* 书本边框装饰 */}
      <div className="absolute inset-0 pointer-events-none">
        <div className="border-4 border-gray-700 opacity-30 absolute top-0 left-0 right-0 bottom-0"></div>
        <div className="border-l-4 border-b-4 border-gray-700 opacity-30 absolute top-0 left-0 w-16 h-16"></div>
        <div className="border-r-4 border-b-4 border-gray-700 opacity-30 absolute top-0 right-0 w-16 h-16"></div>
        <div className="border-l-4 border-t-4 border-gray-700 opacity-30 absolute bottom-0 left-0 w-16 h-16"></div>
        <div className="border-r-4 border-t-4 border-gray-700 opacity-30 absolute bottom-0 right-0 w-16 h-16"></div>
      </div>
    </div>
  );

  // 内容页面模板
  const ContentPage = ({ pageKey }) => {
    const page = pages[pageKey];

    return (
      <div className={`min-h-screen py-20 px-4 sm:px-6 lg:px-8 bg-fixed ${bookOpen ? 'opacity-0' : 'opacity-100'} transition-opacity duration-700`}>
        <div className="max-w-4xl mx-auto">
          {/* 页面标题 */}
          <div className="mb-12">
            <h2 className="text-4xl font-bold mb-4 text-transparent bg-clip-text bg-gradient-to-r from-amber-700 to-orange-500 relative pb-2 after:content-[''] after:absolute after:bottom-0 after:left-0 after:w-24 after:h-1 after:bg-gradient-to-r after:from-amber-700 after:to-orange-500">
              {page.title}
            </h2>
          </div>

          {/* 页面内容 */}
          <div className="grid grid-cols-1 md:grid-cols-2 gap-8 items-center animate-fadeIn">
            <div className="order-2 md:order-1">
              <p className="text-lg leading-relaxed text-gray-800 whitespace-pre-line font-serif">
                {page.content}
              </p>
            </div>
            <div className="order-1 md:order-2 rounded-lg overflow-hidden shadow-xl transform transition-transform duration-500 hover:scale-105">
              <img src={page.image} alt={page.title} className="w-full h-auto object-cover" />
            </div>
          </div>

          {/* 导航按钮 */}
          <div className="mt-16 flex justify-between">
            <button
              onClick={() => flipPage(Object.keys(pages).find(key => Object.keys(pages).indexOf(key) === Object.keys(pages).indexOf(pageKey) - 1))}
              disabled={!Object.keys(pages).find(key => Object.keys(pages).indexOf(key) === Object.keys(pages).indexOf(pageKey) - 1)}
              className={`px-6 py-2 rounded-full ${Object.keys(pages).find(key => Object.keys(pages).indexOf(key) === Object.keys(pages).indexOf(pageKey) - 1) ? 'bg-amber-700 text-white hover:bg-amber-800' : 'bg-gray-300 text-gray-600 cursor-not-allowed'} transition-colors`}
            >
              上一页
            </button>
            <button
              onClick={() => flipPage(Object.keys(pages).find(key => Object.keys(pages).indexOf(key) === Object.keys(pages).indexOf(pageKey) + 1))}
              disabled={!Object.keys(pages).find(key => Object.keys(pages).indexOf(key) === Object.keys(pages).indexOf(pageKey) + 1)}
              className={`px-6 py-2 rounded-full ${Object.keys(pages).find(key => Object.keys(pages).indexOf(key) === Object.keys(pages).indexOf(pageKey) + 1) ? 'bg-amber-700 text-white hover:bg-amber-800' : 'bg-gray-300 text-gray-600 cursor-not-allowed'} transition-colors`}
            >
              下一页
            </button>
          </div>
        </div>
      </div>
    );
  };

  // 返回顶部按钮
  const BackToTopButton = () => (
    <button
      onClick={scrollToTop}
      className={`fixed bottom-8 right-8 p-3 rounded-full bg-amber-700 text-white shadow-lg transform transition-all duration-300 ${
        showBackToTop ? 'opacity-100 translate-y-0' : 'opacity-0 translate-y-10 pointer-events-none'
      } hover:bg-amber-800 focus:outline-none focus:ring-2 focus:ring-offset-2 focus:ring-amber-500`}
      aria-label="回到顶部"
    >
      <ArrowUpIcon />
    </button>
  );

  // 动态书本翻页效果
  const BookAnimation = () => (
    <div className={`fixed inset-0 pointer-events-none z-50 ${bookOpen ? 'block' : 'hidden'}`}>
      <div className="absolute left-0 top-0 bottom-0 w-1/2 bg-gradient-to-r from-black to-transparent opacity-70"></div>
      <div className="absolute right-0 top-0 bottom-0 w-1/2 bg-gradient-to-l from-black to-transparent opacity-70"></div>
      <div className="absolute left-0 top-0 bottom-0 w-full overflow-hidden">
        <div className="absolute top-0 left-0 w-full h-full book-page-flip"></div>
      </div>
    </div>
  );

  // 根据当前页面渲染内容
  const renderContent = () => {
    if (currentPage === 'cover') {
      return <CoverPage />;
    } else if (Object.keys(pages).includes(currentPage)) {
      return <ContentPage pageKey={currentPage} />;
    }
    return null;
  };

  return (
    <div className="font-sans antialiased">
      {renderContent()}
      <BackToTopButton />
      <BookAnimation />
    </div>
  );
}