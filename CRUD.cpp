#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h> // biblioteca string.h para usar strcmp

// estrutura para representar um usu�rio
struct User {
	char nome [50];
	int idade;
};

// criar novo usu�rio
void criar_usuario(struct User users[], int * count) {
	printf("Digite o nome do usu�rio: ");
	scanf("%s", users[*count].nome);
	
	printf("Digite a idade do usu�rio: ");
	scanf("%d", &users[*count].idade);
	(*count)++;
}

// fun��o para exibir todos os usu�rios
void ler_usuarios(struct User users[], int count) {
	printf("\nUsu�rios cadastrados: \n");
	
	for (int i = 0; i < count; i++) {
		printf("Nome: %s, Idade: %d\n", users[i].nome, users[i].idade);
	}
}

// fun��o para atualizar idade de um usu�rio
void update_user(struct User users[], int count, const char*name, int new_age) {
	for (int i = 0; i < count; i++) {
		if (strcmp(users[i].nome, name)== 0){
			users[i].idade = new_age;
			printf("Idade atualizada com sucesso!\n");
			return;
		}
	}
	printf("Usu�rio n�o encontrado.\n");	
}

// fun��o para remover um usu�rio
void apagar_usuarios(struct User users[], int*count, const char*name) {
	for (int i = 0; i < *count; i++) {
		if (strcmp(users[i].nome, name)== 0) {
			//substituir o usu�rio a ser exclu�do pelo �ltimo usu�rio da lista
			users[i]=users[(*count)- 1];
			(*count)--;
			printf("Usu�rio removido com sucesso!\n");
			return;
		}
	}
	printf("Usu�rio n�o encontrado.\n");
}

// fun��o para salvar os usu�rios em um arquivo
void salvar_em_arquivo(struct User users[], int count, const char*filename) {
	FILE*file = fopen(filename, "w");
	if (file == NULL) {
		printf("Erro ao abrir o arquivo.\n");
		return;
	}
	for (int i = 0; i < count; i++) {
		fprintf(file, "%s %d\n", users[i].nome, users[i].idade);
	}
	
	fclose(file);
	printf("Dados salvos em %s.\n", filename);

}


int main () {
	setlocale(LC_ALL, "PORTUGUESE");
	
	struct User users[100];
	int contar_usuario = 0;
	char filename[] = "users.txt";
	
	int escolha;
	char nome[50];
	int nova_idade;
	
	do {
		printf("\nMenu: \n");
		printf("1. Criar usu�rio\n");
		printf("2. Exibir usu�rio\n");
		printf("3. Atualizar idade\n");
		printf("4. Remover usu�rio\n");
		printf("5. Sair\n");
		
		printf(">> Escolha uma op��o: ");
		scanf("%d", &escolha);
		
		switch (escolha) {
			case 1:
				criar_usuario(users, &contar_usuario);
				break;
			case 2:
				ler_usuarios(users, contar_usuario);
				break;
			case 3:
				printf("Digite o nome do usu�rio: ");
				scanf("%s", nome);
				
				printf("Digite a nova idade: ");
				scanf("%d", &nova_idade);
				
				update_user(users, contar_usuario, nome, nova_idade);
				break;
			case 4:
				printf("Digite o nome do usu�rio a ser removido: ");
				scanf("%s", nome);
				
				apagar_usuarios(users, &contar_usuario, nome);
				break;			
			case 5:
				salvar_em_arquivo(users, contar_usuario, filename);
				break;
			default: 
				printf("Op��o inv�lida.\n");		
		}
	} while (escolha != 5);
	

	return 0;
}
