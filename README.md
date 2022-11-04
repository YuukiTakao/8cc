# Cコンパイラ作成

> https://www.sigbus.info/compilerbook#

こちらのブログを参考にCコンパイラを作成する

## 動作環境としてdockerコンテナを準備する

### 前提
- docker, docker-composeが動作する環境を用する

### コンテナ起動手順
1. `$ git clone git@github.com:YuukiTakao/9cc.git 9cc && cd 9cc`
2. 環境変数の定義。現状作業ディレクトリの定義のみ
   1. `$ echo "PROJECT_PATH=$PWD" > .env`
3. コンテナのビルド、起動
   1. `$ docker-compose up -d`
4. コンテナにログイン
   1. `$ docker exec -it 9cc bash`
