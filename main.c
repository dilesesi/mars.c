#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    srand(time(NULL)); //rastgele sayı üretmek için
    char zorluk, eylem;
    int gecerli;
    int saglik, enerji, oksijen, su, yedekparca, modul, gun, tur;
    int sans, su_harcama, firtinaTuru, kilitMuhurlu;
    gun = 1; 
    tur = 0;

    do { //zorluk seçimi seçmeyince başa dönüyor
        gecerli = 1;

        printf("Zorluklar:\n");
        printf("Kolay (k, K)\n");
        printf("Orta (o, O)\n");
        printf("Zor (z, Z)\n");
        printf("Zorluk girin: \n");
        scanf(" %c", &zorluk);

        switch (zorluk) { //zorluk başlangıçta değerleri atıyor
            case 'k':
            case 'K':
                printf("Kolay zorluk secildi.\n");
                su = 90;
                saglik = 90;
                enerji = 90;
                oksijen = 90;
                yedekparca = 3;
                modul = 90;
                sans = 30;
                firtinaTuru = 3;
                break;
            case 'o':
            case 'O':
                printf("Orta zorluk secildi.\n");
                su = 70;
                saglik = 70;
                enerji = 70;
                oksijen = 70;
                yedekparca = 1;
                modul = 70;
                sans = 40;
                firtinaTuru = 5;
                break;
            case 'z':
            case 'Z':
                printf("Zor zorluk secildi.\n");
                su = 50;
                saglik = 50;
                enerji = 50;
                oksijen = 50;
                yedekparca = 0;
                modul = 50;
                sans = 50;
                firtinaTuru = 7;

                break;
            default:
                printf("Gecersiz secim, tekrar deneyin.\n");
                gecerli = 0;
                break;
        }
    } while (!gecerli);

    do {
        printf("Gun: %d ne yapcaksin?\n\n", gun);
        printf("g: Gezinti\n");
        printf("o: Oksijen arttirma\n");
        printf("t: Tamir\n");
        printf("u: uyu\n");
        printf("k: kum firtinasi\n");
        printf("h: hava kilidi\n");
        printf("d: durum raporu\n");
        printf("q: cikis\n\n");
        scanf(" %c", &eylem);

        switch (eylem) {
            case 'g':
            case 'G':
                oksijen -= 10;
                enerji -= 15;
                if (rand() % 100 < sans) {
                    yedekparca++;
                    printf("Yedek parca buldun!\n");
                } else {
                    printf("Bu kez yedek parca bulamadin.\n");
                };
                if (enerji > 40 && oksijen > 30) {
                    su += 20;
                } 
                else {
                    su = su;
                }
                if (rand() % 100 < 10 || modul < 30) {
                    saglik -= 30;
                    printf("hasar gordun!\n");
                }
                tur += 1;
                break;

            case 'o':
            case 'O':
                printf("ne kadar su harcayacaksin?\n");
                scanf(" %d", &su_harcama);
                if (su_harcama % 2 == 0) {
                    su -= su_harcama;
                    su_harcama /= 2;
                    su_harcama *= 3;
                    oksijen += su_harcama;
                    enerji -= 10;
                    tur += 1;
                    printf("oksijen arttirildi. Su azaldi.\n");
                } else {
                    su_harcama--;
                    su++;
                    su -= su_harcama;
                    su_harcama /= 2;
                    su_harcama *= 3;
                    oksijen += su_harcama;
                    enerji -= 10;
                    tur += 1;
                    printf("oksijen arttirildi. Su azaldi.\n");
                }
                break;

            case 't':
            case 'T':
                if (modul > 70) {
                    if (yedekparca >= 1) {
                        modul += 30;
                        yedekparca--;
                        tur++;
                        printf("modul tamir edildi.\n");
                    } else {
                        printf("yedek parca yok, tamir edilemedi.\n");
                    }
                } else if (modul <= 70 && modul > 30) {
                    if (yedekparca >= 2) {
                        modul += 60;
                        yedekparca -= 2;
                        tur++;
                        printf("modul tamir edildi.\n");
                    } else {
                        printf("yedek parca yeterli degil, tamir edilemedi.\n");
                    }
                } else if (modul <= 30) {
                    if (yedekparca >= 3) {
                        modul += 90;
                        yedekparca -= 3;
                        tur++;
                        printf("modul tamir edildi.\n");
                    } else {
                        printf("yedek parca yeterli degil, tamir edilemedi.\n");
                    }
                } else {
                    printf("modul tamir edilemedi.\n");
                }
                break;

            case 'd':
            case 'D':
                if (saglik < 30) {
                    printf("Saglik cok dusuk.\n");
                } else if (su < 30) {
                    printf("Su cok dusuk.\n");
                } else if (enerji < 30) {
                    printf("Enerji cok dusuk.\n");
                } else if (oksijen < 30) {
                    printf("Oksijen cok dusuk.\n");
                } else if (modul < 30) {
                    printf("Modul cok dusuk.\n");
                } else {
                    printf("tum degerler normal.\n");
                }
                break;

            case 'u':
            case 'U':
                if (oksijen >= 20) {
                    oksijen -= 10;
                    enerji += 50;
                    saglik += 10;
                    gun++;
                    tur = 0;
                } else {
                    enerji += 50;
                    oksijen -= 10;
                    saglik -= 20;
                    gun++;
                    tur = 0;
                }
                break;

            case 'k':
            case 'K': {
                int hasar_alinan_tur, top_oksijen_kaybi, top_saglik_kaybi;
                hasar_alinan_tur = top_oksijen_kaybi = top_saglik_kaybi = 0;

                printf("Kum firtinasi basladi! %d tur surecek.\n", firtinaTuru);

                for (int i = 1; i <= firtinaTuru; i++) {
                    int zar = rand() % 100;
                    int carpan = (i % 2 == 0) ? 2 : 1; // Çift turlarda hasar 2 katı

                    printf("\n[Tur %d] Zar: %d / Esik: 50 -> ", i, zar);

                    if (zar < 50) {
                        printf("HASAR ALINDI!\n");
                        hasar_alinan_tur++;

                        // 1. Sağlık ve Modül Hasarı Etkisi
                        int canKaybi = 5 * carpan;
                        int hasarArtisi = 6 * carpan;
                        saglik -= canKaybi;
                        modul -= hasarArtisi;
                        top_saglik_kaybi += canKaybi;

                        // 2. Oksijen Sızıntısı Kontrolü (Mühürlüyse continue ile atla)
                        if (kilitMuhurlu == 1) {
                            printf("  -> Hava kilidi muhurlu oldugu icin oksijen sizintisi onlendi!\n");
                            if (saglik <= 0 || oksijen <= 0) break;
                            continue;
                        }

                        int oksijenKaybi = 7 * carpan;
                        oksijen -= oksijenKaybi;
                        top_oksijen_kaybi += oksijenKaybi;
                    } else {
                        printf("korundunuz\n");
                    }

                    printf("\n--- FIRTINA OZETI ---\n");
                    printf("Hasar Alinan Tur Sayisi : %d / %d\n", hasar_alinan_tur, firtinaTuru);
                    printf("Toplam Kaybedilen Saglik: %d\n", top_saglik_kaybi);
                    printf("Toplam Kaybedilen Oksijen: %d\n", top_oksijen_kaybi);

                    tur++; // Geçerli komut olduğu için tur sayacını artır
                }
                break;
            }

            case 'h':
            case 'H':
            {

                // Zaten mühürlüyse uyarı verip çıkabilirsin (İsteğe bağlı)
            if (kilitMuhurlu == 1) {
                printf("\nHava kilidi zaten muhurlu!\n");
                break;
            }

                // Enerji kontrolü (En az 1 deneme için 5 enerji gerekebilir)
            if (enerji < 5) {
                printf("\nYetersiz enerji! Hava kilidi terminalini calistirmak icin en az 5 enerji gerekli.\n");
                break;
            }

                // O anki güne göre şifre türetme (A-Z arası)
            char dogruSifre = 'A' + (gun % 26);
            char tahmin;
            int deneme = 0;
            int maxDeneme = 3;

                printf("\n--- HAVA KILIDI GUVENLIK TERMINALI ---\n");
                printf("Ipucu: Sifre, alfabede 'A' harfinden bugunun gun sayisi (%d) kadar ilerideki harftir.\n", gun);

            do {
                printf("Sifreyi girin (Kalan hak: %d): ", maxDeneme - deneme);
                scanf(" %c", &tahmin);

                // Küçük harf girildiyse büyük harfe çevir (ASCII farkı: 32)
            if (tahmin >= 'a' && tahmin <= 'z') {
                tahmin = tahmin - 32;
            }

            deneme++;

            if (tahmin == dogruSifre) {
                printf("SIFRE DOGRU! Hava kilidi basariyla muhurlendi.\n");
                kilitMuhurlu = 1;
            } else {
                enerji -= 5;
                if (enerji < 0) enerji = 0;
                
                printf("HATALI SIFRE!");
                 if (tahmin < dogruSifre) {
                    printf("Ipucu: Alfabede daha ILERI git.\n");
                } else {
                    printf("Ipucu: Alfabede daha GERI git.\n");
                }
            }
            // Tek mantıksal ifadede hem şifre yanlışlığını hem deneme hakkını kontrol et
            } while (tahmin != dogruSifre && deneme < maxDeneme);

            // 3 deneme sonunda hala mühürlenemediyse ceza uygula
            if (kilitMuhurlu == 0) {
                printf("\nALARM! 3 deneme hakki doldu. Kilit sistemi arizalandi.\n");
                modul -= 20;
            }

            tur++; // Geçerli komut olduğu için tur sayacını artır
            break;
            }

            case 'q':
            case 'Q':
                printf("Oyun sonlandirildi.\n");
                return 0;
                break;

            default:
                printf("Gecersiz islem.\n");
                break;
        }
        if (tur % 3 == 0 && tur != 0) {//her 3 turda bir yeni gün başlıyor
            oksijen -= 10;
            saglik += 10;
            su += 10;
            gun += 1;
            tur = 0;
            printf("yeni gun\n");
        }

        if (saglik <= 0 || enerji <= 0 || oksijen <= 0 || su <= 0 || modul <= 0) {
            printf("Oyun bitti. Hayatta kalamadiniz.\n");
            return 0;
        }

        if (gun >= 15) {
            printf("Tebrikler! 15 gunu tamamladiniz ve hayatta kaldiniz.\n");
            return 0;
        }

        if (saglik > 100) { //değerlerin 100ü geçmemesi için
            saglik = 100;
        }

        if (enerji > 100) {
            enerji = 100;
        }

        if (oksijen > 100) {
            oksijen = 100;
        }

        if (su > 100) {
            su = 100;
        }

        if (modul > 100) {
            modul = 100;
        }

    } while (gun < 16);

    return 0;
}