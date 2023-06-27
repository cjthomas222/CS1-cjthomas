using System;

namespace HW16
{
    public class HW16Async
    {

        static void printNums(int n)
        {
            for (int i = 0; i < 55; i++)
            {
                Console.WriteLine(i);
                Task.Delay(100).Wait();
            }
        }

        static void printLetters(int n)
        {
            for (int i = 0; i < 55; i++)
            {
                Console.WriteLine((char)(i + 65));
                Task.Delay(100).Wait();
            }
            
        }

        static Task Thing()
        {
            return Task.Run(() => printNums(100));
        }

        static async void doStuff()
        {
            await Thing();
        }
        static void Main(string[] args)
        {
            doStuff();
            printLetters(100);
        }
    }
}