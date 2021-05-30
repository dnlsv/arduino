#include <conio.h>
#include <iostream>
#include <iomanip>

using namespace std;

int main()
{
    setlocale(LC_ALL, "rus");
    double x, y;
    double R;
    double* xmas = new double[10];

    cout << "¬ведите y: " << endl;
    cin >> y;
    cout << "¬ведите 10 значений x: " << endl;
    for (int i = 0; i < 10; i++)
    {
        cin >> x;
        xmas[i] = x;
    }

    cout << endl << "  " << left << setw(10) << "x" << setw(20) << "R(x,y)(asm)" << setw(20) << "R(x,y)(C++)" << setw(35) << "R(x,y)(asm) - R(x,y)(C++)" << endl;
    cout << " ----------------------------------------------------------------------------" << endl;

    for (int i = 0; i < 10; i++)
    {
        x = xmas[i];

        R = pow(((cos(x) / (y * log2(x + 1))) * sin(y) * pow(2, (y * log2(x))) + y * log2(x + 1)), 3) + pow(exp(y), (0.5)) - tan(x / y) - pow(2, (x - 1));

        double a, b, c, d;
        double one = 1;
        int yy;
        yy = (int)y;
        double e;
        e = exp(1);

        __asm
        {
            fld x
            fcos
            fstp a
            fld one
            fld x
            fadd
            fst b
            finit
            fld y
            fld b
            fyl2x
            fst b
            finit
            fld b
            fld a
            fdiv ST(0), ST(1)
            fst a
            finit
            fld y
            fsin
            fld a
            fmul
            fst a
            finit
            fld y
            fld x
            fyl2x
            fst b
            finit
            fld b
            frndint
            fstp c
            fld b
            fld c
            fsub
            fst d
            finit
            fld c
            fld one
            fscale
            fst c
            finit
            fld d
            f2xm1
            fld one
            fadd
            fst d
            finit
            fld d
            fld c
            fmul
            fst b
            finit
            fld b
            fld a
            fmul
            fst a
            finit
            fld one
            fld x
            fadd
            fst b
            fld y
            fld b
            fyl2x
            fst b
            finit
            fld b
            fld a
            fadd
            fst a
            finit
            fld a
            fld a
            fmul
            fst b
            finit
            fld b
            fld a
            fmul
            fst a
            finit
            mov eax, yy
            mov ebx, 0
            metka_1 :
            add ebx, 1
                cmp ebx, eax
                je metka_2
                fld e
                fld e
                fmul
                fst e
                jmp metka_1
                metka_2 :
            finit
                fld e
                fsqrt
                fstp b
                fld b
                fld a
                fadd
                fst a
                finit
                fld y
                fld x
                fdiv ST(0), ST(1)
                fst b
                finit
                fld b
                fsin
                fstp c
                fld b
                fcos
                fstp d
                fld d
                fld c
                fdiv ST(0), ST(1)
                fst b
                finit
                fld a
                fld b
                fsub
                fst a
                finit
                fld x
                fld one
                fsub
                fst b
                finit
                fld b
                fld one
                fscale
                fst b
                finit
                fld a
                fld b
                fsub
                fst a
                finit
        }
        cout << "  " << left << setw(10) << x << setw(20) << a << setw(20) << R << setw(35) << a - R << endl;
    }
}