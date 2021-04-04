#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

#define EPSILON 0.001

double babilon(double x) {
    double xn = 1;
    double xn1 = x;
    while (fabs(xn1 - xn) > EPSILON) {
        xn1 = (xn + xn1) / 2.0;
        xn = x / xn1;
        //printf("xn: %.6f, xn1: %.6f, diff %.6f\n", xn, xn1, xn1-xn); debug
    }
    return xn;
}

int main(void) {
    double a;
    double r;
    int opt=0;
     srand(time(NULL));  // generare valori random la fiecare rulare
    
    do{
        
        printf("-----Meniu------\n");
        printf("1. Numar introdus de la tastatura: \n");
        printf("2. Numar aleatoriu: \n");
        printf("0. Iesire\n");
        printf("Alegeti optiunea:  \n");
        scanf("%d",&opt);
        switch(opt){
        case 1:
            printf("Dati numarul:");
            scanf("%lf",&a);
            r=babilon(a);
            printf("Numar %.6f, rezultat %.6f, diferenta fata de stdlib %.6f\n", a, r, sqrt(a)-r);
            break;
            case 2:
                a = (9999.0/RAND_MAX) * rand(); // genereaza nr aleatoriu;
                r=babilon(a);
                printf("Numar %.6f, rezultat %.6f, diferenta fata de stdlib %.6f\n", a, r, sqrt(a)-r);
                break;
            case 0:
                break;
    }
    
  }while(opt!=0);
    return 0;
}
