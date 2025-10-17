#include <stdio.h>
#include <string.h>
#define TAM 100

typedef struct {
    int dia;
    int mes;
    int ano;
} Data;

typedef struct {
    int matricula;
    char nome[150];
    char sexo;
    char cpf[15];
    Data nascimento;
    int contadorDisciplinas;
} Aluno;

typedef struct {
    int matricula;
    char nome[150];
    char sexo;
    char cpf[15];
    Data nascimento;
} Professor;

typedef struct {
    int codigo;
    char nome[50];
    int semestre;
    int codProfessor;
    int alunosIds[TAM];
    int totalAlunos;
} Disciplina;

Disciplina listarDisciplinas[TAM];
int qtdDisciplinas = 0;

int main() {
    Aluno listarAlunos[TAM];
    Professor listarProfessores[TAM];
    int qtdAlunos = 0;
    int qtdProfessores = 0;
    int opcao;

    do {
        
        printf("\t**** Projeto Escola ***\n");
        

        printf("Escolha uma opção:\n");
        printf("1 - Cadastrar (alunos, professores e disciplinas)\n");
        printf("2 - Relatórios: Alunos\n");
        printf("3 - Relatórios: Professores\n");
        printf("4 - Relatórios: Disciplinas\n");
        printf("0 - Sair\n");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1: {
                int cadastro;
                do {
                    printf("\nVocê escolheu a opção 1: Cadastrar\n");
                    printf("1 - Cadastro de Alunos\n");
                    printf("2 - Cadastro de Professores\n");
                    printf("3 - Cadastro de Disciplinas\n");
                    printf("0 - Voltar\n");
                    scanf("%d", &cadastro);

                    switch (cadastro) {
                        case 1: {
                            int subopcao;
                            do {
                                printf("\nCadastro de Alunos:\n");
                                printf("1 - Incluir\n");
                                printf("2 - Excluir\n");
                                printf("3 - Atualizar\n");
                                printf("0 - Voltar\n");
                                scanf("%d", &subopcao);
                                getchar();

                                switch (subopcao) {
                                    case 1: {
                                        if (qtdAlunos < TAM) {
                                            Aluno novo;
                                            printf("\nIncluir Aluno\n");
                                            printf("Matrícula: ");
                                            scanf("%d", &novo.matricula);
                                            while (getchar() != '\n');

                                            printf("Nome: ");
                                            fgets(novo.nome, sizeof(novo.nome), stdin);
                                            novo.nome[strcspn(novo.nome, "\n")] = '\0';

                                            printf("Sexo (M/F): ");
                                            scanf(" %c", &novo.sexo);

                                            printf("CPF: ");
                                            scanf("%s", novo.cpf);

                                            printf("Data de nascimento (dd mm aaaa): ");
                                            scanf("%d %d %d", &novo.nascimento.dia, &novo.nascimento.mes, &novo.nascimento.ano);
                                            
                                            novo.contadorDisciplinas = 0;
                                            listarAlunos[qtdAlunos] = novo;
                                            qtdAlunos++;

                                            printf("\nAluno cadastrado com sucesso!\n");
                                            while (getchar() != '\n');
                                            printf("Pressione Enter para continuar...");
                                            getchar();
                                        } else {
                                            printf("O limite foi atingido!\n");
                                        }
                                        break;
                                    }
                                    case 2: {
                                        printf("\n**** Lista de Alunos ****\n");
                                        for (int i = 0; i < qtdAlunos; i++) {
                                            printf("Matrícula: %d - Nome: %s - Sexo: %c\n", 
                                                   listarAlunos[i].matricula, 
                                                   listarAlunos[i].nome, 
                                                   listarAlunos[i].sexo);
                                        }

                                        printf("\nDigite a Matrícula do aluno que deseja excluir: ");
                                        int mat;
                                        scanf("%d", &mat);

                                        int achou = 0;
                                        for (int i = 0; i < qtdAlunos; i++) {
                                            if (listarAlunos[i].matricula == mat) {
                                                achou = 1;
                                                for (int j = i; j < qtdAlunos - 1; j++) {
                                                    listarAlunos[j] = listarAlunos[j + 1];
                                                }
                                                qtdAlunos--;
                                                break;
                                            }
                                        }

                                        if (achou) {
                                            printf("Aluno excluído com sucesso!\n");
                                        } else {
                                            printf("Aluno com Matrícula %d não encontrado.\n", mat);
                                        }
                                        break;
                                    }
                                    case 3: {
                                        printf("\nDigite a Matrícula do aluno que deseja atualizar: ");
                                        int mat;
                                        scanf("%d", &mat);

                                        int encontrado = 0;
                                        for (int i = 0; i < qtdAlunos; i++) {
                                            if (listarAlunos[i].matricula == mat) {
                                                encontrado = 1;

                                                printf("\nDados atuais do aluno:\n");
                                                printf("Matrícula: %d\n", listarAlunos[i].matricula);
                                                printf("Nome: %s\n", listarAlunos[i].nome);
                                                printf("Sexo: %c\n", listarAlunos[i].sexo);
                                                printf("CPF: %s\n", listarAlunos[i].cpf);
                                                printf("Nascimento: %02d/%02d/%04d\n", 
                                                       listarAlunos[i].nascimento.dia, 
                                                       listarAlunos[i].nascimento.mes, 
                                                       listarAlunos[i].nascimento.ano);

                                                printf("\nDigite os novos dados:\n");
                                                printf("Nome: ");
                                                getchar();
                                                fgets(listarAlunos[i].nome, sizeof(listarAlunos[i].nome), stdin);
                                                listarAlunos[i].nome[strcspn(listarAlunos[i].nome, "\n")] = '\0';

                                                printf("Sexo (M/F): ");
                                                scanf(" %c", &listarAlunos[i].sexo);

                                                printf("CPF: ");
                                                scanf("%s", listarAlunos[i].cpf);

                                                printf("Data de nascimento (dd mm aaaa): ");
                                                scanf("%d %d %d", &listarAlunos[i].nascimento.dia, 
                                                      &listarAlunos[i].nascimento.mes, 
                                                      &listarAlunos[i].nascimento.ano);

                                                printf("\nAluno atualizado com sucesso!\n");
                                                break;
                                            }
                                        }

                                        if (!encontrado) {
                                            printf("Aluno com Matrícula %d não encontrado.\n", mat);
                                        }
                                        break;
                                    }
                                    case 0:
                                        printf("Voltando ao menu de cadastro...\n");
                                        break;
                                    default:
                                        printf("Opção inválida.\n");
                                }
                            } while (subopcao != 0);
                            break;
                        }
                        case 2: {
                            printf("\nCadastro de Professores:\n");
                            int subopcao_prof;
                            do {
                                printf("1 - Incluir\n");
                                printf("2 - Excluir\n");
                                printf("3 - Atualizar\n");
                                printf("0 - Voltar\n");
                                scanf("%d", &subopcao_prof);
                                getchar();

                                switch (subopcao_prof) {
                                    case 1: {
                                        if (qtdProfessores < TAM) {
                                            Professor novo_prof;
                                            printf("\nIncluir professor\n");
                                            printf("Matrícula: ");
                                            scanf("%d", &novo_prof.matricula);
                                            while (getchar() != '\n');

                                            printf("Nome: ");
                                            fgets(novo_prof.nome, sizeof(novo_prof.nome), stdin);
                                            novo_prof.nome[strcspn(novo_prof.nome, "\n")] = '\0';

                                            printf("Sexo (M/F): ");
                                            scanf(" %c", &novo_prof.sexo);

                                            printf("CPF: ");
                                            scanf("%s", novo_prof.cpf);

                                            printf("Data de nascimento (dd mm aaaa): ");
                                            scanf("%d %d %d", &novo_prof.nascimento.dia, 
                                                  &novo_prof.nascimento.mes, 
                                                  &novo_prof.nascimento.ano);

                                            listarProfessores[qtdProfessores] = novo_prof;
                                            qtdProfessores++;

                                            printf("\nProfessor cadastrado com sucesso!\n");
                                            while (getchar() != '\n');
                                            printf("Pressione Enter para continuar...");
                                            getchar();
                                        } else {
                                            printf("O limite foi atingido!\n");
                                        }
                                        break;
                                    }
                                    case 2: {
                                        printf("\n**** Lista de Professores ****\n");
                                        for (int i = 0; i < qtdProfessores; i++) {
                                            printf("Matrícula: %d - Nome: %s - Sexo: %c\n", 
                                                   listarProfessores[i].matricula, 
                                                   listarProfessores[i].nome, 
                                                   listarProfessores[i].sexo);
                                        }

                                        int mat_p;
                                        printf("\nDigite a Matrícula do professor que deseja excluir: ");
                                        scanf("%d", &mat_p);

                                        int achou_p = 0;
                                        for (int i = 0; i < qtdProfessores; i++) {
                                            if (listarProfessores[i].matricula == mat_p) {
                                                achou_p = 1;
                                                for (int j = i; j < qtdProfessores - 1; j++) {
                                                    listarProfessores[j] = listarProfessores[j + 1];
                                                }
                                                qtdProfessores--;
                                                break;
                                            }
                                        }

                                        if (achou_p) {
                                            printf("Professor excluído com sucesso!\n");
                                        } else {
                                            printf("Professor com matrícula %d não encontrado.\n", mat_p);
                                        }
                                        break;
                                    }
                                    case 3: {
                                        printf("\nDigite a Matrícula do professor que deseja atualizar: ");
                                        int mat_p1;
                                        scanf("%d", &mat_p1);

                                        int encontrado_p = 0;
                                        for (int i = 0; i < qtdProfessores; i++) {
                                            if (listarProfessores[i].matricula == mat_p1) {
                                                encontrado_p = 1;

                                                printf("\nDados atuais do professor:\n");
                                                printf("Matrícula: %d\n", listarProfessores[i].matricula);
                                                printf("Nome: %s\n", listarProfessores[i].nome);
                                                printf("Sexo: %c\n", listarProfessores[i].sexo);
                                                printf("CPF: %s\n", listarProfessores[i].cpf);
                                                printf("Nascimento: %02d/%02d/%04d\n", 
                                                       listarProfessores[i].nascimento.dia, 
                                                       listarProfessores[i].nascimento.mes, 
                                                       listarProfessores[i].nascimento.ano);

                                                printf("\nDigite os novos dados:\n");
                                                printf("Nome: ");
                                                getchar();
                                                fgets(listarProfessores[i].nome, sizeof(listarProfessores[i].nome), stdin);
                                                listarProfessores[i].nome[strcspn(listarProfessores[i].nome, "\n")] = '\0';

                                                printf("Sexo (M/F): ");
                                                scanf(" %c", &listarProfessores[i].sexo);

                                                printf("CPF: ");
                                                scanf("%s", listarProfessores[i].cpf);

                                                printf("Data de nascimento (dd mm aaaa): ");
                                                scanf("%d %d %d", &listarProfessores[i].nascimento.dia, 
                                                      &listarProfessores[i].nascimento.mes, 
                                                      &listarProfessores[i].nascimento.ano);

                                                printf("\nProfessor atualizado com sucesso!\n");
                                                break;
                                            }
                                        }

                                        if (!encontrado_p) {
                                            printf("Professor com matrícula %d não encontrado.\n", mat_p1);
                                        }
                                        break;
                                    }
                                    case 0:
                                        printf("Voltando ao menu de cadastro...\n");
                                        break;
                                    default:
                                        printf("Opção inválida.\n");
                                }
                            } while (subopcao_prof != 0);
                            break;
                        }
                        case 3: {
                            printf("\nCadastro de Disciplinas:\n");
                            int subopcao_disc;
                            do {
                                printf("1 - Incluir\n");
                                printf("2 - Excluir\n");
                                printf("3 - Atualizar\n");
                                printf("4 - Adicionar Aluno\n");
                                printf("5 - Remover Aluno\n");
                                printf("0 - Voltar\n");
                                scanf("%d", &subopcao_disc);
                                getchar();

                                switch (subopcao_disc) {
                                    case 1: {
                                        if (qtdDisciplinas < TAM) {
                                            Disciplina nova_disc;
                                            printf("\nIncluir Disciplina\n");
                                            printf("Nome da disciplina: ");
                                            fgets(nova_disc.nome, sizeof(nova_disc.nome), stdin);
                                            nova_disc.nome[strcspn(nova_disc.nome, "\n")] = '\0';

                                            printf("Código da disciplina: ");
                                            scanf("%d", &nova_disc.codigo);

                                            printf("Semestre da disciplina: ");
                                            scanf("%d", &nova_disc.semestre);

                                            printf("Código do professor responsável: ");
                                            scanf("%d", &nova_disc.codProfessor);

                                            nova_disc.totalAlunos = 0;
                                            listarDisciplinas[qtdDisciplinas++] = nova_disc;

                                            printf("\nDisciplina cadastrada com sucesso!\n");
                                            while (getchar() != '\n');
                                            printf("Pressione Enter para continuar...");
                                            getchar();
                                        } else {
                                            printf("O limite de disciplinas foi atingido!\n");
                                        }
                                        break;
                                    }
                                    case 2: {
                                        printf("\n---- Lista de Disciplinas ----\n");
                                        for (int i = 0; i < qtdDisciplinas; i++) {
                                            printf("ID: %d - Nome: %s - Professor: %d\n",
                                                   listarDisciplinas[i].codigo, 
                                                   listarDisciplinas[i].nome, 
                                                   listarDisciplinas[i].codProfessor);
                                        }

                                        int id;
                                        printf("\nDigite o codigo da disciplina que deseja excluir: ");
                                        scanf("%d", &id);

                                        int achou = 0;
                                        for (int i = 0; i < qtdDisciplinas; i++) {
                                            if (listarDisciplinas[i].codigo == id) {
                                                achou = 1;
                                                for (int j = i; j < qtdDisciplinas - 1; j++) {
                                                    listarDisciplinas[j] = listarDisciplinas[j + 1];
                                                }
                                                qtdDisciplinas--;
                                                break;
                                            }
                                        }

                                        if (achou) {
                                            printf("Disciplina excluída com sucesso!\n");
                                        } else {
                                            printf("Disciplina com código %d não encontrada.\n", id);
                                        }
                                        break;
                                    }
                                    case 3: {
                                        int id;
                                        printf("\nDigite o código da disciplina que deseja atualizar: ");
                                        scanf("%d", &id);

                                        int encontrado = 0;
                                        for (int i = 0; i < qtdDisciplinas; i++) {
                                            if (listarDisciplinas[i].codigo == id) {
                                                encontrado = 1;

                                                printf("\nDados atuais:\n");
                                                printf("código: %d\n", listarDisciplinas[i].codigo);
                                                printf("Nome: %s\n", listarDisciplinas[i].nome);
                                                printf("Semestre: %d\n", listarDisciplinas[i].semestre);
                                                printf("Professor: %d\n", listarDisciplinas[i].codProfessor);

                                                printf("\nDigite os novos dados:\n");
                                                getchar();
                                                printf("Nome: ");
                                                fgets(listarDisciplinas[i].nome, sizeof(listarDisciplinas[i].nome), stdin);
                                                listarDisciplinas[i].nome[strcspn(listarDisciplinas[i].nome, "\n")] = '\0';

                                                printf("Novo código da disciplina: ");
                                                scanf("%d", &listarDisciplinas[i].codigo);

                                                printf("Novo semestre: ");
                                                scanf("%d", &listarDisciplinas[i].semestre);

                                                printf("Novo código do professor: ");
                                                scanf("%d", &listarDisciplinas[i].codProfessor);

                                                printf("Disciplina atualizada com sucesso!\n");
                                                break;
                                            }
                                        }

                                        if (!encontrado) {
                                            printf("Disciplina com código %d não encontrada.\n", id);
                                        }
                                        break;
                                    }
                                    case 4: {
                                        int idDisc, idAluno;
                                        printf("Informe o código da disciplina: ");
                                        scanf("%d", &idDisc);
                                        printf("Informe o código do aluno para adicionar: ");
                                        scanf("%d", &idAluno);

                                        int achou = 0;
                                        for (int i = 0; i < qtdDisciplinas; i++) {
                                            if (listarDisciplinas[i].codigo == idDisc) {
                                                listarDisciplinas[i].alunosIds[listarDisciplinas[i].totalAlunos++] = idAluno;
                                                
                                                for (int j = 0; j < qtdAlunos; j++) {
                                                    if (listarAlunos[j].matricula == idAluno) {
                                                        listarAlunos[j].contadorDisciplinas++;
                                                        break;
                                                    }
                                                }    
                                                printf("Aluno adicionado a disciplina.\n");
                                                achou = 1;
                                                break;
                                            }
                                        }
                                        if (!achou) {
                                            printf("Disciplina não encontrada.\n");
                                        }
                                        break;
                                    }
                                    case 5: {
                                        int idDisc, idAluno;
                                        printf("Código da disciplina: ");
                                        scanf("%d", &idDisc);
                                        printf("Código do aluno a remover: ");
                                        scanf("%d", &idAluno);

                                        int achou = 0;
                                        for (int i = 0; i < qtdDisciplinas; i++) {
                                            if (listarDisciplinas[i].codigo == idDisc) {
                                                for (int j = 0; j < listarDisciplinas[i].totalAlunos; j++) {
                                                    if (listarDisciplinas[i].alunosIds[j] == idAluno) {
                                                        for (int k = j; k < listarDisciplinas[i].totalAlunos - 1; k++) {
                                                            listarDisciplinas[i].alunosIds[k] = listarDisciplinas[i].alunosIds[k + 1];
                                                        }
                                                        listarDisciplinas[i].totalAlunos--;
                                                        
                                                        for (int l = 0; l < qtdAlunos; l++) {
                                                            if (listarAlunos[l].matricula == idAluno) {
                                                                listarAlunos[l].contadorDisciplinas--;
                                                                break;
                                                            }
                                                        }
                                                        printf("Aluno removido.\n");
                                                        achou = 1;
                                                        break;
                                                    }
                                                }
                                            }
                                        }

                                        if (!achou) {
                                            printf("Disciplina ou aluno não encontrado.\n");
                                        }
                                        break;
                                    }
                                    case 0:
                                        printf("Voltando ao menu...\n");
                                        break;
                                    default:
                                        printf("Opção inválida.\n");
                                }
                            } while (subopcao_disc != 0);
                            break;
                        }
                        case 0:
                            printf("Voltando ao menu principal...\n");
                            break;
                        default:
                            printf("Opção inválida.\n");
                    }
                } while (cadastro != 0);
                break;
            }
            case 2: {
                int cadastro2;
                do {
                    printf("\nVocê escolheu a opção 2: Relatórios: alunos\n");
                    printf("1 - Listar todos os alunos\n");
                    printf("2 - Listar alunos por sexo (Masculino/Feminino)\n");
                    printf("3 - Listar alunos ordenados por nome\n");
                    printf("4 - Listar alunos ordenados por data de nascimento\n");
                    printf("5 - Listar aniversariantes do mês\n");
                    printf("6 - Listar alunos a partir de uma string de busca no nome\n");
                    printf("7 - Listar alunos matriculados em menos de 3 disciplinas\n");
                    printf("0 - Voltar\n");
                    scanf("%d", &cadastro2);
                    getchar();

                    switch (cadastro2) {
                        case 1: {
                            printf("\n--- Lista de Todos os Alunos ---\n");
                            if (qtdAlunos == 0) {
                                printf("Nenhum aluno cadastrado.\n");
                            } else {
                                for (int i = 0; i < qtdAlunos; i++) {
                                    printf("Matrícula: %d\n", listarAlunos[i].matricula);
                                    printf("Nome: %s\n", listarAlunos[i].nome);
                                    printf("Sexo: %c\n", listarAlunos[i].sexo);
                                    printf("CPF: %s\n", listarAlunos[i].cpf);
                                    printf("Data de Nascimento: %02d/%02d/%04d\n\n",
                                           listarAlunos[i].nascimento.dia,
                                           listarAlunos[i].nascimento.mes,
                                           listarAlunos[i].nascimento.ano);
                                }
                            }
                            printf("Pressione Enter para continuar...");
                            getchar();
                            break;
                        }
                        case 2: {
                            printf("\n--- Alunos do sexo masculino ---\n");
                            for (int i = 0; i < qtdAlunos; i++) {
                                if (listarAlunos[i].sexo == 'M' || listarAlunos[i].sexo == 'm') {
                                    printf("Código de matricula: %d\n", listarAlunos[i].matricula);
                                    printf("Nome: %s\n", listarAlunos[i].nome);
                                    printf("Sexo: %c\n", listarAlunos[i].sexo);
                                    printf("Data de nascimento: %d\n", listarAlunos[i].nascimento.ano);
                                    printf("\n");
                                }
                            }

                            printf("\n--- Alunas do sexo feminino ---\n");
                            for (int i = 0; i < qtdAlunos; i++) {
                                if (listarAlunos[i].sexo == 'F' || listarAlunos[i].sexo == 'f') {
                                    printf("Código de matricula: %d\n", listarAlunos[i].matricula);
                                    printf("Nome: %s\n", listarAlunos[i].nome);
                                    printf("Sexo: %c\n", listarAlunos[i].sexo);
                                    printf("Data de nascimento: %d\n", listarAlunos[i].nascimento.ano);
                                    printf("\n");
                                }
                            }

                            printf("Pressione Enter para continuar...");
                            getchar();
                            break;
                        }
                        case 3: {
                            Aluno temp[TAM];
                            int cont = 0;
                            for (int i = 0; i < qtdAlunos; i++) {
                                if (listarAlunos[i].matricula != 0) {
                                    temp[cont++] = listarAlunos[i];
                                }
                            }

                            for (int i = 0; i < cont - 1; i++) {
                                for (int j = 0; j < cont - i - 1; j++) {
                                    if (strcmp(temp[j].nome, temp[j + 1].nome) > 0) {
                                        Aluno aux = temp[j];
                                        temp[j] = temp[j + 1];
                                        temp[j + 1] = aux;
                                    }
                                }
                            }

                            printf("\nAlunos em Ordem Alfabética\n");
                            for (int i = 0; i < cont; i++) {
                                printf("Nome: %s | Matrícula: %d\n", temp[i].nome, temp[i].matricula);
                            }
                            printf("\n");

                            printf("Pressione Enter para continuar...");
                            getchar();
                            break;
                        }
                        case 4: {
                            Aluno temp[TAM];
                            int cont = 0;
                            for (int i = 0; i < qtdAlunos; i++) {
                                if (listarAlunos[i].matricula != 0) {
                                    temp[cont++] = listarAlunos[i];
                                }
                            }
                            
                            for(int i = 0; i < qtdAlunos; i++){
                                for(int j = 0; j < cont - i - 1; j++){
                                    if(temp[j].nascimento.ano > temp[j + 1].nascimento.ano) {
                                        Aluno aux = temp[j];
                                        temp[j] = temp[j + 1];
                                        temp[j + 1] = aux;
                                    }
                                }
                            }
                            
                            printf("\nAlunos Ordenados por Data de Nascimento\n\n");
                            for (int i = 0; i < cont; i++) {
                                printf("Nascimento: %02d/%02d/%02d | Nome: %s\n\n", 
                                       temp[i].nascimento.dia, 
                                       temp[i].nascimento.mes, 
                                       temp[i].nascimento.ano, 
                                       temp[i].nome);
                            }
                            
                            printf("Pressione Enter para continuar...");
                            getchar();
                            break;
                        }
                        case 5: {
                            int busca;
                            int encontrou = 0;
                            Aluno temp[TAM];
                            
                            printf("\nDigite o mes de referência: ");
                            scanf("%d", &busca);
                            
                            for(int i = 0; i < qtdAlunos; i++){
                                if(listarAlunos[i].nascimento.mes == busca)
                                    encontrou = 1;
                            }
                            
                            if(encontrou == 0) {
                                printf("\nNão há aniversariantes no mes escolhido!\n\n");
                            } else {
                                printf("\nAniversariantes do Mes\n");
                                for(int i = 0; i < qtdAlunos; i++){
                                    if(listarAlunos[i].nascimento.mes == busca)
                                        printf("\nNome: %s | Data de nascimento: %02d/%02d/%02d | Matrícula: %d\n\n", 
                                               listarAlunos[i].nome, 
                                               listarAlunos[i].nascimento.dia, 
                                               listarAlunos[i].nascimento.mes, 
                                               listarAlunos[i].nascimento.ano, 
                                               listarAlunos[i].matricula);
                                }
                            }
                            
                            printf("Pressione Enter para continuar...");
                            getchar();
                            break;
                        }
                        case 6: {
                            char busca[100];
                            printf("\nDigite a string de busca: ");
                            fgets(busca, sizeof(busca), stdin);
                            busca[strcspn(busca, "\n")] = '\0';

                            int encontrou = 0;
                            printf("\n--- Alunos que correspondem à busca ---\n");
                            for (int i = 0; i < qtdAlunos; i++) {
                                if (strstr(listarAlunos[i].nome, busca) != NULL) {
                                    printf("Matrícula: %d\n", listarAlunos[i].matricula);
                                    printf("Nome: %s\n", listarAlunos[i].nome);
                                    printf("Sexo: %c\n", listarAlunos[i].sexo);
                                    printf("CPF: %s\n", listarAlunos[i].cpf);
                                    printf("Data de Nascimento: %02d/%02d/%04d\n\n",
                                           listarAlunos[i].nascimento.dia,
                                           listarAlunos[i].nascimento.mes,
                                           listarAlunos[i].nascimento.ano);
                                    encontrou = 1;
                                }
                            }

                            if (!encontrou) {
                                printf("Nenhum aluno encontrado com a string informada.\n");
                            }

                            printf("Pressione Enter para continuar...");
                            getchar();
                            break;
                        }
                        case 7: {
                            printf("\n--- Alunos Matriculados em Menos de 3 Disciplinas ---\n");
                            for (int i = 0; i < qtdAlunos; i++) {
                                if (listarAlunos[i].contadorDisciplinas < 3) {
                                    printf("Matrícula: %d\n", listarAlunos[i].matricula);
                                    printf("Nome: %s\n", listarAlunos[i].nome);
                                    printf("Sexo: %c\n", listarAlunos[i].sexo);
                                    printf("Data de Nascimento: %02d/%02d/%04d\n\n",
                                           listarAlunos[i].nascimento.dia,
                                           listarAlunos[i].nascimento.mes,
                                           listarAlunos[i].nascimento.ano);
                                }
                            }

                            printf("Pressione Enter para continuar...");
                            getchar();
                            break;
                        }
                        case 0:
                            break;
                        default:
                            printf("Opção inválida.\n");
                    }
                } while (cadastro2 != 0);
                break;
            }
            case 3: {
                int cadastro3;
                do {
                    printf("Você escolheu a opção 3: Relatorios: Professores\n");
                    printf("1 - Listar todos os Professores\n");
                    printf("2 - Listar professores por sexo (Masculino/Feminino)\n");
                    printf("3 - Listar professores ordenados por nome\n");
                    printf("4 - Listar professores ordenados por data de nascimento\n");
                    printf("5 - Listar aniversariantes do mês\n");
                    printf("6 - Listar professores a partir de uma string de busca no nome\n");
                    printf("0 - Voltar\n");
                    scanf("%d", &cadastro3);
                    getchar();
                    
                    switch (cadastro3) {
                        case 1: {
                            printf("\n--- Lista de Todos os Professores ---\n");
                            if (qtdProfessores == 0) {
                                printf("Nenhum Professor cadastrado.\n");
                            } else {
                                for (int i = 0; i < qtdProfessores; i++) {
                                    printf("Matrícula: %d\n", listarProfessores[i].matricula);
                                    printf("Nome: %s\n", listarProfessores[i].nome);
                                    printf("Sexo: %c\n", listarProfessores[i].sexo);
                                    printf("CPF: %s\n", listarProfessores[i].cpf);
                                    printf("Data de Nascimento: %02d/%02d/%04d\n\n",
                                           listarProfessores[i].nascimento.dia,
                                           listarProfessores[i].nascimento.mes,
                                           listarProfessores[i].nascimento.ano);
                                }
                            }
                            printf("Pressione Enter para continuar...");
                            getchar();
                            break;
                        }
                        case 2: {
                            printf("\n--- Professores do sexo masculino ---\n");
                            for (int i = 0; i < qtdProfessores; i++) {
                                if (listarProfessores[i].sexo == 'M' || listarProfessores[i].sexo == 'm') {
                                    printf("Código de matricula: %d\n", listarProfessores[i].matricula);
                                    printf("Nome: %s\n", listarProfessores[i].nome);
                                    printf("Sexo: %c\n", listarProfessores[i].sexo);
                                    printf("Data de nascimento: %d\n",listarProfessores[i].nascimento.ano);
                                    printf("\n");
                                }
                            }
                        
                            printf("\n--- Professores do sexo feminino ---\n");
                            for (int i = 0; i < qtdProfessores; i++) {
                                if (listarProfessores[i].sexo == 'F' || listarProfessores[i].sexo == 'f') {
                                    printf("Código de matricula: %d\n", listarProfessores[i].matricula);
                                    printf("Nome: %s\n", listarProfessores[i].nome);
                                    printf("Sexo: %c\n", listarProfessores[i].sexo);
                                    printf("Data de nascimento: %d\n", listarProfessores[i].nascimento.ano);
                                    printf("\n");
                                } 
                            }
                      
                            printf("Pressione Enter para continuar...");
                            getchar();
                            break;
                        }
                        case 3: {
                            Professor temp[TAM];
                            int cont = 0;
                            
                            for (int i = 0; i < qtdProfessores; i++) {
                                if (listarProfessores[i].matricula != 0) {
                                    temp[cont++] = listarProfessores[i];
                                }
                            }
                        
                            for (int i = 0; i < cont - 1; i++) {
                                for (int j = 0; j < cont - i - 1; j++) {
                                    if (strcmp(temp[j].nome, temp[j + 1].nome) > 0) {
                                        Professor aux = temp[j];
                                        temp[j] = temp[j + 1];
                                        temp[j + 1] = aux;
                                    }
                                }
                            }
                        
                            printf("\nProfessores em Ordem Alfabética\n");
                            for (int i = 0; i < cont; i++) {
                                printf("Nome: %s | Matrícula: %d\n", temp[i].nome, temp[i].matricula);
                            }
                            printf("\n");
                            
                            printf("Pressione Enter para continuar...");
                            getchar();
                            break;
                        }
                        case 4: {
                            Professor temp[TAM];
                            int cont = 0;
                            for (int i = 0; i < qtdProfessores; i++) {
                                if (listarProfessores[i].matricula != 0) {
                                    temp[cont++] = listarProfessores[i];
                                }
                            }
                            
                            for(int i = 0; i < qtdProfessores; i++){
                                for(int j = 0; j < cont - i - 1; j++){
                                    if(temp[j].nascimento.ano > temp[j + 1].nascimento.ano) {
                                        Professor aux = temp[j];
                                        temp[j] = temp[j + 1];
                                        temp[j + 1] = aux;
                                    }
                                }
                            }
                            
                            printf("\nProfessores Ordenados por Data de Nascimento\n\n");
                            for (int i = 0; i < cont; i++) {
                                printf("Nascimento: %02d/%02d/%02d | Nome: %s\n\n", 
                                       temp[i].nascimento.dia, 
                                       temp[i].nascimento.mes, 
                                       temp[i].nascimento.ano, 
                                       temp[i].nome);
                            }
                            
                            printf("Pressione Enter para continuar...");
                            getchar();
                            break;
                        }
                        case 5: {
                            int busca;
                            int encontrou = 0;
                            Professor temp[TAM];
                            
                            printf("\nDigite o mes de referência: ");
                            scanf("%d", &busca);
                            
                            for(int i = 0; i < qtdProfessores; i++){
                                if(listarProfessores[i].nascimento.mes == busca)
                                    encontrou = 1;
                            }
                            
                            if(encontrou == 0) {
                                printf("\nNão há aniversariantes no mes escolhido!\n\n");
                            } else {
                                printf("\nAniversariantes do Mes\n");
                                for(int i = 0; i < qtdProfessores; i++){
                                    if(listarProfessores[i].nascimento.mes == busca)
                                        printf("\nNome: %s | Data de nascimento: %02d/%02d/%02d | Matrícula: %d\n\n", 
                                               listarProfessores[i].nome, 
                                               listarProfessores[i].nascimento.dia, 
                                               listarProfessores[i].nascimento.mes, 
                                               listarProfessores[i].nascimento.ano, 
                                               listarProfessores[i].matricula);
                                }
                            }
                            
                            printf("Pressione Enter para continuar...");
                            getchar();
                            break;
                        }
                        case 6: {
                            char busca[100];
                            printf("\nDigite a string de busca para professor: ");
                            while (getchar() != '\n');
                            fgets(busca, sizeof(busca), stdin);
                            busca[strcspn(busca, "\n")] = '\0';
                        
                            int encontrou = 0;
                            printf("\n--- Professores que correspondem à busca ---\n");
                            for (int i = 0; i < qtdProfessores; i++) {
                                if (strstr(listarProfessores[i].nome, busca) != NULL) {
                                    printf("Matrícula: %d\n", listarProfessores[i].matricula);
                                    printf("Nome: %s\n", listarProfessores[i].nome);
                                    printf("Sexo: %c\n", listarProfessores[i].sexo);
                                    printf("CPF: %s\n", listarProfessores[i].cpf);
                                    printf("Data de Nascimento: %02d/%02d/%04d\n\n",
                                           listarProfessores[i].nascimento.dia,
                                           listarProfessores[i].nascimento.mes,
                                           listarProfessores[i].nascimento.ano);
                                    encontrou = 1;
                                }
                            }
                        
                            if (!encontrou) {
                                printf("Nenhum professor encontrado com a string informada.\n");
                            }
                        
                            printf("Pressione Enter para continuar...");
                            getchar();
                            break;
                        }
                        case 0:
                            break;
                        default:
                            printf("Opção inválida.\n");
                    }
                } while (cadastro3 != 0);
                break;
            }
            case 4: {
                int cadastro4;
                do {
                    printf("Você escolheu a opção 4: Relatórios: Disciplinas\n");
                    printf("1 - Listar todas as disciplinas\n");
                    printf("2 - Listar uma disciplina (dados da disciplina + alunos matriculados)\n");
                    printf("3 - Listar disciplinas com mais de 40 alunos (mostrar nome do professor também)\n");
                    printf("0 - Voltar\n");
                    scanf("%d", &cadastro4);
                    getchar();

                    switch (cadastro4) {
                        case 1: {
                            printf("\n--- Lista de Todas as Disciplinas ---\n");
                            if (qtdDisciplinas == 0) {
                                printf("Nenhuma Disciplina cadastrada.\n");
                            } else {
                                for (int i = 0; i < qtdDisciplinas; i++) {
                                    printf("Nome: %s\n", listarDisciplinas[i].nome);
                                    printf("Código: %d\n", listarDisciplinas[i].codigo);
                                    printf("Semestre: %d\n", listarDisciplinas[i].semestre);
                                    printf("Professor: %d\n", listarDisciplinas[i].codProfessor);
                                }
                            }
                            printf("Pressione Enter para continuar...");
                            getchar();
                            break;
                        }
                        case 2: {
                            int codigoBusca;
                            printf("\nDigite o código da disciplina que deseja detalhar: ");
                            scanf("%d", &codigoBusca);
                            getchar();
                                
                            int encontrou = 0;
                            for (int i = 0; i < qtdDisciplinas; i++) {
                                if (listarDisciplinas[i].codigo == codigoBusca) {
                                    encontrou = 1;
                                    printf("\n--- Detalhes da Disciplina ---\n");
                                    printf("Nome: %s\n", listarDisciplinas[i].nome);
                                    printf("Semestre: %d\n", listarDisciplinas[i].semestre);
                                    printf("Professor (código): %d\n", listarDisciplinas[i].codProfessor);
                                
                                    if (listarDisciplinas[i].totalAlunos == 0) {
                                        printf("Nenhum aluno matriculado nesta disciplina.\n\n");
                                    } else {
                                        printf("\nAlunos matriculados:\n");
                                        for (int j = 0; j < listarDisciplinas[i].totalAlunos; j++) {
                                            int idAluno = listarDisciplinas[i].alunosIds[j];
                                            
                                            for (int k = 0; k < qtdAlunos; k++) {
                                                if (listarAlunos[k].matricula == idAluno) {
                                                    printf("- %s (Matrícula: %d)\n", listarAlunos[k].nome, listarAlunos[k].matricula);
                                                    break;
                                                }
                                            }
                                        }
                                    }
                                    break;
                                }    
                            }    
                            if (!encontrou) {
                                printf("Disciplina com código %d não encontrada.\n", codigoBusca);
                            }
                            printf("Pressione Enter para continuar...");
                            getchar();
                            break;
                        }
                        case 3: {
                            int encontrou = 0;
                            printf("\n### Disciplinas com mais de 40 alunos: ###\n");
                            
                            for (int i = 0; i < qtdDisciplinas; i++) {
                                if (listarDisciplinas[i].totalAlunos > 40) {
                                    encontrou = 1;
                                    char nomeProfessor[100] = "Professor não encontrado";
                                    for (int j = 0; j < qtdProfessores; j++) {
                                        if (listarProfessores[j].matricula == listarDisciplinas[i].codProfessor) { 
                                            strcpy(nomeProfessor, listarProfessores[j].nome);
                                            break;
                                        }
                                    }
                                    
                                    printf("\nDisciplina: %s\n", listarDisciplinas[i].nome);
                                    printf("Total de Alunos: %d\n", listarDisciplinas[i].totalAlunos);
                                    printf("Professor: %s\n", nomeProfessor);  
                                }
                            }
                                
                            if (!encontrou) {
                                printf("Nenhuma disciplina com mais de 40 alunos foi encontrada.\n");
                            }
                                
                            printf("Pressione Enter para continuar...");
                            getchar();
                            break;
                        }
                        case 0:
                            break;
                        default:
                            printf("Opção inválida.\n");
                    }
                } while (cadastro4 != 0);
                break;
            }
            case 0:
                printf("Encerrando programa...\n");
                break;
            default:
                printf("Opção inválida!\n");
        }
    } while (opcao != 0);

    return 0;
}
