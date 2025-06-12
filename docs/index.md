---
layout: home

title: H.S.B.C.R.
titleTemplate: 课程资源共享平台

hero:
  name: HUST SFT-BME Courses Resource
  text: 课程资源共享平台
  tagline: 华科未院生医方向24级课程资料与资源收集
  image:
    src: /Casumi Husteru_01_zen.png
    alt: 项目Logo
  actions:
#    - theme: brand
#      text: 快速开始
#      link: /guide/getting-started
    - theme: brand
      text: 浏览课程
      link: /courses/
    - theme: alt
      text: 项目介绍
      link: /about
    - theme: alt
      text: 贡献资料
      link: /contributing/
    - theme: alt
      text: GitHub 仓库
      link: https://github.com/TurkeyC/HUST_SFTBME_Courses_Resource/

features:
  - icon: 📚
    title: 完整的课程体系
    details: 涵盖大一上下学期所有专业课程，包括课件、作业、真题、实验代码等完整资料
  - icon: 🎯
    title: 精心整理分类
    details: 按学期和课程分类整理，文件命名规范，方便查找和使用
  - icon: 🤝
    title: 开源协作
    details: 采用 MIT 开源协议，欢迎所有同学贡献资料，共同完善资源库
  - icon: 🚀
    title: 持续更新
    details: 定期更新课程资料，添加新的学习资源和考试真题
  - icon: 💡
    title: 学习指导
    details: 提供学习方法、考试技巧和经验分享，帮助同学们更好地学习
  - icon: 🌟
    title: 质量保证
    details: 所有资料经过筛选和验证，确保内容的准确性和实用性
---

<div class="home-content">

## 📊 项目统计

<div class="stats-container">
  <div class="stat-card animate-fade-in">
    <span class="stat-number count-up">20+</span>
    <span class="stat-label">课程覆盖</span>
  </div>
  <div class="stat-card animate-fade-in" style="animation-delay: 0.2s">
    <span class="stat-number count-up">2</span>
    <span class="stat-label">学期内容</span>
  </div>
  <div class="stat-card animate-fade-in" style="animation-delay: 0.4s">
    <span class="stat-number count-up">100+</span>
    <span class="stat-label">资料文件</span>
  </div>
  <div class="stat-card animate-fade-in" style="animation-delay: 0.6s">
    <span class="stat-number">MIT</span>
    <span class="stat-label">开源协议</span>
  </div>
</div>

## 🤗 参与贡献

<div class="contribution-section animate-slide-up">
  <p>我们非常欢迎您的参与！您可以通过以下方式为项目做出贡献：</p>
  
  <ul class="contribution-list">
    <li class="animate-slide-right" style="animation-delay: 0.1s">
      <strong>提交资料</strong>：分享您的课程笔记、作业答案或考试经验
    </li>
    <li class="animate-slide-right" style="animation-delay: 0.2s">
      <strong>报告问题</strong>：发现错误或有改进建议请及时反馈
    </li>
    <li class="animate-slide-right" style="animation-delay: 0.3s">
      <strong>功能建议</strong>：提出新的功能需求或改进建议
    </li>
    <li class="animate-slide-right" style="animation-delay: 0.4s">
      <strong>推荐资源</strong>：推荐优质的学习资源和工具
    </li>
  </ul>
  
  <a href="/contributing" class="contact-link">查看详细的贡献指南 →</a>
</div>

## 📬 联系我们

<div class="contact-section animate-fade-in">
  <p>如果您有任何问题或建议，请通过以下方式联系我们：</p>
  
  <ul class="contribution-list">
    <li class="animate-bounce-in" style="animation-delay: 0.1s">
      <a href="https://github.com/TurkeyC/HUST_SFTBME_Courses_Resource/issues" class="contact-link">
        GitHub Issues: 提交问题
      </a>
    </li>
    <li class="animate-bounce-in" style="animation-delay: 0.2s">
      项目维护者: TurkeyC
    </li>
    <li class="animate-bounce-in" style="animation-delay: 0.3s">
      许可协议: MIT License
    </li>
  </ul>
</div>

<div class="divider animate-width"></div>

<p class="footer-note animate-fade-in">
  <em>本项目旨在为华中科技大学未来技术学院生医方向的同学们提供便利的学习资源，促进学术交流与合作。所有资料仅供学习参考使用。</em>
</p>

</div>

<style>
.home-content {
  max-width: 1200px;
  margin: 0 auto;
  padding: 2rem 1rem;
}

/* 统计卡片样式 */
.stats-container {
  display: flex;
  flex-wrap: wrap;
  justify-content: center;
  gap: 1.5rem;
  margin: 2rem 0;
}

.stat-card {
  background: var(--vp-c-bg-soft);
  border-radius: 12px;
  padding: 1.5rem;
  min-width: 160px;
  text-align: center;
  box-shadow: 0 4px 12px rgba(0, 0, 0, 0.05);
  transition: transform 0.3s, box-shadow 0.3s;
  display: flex;
  flex-direction: column;
  align-items: center;
}

.stat-card:hover {
  transform: translateY(-6px);
  box-shadow: 0 12px 24px rgba(0, 0, 0, 0.08);
}

.stat-number {
  font-size: 2.5rem;
  font-weight: 700;
  color: var(--vp-c-brand);
  margin-bottom: 0.5rem;
}

.stat-label {
  font-size: 1rem;
  color: var(--vp-c-text-2);
}

/* 贡献部分样式 */
.contribution-section, .contact-section {
  margin: 2rem 0;
  padding: 1.5rem;
  background: var(--vp-c-bg-soft);
  border-radius: 12px;
  box-shadow: 0 4px 12px rgba(0, 0, 0, 0.05);
}

.contribution-list, .contact-list {
  padding-left: 1rem;
  margin: 1.5rem 0;
}

.contribution-list li, .contact-list li {
  margin-bottom: 0.8rem;
  position: relative;
  padding-left: 1.5rem;
  list-style: none;
}

.contribution-list li::before {
  content: "•";
  color: var(--vp-c-brand);
  font-weight: bold;
  position: absolute;
  left: 0;
}

/* 联系我们样式 */
.contact-link {
  color: var(--vp-c-brand);
  text-decoration: none;
  transition: color 0.3s;
}

.contact-link:hover {
  color: var(--vp-c-brand-dark);
  text-decoration: underline;
}

.icon {
  margin-right: 0.5rem;
}

/* 分隔线 */
/*.divider {*/
/*  height: 2px;*/
/*  background: linear-gradient(90deg, transparent, var(--vp-c-divider), transparent);*/
/*  margin: 2rem auto;*/
/*  width: 80%;*/
/*}*/

.footer-note {
  text-align: center;
  color: var(--vp-c-text-2);
  font-size: 0.9rem;
  margin-top: 2rem;
}

/* 动画效果 */
.animate-fade-in {
  opacity: 0;
  animation: fadeIn 1s ease forwards;
}

.animate-slide-up {
  opacity: 0;
  transform: translateY(30px);
  animation: slideUp 0.8s ease forwards;
}

.animate-slide-right {
  opacity: 0;
  transform: translateX(-30px);
  animation: slideRight 0.8s ease forwards;
}

.animate-bounce-in {
  opacity: 0;
  transform: scale(0.8);
  animation: bounceIn 0.6s ease forwards;
}

.animate-pulse {
  animation: pulse 2s infinite;
}

.animate-width {
  width: 0;
  animation: expandWidth 1.5s ease forwards;
}

.count-up {
  animation: countUp 2s ease-out forwards;
}

@keyframes fadeIn {
  to { opacity: 1; }
}

@keyframes slideUp {
  to { opacity: 1; transform: translateY(0); }
}

@keyframes slideRight {
  to { opacity: 1; transform: translateX(0); }
}

@keyframes bounceIn {
  0% { opacity: 0; transform: scale(0.8); }
  70% { opacity: 1; transform: scale(1.05); }
  100% { opacity: 1; transform: scale(1); }
}

@keyframes pulse {
  0% { transform: scale(1); }
  50% { transform: scale(1.05); }
  100% { transform: scale(1); }
}

@keyframes expandWidth {
  to { width: 80%; }
}

@keyframes countUp {
  from { opacity: 0; transform: translateY(20px); }
  to { opacity: 1; transform: translateY(0); }
}

/* 响应式设计 */
@media (max-width: 768px) {
  .stats-container {
    flex-direction: column;
    align-items: center;
    gap: 1rem;
  }
  
  .stat-card {
    width: 90%;
  }
}
</style>
