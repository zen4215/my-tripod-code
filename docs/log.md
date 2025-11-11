# 開発記録

## 前提

機体はESP32マイコンとKRS3304R2サーボモータ5個3脚で構成される。コントローラにはPS4コントローラを使用している。

[ソースコード](https://github.com/akatdesign/tripod-passive-wheels)には定数化されていないマジックナンバーがいたるところに使われており、共通化可能と思われる部分も散見され、改善の余地があると考える。

コントローラの操作によってなめらかに操作し、より安定した移動を可能な状態にすることを目標とする。

## 開発環境

- Windows11
- Visual Studio Code (PlatformIO)
- Arduino Framework

## ライブラリ

### KRS3304R2サーボモータ用

KRS3304R2を動かすため、オリジナルのソースコードに"IcsClass_V210"というライブラリを見つけた。KRS3304R2の[製品ページ](https://kondo-robot.com/product/krs-3304r2-ics)を探したところ、[Arduino用のライブラリ](https://kondo-robot.com/faq/ics-library-a3)が公開されており、配布されていたZipファイルを解凍すると"IcsClass_V300"という恐らくバージョン違いのライブラリを見つけたため、それを利用することにした。

### PS4コントローラ用

以前に使用したことのあるライブラリを使用することを考えたが、レポジトリを見つけられなかったためオリジナルと同じ[ライブラリ](https://github.com/jvpernis/esp32-ps3)を使用することにした。本来esp-idf用のライブラリだが、Arduinoもサポートされている。

## 使用機器/ライブラリの仕様

### IcsClass_V300

#### 初期設定

```cpp
#include <IcsHardSerialClass.h>

const byte EN_PIN = 2;        //Arduinoに接続したenableピンのピン番号
const long BAUDRATE = 115200; //サーボの通信速度
const int TIMEOUT = 1000;     //サーボとのシリアル通信に設定する応答待ち時間

//インスタンス＋ENピン(2番ピン)およびUARTの指定
//ボードに接続しているシリアルポートに合わせて&Serialを変更してください。
//(&Serial / &Serial1 / &Serial2...)
IcsHardSerialClass krs(&Serial1,EN_PIN,BAUDRATE,TIMEOUT);
```

#### 関数

```cpp
krs.begin(); //in setup()
krs.setPos(int id, int degree); //set servo position
krs.setStrc(int id, int num); //サーボの硬さ。numが小さいほど柔らかい。とりあえず50。
```

### KRS3304R2

可動域±135°(7500±4000)
