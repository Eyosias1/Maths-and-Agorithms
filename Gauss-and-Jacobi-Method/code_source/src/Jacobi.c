#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include "LeTest.h"


// Pour afficher les matrice colonne
void affiche2(float *arr, int n)
{
        for(int j=0;j<n; j++)
        {
           printf("x[%d] = %f\n", j, arr[j]);
        }
        printf("\n");
}

// pout calculer la norme
float funcNorme(float ** a, float * x, int size, float * b)
{
    float sum;
    float norme = 0;
    //produit matriciel A*X
    for (int i = 0; i < size; i++)
    {
        sum = 0;
        for (int j = 0; j < size; j++)
        {
           sum += a[i][j]*x[j];
        }
        //calculer A*X - b pour chaque element
        sum -= b[i];
        //la somme de chaque element de aX-b au carree
        norme += sum*sum;
    }
    return (sqrt(norme));
}

// Algorithme de jacobi
int Jacobi(float epsilon, float ** A, int size, float * x, float * b)
{
    int i, j, count;
    int maxIter = 0;
    printf("Donnez le nombre d'iteration: ");
    scanf("%d", &maxIter);
    float sum = 0;
    // boucle des iteration
    for (count = 0; count < maxIter; count++)
    {
        //boucle de ligne
        for(i = 0; i < size; i++)
        {
            sum = 0;
            //boucle de colonne
            for ( j = 0; j < size; j++)
            {
                if (j != i)
                {
                    sum += A[i][j] *  x[j];
                }
            }
            x[i] = ( 1 / (A[i][i]) ) * (b[i] - sum);
        }
        printf("***** iteration %d *****\n", count+1);
        printf("norme = %.10f\n", funcNorme(A, x, size, b));
        if (funcNorme(A, x, size, b) < epsilon)
        {
            printf("==== Solution trouvee ====\n");
            return 0;
        }
    }
}

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

// Afficher la Matrice A
void affiche(float ** A, int size)
{
    for (int i=0; i<size; i++)
    {
        for(int j=0; j<size; j++)
        {
           printf("%f ", A[i][j]);
        }
        printf("\n");
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

//Pour verifier si la matrice est diganale dominante
int diagDom(float ** A, int size)
{
    float sum;
    int flag;
    for(int i=0; i<size; i++)
    {
        sum=0;
        flag = 0;
        for(int j=0; j<size; j++)
        {
            //Si un element est nulle incrementer Flag
            if (A[i][j] == 0)
                flag++;
            //somme des element d'une ligne sans l'element de la digonale
            if(i != j)
                sum += fabs(A[i][j]);
            // si la sommes est superieure a l'element de la digonale la matrice n'est pas donminante
            if(sum>fabs(A[i][i]))
                return (0);
        }
        //si tous les elements d'une lingne sont nuls, la matrice n'est pas carree
        if (flag == size)
            return (0);
    }
    return (1);
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


int main()
{
    srand(time(NULL));
    clock_t begin = clock();
    int size = 0;
    printf("Donnez la taille de la matrice caree, exemple: 3 pour une matrice de taille 3X3: ");
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
    if (val == 0)
    {
        printf("Donnez les elements de la matrice A:\n");
        inputMatriceA(A, size);
    }
    // regarde si la matrice n'est pas diagonale dominante
    if(!(diagDom(A, size)))
    {
        printf("=====\nLa matrice n'est pas stritement diagonale dominante ou elle n'est pas carree!\n");
    }
    affiche(A, size);
    float * x = calloc(size, sizeof(float));
    float * b = calloc(size, sizeof(float));
    //demander a l'utilisateur la matrice b
    printf("Donnez les elements de la matrice b: ");
        for(int i=0; i<size; i++)
            scanf("%f", &(b[i]));
    printf("Donnez la valeur d'epsilon, exemple: pour 10^(-3) entrer -3: ");
    int power = -1;
    scanf("%d", &power);
    float epsi = pow(10,power);
    Jacobi(epsi,A,size,x,b);
    affiche2(x, size);
    liberer(A, size);
    free(b);
    free(x);
    clock_t end = clock();
    unsigned long millis = (end -  begin) * 1000 / CLOCKS_PER_SEC;
    // affiche un message si elle n'est pas diagonale dominante
    printf( "Finished in %ld ms\n", millis );
    return (0);
}
