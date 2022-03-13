
# Qt Serial Communication Uygulaması

## Özet

Roket üzerinden bulunan sensörlerden gelen verileri Com port üzerinden alan, işleyen ve Ethernet portu üzerinden gönderen uygulama.
Proje geliştirilirken Qt, test çalışmalarında ise Docklight ve sanal com port kullanılmıştır.


## Proje Detayları
* İlk olarak haberleşmenin yönetilmesi için arayüz üzerinden sender ip, receiver ip ve com
port seçimi almaktadır. Kontrollerin yapılmasının ardından hatalı giriş yoksa başlat butonuna tıklanmasıyla birlikte uygulama çalışmaktadır.

![baslangic1](https://user-images.githubusercontent.com/49278142/158070681-c305261a-3b57-4e8f-a300-a1fb3dfc6778.png)
---
![comportsecim](https://user-images.githubusercontent.com/49278142/158070731-52d77e6f-5fc9-4459-96ec-7a849d5d0786.png)
---
*Uygulama çalıştıktan sonra arayüz aşağıdaki gibi görünmektedir:*

![durdur](https://user-images.githubusercontent.com/49278142/158070826-7ffd4699-ecaa-4987-a425-2709d6c32d6a.png)
---
* Verilerin com port üzerinden alınmasının ardından loglama aşamasına geçilir. Veriler tiplerine göre ayrı **.csv** dosyalarına ayrıştırılır ve sistem saati ve tarihine göre adlandırılan klasörlerin içerisine yerleştirilir.



*Oluşturulan klasörler ve içersine yerleştirilmiş olan csv dosyaları:*

![dosyalar](https://user-images.githubusercontent.com/49278142/158071463-f895e50c-461a-473d-bc6e-e89345a147d5.png)

*Klasörler uygulama başladığında otomatik olarak oluşturulmaktadır. Aynı zamanda arayüz üzerinde bulunan **"new log"** butonu ile de yeni klasör oluşturulabilir.*


