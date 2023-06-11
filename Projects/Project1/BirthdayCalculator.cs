using System;

namespace BirthdayCalculator
{
    class Program
    {
        static void Main(string[] args)
        {
            Console.WriteLine("Enter your birthday:");

            Console.Write("Year: ");
            int year = GetValidIntegerInput();

            Console.Write("Month: ");
            int month = GetValidIntegerInput();

            Console.Write("Day: ");
            int day = GetValidIntegerInput();

            DateTime today = DateTime.Today;
            DateTime birthday = new DateTime(year, month, day);
            int age = today.Year - birthday.Year;

            if (age < 0 || age > 150)
            {
                Console.WriteLine("Invalid age.");
                return;
            }

            Console.WriteLine($"Your age is: {age}");

            if (today.Month == birthday.Month && today.Day == birthday.Day)
            {
                Console.WriteLine("Happy birthday!");
            }

            string westernSign = GetWesternSign(month, day);
            string chineseSign = GetChineseSign(year);

            Console.WriteLine($"Western Sign: {westernSign}");
            Console.WriteLine($"Chinese Sign: {chineseSign}");

            Console.ReadLine();
        }

        static int GetValidIntegerInput()
        {
            while (true)
            {
                if (int.TryParse(Console.ReadLine(), out int result))
                {
                    return result;
                }
                else
                {
                    Console.WriteLine("Invalid input. Please enter a valid integer.");
                }
            }
        }

        static string GetWesternSign(int month, int day)
        {
            string[] sunSigns = {
                "Aquarius", "Pisces", "Aries", "Taurus",
                "Gemini", "Cancer", "Leo", "Virgo",
                "Libra", "Scorpio", "Sagittarius", "Capricorn"
            };

            int[] cutoffDays = { 20, 19, 21, 20, 21, 21, 23, 23, 23, 23, 22, 22 };

            int index = month - 1;
            if (day <= cutoffDays[index])
                index--;

            if (index < 0)
                index = 11;

            return sunSigns[index];
        }

        static string GetChineseSign(int year)
        {
            string[] chineseSigns = {
                "Monkey", "Rooster", "Dog", "Pig",
                "Rat", "Ox", "Tiger", "Rabbit",
                "Dragon", "Snake", "Horse", "Sheep"
            };

            int startIndex = 1900;
            int index = (year - startIndex) % 12;

            if (index < 0)
                index += 12;

            return chineseSigns[index];
        }
    }
}