# mca_aveに入っているプログラムの実行について
## 環境
WSL(個人ユーザーで実行), VScode, gcc
## make で実行してみた
- 分割コンパイルが必要
- Makefile があるので terminal で 
    ```
    $make 
    ```
    としてみたところ、次のエラーが出た。
    ```
    /usr/bin/ld: create_cdf.o:(.bss+0x0): multiple definition of `ave_EmxNum'; mca_ave.o:(.bss+0x0): first defined here
    /usr/bin/ld: cannot find -lcdf: No such file or directory
        collect2: error: ld returned 1 exit status
    make: *** [Makefile:7: bnd] Error 1
    ```

## 各エラーの対処
- /usr/bin/ld: create_cdf.o:(.bss+0x0): multiple definition of `ave_EmxNum'; mca_ave.o:(.bss+0x0): first defined here について
    - mca_ave.cの34行目をコメントアウトしたらコンパイルが通った。
    ```c
    long ave_EmxNum;
    ```
    ```c
    // long ave_EmxNum;
    ```

- '/usr/bin/ld: cannot find -lcdf: No such file or directory'について
    - cdf libarary を[ダウンロード](https://cdf.gsfc.nasa.gov/html/sw_and_docs.html)
    - ダウンロードしたファイルを解凍して、中にある README.install に従ってインストール.  
    インストール先は/usr/localの下  
    - ここまでやってコンパイルを試してみた。  
    ```
    $ gcc file.c -lcdf  
    ```
    同じエラーが出た。

    - ライブラリ本体は .soとか .aとかの拡張子がついてるらしいのでlocate コマンドで探した。  
    ```
    $ locate libcdf.so
    ```
    - ここにあるらしい  
    ```
    /home/onosawa/cdf38_1-dist/src/lib/libcdf.so  
    /usr/local/cdf/lib/libcdf.so
    ```
    - Makefile内で-L オプションでライブラリを探しに行く場所を指定したらコンパイルは通った。  
    ```
    変更前  
    gcc -o $(PROGRAM) $(OBJS) -lcdf -lm -lc
    変更後  
    gcc -o $(PROGRAM) $(OBJS) -lcdf -lm -lc -L /usr/local/cdf/lib/
    ```
    - makeしてできた実行ファイルbndを実行した(README参照)  
    実行例
    ```
    $ ./bnd 1990 01 01 8
    ```
    - エラー
    ```
    ./bnd: error while loading shared libraries: libcdf.so: cannot open shared object file: No such file or directory
    ```
    ライブラリが見つからないみたい。
    - パスを追加
    ```
    export LD_LIBRARY_PATH=$LD_LIBRARY_PATH:/usr/local/cdf/lib/
    ```
    エラーが消えた。
