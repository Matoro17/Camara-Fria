#include <stdio.h>
#include <locale.h>

float alturaaSerUsada(float altura);
float placasHorizontais(float comprimento, float largura);

int main (void){
	float altura,comprimento,largura;
	int concreto;
	float perimetroTotal, perimetromediosuoperior, areatotal;
	float areaDePlaca = 1.14;
	setlocale(LC_ALL, "Portuguese");
	printf("\n\tAlgoritmo de Calculo para Camaras frias\nDesenvolvido por: Gabriel Silva de Azevedo\n");
	printf("Insira a Altura\n");
	scanf("%f", &altura);
	printf("Insira o Comprimento\n");
	scanf("%f", &comprimento);
	printf("Insira a Largura\n");
	scanf("%f", &largura);
	printf("Tem concreto no chão?\n1- SIM\t2-NÂO\n");
	scanf("%i", &concreto);
	
	perimetroTotal = (altura*4)+(comprimento*4)+(largura*4);
	perimetromediosuoperior = (altura*4)+(comprimento*2)+(largura*2);
	areatotal = ((altura*comprimento)+(comprimento*largura)+(altura*largura))*2;
	float arealateral = ((altura*largura)+(altura*comprimento))*2;
	float perimetroinferior = (comprimento*2)+(largura*2);
	printf("Materiais Necessarios para o serviço\n\n");
	if(concreto == 1){
		printf("Cantoneiras normais necessárias ---------------- %.2f\n", perimetromediosuoperior/3);
		printf("Cantoneiras PU --------------------------------- %.2f\n", ((largura*2)+(comprimento*2))/3);
		printf("Manta Asfaltica Necessaria --------------------- MA\n");
		printf("Arrebites -------------------------------------- %.2f\n", perimetroTotal/3*50);
		printf("Tubos de Cola Necessarios ---------------------- %.2f\n", perimetroTotal/3);
		printf("Laterais:\n");		
		printf("Placas de %.2f metros de Altura(recomendado) --- %.2f\n", alturaaSerUsada(altura),(perimetroinferior/1.14) *(altura/alturaaSerUsada(altura)));
		
		printf("Teto:\n");
		printf("Placas de %.2f metros de Altura(recoemndado) --- %.2f\n", placasHorizontais(comprimento,largura),(largura*comprimento)/(placasHorizontais(comprimento,largura)*1.14));
		scanf("%i", &concreto);
		
		
		
	}
	else{
		printf("Cantoneiras normais necessárias -------------- %.2f\n", perimetroTotal/3);
		printf("Arrebites ------------------------------------ %.2f\n", perimetroTotal/3*50);
		printf("Tubos de Cola Necessarios -------------------- %.2f\n", perimetroTotal/3);
		printf("Laterais:\n");
		printf("Placas de %.2f metros de Altura(recomendado) - %.2f Placas\n", alturaaSerUsada(altura),perimetroinferior/1.14);
		printf("Teto:\n");
		printf("Placas de %.2f metros de Altura(recoemndado) - %.2f\n", placasHorizontais(comprimento,largura),(largura*comprimento)/(placasHorizontais(comprimento,largura)*1.14));
		printf("Piso:\n");
		printf("Placas de %.2f metros de Altura(recoemndado) - %.2f\n", placasHorizontais(comprimento,largura),(largura*comprimento)/(placasHorizontais(comprimento,largura)*1.14));
		scanf("%i", &concreto);
	}
	
	
	
	
	
}

float placasHorizontais(float comprimento, float largura){
	if(comprimento>=largura){
		return alturaaSerUsada(comprimento);
	}
	else{
		return alturaaSerUsada(largura);
	}
	
}

float alturaaSerUsada(float altura){
	float resto3, resto25, resto28;
	float valor3 = 3, valor25 = 2.5, valor28 = 2.8;
	if(altura > valor3){
		resto3 = altura/valor3;
		resto25 = altura/valor25;
		resto28 = altura/valor28;
	}
	else{	
		resto3 = valor3/altura;
		resto25 = valor25/altura;
		resto28 = valor28/altura;
	}
	if(resto3 == 1){
		return 3;
	}
	else if(resto25 == 1){
		return 2.5;
	}
	else if(resto28==1){
		return 2.8;
	}
	float maior = resto3;
    float menor = resto3;
     if (resto25 < menor){
     	menor = resto25;
	 }        
     if (resto25 > maior){
     	maior = resto25;
	 }        
     if (resto28 < menor){
     	menor = resto28;
	 }
     if (resto28 > maior){
     	maior = resto28;
	 }
	 
	 if(menor == resto3){
	 	return 3;
	 }
	 if(menor == resto25){
	 	return 2.5;
	 }
	 if(menor == resto28){
	 	return 2.8;
	 }
        
	
	
}
