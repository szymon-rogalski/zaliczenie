#include <stdio.h>
#include <stdlib.h>

#define MAX_CARS 20

char marka[MAX_CARS][20];
int rok[MAX_CARS];
char numer_rejestracyjny[MAX_CARS][10];
int przebieg[MAX_CARS];

void menu() {
    printf("Wybierz opcje:\n");
    printf("1. Dodaj samochod\n");
    printf("2. Wyswietl samochody\n");
    printf("3. Zapisz do pliku\n");
    printf("4. Wczytaj z pliku\n");
    printf("0. Zakoncz\n");
}

void addCar(int *count) {
    if (*count >= MAX_CARS) {
        printf("Osiągnieto maksymalną liczbe samochodów!\n");
        return;
    }
    printf("Podaj marke: ");
    scanf("%s", marka[*count]);
    printf("Podaj rok produkcji: ");
    scanf("%d", &rok[*count]);
    printf("Podaj numer rejestracyjny: ");
    scanf("%s", numer_rejestracyjny[*count]);
    printf("Podaj przebieg: ");
    scanf("%d", &przebieg[*count]);

    (*count)++;
}

void displayCars(int count) {
    for (int i = 0; i < count; i++) {
        printf("\nSamochod %d:\n", i + 1);
        printf("Marka: %s\n", marka[i]);
        printf("Rok produkcji: %d\n", rok[i]);
        printf("Numer rejestracyjny: %s\n", numer_rejestracyjny[i]);
        printf("Przebieg: %d km\n", przebieg[i]);
    }
}

void saveToFile(int count) {
    FILE *file = fopen("cars.txt", "w");
    if (!file) {
        printf("Blad zapisu do pliku!\n");
        return;
    }
    for (int i = 0; i < count; i++) {
        fprintf(file, "%s %d %s %d\n", marka[i], rok[i], numer_rejestracyjny[i], przebieg[i]);
    }
    fclose(file);
    printf("Zapisano dane do pliku.\n");
}

void loadFromFile(int *count) {
    FILE *file = fopen("cars.txt", "r");
    if (!file) {
        printf("Blad odczytu pliku!\n");
        return;
    }
    *count = 0;
    while (fscanf(file, "%s %d %s %d", marka[*count], &rok[*count], numer_rejestracyjny[*count], &przebieg[*count]) != EOF) {
        (*count)++;
        if (*count >= MAX_CARS) break;
    }
    fclose(file);
    printf("Wczytano dane z pliku.\n");
}

int main() {
    int count = 0, option;

    do {
        menu();
        scanf("%d", &option);
        switch (option) {
            case 1:
                addCar(&count);
                break;
            case 2:
                displayCars(count);
                break;
            case 3:
                saveToFile(count);
                break;
            case 4:
                loadFromFile(&count);
                break;
            case 0:
                printf("Zamykanie programu...\n");
                break;
            default:
                printf("Wybierz poprawną opcję.\n");
        }
    } while (option != 0);

    return 0;
}