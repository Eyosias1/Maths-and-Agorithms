
#include <stdio.h>
#include <stdlib.h>

#define DenT 20
#define DenT2 40
#define Ser 11
#define Ser2 22
#define Depmen 21
#define Depmen2 42
void affiche(float * A, int n)
{
    for (int  i = 0; i < n; i++)
    {
       printf("%f , ", A[i]); 
    }
    printf("\n");
}


float lagrange(float * x, float * y, int n, float val)
{
    float newY = 0;
    float l;
    for (int i=0; i<n; i++)
    {
        l = 1;
        for (int j=0; j<n; j++)
        {
            if (i!=j)
            {
                l = l* (val - x[j]) / (x[i] - x[j]) ;
            }
        }
        newY = newY + y[i]*l;
    }
    return newY;
}


int main()
{
    float nouvValy = 0;
    int choix = 0;
    float valIser[DenT] = {1, 3, 5, 7, 9, 11, 13, 15, 17, 19, 21, 23, 25, 27, 29, 31, 33, 35, 37, 39};
    float valIser2[Ser] = {4.5, 5.5, 6.5, 10.5, 9.5, 11.5, 12.5, 13.5, 7.5, 8.5, 14.5}; 
    float valIser3[Depmen] = {759, 580, 597, 648, 637, 658, 569, 528, 789, 876, 749, 963, 921, 842, 714, 633, 721, 819, 852, 948, 937};
    printf("choisir les jeux de test parmi ce presenter\n");
    printf("taper 0 pour jeu de test desiter : 1\n");
    printf("taper 1 pour jeu de test serie 1 : 2\n");
    printf("taper 2 pour jeu de test serie 2 : 3\n");
    printf("taper 3 pour jeu de test serie 3 : 4\n");
    printf("taper 4 pour jeu de test depense mensuelle : 5\n");
    scanf("%d", &choix);
    if (choix == 0)
    {
         // jeu d'essaie de denstiter
        float xT[DenT] = {0, 2, 4, 6, 8, 10, 12, 14, 16, 18, 20, 22, 
                        24, 26, 28, 30, 32, 34, 36, 38};
        float yD[DenT] = {0.99987, 0.99997, 1.00000, 0.99997, 0.99988, 
                        0.99973, 0.99953, 0.99927, 0.99897, 0.99846,
                        0.99805, 0.999751, 0.99705, 0.99650, 0.99664, 
                        0.99533, 0.99472, 0.99472, 0.99333, 0.99326};
        printf("======voici les jeu de test de x\n\n");
        affiche(xT, DenT);
        printf("\n====voici les jeu de test de y\n\n");
        affiche(yD, DenT);
        printf("\n====Ainsi voici les points nouveau points de x\n\n");
        affiche(valIser, DenT);
        printf("\n======\nValeur y des nouveaux points ajouter\n======\n");
        for (int i = 0; i < DenT; i++)
        {
            nouvValy = lagrange(xT, yD,DenT, valIser[i]);
            printf(" %f , ",nouvValy);
        }
    }
    else if(choix == 1)
    {
        // jeu de test serie 1
        float xS1[Ser] = {10, 8, 13, 9, 11, 14, 6, 4, 12, 7, 5};
        float yS1[Ser] = {9.14, 8.14, 8.74, 8.77, 9,26, 8.1, 6.13, 
                        3.1, 9.13, 7.26};
        printf("======voici les jeu de test de x\n\n");
        affiche(xS1, Ser);
        printf("\n====voici les jeu de test de y\n\n");
        affiche(yS1, Ser);
        printf("\n====Ainsi voici les points nouveau points de x\n\n");
        affiche(valIser, Ser);
        printf("\n======\nValeur y des nouveaux points ajouter\n======\n");
        for (int i = 0; i < Ser; i++)
        {
            nouvValy = lagrange(xS1, yS1,Ser, valIser2[i]);
            printf(" %f , ",nouvValy);
        }
    
    }
    else if(choix == 2)
    {
        // jeu de test serie 2
        float xS2[Ser] = {10, 8, 13, 9, 11, 14, 6, 4, 12, 7, 5};
        float yS2[Ser] = {7.46, 6.77, 12.74, 7.11, 7.81, 8.84, 6.08, 
                        5.39, 8.15, 6.42, 5.73};

        printf("======voici les jeu de test de x\n\n");
        affiche(xS2, Ser);
        printf("\n====voici les jeu de test de y\n\n");
        affiche(yS2, Ser);
        printf("\n====Ainsi voici les points nouveau points de x\n\n");
        affiche(valIser, Ser);
        printf("\n======\nValeur y des nouveaux points ajouter\n======\n");
        for (int i = 0; i < Ser; i++)
        {
            nouvValy = lagrange(xS2, yS2,Ser, valIser2[i]);
            printf(" %f , ",nouvValy);
        }
    }
    else if(choix == 3)
    {
        // jeu de test serie 3
        float xS3[Ser] = {8, 8, 8, 8, 8, 8, 8, 19, 8, 8, 8};
        float yS3[Ser] = {6.58, 5.76, 7.71, 8.84, 8.47, 7.04,
                        5.25, 12.5, 5.56, 7.91, 6.89};

        printf("======voici les jeu de test de x\n\n");
        affiche(xS3, Ser);
        printf("\n====voici les jeu de test de y\n\n");
        affiche(yS3, Ser);
        printf("\n====Ainsi voici les points nouveau points de x\n\n");
        affiche(valIser, Ser);
        printf("\n======\nValeur y des nouveaux points ajouter\n======\n");
        for (int i = 0; i < Ser; i++)
        {
            nouvValy = lagrange(xS3, yS3,Ser, valIser2[i]);
            printf(" %f , ",nouvValy);
        }
    }
    else if(choix == 4)
    {
        //jeu de test dependance mesuelle
        float xRev[Depmen] =   {752, 855, 871, 734, 610, 582, 921, 492, 
                                569, 462, 907, 643, 862, 524, 679, 902, 
                                918, 828, 875, 809, 894};
        
        float yDep[Depmen] = {85, 83, 162, 79, 81, 83, 281, 81, 81, 80, 243, 
                            84, 84, 82, 80, 226, 260, 82, 186, 77, 223};

        printf("======voici les jeu de test de x\n\n");
        affiche(xRev, Depmen);
        printf("\n====voici les jeu de test de y\n\n");
        affiche(yDep, Depmen);
        printf("\n====Ainsi voici les points nouveau points de x\n\n");
        affiche(valIser, Depmen);
        printf("\n======\nValeur y des nouveaux points ajouter\n======\n");
        for (int i = 0; i < Depmen; i++)
        {
            nouvValy = lagrange(xRev, yDep,Ser, valIser3[i]);
            printf(" %f , ",nouvValy);
        }
    }
    return 0;

}