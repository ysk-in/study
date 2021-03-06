# Model Representation
https://www.coursera.org/learn/machine-learning/lecture/db3jS/model-representation  

## LinearRegression(線形回帰)
* 教師あり学習  
  例えば住宅の価格予測などで使用可能  
  家のサイズ と 価格(答え)のデータセットを与え サイズから価格を予測

## 表記方法(シンボル)について
* 講義内で使用されるシンボルについて
  * m = 訓練サンプル数
  * x = 入力変数(特徴)
  * y = 出力(目標)変数
  * (x, y) = 1件の訓練サンプルに対応
  * (x(i), y(i)) = それぞれx, yのi番目の訓練データに対応

## 訓練セットにより定義されるもの
訓練セット(データセット) を 学習アルゴリズム に入力  
学習アルゴリズム は ある関数(慣習的にh) を出力  

<img src="../../img/01_04_process_learn_a_function.png" width=25%>  

関数hに 家のサイズ(x)を入力することで 価格(y)が推測できる  

### hをどのように表現するか
hΘ(x) = Θ0 + Θ1 * x  
hΘ(x)をh(x)と略記することもある

hΘ(x) = Θ0 + Θ1 * x  
これはLinearRegression(線形回帰)を示す式  
また変数が1つ(x)の線形回帰 = 単回帰  
すべての価格を1つの変数(サイズ)から予測する線形回帰
