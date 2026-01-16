#include <stdio.h>
#define N 10
// Enes KARATAŞ
// 2420161056
// https://www.btkakademi.gov.tr/portal/certificate/validate?certificateId=L8dcN6gjmp

void dizi_yazdir(int dizi[], int bas_ind, int son_ind) {
	int i;
	for (i=bas_ind; i<=son_ind; i++) {
		printf(" %2d", dizi[i]);
	}
}

void takas(int *ap, int *bp) {
	int gecici = *ap;
	*ap = *bp;
	*bp = gecici;
}
int ikili_arama(int dizi[], int n, int aranan) {
    int bas = 0;
    int son = n - 1;
    
    while (bas <= son) {

        int orta = bas + (son - bas) / 2;

        if (dizi[orta] == aranan)
            return orta;
        if (dizi[orta] < aranan)
            bas = orta + 1;
        else
            son = orta - 1;
    }
    return -1;
} 
int bolumleme(int dizi[], int bas_ind, int son_ind) {
	int orta_ind = (bas_ind + son_ind) / 2;
	int pivot = dizi[orta_ind];
	int i = bas_ind, j = son_ind;
	
	printf("\n (pivot : %d)", pivot);
	
	while (i<j) {
		while (dizi[i] < pivot) {
			i++;
		}
		while (dizi[j] > pivot) {
			j--;
		}
		takas(dizi+i, dizi+j);
		printf("\n");
		dizi_yazdir(dizi, 0, N-1);
	}
	return i; 
}

void hizli_sirala(int dizi[], int bas_ind, int son_ind) {
 
	int konum = bolumleme(dizi, bas_ind, son_ind);
	printf(" ----> [ ");
	dizi_yazdir(dizi, bas_ind, konum-1);
	printf("] ve [");
	dizi_yazdir(dizi, konum + 1, son_ind);
	printf("]");
	
	if (bas_ind < son_ind) { 
		if (bas_ind < konum-1) {
			hizli_sirala(dizi, bas_ind, konum-1);
		}
		if (son_ind > konum+1) {
			hizli_sirala(dizi, konum+1, son_ind);
		}
	}
}

int main() {
	int A[] = {6, 14, 3, 5, 56, 52, 8, 34, 7, 45};
	int aranan, sonuc;
	
	printf("\n");
	dizi_yazdir(A, 0, N-1);
	hizli_sirala(A, 0, N-1);  
	
	printf("\n");
	dizi_yazdir(A, 0, N-1);	
	printf("\n \n Aramak istediginiz deger: ");
	scanf("%d", &aranan);
	
	sonuc = ikili_arama(A, N, aranan);
	
	if (sonuc == -1) {
		printf("\n Aradiginiz deger %d, dizide bulunamadi!\n", aranan);
	}
	else {
		printf("\n Aradiginiz deger %d, dizinin %d. indisinde bulundu!\n", aranan, sonuc);
	}
	
	return 0;
}