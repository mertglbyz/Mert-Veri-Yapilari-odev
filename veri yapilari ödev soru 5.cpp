#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// �grenci yapisi
struct Ogrenci {
    int ogrenciNo;
    char ad[100];
    struct Ogrenci* next;
};

// Yeni �grenci ekleme fonksiyonu
struct Ogrenci* ogrenciEkle(struct Ogrenci* head, int no, const char* ad) {
    struct Ogrenci* yeniOgrenci = (struct Ogrenci*)malloc(sizeof(struct Ogrenci));
    yeniOgrenci->ogrenciNo = no;
    strcpy(yeniOgrenci->ad, ad);
    yeniOgrenci->next = NULL;

    if (head == NULL) {
        return yeniOgrenci;
    }

    struct Ogrenci* gecici = head;
    while (gecici->next != NULL) {
        gecici = gecici->next;
    }
    gecici->next = yeniOgrenci;

    return head;
}

// �grenci listesini ekrana yazdiran fonksiyon
void ogrenciListesiYazdir(struct Ogrenci* head) {
    struct Ogrenci* gecici = head;
    while (gecici != NULL) {
        printf("Ogrenci No: %d, Ad: %s\n", gecici->ogrenciNo, gecici->ad);
        gecici = gecici->next;
    }
}

// �grenci silme fonksiyonu
struct Ogrenci* ogrenciSilSonraki(struct Ogrenci* head, const char* hedefAd) {
    if (head == NULL) {
        printf("Liste bo?. Silme islemi yapilamaz.\n");
        return head;
    }

    struct Ogrenci* gecici = head;
    while (gecici->next != NULL) {
        if (strcmp(gecici->ad, hedefAd) == 0) {
            struct Ogrenci* silinecek = gecici->next;
            gecici->next = silinecek->next;
            free(silinecek);
            printf("%s adly ogrencinin sonraki ogrencisi silindi.\n", hedefAd);
            return head;
        }
        gecici = gecici->next;
    }

    printf("%s adli ogrenci bulunamadi veya listenin sonunda bulunuyor.\n", hedefAd);
    return head;
}

int main() {
    struct Ogrenci* liste = NULL;

    // �grenci kayitlari ekleniyor
    liste = ogrenciEkle(liste, 1, "idil");
    liste = ogrenciEkle(liste, 2, "mert");
    liste = ogrenciEkle(liste, 3, "melek");
    liste = ogrenciEkle(liste, 4, "sarp");

    // �grenci listesini ekrana yazdir
    printf("Ogrenci Listesi:\n");
    ogrenciListesiYazdir(liste);

    // Kullanicidan silinecek �grencinin adini al
    char silinecekAd[100];
    printf("Hangi ogrenciden sonraki ogrenciyi silmek istersiniz? �grenci adini girin: ");
    scanf("%s", silinecekAd);

    // �grenci silme islemi
    liste = ogrenciSilSonraki(liste, silinecekAd);

    // G�ncellenmis �grenci listesini ekrana yazdir
    printf("Guncellenmis Ogrenci Listesi:\n");
    ogrenciListesiYazdir(liste);

    // Bellegi temizle (serbest birak)
    while (liste != NULL) {
        struct Ogrenci* temp = liste;
        liste = liste->next;
        free(temp);
    }

    return 0;
}
