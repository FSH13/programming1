#include <cs50.h>
#include <math.h>
#include <stdio.h>
#include <string.h>

float highest(float a[], int b);
float print_array(float a, int b);
float max(float a, float b);
float average(float a, float b);
float print_float(float a);
float half(float a);
int times_two(int a);
void print_int(int a);

int main(void) {
  // verdubbel
  int x = 4;
  int y = times_two(x);
  print_int(y);

  // halveren
  float w = 7;
  float v = half(w);
  print_int(v);

  // afronden #.##
  float u = 1.234567;
  float t = print_float(u);

  // Gemiddeld ook #.##
  float aver = average(x, 7);
  print_float(aver);

  // Hoogste getal uit 2
  float hoogst = max(u, w);
  print_float(hoogst);

  // Afronden array
  float s[] = {1.2345, 2.34567, 3.0001, 4, 5.4321};
  int r = 5;
  int c = 0;
  float result;
  while (c < r) {
    result = print_array(s[c], r);
    c++;
  }

  // Hoogste getal uit array
  float q[] = {1.2345, 2.34567, 20.123, 3.0001, 5.4321};
  float p[] = {123};
  float high = highest(q, r);
}

// functions
int times_two(int a) // verdubbel
{
  return a * 2;
}
float half(float a) // halveren
{
  return a / 2;
}
float print_float(float a) // afronden #.##
{
  return printf("%.2f\n", a);
}
float average(float a, float b) // Gemiddeld ook #.##
{
  return (a + b) / 2;
}
float max(float a, float b) // Hoogste getal uit 2
{
  if (a > b) {
    return a;
  } else {
    return b;
  }
}
float print_array(float a, int b) // Afronden array
{
  return printf("%.2f\n", a);
}
float highest(float a[], int r) // Hoogste getal uit array
{
  int c = 0;
  float result = a[0];
  while (c < r) {
    if (a[c] > result) {
      result = a[c];
    }
    c++;
  }
  return printf("%.3f\n", result);
}

void print_int(int a) { printf("Value = %i\n", a); }
