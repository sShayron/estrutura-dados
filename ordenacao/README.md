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
  * Um dos algoritmos mais simples de ordenação.
  * Algoritmo:
    * Selecione o menor item do vetor.
    * Troque-o com o item da primeira posição do vetor.
    * Repita essas duas operações com os n − 1 itens restantes, depois com os n − 2 itens, até que reste apenas um elemento.
    * O método é ilustrado abaixo:
    ![Ordenacao por selecao]()
