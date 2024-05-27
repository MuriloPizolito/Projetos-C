#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <time.h>
#include <string.h>

void calculoParImpar();
void converterRealDolar();
void calculadoraSimples();
void conversorQuilometrosMetros();
void conversorCelsiusFahrenheit();
void jurosSimples();
void validadorCpf();
void calculadoraImc();
void mediaNotas();
void calculadoraDiasDatas();

int main(){
   setlocale(LC_ALL, "PORTUGUESE");

   int escolha;

   do {
   printf("\nMENU\n");
   printf("1. Identificar se o número é Par ou ímpar.\n");
   printf("2. Converter Dólar para real.\n");
   printf("3. Calculadora simples com dois n�meros.\n");
   printf("4. Conversor de Quilômetros para Metros.\n");
   printf("5. Conversor de Celsius para Fahrenheit.\n");
   printf("6. Calculadora de Juros Simples.\n");
   printf("7. Validador de CPF.\n");
   printf("8. Calculadora de IMC.\n");
   printf("9. Calculadora de Média de 4 notas.\n");
   printf("10. Calculadora de dias entre Datas.\n");
   printf("11. Sair.\n\n");

   printf("Escolha a operação desejada: ");
   scanf("%d", &escolha);


   switch (escolha) {
        case 1:
            calculoParImpar();
            break;
        case 2:
            converterRealDolar();
            break;
        case 3:
            calculadoraSimples();
            break;
        case 4:
            conversorQuilometrosMetros();
            break;
        case 5:
            conversorCelsiusFahrenheit();
            break;
        case 6:
            jurosSimples();
            break;
        case 7:
            validadorCpf();
            break;
        case 8:
            calculadoraImc();
            break;
        case 9:
            mediaNotas();
            break;
        case 10:
            calculadoraDiasDatas();
            break;
        case 11:
            printf("\nFechando o programa.\n");
            break;
        default:
            printf("\nOpção inválida. Tente novamente.\n");
     }
   } while (escolha != 11);


    return 0;
}

void calculoParImpar(){
    int numero;

    printf("\nVerficando se o número é par ou ímpar.\n\n");

    printf("Digite um número: ");
    scanf("%d", &numero);

    if (numero % 2 == 0) {
        printf("\nO número %d é par.\n", numero);
    } else {
        printf("\nO número %d é ímpar.\n", numero);
    }

}

void converterRealDolar() {
    float real, dolar;

    printf("\nConversor de real para dólar.\n\n");

    printf("Digite o valor em real: ");
    scanf("%f", &real);

    //0.19  - valor do d�lar.
    dolar = real * 0.19;

    printf("\nO valor em real convertido para dólar é igual a: $ %.2f\n ", dolar);
}

void calculadoraSimples() {
    int escolha2;
    float numero1, numero2, resultado;

    printf("\nCalculadora simples.\n\n");

    printf("Digite o primeiro número: ");
    scanf("%f", &numero1);

    printf("Digite o segundo número: ");
    scanf("%f", &numero2);

    printf("\n1. Adição.\n");
    printf("2. Subtração.\n");
    printf("3. Multiplicação.\n");
    printf("4. Divisão.\n\n");

    printf("Escolha a operação: ");
    scanf("%d", &escolha2);

    switch (escolha2) {
            case 1:
                resultado = numero1 + numero2;
                printf("\nResultado da adição: %.2f + %.2f = %.2f\n", numero1, numero2, resultado);
                break;
            case 2:
                resultado = numero1 - numero2;
                printf("\nResultado da subtração: %.2f - %.2f = %.2f\n", numero1, numero2, resultado);
                break;
            case 3:
                resultado = numero1 * numero2;
                printf("\nResultado da multiplicação: %.2f x %.2f = %.2f\n", numero1, numero2, resultado);
                break;
            case 4:
                resultado = numero1 / numero2;
                printf("\nResultado da divis�o: %.2f / %.2f = %.2f\n", numero1, numero2, resultado);
                break;
            default:
                printf("Escolha inválida");
    }

}

void conversorQuilometrosMetros() {
    float quilometros, metros;

    printf("\nConversor de Quilômetros para metros.\n\n");

    printf("Digite o valor em Quilômetros: ");
    scanf("%f", &quilometros);

    metros = quilometros * 1000;

    printf("\nO valor em quilômetros convertido para metros é igual a: %.2f m\n", metros);
}

void conversorCelsiusFahrenheit() {
    float celsius, fahrenheit;

    printf("\nConversor de Celsius para Fahrenheit.\n\n");

    printf("Digite o valor em Celsius: ");
    scanf("%f", &celsius);

    fahrenheit = (celsius * 1.8) + 32;

    printf("\nO valor em Celsius convertido para Fahrenheit é igual a: %.2f\n", fahrenheit);
}

void jurosSimples() {
    float valor, taxa, tempo, juros;

    printf("\nCalculadora de Juros Simples.\n\n");

    printf("Digite o valor: ");
    scanf("%f", &valor);

    printf("Qual o valor da taxa de juros: ");
    scanf("%f", &taxa);

    printf("Informe o tempo: ");
    scanf("%f", &tempo);

    juros = valor * taxa * tempo;

    printf("\nO total é: %.2f\n", juros);
}

void validadorCpf() {
    char cpf[12];
    int soma1 = 0;
    int soma2 = 0;
    int digito1, digito2;
    
    printf("\nValidador de CPF.\n\n");
    
    do {
    printf("Informe o número do seu CPF: ");
    scanf("%s", cpf);
    
  		  	// verificando se o cpf tem 11 d�gitos
   			 if (strlen(cpf) != 11){
    			printf("\nCPF inválido: deve conter 11 d�gitos.\n");
    			return;
			}
		
    		// calculando o primeiro d�gito verificador
    		for (int i = 0; i < 9; i++) {
    		soma1 += (cpf[i] - '0') * (10 - i);
			}
			digito1 = (soma1 * 10) % 11;
		
			// calcula o segundo d�gito verificador
			for (int j = 0; j < 10; j++) {
				soma2 += (cpf[j] - '0' * (11 - j));
			}
    		digito2 = (soma2 * 10) % 11;
    	
    		// Verifica se os d�gitos verificadores s�o iguais aos do cpf
    		if ((digito1 == (cpf[9] - '0')) && (digito2 == (cpf[10] - '0'))){
    			printf("CPF válido.\n");
			} else {
				printf("CPF inválido.\n");
			}
		 
		} while (strcmp(cpf, "0") != 0);

}

void calculadoraImc() {
    float peso, altura, imc;

    printf("\nCalculadora IMC.\n\n");

    printf("Informe o seu peso: ");
    scanf("%f", &peso);

    printf("Informe a sua altura: ");
    scanf("%f", &altura);

    imc = peso / (altura * altura);

    printf("\nO IMC é igual a: %.2f\n", imc);

}

void mediaNotas() {
    float nota1, nota2, nota3, nota4, media;

    printf("\nCalculadora de Média de 4 notas.\n\n");

    printf("Digite a primeira nota: ");
    scanf("%f", &nota1);

    printf("Digite a segunda nota: ");
    scanf("%f", &nota2);

    printf("Digite a terceira nota: ");
    scanf("%f", &nota3);

    printf("Digite a quarta nota: ");
    scanf("%f", &nota4);


    media = (nota1 + nota2+ nota3 + nota4) / 4;

    printf("\nO valor da média é igual a: %.2f\n", media);
}

void calculadoraDiasDatas() {
    struct tm dataInicial = {0};
    struct tm dataFinal = {0};

    char strDataInicial[11], strDataFinal[11];

    printf("Digite a data inicial (DD/MM/AAAA): ");
    scanf("%s", strDataInicial);

    printf("Digite a data final (DD/MM/AAAA): ");
    scanf("%s", strDataFinal);

    sscanf(strDataInicial, "%d/%d/%d", &dataInicial.tm_mday, &dataInicial.tm_mon, &dataInicial.tm_year);
    sscanf(strDataFinal, "%d/%d/%d", &dataFinal.tm_mday, &dataFinal.tm_mon, &dataFinal.tm_year);

    // Ajustando os valores para o formato esperado pela struct tm
    dataInicial.tm_mon -= 1; // M�s come�a em 0 (janeiro)
    dataInicial.tm_year -= 1900; // Ano baseado em 1900
    dataFinal.tm_mon -= 1;
    dataFinal.tm_year -= 1900;

    // Convertendo para time_t
    time_t t1 = mktime(&dataInicial);
    time_t t2 = mktime(&dataFinal);

    // Verificando se a convers�o foi bem-sucedida
    if (t1 == -1 || t2 == -1) {
        printf("Erro ao converter datas para o formato time_t.\n");
       // return 1;
    }

    // Calculando a diferen�a em segundos
    double diferencaSegundos = difftime(t2, t1);

    // Convertendo para dias
    int diferencaDias = (int)(diferencaSegundos / (60 * 60 * 24));

    printf("\nA diferença entre as datas é de %d dias.\n", diferencaDias);
}
