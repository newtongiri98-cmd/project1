#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

#define MAX_STATION_NAME  150
#define MAX_BUS_NAME      150
#define MAX_MATCHED_BUSES 20
#define DISCOUNT_OLD_AGE  0.30
#define DISCOUNT_STUDENT  0.45
#define RESET   "\033[0m"
#define BOLD    "\033[1m"
#define RED     "\033[31m"
#define GREEN   "\033[32m"
#define YELLOW  "\033[33m"
#define CYAN    "\033[36m"
#define WHITE   "\033[37m"
void askMapNavigation(const char *source, const char *dest, const char *mid);

struct route {
    char source[MAX_STATION_NAME];
    char destination[MAX_STATION_NAME];
    char busname[MAX_BUS_NAME];
    int fare;
};

struct route routes[] = {
       
{"kirtipur", "tu gate", "route kirtipur yatayat", 25},
{"tu gate", "kirtipur", "route kirtipur yatayat", 25},
{"kirtipur", "balkhu", "route kirtipur yatayat", 25},
{"balkhu", "kirtipur", "route kirtipur yatayat", 25},
{"kirtipur", "college gate", "route kirtipur yatayat", 35},
{"college gate", "kirtipur", "route kirtipur yatayat", 35},
{"kirtipur", "kalimati", "route kirtipur yatayat", 35},
{"kalimati", "kirtipur", "route kirtipur yatayat", 35},
{"kirtipur", "teku", "route kirtipur yatayat", 40},
{"teku", "kirtipur", "route kirtipur yatayat", 40},
{"kirtipur", "tripureshwor", "route kirtipur yatayat", 40},
{"tripureshwor", "kirtipur", "route kirtipur yatayat", 40},
{"kirtipur", "sundhara", "route kirtipur yatayat", 40},
{"sundhara", "kirtipur", "route kirtipur yatayat", 40},


{"tu gate", "balkhu", "kirtipur yatayat", 25},
{"balkhu", "tu gate", "kirtipur yatayat", 25},
{"balkhu", "kalimati", "kirtipur yatayat", 25},
{"kalimati", "balkhu", "kirtipur yatayat", 25},
{"balkhu", "sundhara", "kirtipur yatayat", 35},
{"sundhara", "balkhu", "kirtipur yatayat", 35},
{"kalimati", "sundhara", "kirtipur yatayat", 35},
{"sundhara", "kalimati", "kirtipur yatayat", 35},

// --- rara hill yatayat ---
{"rara hill", "tyangla chowk", "rara hill yatayat", 25},
{"tyangla chowk", "rara hill", "rara hill yatayat", 25},
{"rara hill", "sita petrol pump", "rara hill yatayat", 25},
{"sita petrol pump", "rara hill", "rara hill yatayat", 25},
{"rara hill", "balkhu", "rara hill yatayat", 35},
{"balkhu", "rara hill", "rara hill yatayat", 35},
{"rara hill", "sundhara", "rara hill yatayat", 40},
{"sundhara", "rara hill", "rara hill yatayat", 40},
{"tyangla chowk", "balkhu", "rara hill yatayat", 25},
{"balkhu", "tyangla chowk", "rara hill yatayat", 25},
{"sita petrol pump", "balkhu", "rara hill yatayat", 25},
{"balkhu", "sita petrol pump", "rara hill yatayat", 25},
{"sita petrol pump", "sundhara", "rara hill yatayat", 35},
{"sundhara", "sita petrol pump", "rara hill yatayat", 35},
{"sundhara", "balkhu", "rara hill yatayat", 35},
{"balkhu", "sundhara", "rara hill yatayat", 35},
{"sundhara", "tyangla chowk", "rara hill yatayat", 35},
{"tyangla chowk", "sundhara", "rara hill yatayat", 35},

// --- metropolitan yatayat ---
{"kalanki", "balkhu", "metropolitan yatayat", 25},
{"balkhu", "kalanki", "metropolitan yatayat", 25},
{"balkhu", "satdobato", "metropolitan yatayat", 25},
{"satdobato", "balkhu", "metropolitan yatayat", 25},
{"satdobato", "gwarko", "metropolitan yatayat", 25},
{"gwarko", "satdobato", "metropolitan yatayat", 25},
{"gwarko", "imadol", "metropolitan yatayat", 25},
{"imadol", "gwarko", "metropolitan yatayat", 25},
{"imadol", "koteshwor", "metropolitan yatayat", 35},
{"koteshwor", "imadol", "metropolitan yatayat", 35},
{"kalanki", "satdobato", "metropolitan yatayat", 35},
{"satdobato", "kalanki", "metropolitan yatayat", 35},
{"kalanki", "gwarko", "metropolitan yatayat", 35},
{"gwarko", "kalanki", "metropolitan yatayat", 35},
{"kalanki", "imadol", "metropolitan yatayat", 40},
{"imadol", "kalanki", "metropolitan yatayat", 40},
{"kalanki", "koteshwor", "metropolitan yatayat", 40},
{"koteshwor", "kalanki", "metropolitan yatayat", 40},
{"balkhu", "koteshwor", "metropolitan yatayat", 35},
{"koteshwor", "balkhu", "metropolitan yatayat", 35},
{"satdobato", "koteshwor", "metropolitan yatayat", 35},
{"koteshwor", "satdobato", "metropolitan yatayat", 35},
{"gwarko", "koteshwor", "metropolitan yatayat", 25},
{"koteshwor", "gwarko", "metropolitan yatayat", 25},

// --- sajha yatayat ---
{"kalanki", "balkhu", "sajha yatayat", 25},
{"balkhu", "kalanki", "sajha yatayat", 25},
{"balkhu", "satdobato", "sajha yatayat", 25},
{"satdobato", "balkhu", "sajha yatayat", 25},
{"satdobato", "gwarko", "sajha yatayat", 25},
{"gwarko", "satdobato", "sajha yatayat", 25},
{"gwarko", "imadol", "sajha yatayat", 25},
{"imadol", "gwarko", "sajha yatayat", 25},
{"imadol", "koteshwor", "sajha yatayat", 35},
{"koteshwor", "imadol", "sajha yatayat", 35},
{"kalanki", "satdobato", "sajha yatayat", 35},
{"satdobato", "kalanki", "sajha yatayat", 35},
{"kalanki", "gwarko", "sajha yatayat", 35},
{"gwarko", "kalanki", "sajha yatayat", 35},
{"kalanki", "imadol", "sajha yatayat", 40},
{"imadol", "kalanki", "sajha yatayat", 40},
{"kalanki", "koteshwor", "sajha yatayat", 40},
{"koteshwor", "kalanki", "sajha yatayat", 40},
{"balkhu", "koteshwor", "sajha yatayat", 35},
{"koteshwor", "balkhu", "sajha yatayat", 35},
{"satdobato", "koteshwor", "sajha yatayat", 35},
{"koteshwor", "satdobato", "sajha yatayat", 35},
{"gwarko", "koteshwor", "sajha yatayat", 25},
{"koteshwor", "gwarko", "sajha yatayat", 25},

// --- chakrapath yatayat ---
{"kalanki", "balkhu", "chakrapath yatayat", 25},
{"balkhu", "kalanki", "chakrapath yatayat", 25},
{"balkhu", "satdobato", "chakrapath yatayat", 25},
{"satdobato", "balkhu", "chakrapath yatayat", 25},
{"satdobato", "gwarko", "chakrapath yatayat", 25},
{"gwarko", "satdobato", "chakrapath yatayat", 25},
{"gwarko", "imadol", "chakrapath yatayat", 25},
{"imadol", "gwarko", "chakrapath yatayat", 25},
{"imadol", "koteshwor", "chakrapath yatayat", 35},
{"koteshwor", "imadol", "chakrapath yatayat", 35},
{"kalanki", "satdobato", "chakrapath yatayat", 35},
{"satdobato", "kalanki", "chakrapath yatayat", 35},
{"kalanki", "gwarko", "chakrapath yatayat", 35},
{"gwarko", "kalanki", "chakrapath yatayat", 35},
{"kalanki", "imadol", "chakrapath yatayat", 40},
{"imadol", "kalanki", "chakrapath yatayat", 40},
{"kalanki", "koteshwor", "chakrapath yatayat", 40},
{"koteshwor", "kalanki", "chakrapath yatayat", 40},
{"balkhu", "koteshwor", "chakrapath yatayat", 35},
{"koteshwor", "balkhu", "chakrapath yatayat", 35},
{"satdobato", "koteshwor", "chakrapath yatayat", 35},
{"koteshwor", "satdobato", "chakrapath yatayat", 35},
{"gwarko", "koteshwor", "chakrapath yatayat", 25},
{"koteshwor", "gwarko", "chakrapath yatayat", 25},

// --- bhaktapur yatayat ---
{"koteshwor", "jadibuti", "bhaktapur yatayat", 25},
{"jadibuti", "koteshwor", "bhaktapur yatayat", 25},
{"jadibuti", "lokanthali", "bhaktapur yatayat", 25},
{"lokanthali", "jadibuti", "bhaktapur yatayat", 25},
{"lokanthali", "sallaghari", "bhaktapur yatayat", 25},
{"sallaghari", "lokanthali", "bhaktapur yatayat", 25},
{"sallaghari", "suryabinayak", "bhaktapur yatayat", 25},
{"suryabinayak", "sallaghari", "bhaktapur yatayat", 25},
{"suryabinayak", "jagati", "bhaktapur yatayat", 25},
{"jagati", "suryabinayak", "bhaktapur yatayat", 25},
{"jagati", "bhaktapur", "bhaktapur yatayat", 35},
{"bhaktapur", "jagati", "bhaktapur yatayat", 35},
{"koteshwor", "lokanthali", "bhaktapur yatayat", 35},
{"lokanthali", "koteshwor", "bhaktapur yatayat", 35},
{"koteshwor", "sallaghari", "bhaktapur yatayat", 35},
{"sallaghari", "koteshwor", "bhaktapur yatayat", 35},
{"koteshwor", "suryabinayak", "bhaktapur yatayat", 35},
{"suryabinayak", "koteshwor", "bhaktapur yatayat", 35},
{"koteshwor", "jagati", "bhaktapur yatayat", 35},
{"jagati", "koteshwor", "bhaktapur yatayat", 35},
{"koteshwor", "bhaktapur", "bhaktapur yatayat", 40},
{"bhaktapur", "koteshwor", "bhaktapur yatayat", 40},
{"jadibuti", "sallaghari", "bhaktapur yatayat", 25},
{"sallaghari", "jadibuti", "bhaktapur yatayat", 25},
{"jadibuti", "suryabinayak", "bhaktapur yatayat", 35},
{"suryabinayak", "jadibuti", "bhaktapur yatayat", 35},
{"jadibuti", "bhaktapur", "bhaktapur yatayat", 40},
{"bhaktapur", "jadibuti", "bhaktapur yatayat", 40},
{"lokanthali", "suryabinayak", "bhaktapur yatayat", 25},
{"suryabinayak", "lokanthali", "bhaktapur yatayat", 25},
{"lokanthali", "bhaktapur", "bhaktapur yatayat", 35},
{"bhaktapur", "lokanthali", "bhaktapur yatayat", 35},
{"sallaghari", "bhaktapur", "bhaktapur yatayat", 35},
{"bhaktapur", "sallaghari", "bhaktapur yatayat", 35},
{"suryabinayak", "bhaktapur", "bhaktapur yatayat", 25},
{"bhaktapur", "suryabinayak", "bhaktapur yatayat", 25},
};
static const int totalRoutes = sizeof(routes) / sizeof(routes[0]);


int equalsIgnoreCase(const char *a, const char *b) {
    if (a == NULL || b == NULL) return 0;
    while (*a && *b) {
        if (tolower((unsigned char)*a) != tolower((unsigned char)*b)) return 0;
        a++;
        b++;
    }
    return (*a == '\0' && *b == '\0');
}

void getStringInput(char *buffer, int size)  {
    if (fgets(buffer, size, stdin) != NULL) {
        int len = strlen(buffer);
        if (len > 0 && buffer[len-1] == '\n') { buffer[len-1] = '\0'; len--; }
        while (len > 0 && buffer[len-1] == ' ') { buffer[len-1] = '\0'; len--; }
    } else {
        buffer[0] = '\0';
    }
}

int isDuplicateBus(char list[][MAX_BUS_NAME], int count, const char *name) {
    for (int i = 0; i < count; i++) {
        if (equalsIgnoreCase(list[i], name)) return 1;
    }
    return 0;
}


int collectMatchingBuses(const char *source, const char *dest,
                         char matchedBuses[][MAX_BUS_NAME],
                         int matchedFares[]) {
    int count = 0;
    for (int i = 0; i < totalRoutes && count < MAX_MATCHED_BUSES; i++) {
        int forward  = equalsIgnoreCase(routes[i].source, source) &&
                       equalsIgnoreCase(routes[i].destination, dest);
        int backward = equalsIgnoreCase(routes[i].source, dest) &&
                       equalsIgnoreCase(routes[i].destination, source);

        if (forward || backward) {
            if (!isDuplicateBus(matchedBuses, count, routes[i].busname)) {
                strncpy(matchedBuses[count], routes[i].busname, MAX_BUS_NAME - 1);
                matchedBuses[count][MAX_BUS_NAME - 1] = '\0';
                matchedFares[count] = routes[i].fare;
                count++;
            }
        }
    }
    return count;
}


int getUserCategory() {
    char input[20];
    int choice;

    printf("\nSelect your category:\n");
    printf(" \n");
    printf("[1] Old Age  (30%% discount)\n");
    printf("[2] Student  (45%% discount)\n");
    printf("[3] Normal   (no discount)\n");
    printf(" \n");
    printf("Enter choice (1-3): ");
    getStringInput(input, sizeof(input));
    choice = atoi(input);

    switch (choice) {
        case 1: return 1;
        case 2: return 2;
        case 3: return 3;
        default:
            printf("Invalid choice. Setting as Normal user.\n");
            return 3;
    }
}

void showFareSummary(const char *source, const char *dest,
                     const char *busname, int baseFare, int category) {
    int discountAmt = 0;
    int finalFare   = baseFare;
    const char *categoryName;

    switch (category) {
        case 1:
            categoryName = "Old Age";
            discountAmt  = (int)(baseFare * DISCOUNT_OLD_AGE);
            finalFare    = baseFare - discountAmt;
            break;
        case 2:
            categoryName = "Student";
            discountAmt  = (int)(baseFare * DISCOUNT_STUDENT);
            finalFare    = baseFare - discountAmt;
            break;
        default:
            categoryName = "Normal";
            discountAmt  = 0;
            finalFare    = baseFare;
            break;
    }
printf("\n \n");
    printf("       FARE SUMMARY\n");
    printf(" \n");
    printf("Source      : %s\n", source);
    printf("Destination : %s\n", dest);
    printf("Yatayat     : %s\n", busname);
    printf(" \n");
    printf("Base Fare   : Rs. %d\n", baseFare);
    printf("Category    : %s\n", categoryName);
    printf("Discount    : Rs. %d\n", discountAmt);
    printf(" \n");
    printf("Final Fare  : Rs. %d\n", finalFare);
    printf(" \n");      
}  int findTransferRoute(const char *source, const char *dest) {
    for (int i = 0; i < totalRoutes; i++) {
        if (!equalsIgnoreCase(routes[i].source, source)) continue;

        const char *mid = routes[i].destination;

        for (int j = 0; j < totalRoutes; j++) {
            int fwd = equalsIgnoreCase(routes[j].source, mid) &&
                      equalsIgnoreCase(routes[j].destination, dest);
            int bwd = equalsIgnoreCase(routes[j].source, dest) &&
                      equalsIgnoreCase(routes[j].destination, mid);

            if (fwd || bwd) {
                int totalFare = routes[i].fare + routes[j].fare;

                printf("\nNo direct bus. You need to change buses!\n");
                printf(" \n");
                printf("STEP 1:\n");
                printf("  From : %s\n", routes[i].source);
                printf("  To   : %s\n", routes[i].destination);
                printf("  Bus  : %s\n", routes[i].busname);
                printf("  Fare : Rs. %d\n", routes[i].fare);
                printf(" \n");
                printf("STEP 2:\n");
                printf("  From : %s\n", mid);
                printf("  To   : %s\n", dest);
                printf("  Bus  : %s\n", routes[j].busname);
                printf("  Fare : Rs. %d\n", routes[j].fare);
                printf(" \n");
                printf("Total Base Fare : Rs. %d\n", totalFare);

                int category = getUserCategory();
                showFareSummary(source, dest, "(Transfer)", totalFare, category);
                askMapNavigation(source, dest, mid);

                return 1;
            }
        }
    }
    return 0;
}
\
int main() {
    char source[MAX_STATION_NAME];
    char destination[MAX_STATION_NAME];
    char selInput[20];
    int  selection;

    printf(" \n");
    printf("  Smart Bus Route Finder\n");
    printf(" \n");

    printf("Enter source station     : ");
    getStringInput(source, MAX_STATION_NAME);

    printf("Enter destination station: ");
    getStringInput(destination, MAX_STATION_NAME);

    if (equalsIgnoreCase(source, destination)) {
        printf("Source and destination cannot be the same.\n");
        return 1;
    }

    char matchedBuses[MAX_MATCHED_BUSES][MAX_BUS_NAME];
    int  matchedFares[MAX_MATCHED_BUSES];
    int  busCount = collectMatchingBuses(source, destination, matchedBuses, matchedFares);

    if (busCount == 0) {
        int found = findTransferRoute(source, destination);
        if (!found) {
            printf("\nNo route found from %s to %s.\n", source, destination);
        }
        return 0;
    }

    printf("\nAvailable Yatayat:\n");
    printf(" \n");
    for (int i = 0; i < busCount; i++) {
        printf("[%d] %s\n", i + 1, matchedBuses[i]);
    }
    printf(" \n");
    printf("Select yatayat (1-%d): ", busCount);
    getStringInput(selInput, sizeof(selInput));
    selection = atoi(selInput);

    int validChoice = (selection >= 1 && selection <= busCount);
    switch (validChoice) {
        case 1:
            break;
        default:
            printf("Invalid selection.\n");
            return 1;
    }

    int category = getUserCategory();
    showFareSummary(source, destination, matchedBuses[selection - 1],
                    matchedFares[selection - 1], category);
    askMapNavigation(source, destination, NULL);
    return 0;
}
