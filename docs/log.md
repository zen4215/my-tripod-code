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

KRS3304R2を動かすため、オリジナルのソースコードに"IcsClass_V210"というライブラリを見つけた。KRS3304R2の[製品ページ](https://kondo-robot.com/product/krs-3304r2-ics)を探したところ、[Arduino用のライブラリ](https://kondo-robot.com/faq/ics-library-a3)が公開されており、配布されていたZipファイルを解凍すると"IcsClass_V300"という恐らくバージョン違いのライブラリを見つけたため、それを利用することにした。
