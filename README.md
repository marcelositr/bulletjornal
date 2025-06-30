# bujo - Seu Bullet Journal no Terminal
_Uma ferramenta minimalista e eficiente para organizar seu dia a dia diretamente da linha de comando._

![License](https://img.shields.io/badge/license-GPL--3.0-blue.svg)
![Shell](https://img.shields.io/badge/Shell-Bash-blue)
![Status](https://img.shields.io/badge/status-Em%20desenvolvimento-yellow)
![Feito com](https://img.shields.io/badge/feito%20com-%F0%9F%92%BB%20%2B%20%F0%9F%A4%96-critical)

[![Último commit](https://img.shields.io/github/last-commit/marcelositr/bulletjornal)](https://github.com/marcelositr/bulletjornal/commits/main)
[![Releases](https://img.shields.io/github/v/release/marcelositr/bulletjornal?label=release)](https://github.com/marcelositr/bulletjornal/releases)
[![Issues](https://img.shields.io/github/issues/marcelositr/bulletjornal)](https://github.com/marcelositr/bulletjornal/issues)
[![Stars](https://img.shields.io/github/stars/marcelositr/bulletjornal?style=social)](https://github.com/marcelositr/bulletjornal/stargazers)
[![Wiki](https://img.shields.io/badge/Documentação-Wiki-blueviolet)](https://github.com/marcelositr/bulletjornal/wiki)


`bujo` é um sistema de Bullet Journal para o terminal, implementado como um script Bash. Ele utiliza o editor `nano` com uma sintaxe de cores customizada para transformar um simples arquivo de texto em um poderoso painel de produtividade. Foi criado para quem ama a simplicidade e a velocidade do terminal e quer uma ferramenta de organização que não atrapalhe seu fluxo de trabalho.

![Gemini Shell Banner](https://github.com/marcelositr/bulletjornal/blob/main/images/bujo.png?raw=true)

### Demonstração

*(**Dica:** Grave um pequeno GIF usando uma ferramenta como `asciinema` ou `termtoscreen` e substitua a imagem abaixo. Mostre a criação de uma tarefa, a conclusão dela com 'X', e o uso do comando `bujo -s` para ver o resumo.)*

![Demonstração do bujo](https://raw.githubusercontent.com/marcelositr/bulletjornal/main/img/bujo.gif)

---

### ✨ Principais Funcionalidades

*   **Minimalista e Focado:** Sem distrações, sem interfaces gráficas pesadas. Apenas você, seu terminal e suas tarefas.
*   **Sintaxe Visual com Cores:** Identifique rapidamente tarefas importantes (`!`), concluídas (`X`), reuniões (`M`) e mais, graças a um sistema de cores intuitivo no `nano`.
*   **Migração Inteligente de Tarefas:** Com o comando `bujo -n`, suas tarefas pendentes são automaticamente movidas para o dia atual, garantindo que nada seja esquecido.
*   **Baseado em Arquivos de Texto:** Seus dados são seus, para sempre. Todos os seus registros ficam em arquivos de texto simples, fáceis de ler, fazer backup e versionar com Git.
*   **Customizável:** Defina suas próprias tarefas de rotina no arquivo `daily.bujo` para criar hábitos e automatizar o planejamento do seu dia.
*   **Leve e Rápido:** Escrito em Bash, o `bujo` é extremamente rápido e não consome quase nenhum recurso do sistema.

---

### 🚀 Instalação

A instalação é simples e automatizada. Abra seu terminal e execute os seguintes comandos:

```bash
# 1. Clone o repositório
git clone https://github.com/marcelositr/bulletjornal.git

# 2. Entre no diretório
cd bulletjornal

# 3. Execute o script de instalação (ele pedirá sua senha)
./install.sh
```

➡️ Para instruções detalhadas, pré-requisitos e solução de problemas, consulte a página de **[Instalação na Wiki](https://github.com/marcelositr/bulletjornal/wiki/Instalação)**.

---

### 📖 Uso Básico

Após a instalação, você pode começar a usar o `bujo` imediatamente.

```bash
# Abra seu diário principal para adicionar e editar tarefas
bujo

# Execute o tutorial interativo para aprender a sintaxe
bujo -x

# Comece um novo dia, migrando tarefas pendentes
bujo -n
```

➡️ Para um guia completo de como usar a ferramenta, acesse o **[Guia de Início Rápido](https://github.com/marcelositr/bulletjornal/wiki/Guia-de-Início-Rápido)** e a **[Referência de Comandos](https://github.com/marcelositr/bulletjornal/wiki/Referência-de-Comandos-(Opções))** na nossa Wiki.

---

### 📚 Documentação Completa (Wiki)

Toda a documentação do projeto está na nossa Wiki. Ela é a sua principal fonte de consulta para dominar o `bujo`.

*   **[Guia de Início Rápido](https://github.com/marcelositr/bulletjornal/wiki/Guia-de-Início-Rápido)**
*   **[Referência de Sintaxe](https://github.com/marcelositr/bulletjornal/wiki/Referência-de-Sintaxe)**
*   **[Referência de Comandos](https://github.com/marcelositr/bulletjornal/wiki/Referência-de-Comandos-(Opções))**
*   **[Exemplos e Casos de Uso](https://github.com/marcelositr/bulletjornal/wiki/Exemplos-e-Casos-de-Uso)**
*   **[Customização](https://github.com/marcelositr/bulletjornal/wiki/Customização)**
*   **[FAQ - Perguntas Frequentes](https://github.com/marcelositr/bulletjornal/wiki/FAQ---Perguntas-Frequentes)**

---

### 🤝 Como Contribuir

Sugestões, relatórios de bugs e *pull requests* são muito bem-vindos! Sinta-se à vontade para **abrir uma issue** para discutir novas ideias ou relatar um problema.

### 📜 Licença

Este projeto é licenciado sob a **GNU General Public License v3.0**. Veja o arquivo [LICENSE](LICENSE.txt) para mais detalhes.

---
Created by [@marcelositr](https://github.com/marcelositr)
