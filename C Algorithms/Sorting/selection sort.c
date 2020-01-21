void SelectionSort(double a[], unsigned long N) {
  int i, j, min; 
  double t;

  for (i=0; i < N-1; i++) {
    min = i;
    for (j= i+1; j < N; j++) {
      if (a[j] < a[min]) {
      min = j;
      }
    }
      t = a[min];
      a[min] = a[i];
      a[i] = t;
  }
}
