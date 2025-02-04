#include <stdio.h>
#include <stdlib.h>
#include <math.h>  

struct ogrenciTip {
    int no;
    char cevap[10];
};

struct sonucTip {
    int no;
    int puan;  
};

int main()
{
    struct ogrenciTip ogrenci[3];
    struct sonucTip sonuc[3];
    char anahtar[10];
    int i, j;
    int dogru, yanlis;

    printf("Lutfen cevap anahtarini giriniz (10 harf, A B C D):\n");
    for (i = 0; i < 10; i++) {
        scanf(" %c", &anahtar[i]);  
    }

    printf("\nOgrenci bilgilerini giriniz\n");

    for (j = 0; j < 3; j++) {
        printf("\nOgrenci no: ");
        scanf("%d", &ogrenci[j].no);

        dogru = 0;
        yanlis = 0;

        printf("Cevaplari giriniz (10 harf, A B C D): ");
        for (i = 0; i < 10; i++) {
            scanf(" %c", &ogrenci[j].cevap[i]); 
            if (anahtar[i] == ogrenci[j].cevap[i]) {
                dogru++;
            } else {
                yanlis++;
            }
        }

        sonuc[j].no = ogrenci[j].no;
        sonuc[j].puan = dogru * 3; 

        printf("Dogru: %d, Yanlis: %d, Puan: %d\n", dogru, yanlis, sonuc[j].puan);
    }

    printf("\nSinav Sonuclari:\n");
    printf("------------------------------\n");
    printf("Ogrenci No  |  Puan\n");
    printf("------------------------------\n");

    for (j = 0; j < 3; j++) {
        printf("%10d  |  %3d\n", sonuc[j].no, sonuc[j].puan);
    }

    return 0;
}
