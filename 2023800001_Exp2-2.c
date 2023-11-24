//Experiment 2 Program 2
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main ()
{
  int num, fact = 1;
  char resp;			//for final user response for code repetition

  printf ("Hello All-this is a Factorial Program\n");
  printf ("Kindly Enter a Number Below(preferably a whole number)\n\a");
  scanf ("%d", &num);

  if (num >= 0)
    {
      for (int i = 1; i <= num; i++)
	{
	  fact = fact * i;
	}

      printf ("\n\n\n\n\nThe Factorial of your Number is:- %d\n\n\a", fact);
      printf ("Would You Like to Try Again: (type 'y' for yes) ");
      scanf (" %c", &resp);
      if (resp == 'y' || resp == 'Y')
	{
	  printf ("\n\n\n\n\n");	//for leaving some lines
	  main ();
	}
      else
	{
	  printf ("\n\n\n\n\t\tEXITED CODE SUCCESSFULLY!");
	  return 0;
	}
    }

  else
    {
      printf ("Oops! Something Went Wrong\nTry Again\n\n\n\a");
      main ();
    }
}

