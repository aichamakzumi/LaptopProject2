#include <iostream>
#include <windows.h>
#include "CPU.h"
#include "SSD.h"
#include "VideoCard.h"
#include "RAM.h"
#include "Laptop.h"

using namespace std;

int main()
{
    SetConsoleCP(65001);
    SetConsoleOutputCP(65001);

    cout << "Кількість ноутбуків на початку: " << Laptop::getLaptopCount() << endl << endl;

    CPU cpu1("Intel Core i7-13700H", 5.0, 14);
    SSD ssd1("Samsung 980 Pro", 1000);
    VideoCard gpu1("NVIDIA RTX 4070", 8);
    RAM ram1("DDR5", 32);

    CPU cpu2("AMD Ryzen 7 7840HS", 5.1, 8);
    SSD ssd2("Kingston NV2", 512);
    VideoCard gpu2("AMD Radeon RX 7600M", 8);
    RAM ram2("DDR5", 16);

    Laptop laptop1("ASUS ROG Strix", 68500, "Сірий", cpu1, ssd1, gpu1, ram1);
    cout << "Створено оригінальний ноутбук (к-сть: " << Laptop::getLaptopCount() << "):" << endl;
    laptop1.Print();
    cout << endl;

    Laptop laptop2("Lenovo Legion", 54000, cpu2, ssd2, gpu2, ram2);
    cout << "Створено ноутбук через делегований конструктор (к-сть: " << Laptop::getLaptopCount() << "):" << endl;
    laptop2.Print();
    cout << endl;

    cout << "--- Демонстрація конструктора копіювання ---" << endl;
    Laptop laptopCopy(laptop1); 
    cout << "Створено копію першого ноутбука (к-сть: " << Laptop::getLaptopCount() << "):" << endl;

    laptopCopy.setName("ASUS ROG Strix (Копія)");
    laptopCopy.setColor("Білий");
    laptopCopy.Print();
    cout << endl;

    cout << "--- Перевірка конструктора копіювання для SSD ---" << endl;
    SSD ssdCopy = ssd1; 
    ssdCopy.setModel("Samsung 980 Pro (Копія)");
    ssdCopy.Print();
    cout << endl;

    laptop2.setPrice(52000);
    laptop2.setColor("Синій");
    laptop2.setSSD(ssdCopy);

    cout << "Оновлені дані для Lenovo після роботи аксесорів:" << endl;
    laptop2.Print();
    cout << endl;

    cout << "Загальна кількість ноутбуків у системі: " << Laptop::getLaptopCount() << endl;

    return 0;
}
