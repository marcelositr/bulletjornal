```
----------------------------------------------------------------------
Bullet Journal (bujo)

Um bullet journal tradicional é basicamente uma sintaxe  usada  em  um
caderno para acompanhar itens diários e ver seu progresso de  relance.
'bujo' consiste em um arquivo de sintaxe nano e um script bash simples
com alguns arquivos de suporte. É projetado para  ser  um  equivalente
digital básico de um bullet journal para terminal. Usando uma  sintaxe
de marcação muito minimalista, ele codifica em cores itens com base no
símbolo no  início  de  uma  linha,  assim  como  a  versão  de  papel
tradicional. O script também pode migrar tarefas e reuniões  com  base
na data.

----------------------------------------------------------------------
Dependências

nano

----------------------------------------------------------------------
Instalação

Baixe o arquivo do repositório e execute os seguintes comandos ou leia
o arquivo install.sh e coloque os arquivos.

 Instale o nano se o seu sistema não tiver.
 Clone o repositório.
 Entre no diretório bujo.
 Execute o script de instalação.
 Coloque o arquivo bujo.nanorc.

----------------------------------------------------------------------
Iniciando

Após instalado, execute o comando 'bujo -x' para executar  o  programa
de tutorial. Ele guiará o usuário através da  sintaxe  e  como  ela  é
usada. O script 'bujo' abrirá  um  arquivo  'todo.bujo'  contínuo  que
servirá como um  diário  diário.  Se  o  arquivo  bujo.nanorc  estiver
instalado, ele codificará em cores qualquer arquivo *.bujo no sistema.
Isso pode ser útil se você precisar de listas de 'todo' em  diferentes
diretórios para acompanhar arquivos.

----------------------------------------------------------------------
Visão geral da sintaxe

Alguns dos símbolos para codificar  em  cores  listas  'bujo'.  Muitos
outros estão disponíveis se você conferir o tutorial.

 Tarefa normal
 Tarefa importante
 Reuniões
 Emails
 Tarefa completada
 Tarefa cancelada

----------------------------------------------------------------------
Ajuda

Uso: bujo.sh [OPÇÃO]

 -n começar novo dia e migração
 -M migra todas as tarefas

 -s exibe sumário
 -a exibe todas as tarefas

 -i exibe tarefas importantes
 -t exibe tarefas concluídas
 -l exibe tarefas concluídas e as migra
 -m exibe reuniões
 -E exibe coisas a serem exploradas
 -e exibe e-mails

 -d edita tarefas diárias
 -x abre formato de exemplo
 -b bujo -b [tarefa] adiciona tarefa sem abrir o nano

 -h exibe a ajuda
```
