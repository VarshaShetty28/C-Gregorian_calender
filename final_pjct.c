#include <stdio.h>
#include <stdlib.h>

int get_1st_weekday(int year) {
    int d;
    d = (((year - 1) * 365) + ((year - 1) / 4) - ((year - 1) / 100) + ((year) / 400) + 1) % 7;
    return d;
}

void print_month_calendar(int year, int month) {
    // Calculate the number of days in the month
    int daysInMonth, startingDay, dayOfWeek;
    if (month == 2) {
        // Check for leap year
        if ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0))
            daysInMonth = 29;
        else
            daysInMonth = 28;
    } else if (month == 4 || month == 6 || month == 9 || month == 11) {
        daysInMonth = 30;
    } else {
        daysInMonth = 31;
    }
    
    // Calculate the starting day of the month
    startingDay = (year - 1) * 365 + (year - 1) / 4 - (year - 1) / 100 + (year - 1) / 400;
    for (int i = 1; i < month; ++i) {
        if (i == 2) {
            if ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0))
                startingDay += 29;
            else
                startingDay += 28;
        } else if (i == 4 || i == 6 || i == 9 || i == 11) {
            startingDay += 30;
        } else {
            startingDay += 31;
        }
    }
    dayOfWeek = (startingDay + 1) % 7; // Incrementing the starting day by 1
    
    // Display the calendar
    printf("\n==============================\n");
    printf("       %d-%02d\n", year, month);
    printf("==============================\n");
    printf(" Sun Mon Tue Wed Thu Fri Sat\n");
    
    // Print spaces for the days before the starting day of the month
    for (int i = 0; i < dayOfWeek; ++i) {
        printf("    ");
    }
    
    // Print the days of the month
    for (int day = 1; day <= daysInMonth; ++day) {
        printf("%4d", day);
        if ((day + dayOfWeek) % 7 == 0) {
            printf("\n");
        }
    }
}

void print_year_calendar(int year) {
    int month;
    for (month = 1; month <= 12; month++) {
        print_month_calendar(year, month);
    }
}

int main() {
    int choice, year, month;

    printf("1. Print calendar for an entire year\n");
    printf("2. Print calendar for a specific month\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);

    switch (choice) {
        case 1:
            printf("Enter the year: ");
            scanf("%d", &year);
            print_year_calendar(year);
            break;
        case 2:
            printf("Enter the year: ");
            scanf("%d", &year);
            printf("Enter the month (1-12): ");
            scanf("%d", &month);
            print_month_calendar(year, month);
            break;
        default:
            printf("Invalid choice\n");
    }

    return 0;
}
