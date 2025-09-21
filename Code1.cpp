#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<locale.h>

void cadastrar(int funcionarios[100][6], int *total){
    int i = 0;
    int j = *total;
    int matricula, idade, anos_empresa, filhos, filhos_menores=0, filhos_maiores=0, idadef;
	
//A MATRIZ SE ORGANIZA DA SEGUINTE MANEIRA:  i = matricula || idade funcionario ||tempo de empresa ||  número filhos || filhos menores de idade, || maiores de idade
//   j = numero de funcionários                       [0]             [1]                 [2]               [3]                      [4]                   [5] 

    printf("Digite a matrícula do funcionário: ");
    scanf("%d", &matricula);
    funcionarios[i++][j] = matricula;

    printf("Digite quantos anos tem o funcionário: ");
    scanf("%d", &idade);
    funcionarios[i++][j] = idade;

    printf("Digite quantos anos de empresa tem o funcionário: ");
    scanf("%d", &anos_empresa);
    funcionarios[i++][j] = anos_empresa;

    printf("Digite quantos filhos ele(a) tem: ");
    scanf("%d", &filhos);
    funcionarios[i++][j] = filhos;

    for(int f = 0; f < filhos; f++){
        printf("Digite a idade do filho %d: ", f+1);
        scanf("%d", &idadef);
        if(idadef > 18)
            filhos_maiores++;
        else
            filhos_menores++;
    }

    funcionarios[i++][j] = filhos_menores;
    funcionarios[i++][j] = filhos_maiores;

    (*total)++;  
}


void listar(int funcionarios[100][6], int *total){
	int j, i;
	
	printf("\n===== LISTA DE FUNCIONÁRIOS =====\n");
	printf("Matricula | Idade | Tempo de Empresa | Total Filhos | Filhos Menores | Filhos Maiores\n");
	for (j=0; j<*total; j++){ 
   
    printf("%8d | %5d | %15d | %12d | %14d | %13d \n", funcionarios[0][j],  funcionarios[1][j], funcionarios[2][j],  funcionarios[3][j], funcionarios[4][j],  funcionarios[5][j] );
    
    }    
    
}


int main(){
	
	//var
	
	int filhos, opcao, maiores=0,menores=0;
	int funcionarios[100][6] = {0};
	int total= 0;
	//code
	
   setlocale(LC_ALL,"portuguese");
   
 do{
   printf("\n===============================================");
   printf("\nGESTOR DE PRESENTES - AÇO FERRO SERRANO 2025");
   printf("\n===============================================");
   printf("\n 1 - Cadastrar funcionário");
   printf("\n 2 - Listar funcionários");
   printf("\n 3 - Calcular custo total da empresa");
   printf("\n 4 - Sair");
   printf("\n");
   printf("\n Escolha uma opção: ");
   scanf("%d", &opcao);
     
   switch(opcao){
   	case 1:	

   	cadastrar(funcionarios, &total);  //  <--- teste de lógica do armazenamento do módulo cadastrar() "Dione"
   
   	break;
   	case 2:
   	listar(funcionarios, &total);
   	break;
   	case 3:
	   
   	break;
   	case 4: 
   	return 0;
   	break;
   	default:
   		printf("Opção invalida....");
   }
   }while(opcao != 4);
}

   


