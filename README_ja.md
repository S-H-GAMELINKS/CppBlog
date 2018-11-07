# CppBlog

## 言語

[English](./README.md)

## 概要

SPAなブログアプリ。

C++ Webフレームワーク：[Luna](https://github.com/DEGoodmanWilson/luna) &[Vue.js](https://github.com/vuejs/vue) & [Webpack](https://github.com/webpack/webpack) & [FireBase](https://firebase.google.com) などを使用しています

## ビルド

### CppBlogを動かす

まず, `git clone `

```
git clone https://github.com/S-H-GAMELINKS/CppBlog.git
```

CppBlogディレクトリまで移動

```
cd CppBlog
```

Conanを使い、依存関係をインストール。
その後、ビルド

```
conan install . --profile clang 
conan build .
```

`assets`ディレクトリに移動し、`index.js`をビルド。

```
cd assets
yarn install
yarn build
```

最後に、以下のコマンドでサーバーが立ち上がる

```
cd .. && ./bin/awesomesauce
```

## ライセンス
[MIT](./LICENSE)
