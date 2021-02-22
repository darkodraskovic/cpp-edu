#include <math.h>
#include <string>
#include <map>
#include <vector>

#include "NumWord.h"

map<int, string> numbers{
    {0, "zero"},      {1, "one"},       {2, "two"},      {3, "three"},
    {4, "four"},      {5, "five"},      {6, "six"},      {7, "seven"},
    {8, "eight"},     {9, "nine"},

    {10, "ten"},      {11, "eleven"},   {12, "twelve"},  {13, "thirteen"},
    {14, "fourteen"}, {15, "fifteen"},  {16, "sixteen"}, {17, "seventeen"},
    {18, "eighteen"}, {19, "nineteen"},

    {20, "twenty"},   {30, "thirty"},   {40, "forty"},   {50, "fifty"},
    {60, "sixty"},    {70, "seventy"},  {80, "eighty"},  {90, "ninety"},
};

vector<string> powers = {"thousand", "million", "billion", "trillion", "quadrillion"};

string NumWord::words(long n) {
    if (n == 0) return "";
    if (n < 20) return numbers[n];
    else if (n < 100) return numbers[n - n%10] + (n%10 ? "-" + numbers[n%10] : "");
    else return numbers[n/100] + " hundred " + words(n%100);
}

string NumWord::Words(long n) {
    string w = "";
    for (int i = powers.size(); i > 0; i--) {
        long m = pow(10, i * 3);
        if (n / m) w += words(n / m) + " " + powers[i-1] + " ";
        n %= m;
    }
    w += words(n);
    return w;
}
