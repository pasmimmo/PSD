 void sort(int array[], int begin, int end) {
    int pivot, l, r; 
    if (end > begin) {
       pivot = array[begin];
       l = begin + 1;
       r = end+1;
       while(l < r)
          if (array[l] < pivot) 
             l++;
          else {
             r--;
             swap(array[l], array[r]); 
          }
       l--;
       swap(array[begin], array[l]);
       sort(array, begin, l);
       sort(array, r, end);
    }
 }
