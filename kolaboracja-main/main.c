#include <stdio.h>
#include <stdlib.h>
#define SIZE 5

void printArray(int array[]){
    for(int i = 0; i < SIZE; i++){
        printf("tablica[%d] = %d\n\n",i, array[i]);
    }
}

//void printArray(int *array){
//    for(int i = 0; i < SIZE; i++){
//      //  printf("tablica[%d] = %d\n\n",i, array[i]);
//        printf("*(%p) = %d\n\n",(array + i), *(array + i));
//    }
//}

void menu(void){
    printf("Wybierz opcje: \n");
    printf("1. Wprowadz wartosci do tablicy. \n");
    printf("2. Wyswietl tablice. \n");
    printf("3. Wyswietl najmniejsza wartosc z tablicy. \n");
    printf("4. Wyswietl najwieksza wartosc z tablicy. \n");
    printf("5. Wyswietl srednia wartosc liczb z tablicy.\n");
    printf("6. Zapis do pliku.\n");
    printf("7.Wczytaj z pliku\n");
    printf("0. Wyjdz z programu.\n");
}
void numbers(int array[SIZE], int size){
    int i = array[0];
    for (int i = 0; i < SIZE; i++) {
        scanf("%d",&array[i]);
    }
}

//void minimum(int array[],int size){
//int i = array[0];
//int min = array[1];
//for (i = 0; i < SIZE; ++i) {
//if(min > array[i]){
//min = array[i];
//printf("najmniejsza wartoscia w tablicy jest: %d\n\n", min);
//        }
//    }
//}

int minimum(int *array){
    int min = *array;
    for (int i = 0; i < SIZE; ++i) {
        if(min > *(array + i)){
            min = *(array + i);

        }
    }
    return min;
}

//void maksimum(int array[],int size){
//int i = array[0];
//int max = array[1];
//for (i = 0; i < SIZE; ++i) {
//if(max < array[i]){
//max = array[i];
//printf("najwieksza wartoscia w tablicy jest: %d\n\n", max);
//}
//}
//}

int maksimum(int *array){
    int max = *array;
    for (int i = 0; i < SIZE; ++i) {
        if(max < *(array + i)){
            max = *(array + i);

        }
    }
    return max;
}

float average(int *array){
    int sum = 0;

    for(int i=0; i<SIZE; i++){
        sum += *(array + i);
    }

    float average1 = (float) sum / SIZE;
    return average1;
}
FILE *fptr;
int zapis(int *array){

        fptr = fopen("zapisy.txt", "w");
        if (fptr ==0){
            return 1;
        }
        for (int i=0; i < SIZE; i++){
            fprintf(fptr,"\n %d \n", array[i]);
        }
        fclose(fptr);
        return 0;
    }
int load(int *array) {
    FILE *fptr;
    fptr = fopen("zapisy.txt", "r");
    if (fptr == NULL) {
        printf("Brak pliku.\n\n");
        return 1;
    }
    int i = 0;
    while (fscanf(fptr, "%d", &array[i]) == 1) {
        i++;
        if (i >= SIZE)
            break;
    }
    fclose(fptr);
    printf("Wczytano tablice z pliku.\n\n");
    return 0;
}

int main() {
        int array [SIZE] = {1,2,3,4,5};
        int option = 0,erroeCode = 0;

        do{
            menu();
            scanf("%d",&option);

            switch (option) {
                case 0:
                    break;
                case 1:
                    printf("Wprowadzam dane do tablicy\n\n");
                numbers(array, SIZE);
                break;
                case 2:
                    printArray(array);
                break;
                case 3:
                    printf("okreslam najmniejsza wartosc: %d \n\n", minimum(array));

                break;
                case 4:
                    printf("najwieksza wartosc to: %d\n\n", maksimum(array));
                break;
                case 5:
                    printf("okreslam srednia wartosc liczb: %f \n\n", average(array));
                break;
                case 6:
                    printf("zapisywanie...\n");
                erroeCode = zapis(array);
                if(!erroeCode){
                    printf("zapisane\n");
                }
                else printf("nie udalo sie\n");
                break;
                case 7:
                    erroeCode = load(array);
                if (!erroeCode)
                    printf("Dane wczytane poprawnie z pliku.\n");
                break;
                default:
                    printf("wybierz wlasciwa opcje\n\n");
            }

        }
        while (option != 0);

        printf("koniec programu");

        return 0;
    }

