#include <stdio.h>
#include <stdlib.h>

int cmpfunc (const void * a, const void * b)
{
   return ( *(int*)a > *(int*)b );
}

int main()
{
    FILE *fp = fopen("date.in","r");
    int n,i=0,x=0;
    if(fp != 0)
        fscanf(fp,"%d",&n);
    int val[100];
    while(fscanf(fp, "%d", &val[i]) == 1)
        i++;
    fclose(fp);
    //Am citit datele din fisier si sortez crescator vectorul
    qsort(val,n,sizeof(int),cmpfunc);
    int op=val[0] + val[1];
    int opAnterior=op;
    //Calculez nr total de operatii care este nr de operatii facute la pasul anterior plus lungimea sirului curent
    for(i=2;i<n;i++){
        op += opAnterior+val[i];
        opAnterior = opAnterior + val[i];
    }
    //Scriu nr total de operatii in fisierul date.out
    fp = fopen("date.out","w");
    fprintf(fp,"%d",op);
    fclose(fp);
    return 0;
}
