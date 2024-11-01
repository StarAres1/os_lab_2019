#include <stdio.h>
#include <stdlib.h>
#include "find_min_max.h"

#include <limits.h>

struct MinMax GetMinMax(int *array, unsigned int begin, unsigned int end) {
  struct MinMax min_max;
  min_max.min = INT_MAX;
  min_max.max = INT_MIN;

  for(int i = begin - 1; i < end; i++){
    if (array[i] < min_max.min){
      min_max.min = array[i];
    }

    if (array[i] > min_max.max){
      min_max.max = array[i];
    }
  }
  
  return min_max;
}

  int main(int argc, char *argv[]){
    if (argc < 4){
      printf("Недостаточное количество аргументов");      
      return 1;
    }  

    int size = argc - 3; // первый аргумент имя программы, следующие два наши индексы
    int array[size];


    for (int i = 0; i < size; i++) {
      array[i] = atoi(argv[i + 3]); // Преобразование строковых аргументов в целые числа
    }

    unsigned int begin = atoi(argv[1]);
    unsigned int end = atoi(argv[2]);

    if (begin > end || end > size){
      printf("Ошибка при вводе индексов диапазона");
      return 1;
    }

    struct MinMax result = GetMinMax(array, begin, end);
    printf("Минимум: %d\n", result.min);
    printf("Максимум: %d\n", result.max);

    return 0;

  }

