#include "stdio.h"
#include "stdlib.h"
#include "math.h"
#include "string.h"

#define MAX_PESSOAS 5

struct tPessoa
{
	char  nome[100];
	int   idade;
	int   peso;
	float altura;
	float imc;
};

typedef struct tPessoa Pessoa;

struct tPacientes {
	Pessoa pessoas[MAX_PESSOAS];
	float media;
};

typedef struct tPacientes Pacientes;

void exibirIMCPacientes (Pacientes pacientes);
Pessoa maiorIMC(Pacientes pacientes);
float calculaIMC(Pessoa pessoa);
Pacientes lerPacientes(Pacientes pacientes);

int main () {

  printf("Calculadora IMC\n");
	Pacientes pacientes;

	pacientes = lerPacientes(pacientes);

	exibirIMCPacientes(pacientes);

	Pessoa pessoaMaiorIMC = maiorIMC(pacientes);

	printf("MAIOR IMC: %.2f -- PACIENTE %s.", pessoaMaiorIMC.imc, pessoaMaiorIMC.nome);

	return 0;
}
int i;

void exibirIMCPacientes (Pacientes pacientes){
    for(i=0;i<MAX_PESSOAS;i++){
    	printf("IMC DO PACIENTE %i %.2f\n",i+1,pacientes.pessoas[i].imc);
	}

};
Pessoa maiorIMC(Pacientes pacientes){
  Pessoa save;
	float osMaior=0.0;
	for (i=0;i<MAX_PESSOAS;i++){
		if(pacientes.pessoas[i].imc>osMaior){
			osMaior=pacientes.pessoas[i].imc;
      save=pacientes.pessoas[i];
		}

	}

		return save;
	
};
float calculaIMC(Pessoa pessoa){
	float cal;
	cal=pessoa.peso/(pessoa.altura*pessoa.altura);
	return cal;
	
};
Pacientes lerPacientes(Pacientes pacientes){
	
	for(i=0;i<MAX_PESSOAS;i++){
    printf("Pessoa %i",i+1);
    printf("\nNome:");
		scanf("%s",pacientes.pessoas[i].nome);
    printf("\nIdade:");
		scanf("%i",&pacientes.pessoas[i].idade);
    printf("\nPeso:");
		scanf("%i",&pacientes.pessoas[i].peso);
    printf("\nAltura:");
		scanf("%f",&pacientes.pessoas[i].altura);
		pacientes.pessoas[i].imc=calculaIMC(pacientes.pessoas[i]);
	}
 return pacientes;
}
