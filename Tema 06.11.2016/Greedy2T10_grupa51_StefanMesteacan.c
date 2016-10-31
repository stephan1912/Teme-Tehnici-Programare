#include <stdio.h>
#include <stdlib.h>

//Folosesc o structura pentru a retine datele de intrare
struct Bucata{
    int Id,Greutate,Pret;
}bucata[100];

int cmpfunc (struct Bucata  *a, struct Bucata *b)
{
   return ( (float)((*a).Pret) / (*a).Greutate >= (float)((*b).Pret) / (*b).Greutate);
}

int main()
{
    int n,gMax,i,Pret=0;
    FILE *fp = fopen("date.in","r");
    if(fp != 0)
        fscanf(fp,"%d%d",&n,&gMax);
    for(i=0;i<n;i++){
        fscanf(fp,"%d%d%d",&bucata[i].Id,&bucata[i].Greutate,&bucata[i].Pret);
    }
    fclose(fp);
    //Am citit datele din fisier
    fp = fopen("date.out","w");
    //Sortez 'vectorul' in functie de pretul/greutatea unui metal in ordine crescatoare
    qsort(bucata,n,3*sizeof(int),cmpfunc);

    for(i=0;i<n;i++){
       //Scad din greutatea maxima greutatea metalului curent
       //Daca este mai mare ca 0 folosesc tot metalul
        if(gMax - bucata[i].Greutate > 0){
            Pret += bucata[i].Pret;
            gMax -= bucata[i].Greutate;
            fprintf(fp,"%d",bucata[i].Id);
            fprintf(fp," 100(percent)\n");
            if(gMax == 0)
                break;
        }//daca nu folosesc doar o parte din metal si adaug doar pretul respectivei parti
        else if(gMax - bucata[i].Greutate < 0){
            int diferenta  = bucata[i].Greutate - gMax;
            gMax = 0;
            Pret += diferenta * bucata[i].Pret / bucata[i].Greutate;
            fprintf(fp,"%d",bucata[i].Id);
            fprintf(fp," %d(percent)",(int)((float)diferenta / (float)bucata[i].Greutate * 100));
            break;
        }

    }
    fprintf(fp,"\n%d",Pret);
    fclose(fp);

    return 0;
}
