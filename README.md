# Johnson's Algorithm

## Algoritmanın Ne Yaptığı
**Johnson’s algoritması**, tüm düğüm çiftleri arasındaki en kısa yolları bulmak için kullanılan bir algoritmadır. Ağırlıklı ve yönlü grafiklerde çalışır ve negatif ağırlıklı kenarlara sahip grafiklerde de doğru sonuçlar verebilir, ancak **negatif döngüler** içeriyorsa algoritma geçersiz olacaktır. Johnson’s algoritması, temel olarak **Bellman-Ford algoritması** ile başlar ve her düğüm için **Dijkstra algoritması** çalıştırarak en kısa yolları hesaplar.

## Kategorisi
- **Grafik Algoritması**: Bu algoritma, graf teorisi alanında yer alır. Grafiklerin düğümleri ve kenarları arasında en kısa yolu bulma problemini çözer.
- **En Kısa Yol Algoritması**: Johnson’s algoritması, özellikle **tüm çiftler arası en kısa yol** problemine odaklanır ve bu nedenle, **Floyd-Warshall algoritması** ve **Dijkstra algoritması** gibi diğer en kısa yol algoritmalarıyla benzer bir kategoriye girer.

## Çözüm Yaklaşımı
Johnson's algoritması, **Bellman-Ford** ve **Dijkstra algoritmalarının bir birleşimidir** ve özellikle **yeniden ağırlıklandırma** (reweighting) adı verilen bir teknik kullanır. Çözüm şu adımlardan oluşur:

1. **Yeni bir düğüm eklenir**: Orijinal grafın her düğümüne sıfır ağırlıklı kenarlarla bağlanan bir yeni düğüm (genellikle *s* adı verilir) eklenir.
2. **Bellman-Ford algoritması çalıştırılır**: Yeni düğümden tüm diğer düğümlere olan mesafeler hesaplanır. Eğer negatif döngüler varsa algoritma durur.
3. **Kenarlara yeniden ağırlık verilmesi**: Bellman-Ford algoritmasının sonuçları kullanılarak her kenarın ağırlığı yeniden hesaplanır.
4. **Dijkstra algoritması çalıştırılır**: Yeniden ağırlıklandırılmış graf için her düğümden Dijkstra algoritması çalıştırılır.
5. **Sonuçların düzeltilmesi**: Son olarak, elde edilen sonuçlar orijinal grafın ağırlıklarına göre düzeltilir.

Bu yaklaşım, **negatif ağırlıklı kenarları** ve **daha büyük graf yapıları** için verimli bir çözüm sunar.

## Ne Zaman ve Nerede Kullanıldığı
**Johnson's algoritması**, özellikle **tüm çiftler arası en kısa yol** probleminin çözülmesi gerektiği durumlarda kullanılır. Aşağıdaki alanlarda yaygın olarak uygulanır:
- **Harita Servisleri ve Yol Bulma**: Google Maps gibi harita uygulamaları, çok sayıda şehir ve yollar arasında en kısa yolları bulmak için Johnson's algoritmasını kullanabilir.
- **Ulaştırma ve Lojistik Planlaması**: Karayolları, demir yolları, hava yolu taşımacılığı gibi sistemlerde, şehirler arası en kısa yol hesaplamaları ve seyahat süreleri için kullanılır.
- **Ağ Yönlendirme Protokolleri**: Ağ mühendisliği, özellikle **BGP (Border Gateway Protocol)** gibi protokoller, veri paketlerinin ağda en verimli şekilde yönlendirilmesi için Johnson’s algoritmasından yararlanabilir.
- **Negatif Ağırlıklı Kenarlarla Çalışma**: Negatif ağırlıklı kenarlar içeren grafiklerde en kısa yol hesaplaması yaparken Johnson’s algoritması oldukça etkilidir, çünkü Bellman-Ford algoritması negatif ağırlıklı kenarları işler.

## Karmaşıklık Analizi
Johnson's algoritmasının karmaşıklığı, kullanılan veri yapısına ve algoritmaların uygulama biçimine göre değişiklik gösterebilir. Genel karmaşıklık analizi şu şekildedir:

### Zaman Karmaşıklığı:
- **Bellman-Ford algoritması**: Bellman-Ford’un zaman karmaşıklığı, grafın **V** düğüm sayısı ve **E** kenar sayısı ile orantılıdır ve **O(VE)**'dir.
- **Dijkstra algoritması**: Dijkstra algoritması, **binary heap** kullanıldığında her düğüm için **O(V log V)** ve her kenar için **O(E log V)** işlemi gerektirir. Bu nedenle, tüm düğümler için çalıştırıldığında **O(V^2 log V + VE)**'dir.
  
Yani, Johnson’s algoritmasının **toplam zaman karmaşıklığı**, Bellman-Ford ve Dijkstra algoritmalarının birleşiminden dolayı **O(V^2 log V + VE)**'dir.

### Uzay Karmaşıklığı:
- Johnson’s algoritması, grafı ve ara sonuçları depolamak için **O(V^2)** bellek kullanır. Bu, özellikle grafın çok sayıda düğüm ve kenara sahip olduğu durumlarda dikkat edilmesi gereken bir faktördür.

## Algoritmanın Adımları
1. Orijinal grafa **s** adlı yeni bir düğüm eklenir.
2. Bu yeni düğümden diğer tüm düğümlere ağırlığı 0 olan kenarlar eklenir.
3. **Bellman-Ford algoritması**, bu yeni düğümden çalıştırılır ve her düğüme olan mesafeler hesaplanır.
4. Kenarların ağırlıkları, yeniden ağırlıklandırma işlemiyle güncellenir.
5. **Yeni düğüm** ve **kenarları** grafdan kaldırılır.
6. **Dijkstra algoritması** her düğüm için çalıştırılır ve orijinal grafın ağırlıklarıyla düzeltilmiş en kısa yollar elde edilir.

## Kullanım Yerlerine Ait Örnekler
- **Harita ve Navigasyon Uygulamaları**: Google Maps, şehirler arası yolculuk planlaması, ulaşım süreleri ve alternatif rotaların hesaplanması.
- **Ağ Yönlendirme Protokolleri**: İnternet servis sağlayıcıları arasında veri yönlendirme ve paketlerin en verimli yol üzerinden taşınması.
- **Ulaştırma Planlaması**: Lojistik ve taşımacılık firmaları, taşıma araçlarının en kısa yolu takip etmelerini sağlamak amacıyla Johnson’s algoritmasından faydalanabilir.
- **Toptancı ve Perakende Dağıtım Ağı**: Ürünlerin depo ve mağazalar arasında en kısa süre ve maliyetle taşınması.

## Algoritmanın Avantaj ve Dezavantajları

### Avantajları:
- **Negatif Ağırlıklı Kenarları Destekler**: Johnson’s algoritması, negatif ağırlıklı kenarlara sahip grafikleri işler. Bu özellik, bazı diğer en kısa yol algoritmalarında yoktur (örneğin Dijkstra, negatif ağırlıkları kabul etmez).
- **Seyrek Grafiklerde Verimlilik**: Floyd-Warshall algoritması gibi diğer tüm çiftler arası en kısa yol algoritmalarına göre, seyrek graf yapılarında daha verimli çalışır.

### Dezavantajları:
- **Negatif Döngüleri Desteklemez**: Eğer grafda negatif döngüler varsa, algoritma sonuç vermez ve hata verir. Bellman-Ford algoritması bu durumu tespit etse de negatif döngüler algoritmayı geçersiz kılar.
- **Zaman Karmaşıklığı**: Johnson’s algoritmasının zaman karmaşıklığı **O(V^2 log V + VE)**, özellikle yoğun graf yapılarında çok büyük olabilir. Bu nedenle çok büyük veri setlerinde performans problemi yaşanabilir.
- **Yüksek Bellek Kullanımı**: Grafın depolanması ve algoritmanın ara işlemleri için kullanılan bellek miktarı, büyük graf yapılarında önemli olabilir ve belleği zorlayabilir.

## Kaynakça  
- Azgınoğlu, N. (2010). Johnson Algoritması – En Kısa Yol Problemi. *Nuh Azgınoğlu Blog*. Retrieved from https://www.nuhazginoglu.com/2010/12/15/johnson-algoritmasi-en-kisa-yol-problemi-the-shortest-path-problem/  
- Chandnaik, P. (n.d.). Implement Johnson’s algorithm for all-pairs in C++. *CodeSpeedy*. Retrieved from https://www.codespeedy.com/johnsons-algorithm-for-all-pairs-in-cpp/  
- İspiroğlu, M. (2015). Johnson Algoritması Kullanılarak Üretim Planlaması. *YÖK Ulusal Tez Merkezi*. Retrieved from https://tez.yok.gov.tr/UlusalTezMerkezi/tezDetay.jsp?id=LDLKUUgZuCVOTpI8YtNA9w  
- Johnson, D. B. (1977). Efficient algorithms for shortest paths in sparse networks. *Journal of the ACM, 24*(1), 1-13. https://dl.acm.org/doi/10.1145/321992.321996  
- Sanfoundry. (n.d.). C++ Program to Implement Johnson's Algorithm. *Sanfoundry*. Retrieved from https://www.sanfoundry.com/cpp-program-implement-johnsons-algorithm/  
- Şahin, M. (2020). Dijkstra ve Bellman-Ford Algoritmaları Karşılaştırması. *Türkiye Bilgisayar Bilimleri Dergisi, 15*(2), 85-102. https://dergipark.org.tr/tr/download/article-file/263446  
- Google DeepMind. (2025). Gemini AI [Yapay zeka modeli]. Google. https://deepmind.google
