## Metodo de ordenacao Bubble Sort
```
int vetor[TAM],
      x = 0,
      y = 0,
      aux = 0;      
  
  for( x = 0; x < TAM; x++ ) 
  {
    printf("nEntre com um inteiro para vetor[%d]: ",x);
    scanf("%d",&aux);
    vetor[x] = aux;
  }
  
  // coloca em ordem crescente (1,2,3,4,5...)  
  for( x = 0; x < TAM; x++ )
  {
    for( y = x + 1; y < TAM; y++ ) // sempre 1 elemento à frente
    {
      // se o (x > (x+1)) então o x passa pra frente (ordem crescente)
      if ( vetor[x] > vetor[y] )
      {
         aux = vetor[x];
         vetor[x] = vetor[y];
         vetor[y] = aux;
      }
    }
  } // fim da ordenação
  ```
  
## Ordernacao por selecao 
  * Algoritmo:
    * Selecione o menor item do vetor.
    * Troque-o com o item da primeira posição do vetor.
    * Repita essas duas operações com os n − 1 itens restantes, depois com os n − 2 itens, até que reste apenas um elemento.
    * O método é ilustrado abaixo:
    ![Ordenacao por selecao](https://github.com/sShayron/estrutura-dados/blob/master/ordenacao/ordselecao.png)
      
      *Obs: As chaves em negrito sofreram uma troca entre si.*
      * Custo: *n log n*
      
## Ordernacao por insercao
* Algoritmo:
* Em cada passo a partir de i=2 faça:
  * Selecione o i - énesimo item da seqüência fonte.
  * Coloque-o no lugar apropriado na seqüência destino de acordo com o critério de ordenação.
   * O método é ilustrado abaixo:
    ![Ordenacao por selecao](https://github.com/sShayron/estrutura-dados/blob/master/ordenacao/ordinserc.png)

      *Obs: As chaves em negrito representam a seqüência destino.*
      * Custo: *n log n*
