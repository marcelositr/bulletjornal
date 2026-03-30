# Bullet Journal (bujo) - C++ Edition

[![C++](https://img.shields.io/badge/C++-17-blue.svg)](https://isocpp.org/)
[![License: GPL v3](https://img.shields.io/badge/License-GPLv3-blue.svg)](https://www.gnu.org/licenses/gpl-3.0)
[![Status](https://img.shields.io/badge/status-active-success.svg)]()

Uma ferramenta minimalista e poderosa para organização pessoal diretamente no terminal, reescrita em **C++** para garantir robustez, modularidade e performance. O `bujo` combina a simplicidade de arquivos de texto com a flexibilidade do editor `nano` e um sistema inteligente de migração de tarefas.

---

## Destaques

- **Puro Terminal:** Sem interfaces pesadas, focado 100% em produtividade CLI.
- **Sintaxe Visual:** Realce de cores customizado para o `nano`, permitindo identificar instantaneamente o status das tarefas.
- **Migração Automática:** Nunca perca uma tarefa pendente. O sistema move seus itens importantes para o novo dia com um comando.
- **Arquitetura POO:** Desenvolvido seguindo princípios SOLID, DRY e Clean Code.
- **Privacidade Total:** Seus dados são salvos localmente em arquivos `.bujo` no diretório `~/.bujo/`.

---

## Instalação e Compilação

### Pré-requisitos
- Compilador C++ (suporte a C++17)
- `make`
- Editor `nano`

### Compilando
```bash
# Clone o repositório
git clone https://github.com/marcelositr/bulletjornal.git
cd bulletjornal

# Compile o binário
make

# Opcional: Execute os testes unitários
make test
```

### Configurando o Realce de Sintaxe
Para ativar as cores no `nano`, o sistema gera automaticamente um arquivo em `~/.config/nano/nano-syntax.nanorc`. Certifique-se de incluí-lo no seu `~/.nanorc`:

```bash
echo 'include "~/.config/nano/nano-syntax.nanorc"' >> ~/.nanorc
```

---

## 📖 Guia de Uso Rápido

O `bujo` pode ser usado de forma interativa ou via argumentos de linha de comando:

- `./bulletjornal`: Abre o menu principal interativo.
- `./bulletjornal -n`: Inicia um novo dia e migra tarefas pendentes.
- `./bulletjornal -s`: Exibe um resumo rápido das notas atuais.
- `./bulletjornal -h`: Exibe a ajuda.

### Sintaxe de Tarefas
- `* Tarefa`: Tarefa normal.
- `! Tarefa`: Tarefa importante/urgente.
- `M Reunião`: Compromisso ou reunião.
- `X * Tarefa`: Marcar como concluída.
- `>> * Tarefa`: Tarefa migrada para outro dia.

---

## Documentação Completa (Wiki)

Para detalhes profundos sobre a lógica de migração, customização de categorias e fluxos de trabalho avançados, visite nossa **[Wiki oficial](https://github.com/marcelositr/bulletjornal/wiki)**.

- **[Guia de Instalação Detalhado](https://github.com/marcelositr/bulletjornal/wiki/Instalacao)**
- **[Referência de Sintaxe](https://github.com/marcelositr/bulletjornal/wiki/Sintaxe)**
- **[Fluxo de Trabalho de Migração](https://github.com/marcelositr/bulletjornal/wiki/Migracao)**

---

## Contribuindo

Contribuições são o que tornam a comunidade open source um lugar incrível para aprender, inspirar e criar. Qualquer contribuição que você fizer será **muito apreciada**.

1. Faça um Fork do projeto
2. Crie sua Feature Branch (`git checkout -b feature/AmazingFeature`)
3. Commit suas mudanças (`git commit -m 'Add some AmazingFeature'`)
4. Push para a Branch (`git push origin feature/AmazingFeature`)
5. Abra um Pull Request

---

## Licença

Distribuído sob a licença **GPLv3**. Veja o arquivo `LICENSE` para mais informações.

---
Desenvolvido por [marcelositr](https://github.com/marcelositr)
