#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

struct produto{
    int codigo;
    char nome[50];
    char categoria[50];
    int estoque;    
    float preco;
    char fornecedor[50];
    int ativo;
    char perecivel;  // 's' ou 'n'
    char validade[11]; // "dd/mm/aaaa"
    int dia, mes, ano;
};
struct produto p[100];
int totalp=0;
int cont = 0;

void menu();
void cadastro();
void editar();
void excluir();
void consultar();
void listar();

void limparBuffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

int lerInteiro(const char* prompt) {
    int valor;
    while (1) {
        printf("%s", prompt);
        if (scanf("%d", &valor) == 1) {
            limparBuffer(); // limpa caractere a mais
            return valor; 
        } else {
            printf("Entrada invalida! Digite apenas numeros.\n");
            limparBuffer(); // limpa caractere invalido
        }
    }
}

float lerFloat(const char* prompt) {
    float valor;
    while (1) {
        printf("%s", prompt);
        if (scanf("%f", &valor) == 1) {
            limparBuffer();
            return valor;
        } else {
            printf("Entrada invalida! Digite um numero valido.\n");
            limparBuffer();
        }
    }
}

int main(){
    menu();
}

void pausar() {
    printf("\nPressione Enter para continuar...");
    limparBuffer();
}

void menu(){
    int op;
    for(;;){
        printf("\n\n===============HyperSoft===============");
        printf("\n-------------Menu Principal------------\n");
        printf("1-cadastrar novo produto\n");
        printf("2-editar produto\n");
        printf("3-excluir produto\n");
        printf("4-consultar produto\n");
        printf("5-listar produto\n");
        printf("0-finalizar\n");
        op=lerInteiro("");        
        if(op==1){
            cadastro();
        }else if(op==2){
            editar();
        }else if(op==3){
            excluir();
        }else if(op==4){
            consultar();
        }else if(op==5){
            listar();
        }else if(op==0){
            printf("Fechando o sistema...\n");
            break;
        }else{
            printf("opcao invalida\n");
        }
    // limpar a tela no Linux
    system("clear");

    // limpar a tela no Windows
    system("cls");
    }
}
void cadastro() {
    printf("\n== Cadastro de produtos ==\n");
    p[cont].codigo = cont + 1;  // 0 vai 1 dps 2 e etc
    printf("codigo %i\n", p[cont].codigo);

    printf("nome do produto:");
    scanf("%s", p[cont].nome); 
    
    printf("categoria:");
    scanf("%s", p[cont].categoria);
    
    printf("fornecedor:");
    scanf("%s", p[cont].fornecedor);
    
    
    do
    {
        p[cont].estoque = lerInteiro("Quantidade:");
        if(p[cont].estoque < 0)
        printf("Quantidade invalida...\n");
    } while (p[cont].estoque < 0);
    
    do
    {
        p[cont].preco = lerFloat("Preco:");
        if(p[cont].preco < 0)
        printf("Preco invalido...\n");
    } while (p[cont].preco <= 0.0);

    
    
    char resposta;
        int formatoValido;

        do{
        printf("O produto e perecivel (s/n):");
        scanf(" %c", &resposta);
        resposta = tolower(resposta);

            if (resposta == 's') {
            do {
                printf("Digite a validade (dd/mm/aaaa): ");
                scanf("%10s", p[cont].validade);

                formatoValido = (strlen(p[cont].validade) == 10 && 
                            p[cont].validade[2] == '/' && 
                            p[cont].validade[5] == '/');

                if(formatoValido) {
                    formatoValido = (sscanf(p[cont].validade, "%d/%d/%d", &p[cont].dia, &p[cont].mes, &p[cont].ano) == 3);
                }

                if(formatoValido) {
                    formatoValido = (p[cont].dia >= 1 && p[cont].dia <= 31 && 
                                p[cont].mes >= 1 && p[cont].mes <= 12 && 
                                p[cont].ano >= 2025 && p[cont].ano <= 2100);
                }
                
                if(!formatoValido) {
                    printf("Formato invalido! Use dd/mm/aaaa com valores validos.\n");
                } else {
                    printf("Validade armazenada\n");
                }
            } while (!formatoValido);
        }
        else if (resposta == 'n') {
            strcpy(p[cont].validade, "N/A");
            printf("Produto nao perecivel.\n");
        } 
        else {
            printf("Resposta invalida! Use 's' ou 'n'.\n");
        }
    } while(resposta != 's' && resposta != 'n');
    printf("Produto cadastrado com sucesso! \n");
    p[cont].ativo = 1;
    totalp++;
    cont++;
    system("pause");

    system("clear");


    system("cls");
}

void editar(){
    if(totalp == 0) {
        printf("Nao ha produtos cadastrados para editar!\n");
        return;
    }

    printf("\nProdutos disponiveis para editar:\n");
    for (int i = 0; i < totalp; i++) {
        if (p[i].ativo) {
            printf("Codigo: %d - %s\n", p[i].codigo, p[i].nome);
        }
    }
    
    int codigo;
    printf("Digite o codigo do produto para editar:\n");
    scanf("%d", &codigo);

    int encontrado = -1;
    for(int i = 0; i < totalp; i++) {
        if(p[i].codigo == codigo && p[i].ativo == 1) {
            encontrado = i;
            break;
        }
    }
    
    if(encontrado == -1) {
        printf("Produto nao encontrado ou inativo\n");
        return;
    }
    
    printf("== Editando produto codigo %i - nome %s =\n", 
           p[encontrado].codigo, p[encontrado].nome);

    printf("Novo nome (nome atual: %s): ", p[encontrado].nome);
    scanf(" %49[^\n]", p[encontrado].nome);

    printf("Nova categoria (categoria atual: %s): ", p[encontrado].categoria);
    scanf(" %49[^\n]", p[encontrado].categoria);

    printf("Novo fornecedor (fornecedor atual: %s): ", p[encontrado].fornecedor);
    scanf(" %49[^\n]", p[encontrado].fornecedor);

    do {
        printf("quantidade atual: %d, ", p[encontrado].estoque);
        p[encontrado].estoque=lerInteiro("Nova quantidade: ");
        if(p[encontrado].estoque < 0) {
            printf("Quantidade nao pode ser negativa!\n");
        }
    } while(p[encontrado].estoque < 0);

    do {
        printf("Preco atual: %.2f, ", p[encontrado].preco);
        p[encontrado].preco = lerFloat("Novo preco: ");
        if(p[encontrado].preco < 0) {
            printf("Preco nao pode ser negativo!\n");
        }
    } while(p[encontrado].preco < 0);

    char resposta;
    int formatoValido;
    do {
        printf("O produto e perecivel? (s/n) [atual: %s]: ",
               strcmp(p[encontrado].validade, "N/A") == 0 ? "Nao" : "Sim");
        scanf(" %c", &resposta);
        resposta = tolower(resposta);

        if (resposta == 's') {
        do {
            printf("Digite a validade nova data (dd/mm/aaaa): ");
            scanf("%10s", p[cont].validade);
            
            formatoValido = (strlen(p[cont].validade) == 10 && 
                          p[cont].validade[2] == '/' && 
                          p[cont].validade[5] == '/');
            
            if(formatoValido) {
                formatoValido = (sscanf(p[cont].validade, "%d/%d/%d", &p[cont].dia, &p[cont].mes, &p[cont].ano) == 3);
            }
            
            if(formatoValido) {
                formatoValido = (p[cont].dia >= 1 && p[cont].dia <= 31 && 
                               p[cont].mes >= 1 && p[cont].mes <= 12 && 
                               p[cont].ano >= 2025 && p[cont].ano <= 2100);
            }
            
            if(!formatoValido) {
                printf("Formato invalido! Use dd/mm/aaaa com valores validos.\n");
            } else {
                printf("Validade armazenada\n");
            }
        } while (!formatoValido);
        }
        else if (resposta == 'n') {
            strcpy(p[cont].validade, "N/A");
            printf("Produto nao perecivel.\n");
        } 
        else {
            printf("Resposta invalida! Use 's' ou 'n'.\n");
        }
    } while(resposta != 's' && resposta != 'n');

    printf("Produto editado com sucesso!\n");

    system("clear");


    system("cls");
}

void excluir() {
    printf("\n=== Excluir produto ===\n");
    // Verifica se tem produtos cadastrados
    if (totalp == 0) {
        printf("Nenhum produto cadastrado.\n");
        pausar();
        return;
    }
    // Mostra lista de produtos ativos
    printf("\nProdutos disponiveis para exclusao:\n");
    for (int i = 0; i < totalp; i++) {
        if (p[i].ativo) {
            printf("Codigo: %d - %s\n", p[i].codigo, p[i].nome);
        }
    }
    // digite o codigo do produto que quer excluir
    int codigo;
    printf("\nDigite o codigo do produto que deseja excluir: ");
    scanf("%d", &codigo);
    limparBuffer();
    // busca o produto
    int encontrado = -1;
    for (int i = 0; i < totalp; i++) {
        if (p[i].codigo == codigo && p[i].ativo) {
            encontrado = i;
            break;
        }
    }
    // verifica se encontrou
    if (encontrado == -1) {
        printf("Produto nao encontrado ou ja inativo!\n");
        pausar();
        return;
    }
    printf("Tem certeza que deseja excluir '%s' (Codigo: %d)? (s/n): ",
           p[encontrado].nome, p[encontrado].codigo);
    char resposta;
    scanf("%c", &resposta);
    limparBuffer();
    if (tolower(resposta) == 's') {
        p[encontrado].ativo = 0;
        printf("Produto excluido com sucesso!\n");
    } else {
        printf("Exclusao cancelada.\n");
    }
    system("pause");
    system("clear");
    system("cls");
}

void mostrarProduto(int indice) {
    printf("\n----------------------------------------");
    printf("\nCodigo: %d", p[indice].codigo);
    printf("\nNome: %s", p[indice].nome);
    printf("\nCategoria: %s", p[indice].categoria);
    printf("\nEstoque: %d", p[indice].estoque);
    printf("\nPreco: R$%.2f1", p[indice].preco);
    printf("\nFornecedor: %s", p[indice].fornecedor);
    printf("\nPerecivel: %c", p[indice].perecivel);
    printf("\nValidade: %s", (p[indice].perecivel == 's') ? p[indice].validade : "N/A");
    printf("\n----------------------------------------\n");
}

void consultarPorCodigo() {
    printf("\n=== Consultar por codigo ===\n");
    
    if (totalp == 0) {
        printf("Nenhum produto cadastrado.\n");
        system("pause");
        return;
    }
    int codigo;
    printf("Digite o codigo do produto: ");
    if(scanf("%d", &codigo) != 1) {
        printf("Entrada invalida!\n");
        limparBuffer();
        system("pause");
        return;
    }
    limparBuffer();
    int encontrado = -1;
    for (int i = 0; i < totalp; i++) {
        if (p[i].codigo == codigo && p[i].ativo) {
            encontrado = i;
            break;
        }
    }
    if (encontrado == -1) {
        printf("Produto nao encontrado ou inativo.\n");
    } else {
        mostrarProduto(encontrado);
    }
    system("pause");
    system("clear");
    system("cls");
}

void consultarPorNome() {
    printf("\n=== Consultar por nome ===\n");
    if (totalp == 0) {
        printf("Nenhum produto cadastrado.\n");
        system("pause");
        return;
    }
    char nome[50];
    printf("Digite o nome: ");
    scanf("%49[^\n]", nome);
    limparBuffer();
    int encontrados = 0;
    printf("\n===== Resultados da busca =====\n");
    for (int i = 0; i < totalp; i++) {
        if (p[i].ativo && strstr(p[i].nome, nome) != NULL) {
            mostrarProduto(i);
            encontrados++;
        }
    }
    if (encontrados == 0) {
        printf("Nenhum produto encontrado com esse nome.\n");
    }
    system("pause");
    system("clear");
    system("cls");
}

void consultarPorCategoria() {
    printf("\n=== Consultar por categoria ===\n");
    
    if (totalp == 0) {
        printf("Nenhum produto cadastrado.\n");
        system("pause");
        return;
    }
    char categoria[50];
    printf("Digite a categoria: ");
    scanf("%49[^\n]", categoria);
    limparBuffer();

    int encontrados = 0;

    printf("\n===== Produtos na categoria '%s' =====\n", categoria);
    for (int i = 0; i < totalp; i++) {
        if (p[i].ativo && strcmp(p[i].categoria, categoria) == 0) {
            mostrarProduto(i);
            encontrados++;
        }
    }
    if (encontrados == 0) {
        printf("Nenhum produto encontrado nesta categoria.\n");
    }
    system("pause");
    system("clear");
    system("cls");
}

void consultar() {
    int opcao;
    
    do {
        printf("\n=== Consultar produtos ===\n");
        printf("1. Por codigo\n");
        printf("2. Por nome\n");
        printf("3. Por categoria\n");
        printf("0. Voltar ao menu\n");
        printf("Escolha uma opcao: ");
        
        if(scanf("%d", &opcao) != 1) {
            printf("Entrada inválida!\n");
            limparBuffer();
            continue;
        }
        limparBuffer();

        switch(opcao) {
            case 1: consultarPorCodigo(); break;
            case 2: consultarPorNome(); break;
            case 3: consultarPorCategoria(); break;
            case 0: break;
            default: printf("Opção inválida! Tente novamente.\n");
        }
    } while(opcao != 0);
}


void listar(){
    printf("\n=== Lista de produtos ===\n");
    
    if (totalp == 0) {
        printf("Nenhum produto cadastrado.\n");
        return;
    }
    
    int produtosAtivos = 0;
    
    printf("%-6s %-20s %-15s %-8s %-10s %-15s %-12s\n", 
           "Codigo", "Nome", "Categoria", "Qtd", "Preco", "Fornecedor", "Validade");
    printf("----------------------------------------------------------------------------\n");
    
    for (int i = 0; i < totalp; i++) {
        if (p[i].ativo) {
            printf("%-6d %-20s %-15s %-8d R$%-9.2f %-15s %-12s\n", 
                   p[i].codigo,
                   p[i].nome,
                   p[i].categoria,
                   p[i].estoque,
                   p[i].preco,
                   p[i].fornecedor,
                   p[i].perecivel ? p[i].validade : "N/A");
            produtosAtivos++;
        }
    }
    
    if (produtosAtivos == 0) {
        printf("Nenhum produto ativo cadastrado.\n");
    }
    system("pause");
    system("clear");
    system("cls");
}

int buscarPorCodigo(int codigo) {
    for (int i = 0; i < totalp; i++) {
        if (p[i].codigo == codigo && p[i].ativo) {
            return i;
        }
    }
    return -1;
}