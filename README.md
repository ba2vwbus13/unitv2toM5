UNIT V2とM5Stackをつなげる

UnitV2はブラウザからobject recognitionを実行

UARTから勝手にJsonファイル（認識結果）が出力

Jsonファイルをパースして認識した物体をM5Stackのディスプレイに表示

<img width="301" alt="image" src="https://github.com/user-attachments/assets/01803985-88c3-4b4b-a262-e00a3e0590e3">

複数の物体が検出された場合

1人でも人が検出されたら人とする

それ以外が検出されたら一番最後に検出された物体とする
