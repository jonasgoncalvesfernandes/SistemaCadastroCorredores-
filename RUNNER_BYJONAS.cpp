#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CONTA 50

typedef struct
{
       int NumeroPeito;
       char Nome[30];
       int idade;
       int Sexo;         // Usar um int ou char, mas sem ser array, se for para um unico valor
       float TempoProva; // Considerando que seja um valor unico
} Corredor;

void CadastrarCorredor(Corredor corredores[], int qte);
void ConsultarNumPeito(Corredor corredores[], int qte);
void ConsultarNumNome(Corredor corredores[], int qte);
void GerarRelatorio(Corredor corredores[], int qte);
int CalcularMediaTodos(Corredor corredores[], int qte);
int ApresentarMediaETempo60Anos(Corredor corredores[], int qte);
int ApresentarQuantidadeMulheresEmediaIdade(Corredor corredores[], int qte);

int main()
{
       int opcoes;
       int qte = 0; // Declarar e inicializar qte

       Corredor corredores[MAX_CONTA];

       printf("Bem Vindo a Corrida do IFSP, aperte [ENTER] para continuar\n");
       getchar();

       do
       {
              printf("\n----[Menu]----\n");
              printf("\n [1]: Cadastrar corredor");
              printf("\n [2]: Consultar os dados de corredor(a) pelo numero do peito");
              printf("\n [3]: Consultar os dados de corredor(a) pelo nome");
              printf("\n [4]: Gerar relatorio de classificacao");
              printf("\n [5]: Calcular media do tempo de prova entre todos os corredores e corredoras");
              printf("\n [6]: Apresentar a quantidade de corredores(as) acima dos 60 anos e a media do tempo de prova deles(as)");
              printf("\n [7]: Apresentar a quantidade de mulheres e a media de idade delas");
              printf("\n [8]: sair do programa");
              printf("\n\nDigite a opcao desejada: ");
              scanf("%d", &opcoes);

              switch (opcoes)
              {
              case 1:
                     CadastrarCorredor(corredores, qte); // Passando qte como valor
                     qte++;                              // Incrementa o numero de corredores cadastrados
                     break;
              case 2:
                     ConsultarNumPeito(corredores, qte);
                     break;
              case 3:
                     ConsultarNumNome(corredores, qte);
                     break;
              case 4:
                     GerarRelatorio(corredores, qte);
                     break;
              case 5:
                     CalcularMediaTodos(corredores, qte);
                     break;
              case 6:
                     ApresentarMediaETempo60Anos(corredores, qte);
                     break;
              case 7:
                     ApresentarQuantidadeMulheresEmediaIdade(corredores, qte);
                     break;
              case 8:
                     printf("Saindo do programa...\n");
                     break;
              default:
                     printf("Opcao Invalida!\n");
                     break;
              }

       } while (opcoes != 8);

       return 0;
}

// Funcao para cadastrar corredor
void CadastrarCorredor(Corredor corredores[], int qte)
{
       if (qte < MAX_CONTA)
       {
              corredores[qte].NumeroPeito = qte + 1;
              printf("Numero do peito:  [%d]\n", corredores[qte].NumeroPeito);

              printf("Digite o nome: ");
              scanf("%s", corredores[qte].Nome);
              printf("Digite a idade: ");
              scanf("%d", &corredores[qte].idade);
              // Verifica o sexo
              int sexoValido = 0;
              while (!sexoValido)
              {
                     printf("Digite o sexo ([0] para masculino, [1] para feminino): ");
                     scanf("%d", &corredores[qte].Sexo);
                     if (corredores[qte].Sexo == 0 || corredores[qte].Sexo == 1)
                     {
                            sexoValido = 1; // Valor valido, sai do loop
                     }
                     else
                     {
                            printf("Sexo invalido. Por favor, digite 0 ou 1.\n");
                     }
              }
              printf("Digite o tempo da prova: ");
              scanf("%f", &corredores[qte].TempoProva);

              printf("Corredor cadastrado com sucesso!\n");

              printf("\nCorredor %d, nome: %s, idade: %d, sexo: %s com tempo %.2f minutos de prova\n",
                     corredores[qte].NumeroPeito, corredores[qte].Nome, corredores[qte].idade,
                     (corredores[qte].Sexo == 0) ? "Masculino" : "Feminino", corredores[qte].TempoProva);
       }
       else
       {
              printf("Limite de corredores atingido.\n");
       }
}

void ConsultarNumPeito(Corredor corredores[], int qte)
{
       int NumCorredor;
       int ContaEncontrada = -1;

       printf("Digite o numero do corredor que voce deseja consultar: ");
       scanf("%d", &NumCorredor);

       for (int i = 0; i < qte; i++)
       {
              if (corredores[i].NumeroPeito == NumCorredor)
              {
                     ContaEncontrada = i;
                     break;
              }
       }
       if (ContaEncontrada != -1)
       {
              printf("\nCorredor %d, nome: %s, idade: %d, sexo: %s com tempo %.2f minutos de prova\n",
                     corredores[ContaEncontrada].NumeroPeito, corredores[ContaEncontrada].Nome,
                     corredores[ContaEncontrada].idade,
                     (corredores[ContaEncontrada].Sexo == 0) ? "Masculino" : "Feminino",
                     corredores[ContaEncontrada].TempoProva);
       }
       else
       {
              printf("Corredor nao encontrado.\n");
       }
}

// Funcao para consultar corredor pelo nome
void ConsultarNumNome(Corredor corredores[], int qte)
{
       char nome[30];
       int encontrou = 0;

       printf("\nDigite seu nome: ");
       scanf(" %[^\n]s", nome);

       for (int i = 0; i < qte; i++)
       {
              if (strcmp(corredores[i].Nome, nome) == 0)
              {
                     printf("\nNumero do peito: %d, Nome: %s, Idade: %d, Sexo: %s, Tempo de Prova: %.2f\n",
                            corredores[i].NumeroPeito, corredores[i].Nome, corredores[i].idade,
                            (corredores[i].Sexo == 0) ? "Masculino" : "Feminino", corredores[i].TempoProva);
                     encontrou = 1;
                     break; // Sai do loop apos encontrar o corredor
              }
       }

       if (!encontrou)
       {
              printf("Corredor(a) nao encontrado(a).\n");
       }
}

// Funcao para gerar relatorio decrescente
void GerarRelatorio(Corredor corredores[], int qte)
{
       if (qte == 0)
       {
              printf("Nenhum corredor cadastrado!\n");
       }
       else
       {
              // Bubble sort para ordenar os corredores pelo tempo de prova
              for (int i = 0; i < qte - 1; i++)
              {
                     for (int j = 0; j < qte - 1 - i; j++)
                     {
                            if (corredores[j].TempoProva > corredores[j + 1].TempoProva)
                            {
                                   // Troca os corredores usando uma variavel temporaria
                                   Corredor temp = corredores[j];
                                   corredores[j] = corredores[j + 1];
                                   corredores[j + 1] = temp;
                            }
                     }
              }

              // Exibe o relatorio apos a ordenacao
              printf("\n--- Relatorio de Classificacao ---\n");
              for (int i = 0; i < qte; i++)
              {
                     printf("%d. Nome: %s, Tempo de Prova: %.2f minutos\n",
                            corredores[i].NumeroPeito, corredores[i].Nome, corredores[i].TempoProva);
              }
       }
}

// Funcao para calcular a media do tempo de prova de todos os corredores
int CalcularMediaTodos(Corredor corredores[], int qte)
{
       if (qte == 0)
       {
              printf("Nenhum corredor cadastrado!\n");
              return 0;
       }

       float soma = 0;
       for (int i = 0; i < qte; i++)
       {
              soma += corredores[i].TempoProva;
       }

       float media = soma / qte;
       printf("Media do tempo de prova entre todos os corredores: %.2f minutos\n", media);

       return 1; // Retorna 1 para indicar que a operacao foi bem-sucedida
}

// Funcao para apresentar a quantidade de corredores(as) acima dos 60 anos e a media do tempo de prova deles(as)
int ApresentarMediaETempo60Anos(Corredor corredores[], int qte)
{
       if (qte == 0)
       {
              printf("Nenhum corredor cadastrado!\n");
              return 0;
       }

       int cont = 0;
       float soma = 0;
       for (int i = 0; i < qte; i++)
       {
              if (corredores[i].idade > 60)
              {
                     cont++;
                     soma += corredores[i].TempoProva;
              }
       }

       if (cont > 0)
       {
              float media = soma / cont;
              printf("Quantidade de corredores(as) acima dos 60 anos: %d\n", cont);
              printf("Media do tempo de prova dos corredores(as) acima dos 60 anos: %.2f minutos\n", media);
       }
       else
       {
              printf("Nao ha corredores(as) acima dos 60 anos.\n");
       }

       return 1; // Retorna 1 para indicar que a operacao foi bem-sucedida
}

// Funcao para apresentar a quantidade de mulheres e a media de idade delas
int ApresentarQuantidadeMulheresEmediaIdade(Corredor corredores[], int qte)
{
       if (qte == 0)
       {
              printf("Nenhum corredor cadastrado!\n");
              return 0;
       }

       int cont = 0;
       int somaIdade = 0;
       for (int i = 0; i < qte; i++)
       {
              if (corredores[i].Sexo == 1)
              { // Considerando 1 para feminino
                     cont++;
                     somaIdade += corredores[i].idade;
              }
       }

       if (cont > 0)
       {
              float media = (float)somaIdade / cont;
              printf("Quantidade de mulheres: %d\n", cont);
              printf("Media de idade das mulheres: %.2f anos\n", media);
       }
       else
       {
              printf("Nao ha mulheres cadastradas.\n");
       }

       return 1; // Retorna 1 para indicar que a operacao foi bem-sucedida
}
