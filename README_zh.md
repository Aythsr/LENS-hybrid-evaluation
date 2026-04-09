# LENS

一个轻量级的混合仿真框架，作为中间层连接模拟（Docker）与仿真（ns3）

基于 [ns3-3.45](https://gitlab.com/nsnam/ns-3-dev/-/tree/ns-3.45) 进行扩展开发

整体使用方式与tap-bridge类似，但是内部结构与实现逻辑完全重写。

## 项目定位

LENS 主要用于将容器侧的真实协议栈与 ns-3 仿真网络进行桥接，适合以下场景：

- 需要在真实应用进程和可控网络模型之间进行联调。
- 需要复现实验拓扑，同时保留容器部署方式。
- 需要对调度、时序与链路行为进行可重复的混合实验。

## 目录说明

- `contrib/tap-bridgev2/`：核心扩展模块。
- `contrib/tap-bridgev2/model/`：桥接逻辑、调度器、时序控制与相关实现。
- `contrib/tap-bridgev2/examples/`：示例程序与虚拟网络脚本。

### 使用方式

1. 下载 [ns-3.45](https://gitlab.com/nsnam/ns-3-dev/-/tree/ns-3.45)。

2. 将本仓库中的 `contrib/tap-bridgev2` 拷贝到 ns-3 的 `contrib/` 目录下。

3. 创建 Python 虚拟环境并安装依赖：

```bash
python3 -m venv .venv
source .venv/bin/activate
pip install -r requirements.txt
```

4. 在 ns-3 根目录中编译项目。

## 说明

- 本项目与经典 tap-bridge 在使用方式上相近，但内部结构与实现逻辑已重写。
- 建议优先参考 `contrib/tap-bridgev2/examples/` 中的示例和脚本进行验证。
- 核心代码将在论文接收后开源