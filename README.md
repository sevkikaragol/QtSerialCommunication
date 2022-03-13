
# Qt Serial Communication Uygulaması

## Özet

Roket üzerinde bulunan sensörlerden gelen verileri Com port üzerinden alan, Ethernet portu üzerinden gönderen ve aynı zamanda gelen verileri parçalayarak loglama işlemi yapan uygulama.

Proje geliştirilirken **Qt**, test çalışmalarında ise **Docklight ve sanal com port** kullanılmıştır.


## Proje Detayları
* İlk olarak haberleşmenin yönetilmesi için arayüz üzerinden sender ip, receiver ip ve com port bilgileri alınmaktadır. Kontrollerin yapılmasının ardından hatalı giriş yoksa başlat butonuna tıklanmasıyla birlikte uygulama çalışmaktadır.

* Verilerin com port üzerinden alındıktan sonra Ethernet portu üzerinden gönderme işlemine başlanmaktadır. Ayrıca alınan veriler üzerinde loglama işlemi de yapılmaktadır.Veriler tiplerine göre ayrı **.csv** dosyalarına ayrıştırılmaktadır, sistem saati ve tarihine göre adlandırılan klasörlerin içerisine yerleştirilmektedir.

*Klasörler uygulama başladığında otomatik olarak oluşturulmaktadır. Aynı zamanda arayüz üzerinde bulunan **"new log"** butonu ile de yeni klasör oluşturulabilmektedir.*

___

### Proje Arayüz Görselleri


<img src="https://user-images.githubusercontent.com/49278142/158070681-c305261a-3b57-4e8f-a300-a1fb3dfc6778.png" width="500" height="200">

<img src="https://user-images.githubusercontent.com/49278142/158070731-52d77e6f-5fc9-4459-96ec-7a849d5d0786.png" width="500" height="200">

*(Uygulama başlatılmadan önce karşılaşılan arayüz)*


<img src="https://user-images.githubusercontent.com/49278142/158072871-e187ec5e-a2eb-4699-bb33-5adb308cef69.png" width="400" height="150">

*(Eksik veya hatalı bilgi uyarıları)*



<img src="https://user-images.githubusercontent.com/49278142/158070826-7ffd4699-ecaa-4987-a425-2709d6c32d6a.png" width="500" height="200">

*(Uygulamanın başlatılmasından sonra güncellenen arayüz)*

--------

### Proje Çıktıları

<img src="https://user-images.githubusercontent.com/49278142/158071463-f895e50c-461a-473d-bc6e-e89345a147d5.png" width="400" height="250">

*(Oluşturulan klasörler ve içersine yerleştirilmiş olan csv dosyaları)*





