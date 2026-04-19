import matplotlib
matplotlib.use('Agg')
import matplotlib.pyplot as plt
import pandas as pd
import matplotlib.dates as mdates
import os

signals_path = "data/signals.csv"
trades_path = "data/trades.csv"

if not os.path.exists(signals_path):
    print(f"错误：找不到 {signals_path}")
    print("请先运行 C++ 引擎（./build/engine）生成数据文件，再执行本脚本。")
    exit(1)

signals = pd.read_csv(signals_path, parse_dates=["Date"])   

fig, axes = plt.subplots(3, 1, figsize=(14, 10), sharex=True)
fig.suptitle("Event-Driven Trading Engine — Performance Report", fontsize=14)

ax1 = axes[0]
ax1.plot(signals["Date"], signals["NetValue"],
         color="steelblue", linewidth=1.2, label="Net Value")

# 画一条初始资金（10000）的水平参考线，方便判断是盈利还是亏损
ax1.axhline(y=10000, color="gray", linestyle="--", linewidth=0.8, label="Initial Capital (10000)")

ax1.set_ylabel("Net Value (USD)")          # Y 轴标签
ax1.set_title("① Equity Curve")           # 子图标题
ax1.legend(loc="upper left", fontsize=8)  # 图例（loc 控制位置）
ax1.grid(True, alpha=0.3)                 # 背景网格，alpha 控制透明度

ax2 = axes[1]
drawdown_pct = signals["Drawdown"] * 100   # 转换为百分比

ax2.fill_between(signals["Date"], drawdown_pct, 0,
                 color="tomato", alpha=0.5, label="Drawdown")
ax2.plot(signals["Date"], drawdown_pct,
         color="tomato", linewidth=0.8)

# 画一条 10% 熔断阈值的参考线（与 risk.h 中的 limit = 0.10 对应）
ax2.axhline(y=10.0, color="darkred", linestyle="--",
            linewidth=1.0, label="Circuit Breaker (10%)")

ax2.set_ylabel("Drawdown (%)")
ax2.set_title("② Drawdown")
ax2.legend(loc="lower left", fontsize=8)
ax2.grid(True, alpha=0.3)

ax3 = axes[2]
ax3.plot(signals["Date"], signals["Price"],
         color="gray", linewidth=0.8, label="Price")

# 只有在有成交记录时才绘制标记（避免 scatter 收到空数据报警告）
# if not buys.empty:
#     ax3.scatter(buys["Date"], buys["Price"],
#                 marker="^", color="green", s=60, zorder=5, label="BUY")

# if not sells.empty:
#     ax3.scatter(sells["Date"], sells["Price"],
#                 marker="v", color="red",   s=60, zorder=5, label="SELL")

ax3.set_ylabel("Price (USD)")
ax3.set_title("③ Price Chart with Trade Signals")
ax3.legend(loc="upper left", fontsize=8)
ax3.grid(True, alpha=0.3)

ax3.xaxis.set_major_locator(mdates.AutoDateLocator())
ax3.xaxis.set_major_formatter(mdates.AutoDateFormatter(mdates.AutoDateLocator()))
fig.autofmt_xdate(rotation=45)  # 将日期标签旋转 45 度，防止重叠

plt.tight_layout(rect=[0, 0, 1, 0.95])

# 保存路径：data/report.png
# dpi=150：每英寸 150 像素，适合屏幕展示（dpi=300 适合打印，文件更大）
output_path = "data/report.png"
plt.savefig(output_path, dpi=150)

print(f"报告已生成：{output_path}")
print("使用文件管理器或浏览器打开该 PNG 文件即可查看图表。")

