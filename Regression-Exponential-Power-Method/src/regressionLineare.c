#include <stdlib.h>
#include <stdio.h>
#include <math.h>




void    LINEAIRE(float x[], float y[], int size)
{
    float minX = 0; // pour calculer la moyenne de x ou x barre
    float minY = 0; // pour calculer la moyenne de y ou x barre
    float minXY = 0; // pour calculer la moyenne de x*y ou x*y baree
    float minSquaX = 0; // pour calculer la moyenne de y ou x barre
    float coeff = 0;
    float Yintercept = 0;
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

    for (int i = 0; i < size; i++)
    {
        //Erreur de cordonnes y
        SquaredErrorY    += pow( (y[i] - minY), 2);
        //Erreur de la droite
        SquaredErrorLine +=  pow( (y[i] - ( (coeff * x[i]) + Yintercept) ), 2);
    }
    //pour calculer le pourcentage d'erreur
    EpsilonPercentage = 1 - (SquaredErrorLine / SquaredErrorY);


    printf("our line eqaution with the error is y = %fx + %f + %f\n",coeff, Yintercept, SquaredErrorLine);
    printf("which means y = %fx + %f\n",coeff, Yintercept + SquaredErrorLine);
    printf("And our total variation percentage is %f\n", EpsilonPercentage);
}







int main()
{
    int size1 = 11;
    int size2 = 10;
    int choix = 0;
    int choix2 = 0;
    printf("Voulez vous quelle jeu de test \n");
    printf("Jeu de test 3.1 taper 1\nJeu de test 3.2 taper 2\nJeu de test 3.3 taper 3\n");
    scanf("%d", &choix);
    if (choix == 1)
    {
        float x31 [11] = {10, 8, 13, 9, 11, 14, 6, 4, 12, 7, 5};
        float y31 [11] = {8.04, 6.95, 7.58, 8.81, 8.33, 9.96, 7.24, 4.26, 10.84 , 4.82, 5.68};
        printf("\n=========Voici les valeurs de x \n");
        for (int i = 0; i < size1; i++)
        {
        printf("%f ", x31[i]); 
        }
        printf("\n\n=========Voici les valeurs de y\n");        
        for (int i = 0; i < size1; i++)
        {
        printf("%f ", y31[i]); 
        }
        printf("\n\n========On trouve pour le jeu de test 3.1\n\n");
        LINEAIRE(x31, y31, size1);
        printf("\n");
    }
    
    if (choix == 2)
    {
        printf("Vous voulez quelle serie de jeu de test\n");
        printf("Tapez 1 pour serie 1: \n");
        printf("Tapez 2 pour serie 2: \n");
        printf("Tapez 3 pour serie 3: \n");
        scanf("%d", &choix2);
        if (choix2 == 1)
        {
            float xs1[11] = {10, 8, 13, 9, 11, 14, 6, 4, 12, 7, 5};
            float ys1[11] = {9.14, 8.14, 8.74, 8.77, 9.26, 8.1, 6.13, 3.1, 9.13, 7.26, 4.74};
            printf("\n=========Voici les valeurs de x serie 1\n");
            for (int i = 0; i < size1; i++)
            {
            printf("%f ", xs1[i]); 
            }
            printf("\n\n=========Voici les valeurs de y serie 1\n");        
            for (int i = 0; i < size1; i++)
            {
            printf("%f ", ys1[i]); 
            }
            printf("\n\n========On trouve pour le jeu de test 3.2 serie 1 ceci\n\n");
            LINEAIRE(xs1, ys1, size1);
            printf("\n");
        } 
        
        if (choix2 == 2)
        {
            float xs2[11] = {10, 8, 13, 9, 11, 14, 6, 4, 12, 7, 5};
            float ys2[11] = {7.46, 6.77, 12.74, 7.11, 7.81, 8.84, 6.08, 5.39, 8.15, 6.42, 5.73};
            printf("\n=========Voici les valeurs de x serie 2\n");
            for (int i = 0; i < size1; i++)
            {
            printf("%f ", xs2[i]); 
            }
            printf("\n\n=========Voici les valeurs de y serie 2\n");        
            for (int i = 0; i < size1; i++)
            {
            printf("%f ", ys2[i]); 
            }
            printf("\n\n========On trouve pour le jeu de test 3.2 serie 2 ceci\n\n");
            LINEAIRE(xs2, ys2 ,size1);  
        }

        if (choix2 == 3)
        {
            float xs3[11] = {8, 8, 8, 8, 8, 8, 8, 19, 8, 8, 8};
            float ys3[11] = {6.58, 5.76, 7.71, 8.84, 8.47, 7.04, 5.25, 12.5, 5.56, 7.91, 6.89};
            printf("\n==============Voici les valeurs de x serie 3==============\n\n");
            for (int i = 0; i < size1; i++)
            {
            printf("%f ", xs3[i]); 
            }
            printf("\n\n============Voici les valeurs de y serie 3==============\n\n");        
            for (int i = 0; i < size1; i++)
            {
            printf("%f ", ys3[i]); 
            }
            printf("\n\n========On trouve pour le jeu de test 3.2 serie 3 ceci\n\n");
            LINEAIRE(xs3, ys3 ,size1);
        }
    
    }
    
    if (choix == 3)
    {

        float xDepens1[11] = {752, 855, 871, 734, 610, 582, 921,492,569, 462, 907};
        float yRev1[11] = {85, 83, 162, 79, 81, 83, 281, 81, 81, 80, 243};
        printf("\n=========Voici les valeurs de x Depense1\n");
        for (int i = 0; i < size1; i++)
        {
        printf("%f ", xDepens1[i]); 
        }
        printf("\n\n=========Voici les valeurs de y reveunue 1\n");        
        for (int i = 0; i < size1; i++)
        {
        printf("%f ", yRev1[i]); 
        }
        printf("\n\n========On trouve pour le jeu de test 3.3 ceci\n\n");
        LINEAIRE(xDepens1, yRev1 ,11);
        

        float xDepense2[10] = {643, 862, 524, 679, 902, 918, 828, 875, 809, 894};
        float yRev2[10] = {84, 84, 82, 80, 226, 260, 82, 186, 77, 223};
        printf("\n=========Voici les valeurs de x Depense2\n");
        for (int i = 0; i < size2; i++)
        {
        printf("%f ", xDepense2[i]); 
        }
        printf("\n\n=========Voici les valeurs de y reveunue 2\n");        
        for (int i = 0; i < size2; i++)
        {
        printf("%f ", yRev2[i]); 
        }
        printf("\n\n========On trouve pour le jeu de test 3.3\n\n");
        printf("\n");
        LINEAIRE(xDepense2, yRev2 ,10);
    }

}