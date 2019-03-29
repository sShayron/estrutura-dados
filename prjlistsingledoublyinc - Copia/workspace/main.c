#include <stdio.h>
#include <stdlib.h>
#include <ctype.h> // isspace

#include "listSL.c"
#include "listDL.c"

// returns 1 if success and 0 otherwise
int readCitiesAndRoadsFromFile(FILE *fCities,  FILE *fRoads,  ListaSE lstRodovias){
    #define MAXCHAR 1000
    #define MAX 100
    char buffer[MAXCHAR]; // buffer for a line of cities separated by spaces
    char cidade[MAX]; // save the name of a city
    char Str[MAX];
    
    //open files 
    fCities = fopen("/home/ubuntu/workspace/cities", "r");
    fRoads = fopen("/home/ubuntu/workspace/roads", "r");
    
    if (fCities == NULL) {
        printf("\n It was not possible to open file /home/ubuntu/workspace/cities \n");
        return 0;

    } 
    
     if (fRoads == NULL){
        
        printf("\n It was not possible to open file /home/ubuntu/workspace/roads \n");
        return 0;
    } 
    
    
    while(!feof(fRoads)){
        
        memset(buffer, '\0', 1000); // setting '\0' for whole buffer
        
        InfoRodovia elem; // save InfoRodovia for a new element
        
        elem.cidades = inicListaDE(); // intialize Doubly Linked List of cities of the currente element
        
        // copy road name
        fscanf(fRoads, "%s", elem.rodovia);
        printf("\n -----------------------------(%s)--------------------------------- \n", elem.rodovia);
        
        fgets(buffer, MAXCHAR, fCities); // reads a line of cities to the buffer
        printf("\n %s \n ", buffer);
        
        int i=0, j=0;
		memset(cidade, '\0', 100);
		
		while (1){
		    
			while( !isspace(buffer[i]) && buffer[i] != '\0'){
				cidade[j] = buffer[i];
				j++; // next free position for a letter (char)
				i++;
			}
			//printf("\n cidade:  %s \n", cidade);
			
			//add city to the list of cities
            anxListaDE(elem.cidades, cidade);
			
			if(buffer[i] == '\0')
				break; //acabou de ler todas as cidades de uma rodovia
				
			i++; //pula o espaco
			j=0; //reset j so it begins from 0
			memset(cidade, '\0', 100); //reset cidade
			
		}
		
		//printListaDE(elem.cidades);
		
		anxListaSE(lstRodovias, elem);
       
    }
    fclose(fCities);
    fclose(fRoads);
  
    return 1; //all read successfully
    
}


ListaDE rodoviasCidade(ListaSE lstRodovias, char * cidade){
    
    ListaDE rodCortamCidade = inicListaDE();
    
    // finalizar
    return rodCortamCidade;
}


int main()
{
    printf("Initializing ...!\n");
    FILE *fCities;
    FILE *fRoads;
    
    ListaSE lstRodovias = inicListaSE();
    
    if(readCitiesAndRoadsFromFile(fCities, fRoads, lstRodovias)){
        printf("\n Stuctures loaded \n");
    }else{
        printf("\n some problem ocurred while loading files \n");
        exit(1); // shutdown
    }
    
    printListaSE(lstRodovias);
    
    
    ListaDE rodCortamCidade = rodoviasCidade(lstRodovias, "RioDeJaneiro");
    
    printf("\n###############################################################\n ");
    
    printListaDE(rodCortamCidade);
    

    return 0;
}
