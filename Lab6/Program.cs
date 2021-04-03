using System;

namespace Lab6
{
    class Program
    {
        public static void LevelUp(ref Character player)
        {
            player.Level++;
        }
        public static void CreateDefaultName(out string name)
        {
            name = "Default Name";
        }
        static void Main(string[] args)
        {
            
            Character player = new Character();
            string name;
            CreateDefaultName(out name);
            player.Init(name, new Equipment(1), new Equipment(10));
            player.Display();
            LevelUp(ref player);
            player++;
            player.Display();

            Character[] players = new Character[5];
            for (int i = 0; i < players.Length; i++)
            {
                players[i] = new Character();
                players[i].Init();
                players[i].Display();
            }
            Console.ReadKey();
        }
    }
}