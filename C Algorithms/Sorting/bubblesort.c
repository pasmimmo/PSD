void BubbleSort(int *array, int elemN)
 {
   int i, tmp, ultimo;
   int alto=elemN; /* elemN è il numero degli elementi del vettore da ordinare */
   ultimo=alto;
   
   while (alto >= 0) /* in questo modo si evita 1 passaggio*/
     { 
         ultimo = -1;
         for (i=0; i<alto-1; i++) /* si mostra che un semplice array come 
                                     int nums[elemN] = {4,3,2,1};
                                     non viene ordinato correttamente a causa della condizione i<alto-1
                                  */
         {
           if (array[i]>array[i+1]) /* sostituire ">" con "<" per avere un ordinamento decrescente */
           { 
             tmp = array[i]; 
             array[i] = array[i+1]; 
             array[i+1] = tmp;
             ultimo = i;
           } 
         }
     alto = ultimo;
     }
 }
