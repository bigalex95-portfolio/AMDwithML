# Android Malware Detection System

Ocak 2019 - Haziran 2019 , Akademik Tez Çalışması

Ekip: Alibek Erkabayev , Fatih Çomak

Danışman: Arş.Gör. Alper Eğitmen

Literatür araştırmaları yapıldıktan sonra Android kötü amaçlı yazılımları sınıflandırmak ve kategorize etmek için makine öğrenmesini kullanan, statik opcode analizine dayalı bir yaklaşım sunuldu. Bu yaklaşımda Word embedding yönteminin Word2Vec senaryosuyla CBOW modeli ile GloVe yöntemi kullanıldı. Kelime vektörleri üzerinden gerçeklendi.
Teknoloji olarak C++, Python dilleri ile Weka kullanıldı. Veri işlenmesini kolaylaştırmak ve boyut azaltmak için hashleme yapıldı. 70%'i train için kullanılan data Weka algoritmalarıyla test edilerek Benign, Malware aileleri kategorilendirildi. Sonuç olarak CBOW için 91,32%, GloVe için 92,12% başarı elde edildi.

![Alt text](dataflowofapp.jpg?raw=true "Optional Title")


## Steps Of Using Codes

1. Add dataset to current folder

2. compile and run codes in gettingFileList folder

3. compile and run codes in preprocessing folder

4. compile and run codes in generatingCorpus folder

5. compile word2vec and glove applications on linux with makefile and get vectors from corpus

6. compile and run codes in featureGeneration folder using necessary vector file generated 5th step

7. compile and run codes in creating.arffFile folder

8. generated train.arff and test.arff use in weka for classification
