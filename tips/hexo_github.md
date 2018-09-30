# Hexo + github 搭建个人博客
## Hexo 安装
安装Hexo
> npm install hexo-cli -g

generate 生成静态文件。
> hexo g

server 启动服务器。
> hexo s

deploy 部署网站。部署网站前，需要预先生成静态文件。
> hexo d

clean 清除缓存文件 (db.json) 和已生成的静态文件 (public)。
> hexo clean

卸载Hexo

> npm uninstall hexo-cli -g

初始化 Hexo
>hexo init 

更换主题
> git clone https://github.com/iissnan/hexo-theme-next themes/next

## 换主题
修改_config.yml的主题 
> theme: next

站点初始设置_config.yml
> title: 若水阁
subtitle:
description: stay hungry stay foolish
keywords: C++, Haskell, Rust, 高性能计算, 生物信息,分布式存储,分布式计算
author: 王延龙
language: zh-Hans
timezone: Asia/Shanghai

配置个人博客地址math715.github.io
> deploy:
  type: git
  repo: https://github.com/math715/math715.github.io.git
  branch: master

设置主题风格 (修改 hemes/next下的_config.yml文件)
> scheme : Pisces

创建菜单项对应文件目录,以分类为例
```Bash
hexo new page categories
echo "categories: C++" >> source/categories/index.md
```

创建文章
```Bash
hexo new post "title"

# 删除文章
hexo clean 
rm source/_post/title.md
hexo g
```

创建标签目录
```Bash
hexo new page tags
echo "type: "tags" # 设置页面类型" >> source/tags/indel.md
```

侧边栏设置
```Bash
vim themes/next/_config.yml
# 增加内容
social:
  GitHub: https://github.com/math715 
social_icons:
  enable: true
  GitHub: github
```

[hexo 默认配置文件](./default_config.yml)
[next主题配置文件](./next_config.yml)