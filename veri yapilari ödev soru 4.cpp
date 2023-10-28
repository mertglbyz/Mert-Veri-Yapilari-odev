#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Ögrenci yapisi
struct Ogrenci {
    int ogrenciNo;
    char ad[100];
    struct Ogrenci* next;
};

// Ögrenci listesine yeni ögrenci ekleme fonksiyonu
struct Ogrenci* ogrenciEkle(struct Ogrenci* head, int no, const char* ad) {
    struct Ogrenci* yeniOgrenci = (struct Ogrenci*)malloc(sizeof(struct Ogrenci));
    yeniOgrenci->ogrenciNo = no;
    strcpy(yeniOgrenci->ad, ad);
    yeniOgrenci->next = head;
    return yeniOgrenci;
}

// Ögrenci adina göre arama yapma fonksiyonu
struct Ogrenci* ogrenciAraAd(struct Ogrenci* head, const char* hedefAd) {
    struct Ogrenci* gecici = head;
    while (gecici != NULL) {
        if (strcmp(gecici->ad, hedefAd) == 0) {
            return gecici; 
        }
        gecici = gecici->next;
    }
    return NULL; // Ekleme bulunamadi  NULL döndür
}

int main() {
    struct Ogrenci* liste = NULL;

    // Ögrenci kayytlari
    liste = ogrenciEkle(liste, 1, "kenan");
    liste = ogrenciEkle(liste, 2, "salih");
    liste = ogrenciEkle(liste, 3, "recep");
    liste = ogrenciEkle(liste, 4, "mert");

    // Kullancidan aranacak ögrencinin adi
    char arananAd[100];
    printf("Aranacak ogrencinin adini girin: ");
    scanf("%s", arananAd);

    // Ögrenci adina göre arama yap
    struct Ogrenci* sonuc = ogrenciAraAd(liste, arananAd);

    if (sonuc != NULL) {
        printf("Ogrenci Bulundu: Ogrenci No %d, Ady: %s\n", sonuc->ogrenciNo, sonuc->ad);
    } else {
        printf("Ogrenci Bulunamady: %s\n", arananAd);
    }

    // Bellegi temizle
    while (liste != NULL) {
        struct Ogrenci* temp = liste;
        liste = liste->next;
        free(temp);
    }

    return 0;
}
