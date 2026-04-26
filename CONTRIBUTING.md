# 贡献指南

## 如何运行项目

### 前提条件

- C++ 编译器 (支持 C++23)
- CMake 3.10+
- Git

### 构建和运行步骤

1. **克隆仓库**:
   ```bash
   git clone <repository-url>
   cd EventDrivenTradingEngine
   ```

2. **构建项目**:
   ```bash
   mkdir build
   cd build
   cmake ..
   make
   ```

3. **运行引擎**:
   ```bash
   ./engine
   ```

4. **查看输出**:
   - 终端显示交易过程
   - 检查 `data/signals.csv` 和 `data/trades.csv` 文件

### 开发环境设置

**推荐开发环境**: GitHub Codespaces

GitHub Codespaces 提供了一个预配置的云开发环境，包含所有必要的工具和依赖，无需本地安装。项目已针对 Codespaces 优化，开箱即用。

- **如何使用 Codespaces**:
  1. 在 GitHub 仓库页面点击 "Code" 按钮
  2. 选择 "Codespaces" 标签
  3. 点击 "Create codespace on main"
  4. 等待环境初始化完成

- **Codespaces 优势**:
  - 预装 C++23 编译器、CMake 和 VS Code 扩展
  - 自动配置构建工具和调试环境
  - 无需担心本地环境配置问题
  - 支持实时协作

**替代本地环境**:
- 使用支持 C++23 的 IDE (如 VS Code with C++ extension, CLion)
- 配置 CMake 工具以便调试
- 确保数据文件路径正确 (通过符号链接自动处理)

## 参与贡献

### 代码风格

- 使用现代 C++ 特性 (C++23)
- 遵循 RAII 原则
- 使用描述性变量和函数名
- 添加必要的注释

### 提交规范

- 使用清晰的提交消息
- 每个提交专注于单一功能
- 在提交前运行测试

### 贡献流程

1. Fork 本仓库
2. 创建功能分支: `git checkout -b feature/new-feature`
3. 提交更改: `git commit -m "Add new feature"`
4. 推送分支: `git push origin feature/new-feature`
5. 创建 Pull Request

## 测试项目

### 手动测试

1. **运行引擎**: 执行 `./engine` 并观察输出
2. **验证数据**: 检查生成的 CSV 文件是否正确
3. **边界测试**: 使用不同数据文件测试
4. **中断测试**: 使用 Ctrl+C 测试程序终止

### 单元测试

目前项目无内置测试框架。如需添加测试：

1. 集成 Google Test 或 Catch2
2. 为每个模块编写单元测试
3. 测试关键函数: `computeSignal`, `executeBuy`, `updateRisk`

### 性能测试

- 测试大数据集的处理时间
- 监控内存使用
- 验证循环重放的稳定性

### 数据验证

- 确保 CSV 文件格式正确
- 验证价格数据的合理性
- 检查交易逻辑的正确性

## 调试技巧

- 使用 `std::cout` 输出调试信息
- 在关键函数中添加断点
- 检查 CSV 输出以验证状态变化
- 使用 Valgrind 检查内存泄漏

## 常见问题

### 构建失败
- 确认 C++ 编译器版本
- 检查 CMake 版本
- 验证所有源文件存在

### 运行时错误
- 确认数据文件存在且格式正确
- 检查文件路径 (使用相对路径)
- 查看终端错误消息

### 数据问题
- 确保 CSV 第一行为表头
- 验证日期和价格格式
- 检查文件编码 (UTF-8)

## 扩展项目

### 添加新功能
- 实现新策略算法
- 扩展风险管理规则
- 支持多种资产类型
- 添加实时数据源

### 改进架构
- 引入多线程处理
- 添加配置系统
- 实现插件架构
- 集成数据库存储

欢迎任何改进建议和代码贡献！