# 🚀 Mars Kolonisi Yaşam Destek Simülatörü

Bu proje, C programlama dilinin temel yapıları kullanılarak geliştirilmiş, metin tabanlı bir hayatta kalma ve kaynak yönetimi simülasyonudur. Oyuncu, Mars'taki bir araştırma istasyonunda tek başına kalan bir mühendisi yöneterek kurtarma ekibi gelene kadar **15 gün** boyunca hayatta kalmaya çalışır.

---

## 📋 Proje Özellikleri ve Oyun Mekaniği

Simülasyon, oyuncunun kaynaklarını dengede tutması ve rastgele gelişen olaylara karşı stratejik kararlar alması üzerine kuruludur:

* **Zorluk Seviyeleri:** Oyun başında `K` (Kolay), `N` (Normal) ve `Z` (Zor) seçeneklerinden biri belirlenir. Zorluk seviyesi başlangıç kaynaklarını ve olay eşiklerini doğrudan etkiler.
* **Dinamik Zaman Akışı:** Geçerli her komut 1 tur ilerletir (`D` ve geçersiz komutlar hariç). Her **3 turda bir** yeni bir gün başlar; gün değişimlerinde oksijen tüketimi gerçekleşir ve modül hasarı kritik seviyedeyse sağlık kaybı yaşanır.
* **Rastgelelik Sistemi:** Tüm keşif, hasar ve olay kontrolleri `srand(time(NULL))` ve `rand() % 100` altyapısıyla eşik değer karşılaştırmasına dayanır.
* **Sınırlandırma ve Güvenlik:** Sağlık, enerji, oksijen ve modül hasarı değerleri her işlem sonrasında `0 - 100` aralığında tutulur.

---

## 🎮 Komut Listesi

Oyun içi komutlar büyük/küçük harf duyarsızdır (`switch-case` fall-through yapısı ile):

| Komut | İşlev | Açıklama |
| :---: | :--- | :--- |
| **`G`** | **Keşif Görevi** | Enerji ve oksijen harcayarak istasyon dışında su veya yedek parça arar. Yaralanma riski taşır. |
| **`O`** | **Oksijen Üret** | Depodaki suyu (her 2 birim suya karşılık 3 birim oksijen) ve enerjiyi kullanarak oksijen üretir. |
| **`T`** | **Tamir Et** | Yedek parça kullanarak mevcut modül hasarını (hafif, orta, ağır kademelerine göre) onarır. |
| **`D`** | **Durum Raporu** | Mevcut kaynakları, gün/tur bilgisini ve kritik seviye uyarılarını listeler (tur harcamaz). |
| **`U`** | **Uyu / Dinlen** | Enerji ve sağlık yeniler; ancak oksijen kritik seviyedeyse sağlık kaybına yol açar. |
| **`K`** | **Kum Fırtınası** | Zorluk seviyesine göre belirlenen tur boyunca süren fırtına simülasyonunu başlatır (`for` döngüsü). |
| **`H`** | **Hava Kilidi** | Gün sayısına bağlı dinamik ASCII şifresini 3 denemede çözerek kilidi mühürler (`do-while` döngüsü). |
| **`Q`** | **Çıkış** | Simülasyonu sonlandırır ve sonuç/puan raporunu ekrana yazdırır. |

---

## 🛠️ Kullanılan C Yapıları

* **Karar Yapıları (`switch-case`, `if-else if-else`):** Zorluk seçimi, komut yönlendirmesi ve hasar kademelerinin değerlendirilmesi.
* **Döngüler (`do-while`, `for`):** Ana oyun döngüsü, sınırlı denemeli şifre doğrulama ekranı ve çok turlu kum fırtınası simülasyonu (`break` ve `continue` kontrol ifadeleriyle).
* **Aritmetik ve Mantıksal Operatörler:** Mod (`%`) operatörü ile çift tur hasar çarpanı, su dönüşüm artığı ve gün/tur takibi; ASCII karakter aritmetiği ile dinamik şifre üretimi.

---

## ⚙️ Kurulum ve Çalıştırma

Projeyi yerel bilgisayarınızda derleyip çalıştırmak için bir C derleyicisine (GCC vb.) ihtiyacınız vardır.

1. Depoyu bilgisayarınıza klonlayın:
   ```bash
   git clone [https://github.com/dilesesi/mars.c.git](https://github.com/dilesesi/mars.c.git)
   cd mars.c
