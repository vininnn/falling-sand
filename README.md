# falling-sand
Código simples para teste do jogo Falling Sand.
Implementado em C e em C++.

## Dependências

- `gcc` (versão C, C11) ou `g++` (versão C++, C++17)
- `make`
- `pkg-config`
- `SDL2`

**Ubuntu/Debian:**
```bash
sudo apt install build-essential pkg-config libsdl2-dev
```

## Build e Execução

A pasta inclui um `Makefile` configurado para vincular arquivos utilitários e compilar o executável.

Compilar o projeto:

```bash
make
```

Executar o programa:

```bash
./main
```

Build e execução simultâneos:

```bash
make run
```

Limpar a build:

```bash
make clean