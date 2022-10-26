
// Copyright 2022 Sinyakin Andrey

#include <gtest/gtest.h>

#include "include/complex_number.h"

TEST(Sinyakin_Andrey_ComplexNumberTest, create_complex_number_correct) {
  double re = 3.0;
  double im = 0.1;

  ComplexNumber z(re, im);

  ASSERT_EQ(re, z.getRe());
  ASSERT_EQ(im, z.getIm());
}

TEST(Sinyakin_Andrey_ComplexNumberTest, comparing_correct) {
  double re1 = 3.0;
  double im1 = 0.2;

  ComplexNumber z1(re1, im1);

  double re2 = 6.0;
  double im2 = 0.9;

  ComplexNumber z2(re2, im2);

  ASSERT_TRUE(z1 != z2);
}

TEST(Sinyakin_Andrey_ComplexNumberTest, equation_correct) {
  double re = 3.0;
  double im = 0.1;

  ComplexNumber z1(re, im);
  ComplexNumber z2;
  z2 = z1;

  ASSERT_EQ(z1.getRe(), z2.getRe());
  ASSERT_EQ(z1.getIm(), z2.getIm());
}

TEST(Sinyakin_Andrey_ComplexNumberTestt, copy) {
  double re = 1.5, im = 2.75;

  ComplexNumber z(re, im);

  ASSERT_NO_THROW(ComplexNumber z1(z));
}

TEST(Sinyakin_Andrey_ComplexNumberTest, copied_number_correct) {
  double re = 3.0;
  double im = 0.1;

  ComplexNumber z1(re, im);
  ComplexNumber z2(z1);

  ASSERT_EQ(z1.getRe(), z2.getRe());
  ASSERT_EQ(z1.getIm(), z2.getIm());
}

TEST(Sinyakin_Andrey_ComplexNumberTest, change_correct) {
  double re1 = 3.0;
  double im1 = 0.1;

  ComplexNumber z1(re1, im1);

  double re2 = 4.0;
  double im2 = 0.7;

  z1.setRe(re2);
  z1.setIm(im2);

  ASSERT_EQ(re2, z1.getRe());
  ASSERT_EQ(im2, z1.getIm());
}

TEST(Sinyakin_Andrey_ComplexNumberTest, addition_correct) {
  double re1 = 2.0;
  double im1 = 0.1;

  ComplexNumber z1(re1, im1);

  double re2 = 5.0;
  double im2 = 0.8;

  ComplexNumber z2(re2, im2);

  ComplexNumber sum = z1 + z2;

  ASSERT_EQ(7, sum.getRe());
  ASSERT_EQ(0.9, sum.getIm());
}

TEST(Sinyakin_Andrey_ComplexNumberTest, substraction_corrrect) {
  double re1 = 5.0;
  double im1 = 0.8;

  ComplexNumber z1(re1, im1);

  double re2 = 2.0;
  double im2 = 0.3;

  ComplexNumber z2(re2, im2);

  ComplexNumber sub = z1 - z2;

  ASSERT_EQ(3, sub.getRe());
  ASSERT_EQ(0.5, sub.getIm());
}

TEST(Sinyakin_Andrey_ComplexNumberTest, comparasing2_correct) {
  double re1 = 13.0;
  double im1 = 0.5;

  ComplexNumber z1(re1, im1);

  double re2 = 13.0;
  double im2 = 0.5;

  ComplexNumber z2(re2, im2);

  ASSERT_TRUE(z1 == z2);
}

TEST(Sinyakin_Andrey_ComplexNumberTest, division_correct) {
  double r1 = 2.2, i1 = 2.2, r2 = 2.0, i2 = 1.0;

  ComplexNumber a(r1, i1);
  ComplexNumber b(r2, i2);

  ComplexNumber div = a / b;

  double n1 = r1 * r2 + i1 * i2;
  double n2 = i1 * r2 - r1 * i2;
  double d = 1.0 / (r2 * r2 + i2 * i2);

  ASSERT_DOUBLE_EQ(n1 * d, div.getRe());
  ASSERT_DOUBLE_EQ(n2 * d, div.getIm());
}

TEST(Sinyakin_Andrey_ComplexNumberTest, division_with_zero) {
  double re1 = 1.5;
  double im1 = 2.75;

  ComplexNumber z1(re1, im1);
  ComplexNumber z2;
  ASSERT_ANY_THROW(z1 / z2);
}
