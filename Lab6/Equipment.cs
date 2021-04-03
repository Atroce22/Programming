using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Lab6
{
    class Equipment
    {
        private string name;
        private int weight = 0;
        private int price = 0;
        private int damage = 0;

        public static int operator +(Equipment equipment, Equipment equipment1) { return equipment.damage + equipment1.damage; }
        public Equipment() { }
        public Equipment(int dmg)
        {
            damage = dmg;
        }

        public int GetDamage()
        {
            return damage;

        }
        public void SetDamage(int value)
        {
            try
            {
                if (value < 0)
                    throw new ArgumentException("-1");
                if (value >= 1000)
                    throw new ArgumentException("Too much damage");
                damage = value;
            }
            catch (ArgumentException a)
            {
                if (a.Message == "-1")
                {
                    Console.WriteLine("We caught an exception. Reset damage to 0\n");
                    damage = 0;
                }
                else if (a.Message == "Too much damage")
                {
                    Console.WriteLine("We caught an exception. Reset damage to 999\n");
                    damage = 999;
                }
            }
        }

    }
}
