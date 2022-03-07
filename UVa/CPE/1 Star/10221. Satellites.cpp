#include <cstdio>
#include <cstring>
#include <cmath>
using namespace std;

#define PI acos(0) * 2

int main() {
    double r = 6440.0, s, a, arc, chord;        // r 為地球半徑 (km)
    char unit[5];
    while (scanf("%lf %lf %s", &s, &a, unit) != EOF) {
        if (strcmp(unit, "min") == 0) a /= 60;       // 1° = 60′
        while (a > 360) a -= 360;       // 大於一圈進行處理
        if (a > 180) a = 360 - a;       // 夾角不大於 180°
        arc = 2 * PI * (r + s) * (a / 360);         // 弧長 = 周長 * 角度
        /*
        根據母子相似定理求弦長: c = a * cosB + b * cosA
        由於是等腰三角形，可簡化為 c = 2 * (a * cosA)
        */
        chord = 2 * (r + s) * cos((180 - a) / 2 * PI / 180);
        printf("%.6lf %.6lf\n", arc, chord);
    }
    return 0;
}