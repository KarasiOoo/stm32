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

Nowy projekt dodajesz jako folder w katalogu rodziny układu (np. `G030/moj_projekt/`).

## Co jest w repozytorium

- `Core/` — kod aplikacji
- `Drivers/` — CMSIS + HAL wygenerowany przez CubeMX (repo samowystarczalne)
- `*.ioc` — konfiguracja CubeMX
- pliki projektu CubeIDE (`.project`, `.cproject`, `.settings/`, linker `*.ld`)

## Czego nie commitujemy

- `Debug/`, `Release/` — artefakty kompilacji
- `.metadata/` — stan workspace IDE (per maszyna)
- `G030old/`, `workspace_1.17.0/` — archiwum / puste workspace

## Otwieranie w STM32CubeIDE

1. **File → Switch Workspace → Other…** i wybierz folder rodziny (np. `G030/`).
2. **File → Import → Existing Projects into Workspace** i wskaż projekt (np. `G030/ws2811_v3/`).

Każda rodzina układu ma osobny workspace CubeIDE z własnym `.metadata/` (ignorowanym przez git).

## Styl kodu

Bare-metal z wykorzystaniem **CMSIS** — bez warstwy HAL w kodzie aplikacji.
