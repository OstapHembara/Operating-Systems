#include <iostream>
#include <cmath>
#include <cstdlib>
#include <chrono>

using namespace std;

int factorial(int n)
{
    if (n <= 1) return 1;
    else return n*factorial(n - 1);
}



int main( int argc, char** argv)
{
    double dB_board = 0, dArcSin = 0, dX_argument = 0, dAccurency = 0, dResult = 0, dPiece = 0, dStep = 0;

    dX_argument = atof(argv[1]);
    dB_board = atof(argv[2]);
    dAccurency = atof(argv[3]);
    dStep = atof(argv[4]);
    
   auto aPreNanoSec = chrono::high_resolution_clock::now();

    while (dX_argument <= dB_board)
    {
        dArcSin = asin(dX_argument);

        for (int n(0); fabs(asin(dX_argument) - dResult) > fabs(dAccurency); n++)
        {
            dPiece = (factorial(2 * n - 1)*(pow(dX_argument, 2 * n + 1))) / (factorial(2*n)*(2*n+1));
            dResult += dPiece;
        }
        cout << "arcsin(x): " << dArcSin <<"\t"<<"teylor: "<<dResult << endl;
        dX_argument += dStep;;
        dResult = 0;
    }

    auto aAferNanoSec = chrono::high_resolution_clock::now();

    return  chrono::duration_cast<chrono::milliseconds>(aAferNanoSec - aPreNanoSec).count();
}