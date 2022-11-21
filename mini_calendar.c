#include <stdio.h>
#include <stdbool.h>
bool is_leap_year(int year);

// wrote this programm to get more comfortable with pointer arithmetic

int days_in_month[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

bool is_leap_year (int year){
  return (year % 4 == 0 && year % 100 != 0 || year % 400 == 0 );
}

void add_days_to_date(int *mm, int *dd, int *yy, int days_left_to_add){
  int days_left_in_month;
  while (days_left_to_add > 0){
    days_left_in_month = days_in_month[*mm] - *dd;
    if (*mm == 2 && is_leap_year(*yy)){
      days_left_in_month++;
    }
    if (days_left_to_add > days_left_in_month){
      days_left_to_add -= days_left_in_month;
      days_left_to_add--;
      *dd = 1;
      if (*mm == 12){
        *mm = 1;
        *yy = *yy + 1;
      } else {
        *mm = *mm + 1;
      } 
    } else {
      *dd = *dd + days_left_to_add;
      days_left_to_add = 0;
    }
  }
}



int main() {
  /*int year = 0;
  printf("Please type in year: ");
  scanf("%i", &year);
  
  if ( is_leap_year(year) == true){
      printf("Leapyear.\n");
    } else {
      printf("Not a Leapyear.\n");
    }
  } */

  int mm, dd, yy, days_left_to_add;
  
  printf("Please enter a date in the format mm dd yyyy and provide the number of days to add to this date: ");
  scanf("%d %d %d %d", &mm, &dd, &yy, &days_left_to_add);
  add_days_to_date(&mm, &dd, &yy, days_left_to_add);
  printf("The new date is: %i/%i/%i", mm, dd, yy);
  
}
