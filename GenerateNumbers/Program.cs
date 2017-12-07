using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace GenerateNumbers
{
    class Program
    {
        static void Main(string[] args)
        {
            const int NumbersToGenerate = 1000000;

            var rand = new Random();
            rand.Next();

            using (System.IO.StreamWriter file =
            new System.IO.StreamWriter("data.txt"))
            {
                for (int i = 0; i < NumbersToGenerate; ++i)
                {
                    file.WriteLine(rand.Next(-5000,5001));
                }
            }
        }
    }
}
