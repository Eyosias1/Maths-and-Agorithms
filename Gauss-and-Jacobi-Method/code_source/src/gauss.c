#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include "LeTest.h"

// demander a l'utilisateur de remplir la matrice A
void inputMatriceA(float **A, int size)
{
    for (int i=0; i<size; i++)
    {
        printf("ligne %d:", i+1);
        for(int j=0; j<size; j++)
        {
            scanf("%f", &(A[i][j]));
        }
    }
}

// pour générer aléatoirement une matrice creuse
void genMat(float ** mat, int size)
{
    int i, j;
    int total = round((size*size)*(3/10.0));
    for (int k = 0; k < total; k++)
    {
        // choisir aleatoirement une case et sa valeur 
        i = (rand() % (size));
        j = (rand() % (size));
        mat[i][j] = rand() % (size + 1); 
    }
}

// Initialiser la matrice A
float ** initMatrice(int size)
{
    float ** A = calloc(size, sizeof(float *));
    for(int i=0; i<size; i++)
    {
        A[i] = calloc(size, sizeof(float)); 
    } 
    return A;
}

// Algorithme de gauss
int gauss(float **arr, float *b, int n)
{
    float pivot=0;
    int compteur = 0;
    for(int k=0; k<n-1; k++)
    {
        for(int i=k+1; i<n; i++)
        {
            compteur++;
            pivot = arr[i][k]/arr[k][k];
            for(int j=k; j<n; j++)
            {
                compteur++;
                arr[i][j] = arr[i][j]-pivot*arr[k][j];
                compteur++;
                
            }
            compteur++;
            b[i]=b[i]-pivot*b[k];
            compteur++;
        }
        
    }
    return (compteur);
}

// Afficher la Matrice A
void affiche(float **arr, int n)
{
    for (int i=0; i<n; i++)
    {
        for(int j=0;j<n; j++)
        {
           printf("%.2f ", arr[i][j]);
        }
        printf("\n");
    }
}

// Deuxieme etape de resolution de gauss
float * resolution(float **A, float * b, int size)
{
    int i, j;
    float somme;
    int compteur = gauss(A, b, size);
    affiche(A, size);
    int n = 0;
    float * x = calloc(size, sizeof(float));
    for (i = size - 1; i >= 0; i--)
    {
        float somme = 0;
        compteur++;
        for (j = i + 1; j < size; j++)
        {
            somme += A[i][j]*x[j];
            compteur++;
        }
        x[i] = (b[i] - somme)/A[i][i];
        compteur++;
    }
    printf("===== les solution de x sont ======\n");
    printf("==== complexite = %d\n", compteur);
    return(x);
}

// Pour afficher les matrice colonne
void affiche2(float *arr, int n)
{
        for(int j=0;j<n; j++)
        {
           printf("x[%d] = %f\n", j, arr[j]);
        }
        printf("\n");
}

//Liberer la memoire
void liberer(float ** A, int size)
{
    if(A != NULL)
    {
        for(int i=0; i<size; i++)
        {
            free(A[i]);
        }
        free(A);
    }
}

int compteur = 0;
int main()
{
    //Debut de vitesse de convergence
    clock_t begin = clock();
    int size = 0;
    printf("======\nChoisir la taille de la matrice carrer ex pour 3*3 taper 3: ");
    scanf("%d", &size);
    float ** A = initMatrice(size);
    int val;
    printf("Si vous voulez remplir la matrice tapez 0, sinon tapez 1: ");
    scanf("%d", &val);
    // si val = 1 la methode de remplissage automatique de la matrice A
    if (val == 1)
    {
        int choix = 0;
        printf("Avec quelle methode voulez vous generez la matrice A\n");
        printf("Utilisez genMat pour generez une matrice creuse aleatoire\t1:\n");
        printf("Utilisez la matrice de ding dong                         \t2:\n");
        printf("Utilisez la matrice de AbordCaree                        \t3:\n");
        printf("Utilisez la matrice de Franc                             \t4:\n");
        printf("Utilisez la matrice de Hilber                            \t5:\n");
        printf("Utilisez la matrice de Hilber2                           \t6:\n");
        printf("Utilisez la matrice de Kms                               \t7:\n");
        printf("Utilisez la matrice de Lehmar                            \t8:\n");
        printf("Utilisez la matrice de Lotkin                            \t9:\n");
        printf("Utilisez la matrice de Moler                            \t10:\n");
        printf("Quelle est votre choix entre 1 et 10 : ");
        scanf("%d", &choix);
        switch (choix)
        {
            case 1:
                genMat(A, size);
                break;
            case 2:
                DingDong(A, size);
                break;
            case 3:
                ABordCaree(A, size);
                break;
            case 4:
                Franc(A, size);
                break;
            case 5:
                Hilber(A, size);
                break;
            case 6:
                Hilber2(A, size);
                break;
            case 7:
                Kms(A, size);
                break;
            case 8:
                Lehmar(A, size);
                break;
            case 9:
                Lotkin(A, size);
                break;
            case 10:
                Moler(A, size); 
                break;
            default:
                printf("hors de portee\n veuillez remplir la matrice\n");
                inputMatriceA(A, size);
                break;
        }
    }
    // si val = 0 l'utilisateurs insere lui meme les valeur de A
    else if (val == 0)
    {
        printf("Donnez les elements de la matrice A:\n");
        inputMatriceA(A, size);
    }
    affiche(A, size);
    //demander a l'utilisateur la matrice b
    float * b = calloc(size, sizeof(float));
    printf("Donnez les elements de la matrice b: ");
        for(int i=0; i<size; i++)
            scanf("%f", &(b[i]));
    float * x = resolution(A, b, size);
    affiche2(x, size);
    clock_t end = clock();
    unsigned long millis = (end -  begin) * 1000 / CLOCKS_PER_SEC;
    printf( "Finished in %ld ms\n", millis );
    liberer(A, size);
    free(x);
    free(b);
    return(0);
}