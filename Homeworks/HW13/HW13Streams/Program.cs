using System;

namespace HW13Streams
{
    public class HW13Streams
    {
        static void Main(string[] args)
        {
            string fileName = "test.txt";
            string fileOutput = "output.txt";
            using(StreamReader sr = new StreamReader(fileName))
            {
                string line = sr.ReadToEnd();
                using(StreamWriter sw = new StreamWriter(fileOutput))
                {
                    sw.Write(line);
                    sw.WriteLine("This is a test");
                }
            }





            // if(!File.Exists(fileName))
            // {
            //     Console.WriteLine("File does not exist");
            //     Environment.Exit(1);
            // }

            // FileStream fs = File.Open(fileName, FileMode.Open);
            // byte[] bytes = new byte[fs.Length + 10];
            // long numbytesToRead = fs.Length;
            // int numbytesRead = 0;

            // do
            // {
            //     int n = fs.Read(bytes, numbytesRead, numbytesRead);
            //     numbytesRead += n;
            //     numbytesToRead -= n;
            // } while(numbytesToRead > 0);

            // Console.WriteLine(System.Text.Encoding.UTF8.GetString(bytes));
            // fs.Close();
        }
    }
}