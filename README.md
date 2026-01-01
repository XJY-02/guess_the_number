# 猜数字游戏 - C++面向对象练习项目

一个用于练习C++面向对象基础的控制台猜数字游戏，重点在于从C语言过程式思维向C++对象式思维的过渡。

## 项目简介
实现基本的猜数字游戏：AI生成随机数，玩家猜测，AI提示大小直到猜中。通过这个简单项目练习C++的类设计、多文件组织和基本的工程化思维。

## 核心实现
- **Game类**：游戏主循环和流程控制
- **AI类**：生成随机数并判断猜测结果
- **Player类**：处理玩家输入，包含输入验证
- **GameStats类**：记录游戏数据

## 项目结构
```
项目根目录/
├── include/           # 头文件目录
│   ├── Game.h
│   ├── AI.h
│   ├── Player.h
│   └── GameStats.h
├── src/              # 源文件目录
│   ├── main.cpp
│   ├── Game.cpp
│   ├── AI.cpp
│   ├── Player.cpp
│   └── GameStats.cpp
└── build/            # 编译输出目录
```

## 设计思想体现

### 📝 面向对象设计原则应用
- **单一职责原则**：每个类专注于单一功能
  - `Game`只负责流程控制
  - `AI`只负责出题和判断
  - `Player`只负责输入处理
  - `GameStats`只负责数据统计

- **组合模式**：`Game`通过包含（has-a）`AI`、`Player`和`GameStats`对象来构建完整游戏

- **依赖注入思想**：通过接口设计降低类间耦合度，为未来扩展（如更换AI算法）留下空间

## 编译运行
```bash
# 编译（需要C++17支持）
g++ -std=c++17 -I./include src/*.cpp -o build/program.exe

# 运行
./build/guess_game
```
---
开始游戏：./build/program.exe