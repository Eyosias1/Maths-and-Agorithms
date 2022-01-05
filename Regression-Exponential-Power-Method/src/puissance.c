#include <stdlib.h>
#include <stdio.h>
#include <math.h>

float *    LINEAIRE(float x[], float y[], int size)
{
    float minX = 0; // pour calculer la moyenne de x ou x barre
    float minY = 0; // pour calculer la moyenne de y ou x barre
    float minXY = 0; // pour calculer la moyenne de x*y ou x*y baree
    float minSquaX = 0; // pour calculer la moyenne de y ou x barrefloat minX = 0;
    float coeff = 0;
    float Yintercept = 0;
    float *PUISSANCE_EQUA = (float *) calloc(2, sizeof(float));

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

    PUISSANCE_EQUA[0] = Yintercept;
    PUISSANCE_EQUA[1] = coeff;
    for (int i = 0; i < size; i++)
    {
        //Erreur de cordonnes y
        SquaredErrorY    += pow( (y[i] - minY), 2);
        //Erreur de la droite
        SquaredErrorLine +=  pow( (y[i] - ( (coeff * x[i]) + Yintercept) ), 2);
    }
    //pour calculer le pourcentage d'erreur
    EpsilonPercentage = 1 - (SquaredErrorLine / SquaredErrorY);
    

    printf("Our line eqaution is y = %fx + %f + %f\n",coeff, Yintercept, SquaredErrorLine);
    printf("Which means y = %fx + %f\n",coeff, Yintercept + SquaredErrorLine);
    printf("And our total variation percentage is %f\n", EpsilonPercentage);
    return (PUISSANCE_EQUA);
}


void    Puissance(float x[], float y[], int size)
{
    float *YCORDONNEE_log = (float *) calloc(size, sizeof(float));
    float *XCORDONNE_log = (float *) calloc(size, sizeof(float));;
    float *PuisanceEquation = NULL ;

    for (int i = 0; i < size; i++)
    {
       YCORDONNEE_log[i] = log(y[i]);
       XCORDONNE_log[i] = log(x[i]);
    }

    PuisanceEquation =  LINEAIRE(XCORDONNE_log, YCORDONNEE_log, size);

    PuisanceEquation[0] = exp(PuisanceEquation[0]);

    printf("And our Puissance equation is y = %fx^%f", PuisanceEquation[0], PuisanceEquation[1]);


    
}

int main()
{
    float x35[7] = {20, 30, 40 ,50, 100, 300, 500};
    float y35[7] = {352, 128, 62.3, 35.7, 6.3, 0.4, 0.1};
    printf("Voici le jeu de test 3.5\n");
    printf("\n=========Voici les valeurs de x \n");
    for (int i = 0; i < 7; i++)
    {
    printf("%f ", x35[i]); 
    }
    printf("\n\n=========Voici les valeurs de y \n");        
    for (int i = 0; i < 7; i++)
    {
    printf("%f ", y35[i]); 
    }
    printf("\n\n========On trouve pour le jeu de test 3.5 \n\n");
    Puissance(x35, y35, 7);

   

  
    return(0);
}