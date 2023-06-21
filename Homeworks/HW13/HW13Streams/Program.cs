using System;

namespace HW13Streams
{
    class HW13Streams
    {
        static void Main(string[] args)
        {
            string fileName = "test.txt";
            if(!File.Exists(fileName))
            {
                Console.WriteLine("File does not exist");
                return;
            }
        }
    }
}