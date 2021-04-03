using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Lab6
{
    class Character
    {
        
        private string name;
        private string race;
        private int level = 0;
        private int health = 0;
        private int mana = 0;
        private int experience = 0;
        private float damage = 0;
        private bool dead = false;
        private Random random = new Random();
        public static List<string> NAMES = new List<string> { "Lo Whitbottom", "Meginhard Swiftfoot", "Godomar Gawkroger", "Gerontius Chubb - Baggins", "Walcaud Leafwalker", "Griffon Harfoot", "Balbo Sackville", "Butilin Lothran", "Willehad Silverstring", "Berengar Undertree" };
        public static List<string> RACES = new List<string> { "Human", "Orc", "Elf", "Hobbit", "Charr", "Norn" };
        private Equipment leftHand = null;
        private Equipment rightHand = null;

        public void Init(string name)
        {
            this.name = name;
            race = "Human";
            level = 1;
            health = 40;
            mana = 20;
            damage = 5;
            experience = 0;
        }

        public void Init()
        {
            name = NAMES[random.Next(NAMES.Count)];
            race = RACES[random.Next(RACES.Count)];
            level = random.Next(10) + 1;
            leftHand = new Equipment(random.Next(25) + 1);
            rightHand = new Equipment(random.Next(25) + 1);
            UpdateData();
        }

        public string Read()
        {
            Console.WriteLine("Input character name: ");
            return Console.ReadLine();
        }

        public void Display()
        {
            Console.WriteLine(string.Format("Name: {0}\nRace: {1}\nLevel: {2}\nExperience: {3} / 100\nHealth: {4}\nMana: {5}\nDamage: {6} ({7} + {8})\n\n", name, race, level, experience, health, mana, GetDamage(), damage, GetEquipmentDamage()));
        }

        public void LevelUp()
        {
            level++;
            UpdateData();
        }

        public void Add(int exp)
        {
            experience += exp;
            while (experience >= 100)
            {
                experience -= 100;
                LevelUp();
            }
        }

        public void TakeDamage(int dmg)
        {
            health -= dmg;
            if (health <= 0)
            {
                health = 40 * level;
                experience = 0;
                dead = true;
                Console.WriteLine("You're dead\n");
            }
        }

        public string GetRace()
        {
            return race;
        }

        public int GetLevel()
        {
            return level;
        }

        public int GetHealth()
        {
            return health;
        }

        public int GetMana()
        {
            return mana;
        }

        public int GetExperience()
        {
            return experience;
        }

        public float GetDamage()
        {
            return damage + GetEquipmentDamage();
        }

        private void UpdateData()
        {
            health = 40 * level;
            mana = 20 * level;
            damage = 5 * level;
        }

        private int GetEquipmentDamage()
        {
            int finalDamage = 0;
            if (leftHand != null)
                finalDamage += leftHand.GetDamage();
            if (rightHand != null)
                finalDamage += rightHand.GetDamage();
            return finalDamage;
        }
    
}
}
