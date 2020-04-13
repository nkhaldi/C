/*
 * Условие:
 *    В небоскребе n этажей. Известно, что если уронить стеклянный шарик с этажа номер p,
 *    и шарик разобьется, то если уронить шарик с этажа номер p+1, то он тоже разобьется.
 *    Также известно, что при броске с последнего этажа шарик всегда разбивается.
 *    Вы хотите определить минимальный номер этажа, при падении с которого шарик разбивается.
 *    Для проведения экспериментов у вас есть два шарика. Вы можете разбить их все,
 *    но в результате вы должны абсолютно точно определить этот номер.
 *    Определите, какого числа бросков достаточно, чтобы заведомо решить эту задачу.
 * Формат входных данных:
 *    Программа получает на вход количество этажей в небоскребе.
 * Формат выходных данных:
 *    Требуется вывести наименьшее число бросков, при котором можно всегда решить задачу.
 * Примечание:
 *    Комментарий к первому примеру. Нужно бросить шарик со 2-го этажа.
 *    Если он разобьется, то бросим второй шарик с 1-го этажа,
 *    а если не разобьется - то бросим шарик с 3-го этажа.
 * Подсказки:
 *    1. Как следует действовать, если шарик был бы только один?
 *    2. Пусть шариков два и мы бросили один шарик с этажа номер k.
 *    Как мы будем действовать в зависимости от того, разобьется ли шарик или нет?
 *    3. Пусть f(n) - это минимальное число бросков, за которое можно определить
 *    искомый этаж, если бы в небоскребе было n этажей.
 *    Выразите f(n) через значения f(a) для меньших значений a.
 */

#include <iostream>

using namespace std;

int sum(int);
int min(int);

int main() {
    int n;
    cout << "Enter the hight of the building: ";
    cin >> n;
    n--;
    cout << "The aswer is " << min(n) << endl;
    return 0;
}

int sum(int n) {
    if (n == 0)
        return 0;
    return n + sum(n - 1);
}

int min(int n) {
    int i = 1;
    while (sum(i) < n) 
        i++;
    return i;
}
