# soal-shift-sisop-modul-2-F08-2021 

## Anggota Kelompok :
Anggota | NRP
--------|-------------
M. Rayhan Raffi P. | 05111940000110
M. Akmal Joedhiawan | 05111940000125
Nur Moh. Ihsanuddien | 05111940000142

## Penjelasan NO 1
**a** Dikarenakan Stevany sangat menyukai huruf Y, Steven ingin nama
folder-foldernya adalah Musyik untuk mp3, Fylm untuk mp4, dan Pyoto untuk jpg

```
char *argv[] = {"mkdir", "-p", "Musyik","Fylm","Pyoto" ,NULL};
execv("/usr/bin/mkdir", argv);}
```
Keterangan : 
- Pada proses child paling awal dilakukan dengan menggunakan execv untuk mengeksekusi sesuai dengan didalam argv yaitu membuat folder Fylm,Pyoto, dan Musyik

**b** untuk musik Steven mendownloadnya dari link di bawah, film dari link di bawah lagi, dan foto dari link
dibawah juga :).


```
#Foto
	char *argv[] = {"wget","-q","--no-check-certificate","https://drive.google.com/uc?id=1FsrAzb9B5ixooGUs0dGiBr-rC7TS9wTD&export=download","-O","Foto_for_Stevany.zip", NULL};
  execv("/usr/bin/wget",argv);
```

```
#Film
char *argv[] = {"wget","-q","--no-check-certificate","https://drive.google.com/uc?id=1ktjGgDkL0nNpY-vT7rT7O6ZI47Ke9xcp&export=download","-O","Film_for_Stevany.zip", NULL};
execv("/usr/bin/wget", argv);
```

```
#Musik
char *argv[] = {"wget","-q","--no-check-certificate","https://drive.google.com/uc?id=1ZG8nRBRPquhYXq_sISdsVcXx5VdEgi-J&export=download","-O","Musik_for_Stevany.zip", NULL};
execv("/usr/bin/wget", argv);
```

Keterangan : 
-Pada tiap-tiap perintah menggunakan execv untuk mengeksekusi dengan isi dalam char * argv sesuai yang telah diberikan di soal untuk mendonwload konten berformat zip

**c**Steven tidak ingin isi folder yang dibuatnya berisikan zip, sehingga perlu
meng-extract-nya setelah didownload serta

```
#Foto
char *argv[] = {"unzip","Foto_for_Stevany.zip","-d","/home/ihsannm/soal-shift-sisop-modul-2-F08-2021/soal1", NULL};
execv("/usr/bin/unzip", argv);
```

```
#Film
char *argv[] = {"unzip","Film_for_Stevany.zip","-d","/home/ihsannm/soal-shift-sisop-modul-2-F08-2021/soal1", NULL};
execv("/usr/bin/unzip", argv);
```

```
#Musik
char *argv[] = {"unzip","Musik_for_Stevany.zip","-d","/home/ihsannm/soal-shift-sisop-modul-2-F08-2021/soal1", NULL};
execv("/usr/bin/unzip", argv);
```
Keterangan :
- Unzip dilakukan dengan menggunakan execv untuk mengeksekusi perintah dalam argv dimana unzip file (namafile).zip dan dilakukan di direktori yang dimasukkan 

## Penjelasan NO 2 

## Penjelasan NO 3 

