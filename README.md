# Bullet Journal (bujo)

Um bullet journal tradicional é basicamente uma sintaxe usada em um caderno para acompanhar itens diários e ver seu progresso de relance. 'bujo' consiste em um arquivo de sintaxe nano e um script bash simples com alguns arquivos de suporte. É projetado para ser um equivalente digital básico de um bullet journal para terminal. Usando uma sintaxe de marcação muito minimalista, ele codifica em cores itens com base no símbolo no início de uma linha, assim como a versão de papel tradicional. O script também pode migrar tarefas e reuniões com base na data.

---

## Dependências

- nano

---

## Instalação

Baixe o arquivo do repositório e execute os seguintes comandos ou leia o arquivo install.sh e coloque os arquivos manualmente.

1. Instale o nano se o seu sistema não tiver.
2. Clone o repositório.
3. Entre no diretório bujo.
4. Execute o script de instalação.
5. Coloque o arquivo bujo.nanorc. `sudo cp bujo.nanorc /usr/share/nano`

---

## Iniciando

Após instalado, execute o comando `bujo -x` para executar o programa de tutorial. Ele guiará o usuário através da sintaxe e como ela é usada. O script 'bujo' abrirá um arquivo contínuo 'todo.bujo' que servirá como um diário diário. Se o arquivo bujo.nanorc estiver instalado, ele codificará em cores qualquer arquivo *.bujo no sistema. Isso pode ser útil se você precisar de listas de 'todo' em diferentes diretórios para acompanhar arquivos.

---

## Visão geral da sintaxe

Alguns dos símbolos para codificar em cores listas 'bujo'. Muitos outros estão disponíveis se você conferir o tutorial.

- Tarefa normal
- Tarefa importante
- Reuniões
- Emails
- Tarefa completada
- Tarefa cancelada

---

## Ajuda

Uso: bujo.sh [OPÇÃO]

- `-n` começar novo dia e migração
- `-M` migrar todas as tarefas

- `-s` exibir sumário
- `-a` exibir todas as tarefas

- `-i` exibir tarefas importantes
- `-t` exibir tarefas concluídas
- `-l` exibir tarefas concluídas e migrá-las
- `-m` exibir reuniões
- `-E` exibir coisas a serem exploradas
- `-e` exibir e-mails

- `-d` editar tarefas diárias
- `-x` abrir formato de exemplo
- `-b` bujo -b [tarefa] adicionar tarefa sem abrir o nano

- `-h` exibir ajuda

---

# Bullet Journal (bujo)

A traditional bullet journal is essentially a syntax used in a notebook to track daily items and see your progress at a glance. 'bujo' consists of a nano syntax file and a simple bash script with some support files. It is designed to be a basic digital equivalent of a bullet journal for the terminal. Using a very minimalist markup syntax, it color-codes items based on the symbol at the beginning of a line, just like the traditional paper version. The script can also migrate tasks and meetings based on the date.

---

## Dependencies

- nano

---

## Installation

Download the file from the repository and run the following commands or read the install.sh file and place the files manually.

1. Install nano if your system doesn't have it.
2. Clone the repository.
3. Enter the bujo directory.
4. Run the install script.
5. Place the bujo.nanorc file. `sudo cp bujo.nanorc /usr/share/nano`

---

## Getting Started

After installation, run the command `bujo -x` to execute the tutorial program. It will guide the user through the syntax and how it is used. The 'bujo' script will open a continuous 'todo.bujo' file that will serve as a daily journal. If the bujo.nanorc file is installed, it will color-code any *.bujo file on the system. This can be useful if you need 'todo' lists in different directories to keep track of files.

---

## Syntax Overview

Some of the symbols for color-coding 'bujo' lists. Many more are available if you check the tutorial.

- Normal task
- Important task
- Meetings
- Emails
- Completed task
- Canceled task

---

## Help

Usage: bujo.sh [OPTION]

- `-n` start new day and migration
- `-M` migrate all tasks

- `-s` display summary
- `-a` display all tasks

- `-i` display important tasks
- `-t` display completed tasks
- `-l` display completed tasks and migrate them
- `-m` display meetings
- `-E` display things to explore
- `-e` display emails

- `-d` edit daily tasks
- `-x` open example format
- `-b` bujo -b [task] add task without opening nano

- `-h` display help
