using System;
using System.Collections.Generic;

namespace HW11Collections
{
    public class HW11Collections
    {
        static void Main(string[] args)
        {
            Dictionary<string, int> dict = new Dictionary<string, int>();
            dict.Add("one", 1);
            dict.Add("two", 2);
            dict.Add("Forty-Two", 42);
            dict.Add("Connor", 21);
            dict["Connor"] = 22;
            Console.WriteLine(dict.TryAdd("Connor", 23));

            Queue<int> queue = new Queue<int>();
            queue.Enqueue(11);
            queue.Enqueue(22);
            queue.Enqueue(33);
            queue.Enqueue(44);
            queue.Enqueue(55);
            queue.Enqueue(66);
            queue.Dequeue();

            Stack<int> stack = new Stack<int>();
            stack.Push(11);
            stack.Push(22);
            stack.Push(33);
            stack.Push(44);
            stack.Push(55);
            stack.Push(66);
            stack.Pop();

            PrintDictionary<string,int>(dict);
            PrintQueue<int>(queue);
            PrintStack<int>(stack);
        }

        static void PrintDictionary<Tkey, Tvalue>(Dictionary<Tkey, Tvalue> dict)
        {
            Console.WriteLine("Printing dictionary...");
            foreach (KeyValuePair<Tkey, Tvalue> kvp in dict)
            {
                Console.WriteLine($"{kvp.Key} : {kvp.Value}");
            }
            Console.WriteLine();
        }

        static void PrintQueue<T>(Queue<T> queue)
        {
            Console.WriteLine("Printing queue...");
            foreach (var i in queue)
            {
                Console.Write($"{i} ");
            }
            Console.WriteLine();
        }

        static void PrintStack<T>(Stack<T> stack)
        {
            Console.WriteLine("Printing stack...");
            foreach (var i in stack)
            {
                Console.Write($"{i} ");
            }
            Console.WriteLine();
        }
    }
}