# STM32 Firmware

Repozytorium projektów bare-metal dla mikrokontrolerów STM32, tworzonych w **STM32CubeIDE**.

Kod źródłowy jest wersjonowany bezpośrednio w katalogu workspace IDE (`STM32CubeIDE`).

## Struktura

```
STM32CubeIDE/
├── G030/                  # STM32G0
│   ├── ws2811_v3/
│   ├── clear/
│   └── ws2811_driver/
├── L476/                  # STM32L4
│   └── test/
├── F401/                  # STM32F4
│   └── switching/
├── L010/                  # STM32L0
├── G474/                  # STM32G4
├── F446/                  # STM32F4 (pusty workspace)
├── common/                # współdzielony kod (np. drivery)
│   └── ws2812/
├── .gitignore
└── README.md
```
