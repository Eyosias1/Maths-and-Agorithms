#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>


void   ABordCaree(float **A,int size)
{
    for (int i = 0; i < size; i++)
    {
       for (int j = 0; j < size; j++)
       {
           if (i == j)
           {
                A[i][j] = 1;
           }
           else if (i == 0 || j == 0)
           {
               A[i][j] = pow(2, 1.0 - j);
           }
           else
           {
               A[i][j] = 0;
           }
       }
    }
}

void    DingDong(float ** A, int size)
{
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
           A[i][j] = (1.0 / (2 * (size - i - j + 0.5))); 
        }
    }
}
//float ** A, int size
void    Franc(float ** A, int size)
{
    for (int i = 0; i < size; i++)
    {
       for (int j = 0; j < size; j++)
       {
          if (i >= j + 2.0)
          {
              A[i][j] = 0.0;
          }
          else
          {
              A[i][j] = i <= j ? i + 1.0 : j + 1.0;
          }
       }
    }
}

void    Hilber(float ** A, int size)
{
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            A[i][j] = (1.0 / (i + j + 1));  
        }
    }
}


void    Hilber2(float ** A, int size)
{
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            A[i][j] = (1.0 / (i + j + 3));  
        }
    }
}

void    Kms(float ** A, int size)
{
    float p = 0.5;
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            A[i][j] = pow(0.5, abs(i - j));
        }
    }
}


void    Lehmar(float ** A, int size)
{
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            if (i <= j)
            {
                A[i][j] = (i + 1.0) / (j + 1);
            }
            else
            {
                A[i][j] = (j + 1.0) / (i + 1);
            }
        }
    }
}

void    Lotkin(float ** A, int size)
{
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            if (i == 0)
            {
                A[i][j] = 1;
            }
            else
            {
                A[i][j] = (1.0 / (i + j + 1));
            }
        }
    }
}

void    Moler(float ** A, int size)
{
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            if (i == j)
            {
                A[i][j] = i + 1.0;
            }
            else
            {
                A[i][j] = i <= j ? i - 1.0: j - 1.0;
            }
        }
    }
}


