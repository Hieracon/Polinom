#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
{
   int a[20]; // vectorul de coeficienti ai polinomului a0,a1,a2...
   int Px_5; //P(x-5)
   int Px_10; //P(x-10)
   int P1x_2; // P prim(x+2)
   int P2x; // P secund(x)
   int grad;
   int x;
   float temp;
   int it;

        FILE *fp;

        fp = fopen("C:/Users/Florin/Desktop/Polinom/data.txt", "r+");

        fscanf(fp, "%d", &grad);

        for(it = 0; it < grad; ++it){
            fscanf(fp, "%d", &a[it]);
        }

        fscanf(fp, "%d", &x);

        Px_5 = 0;

        for(it = 0; it < grad; ++it){
            Px_5 = Px_5 + ( a[it] * pow(x - 5, it) );
        }

        Px_10 = 0;

        for(it = 0; it < grad; ++it){
            Px_10 = Px_10 + ( a[it] * pow(x - 10, it) );
        }

        P1x_2 = 0;

        for(it = 1; it < grad; ++it){
            P1x_2 = P1x_2 + ( it * a[it] * pow(x + 2, it - 1) );
        }

        P2x = 0;

        for(it = 2; it < grad; ++it){
            P2x = P2x + ( it * (it - 1) * a[it] * pow(x, it - 2) );
        }

        if( (P1x_2 - Px_10) != 0){
            temp = (P2x + 5*Px_5) / (P1x_2 - Px_10);
            printf("%f", temp);
        }
        else{
            printf("N/A");
        }

    return 0;
}
