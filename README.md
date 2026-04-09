# LENS

A lightweight hybrid framework that bridges emulation (Docker containers) and simulation (ns-3).

Built as an extension on top of [ns-3.45](https://gitlab.com/nsnam/ns-3-dev/-/tree/ns-3.45).

Although the usage is similar to tap-bridge, the internal architecture and implementation are fully rewritten.

## Project Scope

LENS is designed to connect real container-side protocol stacks with ns-3 network simulation, which is useful for:

- Joint debugging between real applications and controlled network models.
- Reproducible hybrid experiments while keeping container-based deployment.
- Experiments that require explicit control over scheduling, timing, and link behavior.

## Repository Layout

- `contrib/tap-bridgev2/`: core extension module.
- `contrib/tap-bridgev2/model/`: bridge logic, schedulers, timing control, and related implementations.
- `contrib/tap-bridgev2/examples/`: example programs and virtual networking scripts.

## Usage

1. Download [ns-3.45](https://gitlab.com/nsnam/ns-3-dev/-/tree/ns-3.45).
2. Copy `contrib/tap-bridgev2` from this repository into the `contrib/` directory of ns-3.
3. Create a Python virtual environment and install dependencies:

```bash
python3 -m venv .venv
source .venv/bin/activate
pip install -r requirements.txt
```

4. Build the ns-3 project from its root directory.

## Notes

- LENS follows a tap-bridge-like workflow, but its internal design and behavior are reimplemented.
- Start with the content in `contrib/tap-bridgev2/examples/` to verify your setup quickly.
- The core code will be open-sourced after the paper is accepted.
