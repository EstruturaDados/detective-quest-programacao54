#include <stdio.h>
#include<stdlib.h>
#include<string.h>

// Desafio Detective Quest
// Tema 4 - Árvores e Tabela Hash
// Este código inicial serve como base para o desenvolvimento das estruturas de navegação, pistas e suspeitos.
// Use as instruções de cada região para desenvolver o sistema completo com árvore binária, árvore de busca e tabela hash.


    
    
    // 🌱 Nível Novato: Mapa da Mansão com Árvore Binária
    //
    // - Crie uma struct Sala com nome, e dois ponteiros: esquerda e direita.
    typedef struct Sala{
        char nome[30];
        struct Sala* esquerda;
        struct Sala* direita;
    } Sala;
    // - Use funções como criarSala(), conectarSalas() e explorarSalas().
    Sala* criarSala(const char*nome){
        Sala* nova=(Sala*)malloc(sizeof(Sala));
        strcpy(nova->nome);
        nova->esquerda=NULL;
        nova->direita=NULL;
        return nova;
    }
    void conectarSala(Sala* origem,Sala* esquerda,Sala* direita){
        origem->esquerda=esquerda;
        origem->direita=direita;
    }
    void explorarSala(Sala* atual){
        char escolha;
        while(atual!= NULL){
            printf("Você está na sala: %s\n", atual->nome);
            printf("Escolha um caminho: esquerda (e), direita(d), sair (s):\n");
            scanf("%c", &escolha);

            if(escolha=='e'){
                if (atual->esquerda!= NULL){
                    atual=atual->esquerda;
                } else{
                    printf("Não há sala à esquerda.\n");
                }
            }else if (escolha=='d'){
                if (atual->direita != NULL){
                    atual=atual->direita;
                }else{
                    printf("Não há sala à direita.\n");
                }
            }else if (escolha=='s'){
                printf("Exploração encerrada.\n");
                break;
            }else{
                printf("Opção inválida.\n");
            }
        }
    }

    int main(){
        Sala* hall=criarSala("Hall de Entrada");
        Sala* biblioteca=criarSala("Biblioteca");
        Sala* cozinha=criarSala("Cozinha");
        Sala* sotao=criarSala("Sótão");
        Sala* jardim=criarSala("Jardim");

        conectarSala(hall, biblioteca,cozinha);
        conectarSala(biblioteca,sotao,NULL);
        conectarSala(cozinha,NULL, jardim);

        explorarSala(hall);

        free(hall);
        free(biblioteca);
        free(cozinha);
        free(sotao);
        free(jardim);
        return 0;
    }
    // - A árvore pode ser fixa: Hall de Entrada, Biblioteca, Cozinha, Sótão etc.
    // - O jogador deve poder explorar indo à esquerda (e) ou à direita (d).
    // - Finalize a exploração com uma opção de saída (s).
    // - Exiba o nome da sala a cada movimento.
    // - Use recursão ou laços para caminhar pela árvore.
    // - Nenhuma inserção dinâmica é necessária neste nível.

    // 🔍 Nível Aventureiro: Armazenamento de Pistas com Árvore de Busca
    //
    // - Crie uma struct Pista com campo texto (string).
    // - Crie uma árvore binária de busca (BST) para inserir as pistas coletadas.
    // - Ao visitar salas específicas, adicione pistas automaticamente com inserirBST().
    // - Implemente uma função para exibir as pistas em ordem alfabética (emOrdem()).
    // - Utilize alocação dinâmica e comparação de strings (strcmp) para organizar.
    // - Não precisa remover ou balancear a árvore.
    // - Use funções para modularizar: inserirPista(), listarPistas().
    // - A árvore de pistas deve ser exibida quando o jogador quiser revisar evidências.

    // 🧠 Nível Mestre: Relacionamento de Pistas com Suspeitos via Hash
    //
    // - Crie uma struct Suspeito contendo nome e lista de pistas associadas.
    // - Crie uma tabela hash (ex: array de ponteiros para listas encadeadas).
    // - A chave pode ser o nome do suspeito ou derivada das pistas.
    // - Implemente uma função inserirHash(pista, suspeito) para registrar relações.
    // - Crie uma função para mostrar todos os suspeitos e suas respectivas pistas.
    // - Adicione um contador para saber qual suspeito foi mais citado.
    // - Exiba ao final o “suspeito mais provável” baseado nas pistas coletadas.
    // - Para hashing simples, pode usar soma dos valores ASCII do nome ou primeira letra.
    // - Em caso de colisão, use lista encadeada para tratar.
    // - Modularize com funções como inicializarHash(), buscarSuspeito(), listarAssociacoes().

    

