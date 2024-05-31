#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h> //  strcmp

// estrutura para representar um usuário
struct User {
	char nome [50];
	int idade;
};

// criar novo usuário
void criar_usuario(struct User users[], int * count) {
	printf("Digite o nome do usuário: ");
	scanf("%s", users[*count].nome);
	
	printf("Digite a idade do usuário: ");
	scanf("%d", &users[*count].idade);
	(*count)++;
}

// função para exibir todos os usuários
void ler_usuarios(struct User users[], int count) {
	printf("\nUsuários cadastrados: \n");
	
	for (int i = 0; i < count; i++) {
		printf("Nome: %s, Idade: %d\n", users[i].nome, users[i].idade);
	}
}

// função para atualizar idade de um usuário
void update_user(struct User users[], int count, const char*name, int new_age) {
	for (int i = 0; i < count; i++) {
		if (strcmp(users[i].nome, name)== 0){
			users[i].idade = new_age;
			printf("Idade atualizada com sucesso!\n");
			return;
		}
	}
	printf("Usuário não encontrado.\n");	
}

// função para remover um usuário
void apagar_usuarios(struct User users[], int*count, const char*name) {
	for (int i = 0; i < *count; i++) {
		if (strcmp(users[i].nome, name)== 0) {
			//substituir o usuário a ser excluido pelo último usuário da lista
			users[i]=users[(*count)- 1];
			(*count)--;
			printf("Usuário removido com sucesso!\n");
			return;
		}
	}
	printf("Usuário não encontrado.\n");
}

// função para salvar os usuários em um arquivo
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
		printf("1. Criar usuário\n");
		printf("2. Exibir usuário\n");
		printf("3. Atualizar idade\n");
		printf("4. Remover usuário\n");
		printf("5. Sair\n");
		
		printf(">> Escolha uma opção: ");
		scanf("%d", &escolha);
		
		switch (escolha) {
			case 1:
				criar_usuario(users, &contar_usuario);
				break;
			case 2:
				ler_usuarios(users, contar_usuario);
				break;
			case 3:
				printf("Digite o nome do usuário: ");
				scanf("%s", nome);
				
				printf("Digite a nova idade: ");
				scanf("%d", &nova_idade);
				
				update_user(users, contar_usuario, nome, nova_idade);
				break;
			case 4:
				printf("Digite o nome do usuário a ser removido: ");
				scanf("%s", nome);
				
				apagar_usuarios(users, &contar_usuario, nome);
				break;			
			case 5:
				salvar_em_arquivo(users, contar_usuario, filename);
				break;
			default: 
				printf("Opção inválida.\n");		
		}
	} while (escolha != 5);
	

	return 0;
}
