#include <stdio.h>
#include <math.h>

// The default places for laptimes.
const int laps_100m[2]    = {   50,   100};
const int laps_200m[4]    = {   50,   100,   150,   200};
const int laps_300m[6]    = {   50,   100,   150,   200,   250,   300};
const int laps_400m[4]    = {  100,   200,   300,   400};
const int laps_800m[4]    = {  200,   400,   600,   800};
const int laps_1000m[5]   = {  200,   400,   600,   800,  1000};
const int laps_1500m[7]   = {  300,   500,   700,   900,  1100,  1300,  1500};
const int laps_3000m[8]   = {  200,   600,  1000,  1400,  1800,  2200,  2600, \
  			      3000};
const int laps_3000mST[8] = {  200,   600,  1000,  1400,  1800,  2200,  2600, \
 			      3000};
const int laps_5000m[13]  = {  200,   600,  1000,  1400,  1800,  2200,  2600, \
  			      3000,  3400,  3800,  4200,  4600,  5000};
const int laps_10000m[]   = {  400,   800,  1200,  1600,  2000,  2400,  2800, \
  			      3200,  3600,  4000,  4400,  4800,  5200,  5600, \
			      6000,  6400,  6800,  7200,  7600,  8000,  8400, \
			      8800,  9200,  9600, 10000};


// Present the user a menu with the race-types he can select from.
void show_races() {

  printf("\nFor what kind of race do you want to calculate the laptimes?\n\n");
  printf("  1)   100m\n");
  printf("  2)   200m\n");
  printf("  3)   300m\n");
  printf("  4)   400m\n");
  printf("  5)   800m\n");
  printf("  6)  1000m\n");
  printf("  7)  1500m\n");
  printf("  8)  3000m\n");
  printf("  9)  3000m steeple\n");
  printf(" 10)  5000m\n");
  printf(" 11) 10000m\n\n");

}


// Ask the user for what race-type he wants to calculate his laptimes.
int read_racetype(void) {

  char line[100];
  int racetype;

  printf("Enter the number corresponding to the kind of race [1-11]: ");

  fgets(line, sizeof(line), stdin);
  sscanf(line, "%d", &racetype);

  return (racetype);

}


// Read the time the user wants to run.
double read_wanted_time(void) {

  char line[100];
  double wanted_time;
  int hours, minutes, seconds, hundreds;

  printf("Enter the time you want to run for this race (HH:MM\'SS\"SS): ");

  fgets(line, sizeof(line), stdin);
  sscanf(line, "%d:%d\'%d\"%d", &hours, &minutes, &seconds, &hundreds);

  wanted_time = hours*3660+minutes*60+seconds+hundreds/100.0;

  return (wanted_time);

}

void show_laptimes(const int* laps, int nblaps, double wanted_time, int distance) {

  int i;
  int hours, minutes, seconds, hundreds;

  for (i=0; i<nblaps; i++) {

    hours = floor(((double)laps[i]/distance*wanted_time)/(60*60.0));
    minutes = floor(((double)laps[i]/distance*wanted_time)/60.0);
    seconds = floor( ((double)laps[i]/distance*wanted_time) - minutes*60);
    hundreds = floor( ( ((double)laps[i]/distance*wanted_time) - minutes*60 \
	         - seconds )*100 );

    printf("\tAfter %5dm: ", laps[i]);
    if (hours <= 0) {
      printf("   ");
    } else {
      printf("%02d:", hours);
    }
    if ( (hours <= 0) && (minutes <= 0)) {
      printf("   ");
    } else {
      printf("%02d\'", minutes);
    }
    if ( (hours <= 0) && (minutes <= 0) && (seconds <= 0) ) {
      printf("     \n");
    } else {
      printf("%02d\"%02d\n", seconds, hundreds);
    }
  }
}


// Make this return a pointer to a list of time-structs???
int calculate_laptimes(int racetype, double wanted_time) {

  printf("\n");

  switch (racetype) {

    case 1:

      printf("These should be your laptimes for 100m:\n");
      show_laptimes(laps_100m, sizeof(laps_100m)/sizeof(int), wanted_time, 100);
      break;

    case 2:

      printf("These should be your laptimes for 200m:\n");
      show_laptimes(laps_200m, sizeof(laps_100m)/sizeof(int), wanted_time, 200);
      break;

    case 3:

      printf("These should be your laptimes for 300m:\n");
      show_laptimes(laps_300m, sizeof(laps_300m)/sizeof(int), wanted_time, 300);
      break;

    case 4:

      printf("These should be your laptimes for 400m:\n");
      show_laptimes(laps_400m, sizeof(laps_400m)/sizeof(int), wanted_time, 400);
      break;

    case 5:

      printf("These should be your laptimes for 800m:\n");
      show_laptimes(laps_800m, sizeof(laps_800m)/sizeof(int), wanted_time, 800);
      break;

    case 6:

      printf("These should be your laptimes for 1000m:\n");
      show_laptimes(laps_1000m, sizeof(laps_1000m)/sizeof(int), wanted_time, 1000);
      break;

    case 7:

      printf("These should be your laptimes for 1500m:\n");
      show_laptimes(laps_1500m, sizeof(laps_1500m)/sizeof(int), wanted_time, 1500);
      break;

    case 8:

      printf("These should be your laptimes for 3000m:\n");
      show_laptimes(laps_3000m, sizeof(laps_3000m)/sizeof(int), wanted_time, 3000);
      break;

    case 9:

      printf("These should be your laptimes for 3000m steeple:\n");
      show_laptimes(laps_3000mST, sizeof(laps_3000mST)/sizeof(int), wanted_time, 3000);
      break;

    case 10:

      printf("These should be your laptimes for 5000m:\n");
      show_laptimes(laps_5000m, sizeof(laps_5000m)/sizeof(int), wanted_time, 5000);
      break;

    case 11:

      printf("These should be your laptimes for 10000m:\n");
      show_laptimes(laps_10000m, sizeof(laps_10000m)/sizeof(int), wanted_time, 10000);
      break;
      
  }

  return (0);

}

int main() {

  int racetype;
  double wanted_time;

  show_races();
  racetype = read_racetype();
  wanted_time = read_wanted_time();

  calculate_laptimes(racetype, wanted_time);

  printf("\nlaptimes was created by Bart Vandewoestyne and is of course\n");
  printf("completely Open Source Software.\n");
  printf("Please send your bugreports, comments and suggestions\n");
  printf("to Bart.Vandewoestyne@telenet.be.\n");
  printf("\nNow press the 'Enter'-key to end...");
  getchar();

  return (0);

}
