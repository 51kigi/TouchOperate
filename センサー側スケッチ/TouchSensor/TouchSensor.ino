//参考サイト
//http://inter-arteq.com/arduino%E3%82%92%E4%BD%BF%E3%81%A3%E3%81%A6%E3%82%BF%E3%83%83%E3%83%81%E3%82%BB%E3%83%B3%E3%82%B5%E3%83%BC/
//http://playground.arduino.cc/Main/CapacitiveSensor?from=Main.CapSense
//要素実験　上記サイトからコードを丸ごと持ってきた

//ライブラリを読み込み
#include<CapacitiveSensor.h>

CapacitiveSensor cs = CapacitiveSensor(13, 12); // inputは13番ピン, outputを12番ピン

void setup() {
  // おまじないと思ってよさそうです。
  // キャリブレーションするための時間とかそういうのだと思います。
  cs.set_CS_AutocaL_Millis(0xFFFFFFFF);
  Serial.begin(9600);
}

void loop() {
  // ここの30はノイズをとる強さと考えればいいと思います。
  // 大きくすればノイズはとれますが、遅くなり、
  // 小さくすれば速くなりますが、あまりノイズはとれません。
  long val = cs.capacitiveSensor(30);

  // 値をシリアルに書き出し
  Serial.print("value:tt");
  Serial.println(val);

  // 放電 シリアルモニターで見やすいようにちょっと長めにしてある（10でも大丈夫）
  delay(100);
 
}

