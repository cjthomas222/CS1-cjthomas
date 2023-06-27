using System;
using System.Text;

namespace HW14
{
    public class HW14Delegates
    {
        public delegate void MulticastDelegate(int r);
        public void circleArea(int r)
        {
            Console.WriteLine("Circle area: ");
            Console.WriteLine((int)(Math.PI * r * r));
        }

        public void circumference(int r)
        {
            Console.WriteLine("Circle circumference: ");
            Console.WriteLine((int)(2 * Math.PI * r));
        }

        public string funcReverse(string s, int multiple)
        {
            string newString = new string(s.Reverse().ToArray());
            StringBuilder sb = new StringBuilder();
            for (int i = 0; i < multiple; i++)
            {
                sb.Append(newString);
            }
            return sb.ToString();
        }

        public void actReverse(string s, int multiple)
        {
            string newString = new string(s.Reverse().ToArray());
            StringBuilder sb = new StringBuilder();
            for (int i = 0; i < multiple; i++)
            {
                sb.Append(newString);
            }
            Console.WriteLine(sb.ToString());
        }

        static bool isPalindrome(string s)
        {
            string newString = new string(s.Reverse().ToArray());
            return s == newString;
        }

        public static void Main(string[] args)
        {
            HW14Delegates obj = new HW14Delegates();
            
            MulticastDelegate md = obj.circleArea;
            md += obj.circumference;

            Console.WriteLine("Enter Radius:");
            int radius = int.Parse(Console.ReadLine());
            md(radius);

            Func<string, int, string> rev = obj.funcReverse;
            Action<string, int> rev2 = obj.actReverse;
            Predicate<string> pal = isPalindrome;

            Console.WriteLine("Enter string to reverse:");
            string s = Console.ReadLine();
            Console.WriteLine("Enter number of times to reverse:");
            int n = int.Parse(Console.ReadLine());
            Console.WriteLine("Func: ");
            Console.WriteLine(rev(s, n));
            Console.WriteLine("Action: ");
            rev2(s, n);
            Console.WriteLine("Predicate: (Is string a palindrome?) ");
            Console.WriteLine(pal(s));
        }
    }
}