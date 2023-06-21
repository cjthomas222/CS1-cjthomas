using System;
using System.Collections.Generic;

namespace HW10Lists
{
    public class HW10Lists
    {
        static void PrintLinkedList<T>(LinkedList<T> list)
        {
            Console.WriteLine("Printing linked list...");
            foreach (T item in list)
            {
                Console.Write(item + " ");
            }
            Console.WriteLine();
        }

        static void InsertIntoList<T>(LinkedList<T> list, T value) where T : IComparable<T>
        {
            LinkedListNode<T> node = list.First;
            while (node != null && node.Value.CompareTo(value) < 0)
            {
                node = node.Next;
            }

            if (node != null)
            {
                list.AddBefore(node, value);
            }
            else
            {
                list.AddLast(value);
            }
        }

        static void Main(string[] args)
        {
            LinkedList<int> intList = new LinkedList<int>(new[] { 1, 2, 3, 4, 5, 6, 7, 8, 9 });
            LinkedList<string> stringList = new LinkedList<string>(new[] { "dog", "cat", "monkey", "bird" });

            InsertIntoList(intList, 10);
            InsertIntoList(stringList, "fish");

            PrintLinkedList(intList);
            PrintLinkedList(stringList);
        }
    }
}