// Sistem Asisten Parkir Otomatis
#include <Wire.h>
#include <LiquidCrystal_I2C.h>
#include <Servo.h>
#include <ESP8266WiFi.h>

// Definisi pin
const int trigPin = D6;
const int echoPin = D7;
const int ledPin = D5;
const int servoPin = D1;

// Membuat objek LCD dengan alamat I2C 0x27 dan ukuran 16 kolom x 2 baris
LiquidCrystal_I2C lcd(0x27, 16, 2);
Servo myServo;

// Fungsi untuk menghitung jarak menggunakan HC-SR04
long getDistance() {
    digitalWrite(trigPin, LOW);
    delayMicroseconds(2);
    digitalWrite(trigPin, HIGH);
    delayMicroseconds(10);
    digitalWrite(trigPin, LOW);
    long duration = pulseIn(echoPin, HIGH);
    long distance = duration * 0.034 / 2;
    return distance;
}

void setup() {
    // Inisialisasi komunikasi serial
    Serial.begin(115200);

    // Inisialisasi LCD
    lcd.init();
    lcd.backlight();

    // Inisialisasi pin
    pinMode(trigPin, OUTPUT);
    pinMode(echoPin, INPUT);
    pinMode(ledPin, OUTPUT);
    myServo.attach(servoPin);

    // Posisi awal
    myServo.write(0);  // Penghalang tertutup
    digitalWrite(ledPin, LOW);  // LED mati
}

void loop() {
    long distance = getDistance();
    Serial.print("Jarak: ");
    Serial.print(distance);
    Serial.println(" cm");

    // Menampilkan jarak pada LCD
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("Jarak: ");
    lcd.print(distance);
    lcd.print(" cm");

    // Mengontrol servo dan LED berdasarkan jarak
    if (distance < 10) {  // Jika objek lebih dekat dari 10 cm
        myServo.write(90);  // Buka penghalang
        digitalWrite(ledPin, HIGH);  // Nyalakan LED
        lcd.setCursor(0, 1);
        lcd.print("Penghalang: BUKA");
    } else {
        myServo.write(0);  // Tutup penghalang
        digitalWrite(ledPin, LOW);  // Matikan LED
        lcd.setCursor(0, 1);
        lcd.print("Penghalang: TUTUP");
    }

    delay(500);  // Jeda selama setengah detik
}
