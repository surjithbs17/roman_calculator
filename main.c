/* Author : Surjith Bhagavath Singh
   Code Purpose : Roman Calculator
   Detail: Takes two inputs in roman letters and convert 
   them to integers. Converted integers are added/subtracted/multiplied/divided
   and resultant value is converted into roman letter.
*/



#include <stdio.h>
#include <stdlib.h>
#include <string.h>

const int I = 1;       
const int V = 5;
const int X = 10;
const int L = 50;
const int C = 100;
const int D = 500;       
const int M = 1000;
const int bad_val = -1;
int triple_count = 0;
int triple_count_roman = 0; 
char result_str[20];
 


/* It converts roman character into integer and also checks for repeataility in input*/
int romanchar_to_int( char roman_digit ,int prev_value)
{
   int integer_value;
   if ( roman_digit == 'I' )
      integer_value = I;
   else if ( roman_digit == 'V' )
      integer_value = V;
   else if ( roman_digit == 'X' )
      integer_value = X;
   else if ( roman_digit == 'L' )
      integer_value = L;
   else if ( roman_digit == 'C' )
      integer_value = C;
   else if ( roman_digit == 'D' )
      integer_value = D;
   else if ( roman_digit == 'M' )
      integer_value = M;
   else 
       integer_value = bad_val;

    if (prev_value == integer_value)
      {
        triple_count++;
        if(triple_count == 3)
          {
            printf("Invalid More than 3 times occurance\n");
            return -1;
          }
      }
    else
      triple_count = 0;

   if (prev_value < integer_value)
    integer_value = (integer_value - (2*prev_value));
   return integer_value;
}


/*This function prints the integer value in roman letter string*/

void roman_print ( int val )
{
  int number = val;
  int prev_value = 0;
  int i = 0;
  while ( number > 0 )
  {
    
    int old_prev = prev_value; 
      if ( number >= M )
         {
          result_str[i] = 'M'; 
          number = number - M;
          prev_value = M;
         }
      else if ( number >= D )
        {
          result_str[i] = 'D'; 
          number = number - D;
          prev_value = D;
        }
      else if ( number >= C )
        {
          result_str[i] = 'C'; 
          number = number - C;
          prev_value = C;
        }
      else if ( number >= L )
        {
          result_str[i] = 'L'; 
          number = number - L;
          prev_value = L;
        }
      else if ( number >= X )
        {
          result_str[i] = 'X'; 
          number = number - X;
          prev_value = X;
        }
      
      else if ( number >= V )
        {
          result_str[i] = 'V'; 
          number = number - V;
          prev_value = V;
        }
      else if ( number >= I )
        {
          result_str[i] = 'I'; 
          number = number - I;
          prev_value = I;
        }
  
    
    if (old_prev == prev_value)
    {
      if((prev_value == 1) || (prev_value == 10) || (prev_value == 100))
      {
        triple_count_roman++;
        if(triple_count_roman == 3)
          {
            switch(prev_value)
            {
              case 1:
                {
                  result_str[i-2] = 'V';
                  for(int j= i-1; j<i ; j++)
                  {
                    result_str[j] = '\0';
                  }
                  i = i-2;
                  break;
                }

              case 10:
                {
                  result_str[i-2] = 'L';
                  for(int j= i-1; j<i ; j++)
                  {
                    result_str[j] = '\0';
                  }
                  i = i-2;
                  break;
                }
              
              case 100:
                {
                  result_str[i-2] = 'D';
                  for(int j= i-1; j<i ; j++)
                  {
                    result_str[j] = '\0';
                  }
                  i = i-2;
                  break;
                }
              
            }
          }
      }
      else if((prev_value == 5) || (prev_value == 50) || (prev_value == 500))
      {
            
            switch(prev_value)
            {
              case 5:
                {
                  result_str[i-1] = 'X';
                  result_str[i] = '\0';
                  i = i-1;
                  break;
                }

              case 50:
                {
                  result_str[i-1] = 'C';
                  result_str[i] = '\0';
                  i = i-1;
                  break;
                }
              
              case 500:
                {
                  result_str[i-1] = 'M';
                  result_str[i] = '\0';
                  i = i-1;
                  break;
                }
              
            }

      }
    }
    i++;
  }
}


/* This operates the operator given by the user*/

int operation ( int first_num, int second_num )
{
  int result = 0;
  while(1)
  {
    printf("Enter the operator: ");
    char inp = getchar();
    printf("%c\n",inp);
    
    if ( inp == '+' )
      {
        result = first_num + second_num;
        break;
      }
    else if ( inp == '-' )
      {
        result = first_num - second_num;
        break;
      }
    else if ( inp == '*' )
      {
        result = first_num * second_num;
        break;
      }
    else if ( inp == '/' )
      {
        result = first_num / second_num;
        break;
      }
    else
      printf("ONLY (+,-,*,/)\n");
  }   
  return result;
}



/* Takes the roman input and converts into integer value*/
int in_roman(int number)
{
  char str[20];
  int total = 0;
  char ch = '/0';
  printf("\nEnter the %d roman numeral: ",number);
  memset(str,'/0',sizeof(str));
  scanf("%s",str);

  printf("\n");
  int i = 0;
  int value = 0;
  while (str[i]) 
  {
    ch = str[i];
    i++;
    value = romanchar_to_int(ch,value);
    if (value == -1)
      { 
        total = -1;
        break;
      }
    total = total + value; 
  }
  printf("%d\n",total );
  return total;  
}
       

/* Main Function*/

int main()
{ 
  int first_inp = 0,second_inp = 0,result = 0;
  
  while (1) 
  {   
     while((first_inp = in_roman(1)) == -1 );
     while((second_inp = in_roman(2)) == -1 );
     printf("%d %d\n",first_inp,second_inp );
     int result = operation(first_inp,second_inp);
     roman_print(result);
     printf("Roman Letter is %s\n",&result_str );
  }
  return 0;
}

