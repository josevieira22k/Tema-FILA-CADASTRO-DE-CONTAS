----------------------------------------------------------------------------------------------
COMPILAR E EXECUTAR NO TERMINAL

gcc -finput-charset=UTF-8 fila_contas.c -o fila_contas
./fila_contas

----------------------------------------------------------------------------------------------

Apresentação do Projeto: Sistema de Gerenciamento de Contas Bancárias utilizando Fila Dinâmica

Objetivo Geral

O projeto consiste no desenvolvimento de um sistema de gerenciamento de contas bancárias baseado em um conceito de fila dinâmica. 

A aplicação foi implementada em C, utilizando estruturas de dados como filas encadeadas para 
organizar e manipular as contas bancárias de maneira eficiente e sequencial. 
O sistema tem como objetivo demonstrar o funcionamento prático de estruturas de dados e aplicar 
conceitos de lógica de programação em uma aplicação funcional e acadêmica.

Objetivos Específicos

Gerenciar contas bancárias em uma fila, permitindo operações como inserir, remover, exibir e zerar 
todas as contas.
Simular o comportamento de uma fila em um cenário de sistema bancário, onde as contas são tratadas 
no formato FIFO (First In, First Out), ou seja,
o primeiro elemento inserido é o primeiro a ser removido.

Descrição Técnica

O sistema foi implementado com os seguintes elementos principais:

Estrutura de Dados:

Foi criada uma estrutura de dados chamada Fila, composta por dois ponteiros (frente e tras) que apontam 
para os nós iniciais e finais da fila, respectivamente.
Cada nó da fila é representado pela estrutura Node, que contém uma conta bancária (Conta) e um ponteiro
para o próximo nó.

Estrutura da Conta Bancária:

A conta é representada por uma estrutura chamada Conta, que contém os seguintes atributos:
Número da Conta: Identificação única da conta.
Agência: Código da agência bancária.
Saldo: Valor disponível na conta.
Tipo: Tipo de conta bancária (Corrente, Poupança, Salário, etc.).

Operações Implementadas:

Inserir (Enfileirar): Adiciona uma nova conta ao final da fila.
Remover (Desenfileirar): Remove a conta que está na frente da fila.
Exibir Fila: Exibe todas as contas presentes na fila com formatação clara.
Zerar Fila: Remove todas as contas da fila de maneira segura.

Interface Simples:

O sistema apresenta um menu interativo no terminal, permitindo que o usuário escolha entre as opções disponíveis.
Cada operação é acompanhada de mensagens claras para informar o status ao usuário (sucesso, erro ou fila vazia).

Motivação e Justificativa

Este projeto foi desenvolvido com a finalidade de:

Aplicar conceitos aprendidos em disciplinas de Estruturas de Dados: Estratégia e implementação.
Explorar o uso de filas dinâmicas para resolver problemas reais, como o gerenciamento sequencial de dados.
Fornecer uma base para estudos futuros, como a implementação de sistemas mais complexos utilizando outras 
estruturas de dados (pilhas, árvores, etc.).

Exemplo de Fluxo de Uso

Usuário insere contas na fila:
Exemplo: Conta nº 1234, Agência 5678, Saldo: R$500, Tipo: Corrente.
Usuário solicita exibição da fila:
O sistema apresenta uma tabela formatada com os dados das contas.
Usuário remove uma conta da fila:
A conta no início da fila é removida, seguindo o comportamento FIFO.
Usuário decide zerar a fila:
Todas as contas são removidas, deixando a fila vazia.

Resultados Esperados

Simular o comportamento de uma fila dinâmica no gerenciamento de contas bancárias.
Facilitar a visualização do impacto das operações (inserção, remoção e esvaziamento) em uma estrutura encadeada.
Promover uma maior compreensão do uso de ponteiros e alocação dinâmica de memória no desenvolvimento de software.

Conclusão

O projeto apresenta um sistema funcional e didático para a manipulação de contas bancárias utilizando filas dinâmicas.
Ele demonstra na prática como conceitos teóricos de programação podem ser aplicados para resolver problemas de organização e gerenciamento de dados. Além disso, 
serve como base para estudos e aprimoramentos futuros, podendo ser expandido para um sistema mais robusto com funcionalidades adicionais, como busca e ordenação.
