#include <iostream>
#include <iomanip>
using namespace std;

int getMonth();
int getYear();
bool isLeapYear(int year);
int monthCount(int month, int year);
int yearCount(int year);
int getOffset(int month, int year);
int getDaysInMonth(int month, int year);
void displayYear(int year);
void displayMonth(int month);
void displayTable(int offset, int numDays);



/**********************************************************************
 * This function is an entry point of the program
 ***********************************************************************/
int main()
{
   int month = getMonth();
   int year = getYear();

   int daysInMonth = getDaysInMonth(month, year);

   displayMonth(month);
   displayYear(year);
   displayTable(getOffset(month, year), daysInMonth);

   return 0;

}


/**********************************************************************
 * This function prompts a user for a month
 ***********************************************************************/
int getMonth()
{
   int month;

   while (month < 1 || month > 12)
   {
      cout << "Enter a month number: ";
      cin  >> month;

      if (month < 1 || month > 12)
         cout << "Month must be between 1 and 12.\n";
   }

   return month;
}

/**********************************************************************
 * This function prompts a user for a year.
 ***********************************************************************/
int getYear()
{
   int year;

   while (year < 1753)
   {
      cout << "Enter year: ";
      cin  >> year;

      if (year < 1753)
         cout << "Year must be 1753 or later.\n";
   }
   cout << endl;
   return year;
}




/**********************************************************************
 * Get the amount of days in a particular month.
 ***********************************************************************/
int monthCount(int month, int year)
{
   int daysInMonth = 0;

   for (int initialMonth = 1; initialMonth < month; initialMonth++)
   {
      if (initialMonth == 1 || initialMonth == 3 || initialMonth == 5
          || initialMonth == 7 || initialMonth == 8
          || initialMonth == 10 || initialMonth == 12)
         daysInMonth += 31;

      else if (initialMonth == 4 || initialMonth == 6 ||
               initialMonth == 9 || initialMonth == 11)
         daysInMonth += 30;

      else if (initialMonth == 2 && !isLeapYear(year))
         daysInMonth += 28;

      else
         daysInMonth += 29;

   }

   return daysInMonth;
}

/**********************************************************************
 * This function gets the total number of days from 1753 to a selected year.
 ***********************************************************************/
int yearCount(int year)
{
   int yearDays = 0;

   for (int previousYear = 1753; previousYear < year; previousYear++)
   {
      if (!isLeapYear(previousYear))
         yearDays += 365;

      if (isLeapYear(previousYear))
         yearDays += 366;
   }

   return yearDays;
}

/**********************************************************************
 * This function gets the offset - spacing to visualize on which day of
 * the week month starts.
 ***********************************************************************/
int getOffset(int month, int year)
{
   int yearDays = yearCount(year);

   int monthDays = monthCount(month, year);

   int offset = (yearDays + monthDays) % 7;

   return offset;
}


/**********************************************************************
 * This function gets the exact number of days for a selected month.
 ***********************************************************************/
int getDaysInMonth(int month, int year)
{
   int daysInMonth;

   if (month == 1 || month == 3 || month == 5
          || month == 7 || month == 8
          || month == 10 || month == 12)
      daysInMonth = 31;

   else if (month == 4 || month == 6 ||
            month == 9 || month == 11)
      daysInMonth = 30;

   else if (month == 2 && !isLeapYear(year))
      daysInMonth = 28;

   else
      daysInMonth = 29;

   return daysInMonth;
}


/**********************************************************************
 * This function displays a calendar data.
 ***********************************************************************/
void displayTable(int offsetting, int daysInMonth)
{

   cout << "  Su  Mo  Tu  We  Th  Fr  Sa\n";

   int day;

   if (offsetting == 0)
   {
      day = 2;
      cout << setw(6);
   }
   else if (offsetting == 1)
   {
      day = 3;
      cout << setw(10);
   }
   else if (offsetting == 2)
   {
      day = 4;
      cout << setw(14);
   }
   else if (offsetting == 3)
   {
      day = 5;
      cout << setw(18);
   }
   else if (offsetting == 4)
   {
      day = 6;
      cout << setw(22);
   }
   else if (offsetting == 5)
   {
      day = 7;
      cout << setw(26);
   }
   else if (offsetting == 6)
   {
      day = 1;
      cout << setw(2);
   }
   else
      ;

   for (int weeksDay = 1; weeksDay <= daysInMonth; weeksDay++)
   {
      cout << "  " << setw(2) << weeksDay;
      day++;
      if (day == 8)
      {
         cout << endl;
         day = 1;
      }
   }

   if (day >= 2 && day <= 8)
      cout << endl;

   return;

}


/**********************************************************************
 * This function displays a year.
 ***********************************************************************/
void displayYear(int year)
{
   cout << ", " << year << endl;
}

/**********************************************************************
 * Convert a month's number into a month string and display it.
 ***********************************************************************/
void displayMonth(int month)
{
   switch (month)
   {
      case 1 :
         cout << "January";
         break;
      case 2 :
         cout << "February";
         break;
      case 3 :
         cout << "March";
         break;
      case 4 :
         cout << "April";
         break;
      case 5 :
         cout << "May";
         break;
      case 6 :
         cout << "June";
         break;
      case 7 :
         cout << "July";
         break;
      case 8 :
         cout << "August";
         break;
      case 9 :
         cout << "September";
         break;
      case 10 :
         cout << "October";
         break;
      case 11 :
         cout << "November";
         break;
      case 12 :
         cout << "December";
         break;
   }
}

/**********************************************************************
 * This function checks if a current year is a leap year.
 ***********************************************************************/
bool isLeapYear(int year)
{
   return bool (year % 4 == 0 && year % 100 != 0 || year % 400 == 0);
}
