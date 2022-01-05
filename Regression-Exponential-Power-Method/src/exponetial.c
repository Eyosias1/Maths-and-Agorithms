#include <stdio.h>
#include <stdlib.h>
#include <math.h>

float *    LINEAIRE(float x[], float y[], int size)
{
    float minX = 0; // pour calculer la moyenne de x ou x barre
    float minY = 0; // pour calculer la moyenne de y ou x barre
    float minXY = 0; // pour calculer la moyenne de x*y ou x*y baree
    float minSquaX = 0; // pour calculer la moyenne de y ou x barrefloat minX = 0;
    float coeff = 0;
    float Yintercept = 0;
    float  * ExponentialEquation =  calloc(3, sizeof(float));
    float SquaredErrorLine = 0;
    float SquaredErrorY = 0;
    float EpsilonPercentage = 0;
    // on additionne la somme de chaque element dans sa variable en fonction de sa formule
    for (int i = 0; i < size; i++)
    {
        // Ici on consiste a sommer touts les element neccessaire pour effectuer la formule vu en cour qui dit que f(x) = mx + b
       minX += x[i];
       minY += y[i];
       minXY += (x[i] * y[i]);
       minSquaX += pow(x[i], 2);
    }

    // on divise chaque variable par size pour avoir leur resulat finale
    minX = minX / size;
    minY = minY / size;
    minXY = minXY / size;
    minSquaX = minSquaX / size;


    coeff =  ( (minX * minY) - minXY ) /  ( (minX * minX) - minSquaX);

    Yintercept = minY - (coeff * minX);

    ExponentialEquation[0] = Yintercept;
    ExponentialEquation[1] = coeff;
    ExponentialEquation[2] = minY;

    for (int i = 0; i < size; i++)
    {
        //Erreur de cordonnes y
        SquaredErrorY    += pow( (y[i] - minY), 2);
        //Erreur de la droite
        SquaredErrorLine +=  pow( (y[i] - ( (coeff * x[i]) + Yintercept) ), 2);
    }
    //pour calculer le pourcentage d'erreur
    EpsilonPercentage = 1 - (SquaredErrorLine / SquaredErrorY);
    

    printf("our line eqautionis y = %fx + %f + %f \n",coeff, Yintercept, SquaredErrorLine);
    printf("which means y = %fx + %f\n",coeff, Yintercept + SquaredErrorLine);
    printf("And our total variation percentage is %f\n", EpsilonPercentage);
    return (ExponentialEquation);    
}

int    Exponetial(float x[], float y[], int size)
{
    float *YLOGCorrd = (float *) calloc(size, sizeof(float));
    float *ExponentialEquation = NULL;
    float SquaredErrorLine = 0;
    float SquaredErrorY = 0;
    float EpsilonPercentage = 0; 
    for (int i = 0; i < size; i++)
    {
        if (y[i] < 0)
        {
            printf("y is < to 0 so we can't take the logarithme only for positive numbers \n");
            return (0);
        }
        YLOGCorrd[i] = log(y[i]);
    }
    
    ExponentialEquation =  LINEAIRE(x, YLOGCorrd, size);

    ExponentialEquation[0] = exp(ExponentialEquation[0]);
    
    

    printf("And our Exponential equation is y = %fe^(%fx)\n", ExponentialEquation[0], ExponentialEquation[1]);
    return (1);
}


int main()
{
    float x34[10] = {88, 89, 90, 91, 92, 93, 94, 95, 96, 97};
    float y34[10] = {5.89, 6.77, 7.87, 9.11, 10.56, 12.27, 13.92, 15.72, 17.91, 22.13};
    printf("Voici le jeu de test 3.4\n");
    printf("\n=========Voici les valeurs de x \n");
    for (int i = 0; i < 10; i++)
    {
    printf("%f ", x34[i]); 
    }
    printf("\n\n=========Voici les valeurs de y \n");        
    for (int i = 0; i < 10; i++)
    {
    printf("%f ", y34[i]); 
    }
    printf("\n\n========On trouve pour le jeu de test 3.4 \n\n");
    Exponetial(x34, y34, 10);
    

    return (0);
}