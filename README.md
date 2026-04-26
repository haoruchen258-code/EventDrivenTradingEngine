# EventDrivenTradingEngine

## 项目描述

EventDrivenTradingEngine 是一个用 C++ 实现的事件驱动交易引擎。该引擎模拟实时交易环境，通过处理市场数据（ticks）来执行交易策略、管理投资组合并控制风险。

## 用途

该项目旨在演示事件驱动架构在金融交易中的应用。它可以：

- 加载历史市场数据（CSV 格式）
- 应用简单的移动平均线交易策略
- 执行买入和卖出操作
- 管理投资组合现金和持仓
- 监控风险指标，如最大回撤
- 生成交易日志和信号记录

## 使用的语言和技术

- **编程语言**: C++ (标准 C++23)
- **构建工具**: CMake
- **依赖**: 仅使用 C++ 标准库，无外部依赖
- **数据格式**: CSV 文件用于市场数据和日志输出

## 构建和运行

### 前提条件

- C++ 编译器支持 C++23 (如 GCC 11+ 或 Clang 14+)
- CMake 3.10+

### 构建步骤

1. 克隆仓库：
   ```bash
   git clone <repository-url>
   cd EventDrivenTradingEngine
   ```

2. 创建构建目录：
   ```bash
   mkdir build
   cd build
   ```

3. 配置和构建：
   ```bash
   cmake ..
   make
   ```

### 运行

在构建目录中运行：
```bash
./engine
```

引擎将加载 `data/tr_eikon_eod_data.csv` 中的数据，模拟交易过程，并输出结果到终端。同时生成 `data/signals.csv` 和 `data/trades.csv` 日志文件。

## 数据文件

- `data/tr_eikon_eod_data.csv`: 市场数据（日期和价格）
- `data/signals.csv`: 生成的信号日志
- `data/trades.csv`: 生成的交易日志

## 许可证

[添加许可证信息，如果适用]
