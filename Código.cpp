#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<locale.h>

void cadastrar(int funcionarios[100][7], int *total){
    int i = 0;
    int j = *total;
    int matricula, idade, anos_empresa, filhos, filhos_menores=0, filhos_maiores=0, idadef;
    float bonus;
    
	
//A MATRIZ SE ORGANIZA DA SEGUINTE MANEIRA:  i = matricula || idade funcionario ||tempo de empresa ||  número filhos || filhos menores de idade, || maiores de idade ||  Bonus
//   j = numero de funcion?rios                       [0]             [1]                 [2]               [3]                      [4]                   [5]            [6]

    if (*total >= 2) {
    printf("Limite de funcionários atingido! Pressione Enter para continuar...");
    getchar(); 
    getchar(); 
    return;
    }

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
    
    if (idade <= 21){ 
        bonus = 10 * anos_empresa;
    }else if (idade <= 30){
	
        bonus = 15 * anos_empresa;
    }else{
	
        bonus = 20 * anos_empresa;
    } 
    funcionarios[i++][j] = bonus;
 
	(*total)++; 
   
}
    

	

void listar(int funcionarios[100][7], int *total){
	int j, i;
	
	printf("\n===== LISTA DE FUNCIONÁRIOS =====\n");
	printf("Matrícula | Idade | Tempo de Empresa | Total Filhos | Filhos Menores | Filhos Maiores\n");
	for (j=0; j<*total; j++){  
    printf("%8d | %5d | %15d | %12d | %14d | %13d | %14d,00 \n", funcionarios[0][j],  funcionarios[1][j], funcionarios[2][j],  funcionarios[3][j], funcionarios[4][j],  funcionarios[5][j], funcionarios[6][j] ); 
    }    
    
}

float calcular_custo(int funcionarios[100][7], int*total, float *custo){
	
	int j;
	
	float menores, maiores, custo_funcionario=0, media,valor, custo_total;

    *custo = 0; 

    for(j = 0; j < *total; j++) {
        menores = funcionarios[4][j] * 20;
        maiores = funcionarios[5][j] * 10;
        *custo += menores + maiores + 40;
}
    media = (*custo/ *total);
	return media;	

	
}

int main(){
	
	//var	
	int anos_empresa;
	int filhos, opcao, maiores=0,menores=0;
	int funcionarios[100][7] = {0};
	int total= 0;
	float custo, media;
	//code	
   setlocale(LC_ALL,"portuguese");
   
 do{
   printf("\n===============================================");
   printf("\nGESTOR DE PRESENTES - AO FERRO SERRANO 2025");
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
   	cadastrar(funcionarios, &total);
   	break;
   	case 2:
   	listar(funcionarios, &total);
   	break;
   	case 3:
	media = calcular_custo(funcionarios, &total, &custo);
	printf("\n=====================  CUSTO TOTAL DA FESTA  =========================");  	
	printf("\n | CUSTO TOTAL | CUSTO POR FUNCIONÁRIO |");
	printf("\n |     %.2f    |         %.2f         |", custo, media);
	printf("\n");
   	break;
   	case 4: 
   	return 0;
   	default:
   		printf("Opção invalida....");
   }
   }while(opcao != 4);
}

    
  



