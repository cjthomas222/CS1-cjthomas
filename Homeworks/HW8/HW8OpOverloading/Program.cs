using System;

namespace HW8O
{
    public class Fraction
    {

        private int numerator;
        private int denominator;


        public Fraction(int numerator, int denominator)
        {
            this.Numerator = numerator;
            this.Denominator = denominator;
        }

        public int Numerator
        {
            get {return this.numerator;}
            set {this.numerator = value;}
        }

        public int Denominator
        {
            get {return this.denominator;}
            set {this.denominator = value;}
        }

        public void printFraction()
        {
            Console.WriteLine($"{this.Numerator}/{this.Denominator}");
        }

        public int simplify()
        {
            int gcd = 1;
            for (int i = 1; i <= this.Numerator && i <= this.Denominator; i++)
            {
                if (this.Numerator % i == 0 && this.Denominator % i == 0)
                {
                    gcd = i;
                }
            }
            this.Numerator /= gcd;
            this.Denominator /= gcd;
            return gcd;
        }

        public override string ToString()
        {
            return $"{this.Numerator}/{this.Denominator}";
        }

        public static bool operator ==(Fraction f1, Fraction f2)
        {
            return f1.Numerator == f2.Numerator && f1.Denominator == f2.Denominator;
        }

        public static bool operator !=(Fraction f1, Fraction f2)
        {
            return f1.Numerator != f2.Numerator || f1.Denominator != f2.Denominator;
        }

        public static Fraction operator +(Fraction f1, Fraction f2)
        {
            int newNumerator = f1.Numerator * f2.Denominator + f2.Numerator * f1.Denominator;
            int newDenominator = f1.Denominator * f2.Denominator;
            return new Fraction(newNumerator, newDenominator);
        }

        public static Fraction operator *(Fraction f1, Fraction f2)
        {
            int newNumerator = f1.Numerator * f2.Numerator;
            int newDenominator = f1.Denominator * f2.Denominator;
            return new Fraction(newNumerator, newDenominator);
        }

        public static Fraction operator /(Fraction f1, Fraction f2)
        {
            int newNumerator = f1.Numerator * f2.Denominator;
            int newDenominator = f1.Denominator * f2.Numerator;
            return new Fraction(newNumerator, newDenominator);
        }

    }
    public class HW8OpOverloading
    {
        static void Main(string[] args)
        {
            Fraction f1 = new Fraction(1, 2);
            f1.printFraction();

            Fraction f2 = new Fraction(2, 3);
            Console.WriteLine(f2.ToString());

            Fraction frac10 = new Fraction(3,4);
            Fraction frac11 = new Fraction(2,5);

            Console.WriteLine(frac10 == frac11);

            Fraction f3 = f1 + f2;
            f3.simplify();
            Console.WriteLine(f1.ToString() + " + " + f2.ToString() + " = " + f3.ToString());

            Fraction f4 = f1 * f2;
            f4.simplify();
            Console.WriteLine(f1.ToString() + " * " + f2.ToString() + " = " + f4.ToString());

            Fraction f5 = f1 / f2;
            f5.simplify();
            Console.WriteLine(f1.ToString() + " / " + f2.ToString() + " = " + f5.ToString());

        }
    }
}