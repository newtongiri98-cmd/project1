#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

#define MAX_station_name 150
#define MAX_bus_name 150
#define Discount_rate 0.35

struct route {
    char source[MAX_station_name];
    char destination[MAX_station_name];
    char busname[MAX_bus_name];
    int fare;
};

struct route routes[] = {
    {"kirtipur", "tu gate", "route kirtipur yatayat", 25},
    {"kirtipur", "balkhu", "route kirtipur yatayat", 25},
    {"kirtipur", "college gate", "route kirtipur yatayat", 35},
    {"kirtipur", "kalimati", "route kirtipur yatayat", 35},
    {"kirtipur", "teku", "route kirtipur yatayat", 40},
    {"kirtipur", "tripureshwor", "route kirtipur yatayat", 40},
    {"kirtipur", "sundhara", "route kirtipur yatayat", 40},

    {"tu gate", "balkhu", "kirtipur yatayat", 25},
    {"balkhu", "kalimati", "kirtipur yatayat", 25},
    {"balkhu", "sundhara", "kirtipur yatayat", 35},
    {"kalimati", "sundhara", "kirtipur yatayat", 35},

    {"rara hill", "tyangla chowk", "rara hill yatayat", 25},
    {"rara hill", "sita petrol pump", "rara hill yatayat", 25},
    {"rara hill", "balkhu", "rara hill yatayat", 35},
    {"rara hill", "sundhara", "rara hill yatayat", 40},

    {"tyangla chowk", "balkhu", "rara hill yatayat", 25},
    {"sita petrol pump", "balkhu", "rara hill yatayat", 25},
    {"sita petrol pump", "sundhara", "rara hill yatayat", 35},
    {"sundhara", "balkhu", "rara hill yatayat", 35},
    {"sundhara", "rara hill", "rara hill yatayat", 40},
    {"sundhara", "tyangla chowk", "rara hill yatayat", 35},
    {"balkhu", "rara hill", "rara hill yatayat", 35},
    {"balkhu", "tyangla chowk", "rara hill yatayat", 35},

    {"kalanki", "balkhu", "metropolitan yatayat", 25},
    {"balkhu", "satdobato", "metropolitan yatayat", 25},
    {"satdobato", "gwarko", "metropolitan yatayat", 25},
    {"gwarko", "imadol", "metropolitan yatayat", 25},
    {"imadol", "koteshwor", "metropolitan yatayat", 35},
    {"kalanki", "satdobato", "metropolitan yatayat", 35},
    {"kalanki", "gwarko", "metropolitan yatayat", 35},
    {"kalanki", "imadol", "metropolitan yatayat", 40},
    {"kalanki", "koteshwor", "metropolitan yatayat", 40},
    {"balkhu", "koteshwor", "metropolitan yatayat", 35},
    {"satdobato", "koteshwor", "metropolitan yatayat", 35},
    {"gwarko", "koteshwor", "metropolitan yatayat", 25},

    {"kalanki", "balkhu", "sajha yatayat", 25},
    {"balkhu", "satdobato", "sajha yatayat", 25},
    {"satdobato", "gwarko", "sajha yatayat", 25},
    {"gwarko", "imadol", "sajha yatayat", 25},
    {"imadol", "koteshwor", "sajha yatayat", 35},
    {"kalanki", "satdobato", "sajha yatayat", 35},
    {"kalanki", "gwarko", "sajha yatayat", 35},
    {"kalanki", "imadol", "sajha yatayat", 40},
    {"kalanki", "koteshwor", "sajha yatayat", 40},
    {"balkhu", "koteshwor", "sajha yatayat", 35},
    {"satdobato", "koteshwor", "sajha yatayat", 35},
    {"gwarko", "koteshwor", "sajha yatayat", 25},

    {"kalanki", "balkhu", "chakrapath yatayat", 25},
    {"balkhu", "satdobato", "chakrapath yatayat", 25},
    {"satdobato", "gwarko", "chakrapath yatayat", 25},
    {"gwarko", "imadol", "chakrapath yatayat", 25},
    {"imadol", "koteshwor", "chakrapath yatayat", 35},
    {"kalanki", "satdobato", "chakrapath yatayat", 35},
    {"kalanki", "gwarko", "chakrapath yatayat", 35},
    {"kalanki", "imadol", "chakrapath yatayat", 40},
    {"kalanki", "koteshwor", "chakrapath yatayat", 40},
    {"balkhu", "koteshwor", "chakrapath yatayat", 35},
    {"satdobato", "koteshwor", "chakrapath yatayat", 35},
    {"gwarko", "koteshwor", "chakrapath yatayat", 25},

    {"koteshwor", "jadibuti", "bhaktapur yatayat", 25},
    {"jadibuti", "lokanthali", "bhaktapur yatayat", 25},
    {"lokanthali", "sallaghari", "bhaktapur yatayat", 25},
    {"sallaghari", "suryabinayak", "bhaktapur yatayat", 25},
    {"suryabinayak", "jagati", "bhaktapur yatayat", 25},
    {"jagati", "bhaktapur", "bhaktapur yatayat", 35},
    {"koteshwor", "lokanthali", "bhaktapur yatayat", 35},
    {"koteshwor", "sallaghari", "bhaktapur yatayat", 35},
    {"koteshwor", "suryabinayak", "bhaktapur yatayat", 35},
    {"koteshwor", "jagati", "bhaktapur yatayat", 35},
    {"koteshwor", "bhaktapur", "bhaktapur yatayat", 40},
    {"jadibuti", "sallaghari", "bhaktapur yatayat", 25},
    {"jadibuti", "suryabinayak", "bhaktapur yatayat", 35},
    {"jadibuti", "bhaktapur", "bhaktapur yatayat", 40},
    {"lokanthali", "suryabinayak", "bhaktapur yatayat", 25},
    {"lokanthali", "bhaktapur", "bhaktapur yatayat", 35},
    {"sallaghari", "bhaktapur", "bhaktapur yatayat", 35},
    {"suryabinayak", "bhaktapur", "bhaktapur yatayat", 25}
};

int totalroutes = sizeof(routes) / sizeof(routes[0]);

int equalsignorecase(const char *a, const char *b) {
    if (a == NULL || b == NULL) return 0;
    while (*a && *b) {
        if (tolower((unsigned char)*a) != tolower((unsigned char)*b)) return 0;
        a++;
        b++;
    }
    return (*a == '\0' && *b == '\0');
}

void getstringinput(char *buffer, int size) {
    if (fgets(buffer, size, stdin) != NULL) {
        int len = strlen(buffer);
        if (len > 0 && buffer[len-1] == '\n') { buffer[len-1] = '\0'; len--; }
        while (len > 0 && buffer[len-1] == ' ') { buffer[len-1] = '\0'; len--; }
    } else {
        buffer[0] = '\0';
    }
}

void showfare(int fare) {
    char ans[5];
    printf("Student? (y/n): ");
    getstringinput(ans, sizeof(ans));

    if (tolower(ans[0]) == 'y') {
        printf("Fare: Rs. %d\n", (int)(fare - fare * 0.35));
    } else {
        printf("Fare: Rs. %d\n", fare);
    }
}

int findroute(const char *source, const char *dest) {
    for (int i = 0; i < totalroutes; i++) {
        if (equalsignorecase(routes[i].source, source) &&
            equalsignorecase(routes[i].destination, dest)) {

            printf("Bus: %s\n", routes[i].busname);
            printf("Fare: %d\n", routes[i].fare);

            showfare(routes[i].fare);
            return 1;
        }
    }
    return 0;
}

int findtransfer(const char *source, const char *dest) {
    int i, j;
    int total;

    for (i = 0; i < totalroutes; i++) {
        if (!equalsignorecase(routes[i].source, source)) continue;

        for (j = 0; j < totalroutes; j++) {
            if (equalsignorecase(routes[j].source, routes[i].destination) &&
                equalsignorecase(routes[j].destination, dest)) {

                total = routes[i].fare + routes[j].fare;

                printf("No direct bus found. You need to change bus.\n");
                //
                printf("Step 1 : %s --> %s\n", routes[i].source, routes[i].destination);
                printf("Bus    : %s\n", routes[i].busname);
                printf("Fare   : Rs. %d\n", routes[i].fare);
                //
                printf("Step 2 : %s --> %s\n", routes[j].source, routes[j].destination);
                printf("Bus    : %s\n", routes[j].busname);
                printf("Fare   : Rs. %d\n", routes[j].fare);
                //
                printf("Total  : Rs. %d\n", total);
                showfare(total);
                return 1;
            }
        }
    }
    return 0;
}

int main() {
    char source[MAX_station_name];
    char destination[MAX_station_name];
    int found; 

    printf("Smart Bus Route & Fare Finder\n");

    printf("Enter source: ");
    getstringinput(source, MAX_station_name);

    if (strlen(source) == 0) {
        printf("Source cannot be empty.\n");
        return 1;
    }

    printf("Enter destination: ");
    getstringinput(destination, MAX_station_name);

    if (strlen(destination) == 0) {
        printf("Destination cannot be empty.\n");
        return 1;
    }

    found = findroute(source, destination);

    if (!found) {
        found = findtransfer(source, destination);
    }

    if (!found) {
        printf("No route found from %s to %s.\n", source, destination);
    }

    printf("Thank you!\n");
    return 0;
    
}