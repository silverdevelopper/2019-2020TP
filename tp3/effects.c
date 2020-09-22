#include "effects.h"

/*
 * Parametre olarak aldigi piksel dizisindeki her bir elemana 
 * rastgele olarak gurultu ekler. 
 * Input: pixels : piksel degerleri iceren dizi 
 *        width  : dizinin satirm sayisi
 *        height : dizinin sutun sayisi
 * Output : void
 * 
 */
void effect_random_noise(unsigned char *pixels, int width, int height) {
    int nr_noisy_pixel = (width * height) / 5; // %5 oraninda noise ekle
    int i;
    // Dizideki elemanlarin %5 ine rasgele secerek 
    // gurultu ekler
    for (i = 0; i < nr_noisy_pixel; ++i ) {
        int which_pixel = (rand() % (width * height));
        pixels[which_pixel] = (rand() % 256);
    }
}

/*
 * Fotografa smooth efektini ekler. 
 * Parametre olarak piksel degerlerini icere dizi 
 * ve bu dizinin boyutlarını alır.
 * Input: pixels : piksel degerleri iceren dizi 
 *        width  : dizinin satirm sayisi
 *        height : dizinin sutun sayisi
 * Output : void
 */
void effect_smooth(unsigned char *pixels, int width, int height) {
    int i;
    // Her bir piksel degeri icin 
    for (i = 0; i < width * height -1; ++i) {
        // Yanyana iki degerin ortalamasını alır ve 0-255 aralıgına 
        // gore dengeler.
        pixels[i] = ((pixels[i] + pixels[i+1]) / 2) % 256;
    }
}

/* Invert efekti her pikselin degerinin tumleyenini o pikselin
 * yeni degeri olarak belirler.
 * Input: pixels : piksel degerleri iceren dizi 
 *        width  : dizinin satirm sayisi
 *        height : dizinin sutun sayisi
 * Output : void
 */
void effect_invert(unsigned char *pixels, int width, int height) {
    int i;
    // TODO: Her bir piksel degerini tumleyen olarak degistiren
    for (i=0; i<width*height; i++) {
        pixels[i]=255-pixels[i];
    }
    // fonksiyonu yaziniz.
    // Alistirma 3.a     
}

/* Belirlenen bir esik degerin altinda kalan pikselleri siyah,
 * uzerinde kalanlari ise beyaz yaparak 2 renkli bir resim olusturur.
 * Input: pixels : piksel degerleri iceren dizi 
 *        width  : dizinin satirm sayisi
 *        height : dizinin sutun sayisi
 *        threshold: esik degeri
 * Output : void
 */
void effect_threshold(unsigned char *pixels, int width, int height, int threshold) {
    int i;
    // TODO: Her bir pikseli kontrol eder.
    // Deger thresholdan buyuk ise beyaz, degilse siyah olarak 
    // degerini gunceller.
    // Alistirma 3.b
    for (i=0; i<width*height; i++) {
        if (pixels[i]>threshold) {
            pixels[i]=255;
        }else if(pixels[i]<threshold)
            pixels[i]=0;
       
    }
}

// Alistirma 3.c

void effect_myef(unsigned char *pixels, int width, int height, int plus) {
    int i;
    for (i=0; i<width*height; i++) {
        if (pixels[i]+plus<255) 
            pixels[i]+=plus;
    }
}
