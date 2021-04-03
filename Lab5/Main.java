import java.util.Scanner;
import java.io.IOException;
import java.util.List;
import java.util.Random;


class Character {
    static class Increase {
        public  static int inc(int num)
        {
            return ++num;
        }
    }

    public static final List<String> NAMES = List.of("Lo Whitbottom", "Meginhard Swiftfoot", "Godomar Gawkroger", "Gerontius Chubb - Baggins", "Walcaud Leafwalker", "Griffon Harfoot", "Balbo Sackville", "Butilin Lothran", "Willehad Silverstring", "Berengar Undertree");
    public static final List<String> RACES = List.of("Human", "Orc", "Elf", "Hobbit", "Charr", "Norn");
    
    private static int counter = 0;
    private static Random random = new Random();

    private String name;
    private String race;
    private int level = 0;
    private int health = 0;
    private int mana = 0;
    private int experience = 0;
    private float damage = 0;
    private boolean dead = false;
    private int id = 0;

    private Equipment left_hand = null;
    private Equipment right_hand = null;
    
    public Character(String name, String race, int level, Equipment left, Equipment right) {
        this.name = name;
        this.race = race;
        this.level = level;
        left_hand = left;
        right_hand = right;
        id = counter++;
        update_data();
    }

    public Character(String name) {
        this.name = name;
        race = RACES.get(random.nextInt(RACES.size()));
        level = random.nextInt(10) + 1;
        left_hand = new Equipment(random.nextInt(25) + 1);
        right_hand = new Equipment(random.nextInt(25) + 1);
        id = counter++;
        update_data();
    }

    public Character() {
        name = NAMES.get(random.nextInt(NAMES.size()));
        race = RACES.get(random.nextInt(RACES.size()));
        level = random.nextInt(10) + 1;
        left_hand = new Equipment(random.nextInt(25) + 1);
        right_hand = new Equipment(random.nextInt(25) + 1);
        id = counter++;
        update_data();
    }

    public String read() {
        Scanner in = new Scanner(System.in);
        System.out.println("Input character name: ");
        String s = in.nextLine();
        return s;
    }

    public void display() {
        System.out.printf("ID: %d%nName: %s%nRace: %s%nLevel: %d%nExperience: %d / 100%nHealth: %d%nMana: %d%nDamage: %f (%f + %d)%n%n", id, name, race, level, experience, health, mana, get_damage(), damage, get_equipment_damage());
    }
    public static void display(Character character) {
        character.display();
    }
    public void level_up() {
        level = Increase.inc(level);
        update_data();
    }

    public void add(int exp) {
        experience += exp;
        while (experience >= 100)
        {
            experience -= 100;
            level_up();
        }
    }

    public void take_damage(int dmg){ 
        health -= dmg;
        if (health <= 0)
        {
            health = 40 * level;
            experience = 0;
            dead = true;
            System.out.println("You're dead\n");
        }
    }
    public static int get_counter() {
        return counter;
    }

    public String get_race() {
        return race;
    }

    public int get_level() {
        return level;
    }

    public int get_health() {
        return health;
    }

    public int get_mana() {
        return mana;
    }

    public int get_experience() {
        return experience;
    }

    public float get_damage(){ 
        return damage + get_equipment_damage();
    }

    public Equipment get_left_hand() {
        return left_hand;
    }
    public Equipment get_right_hand() {
        return right_hand;
    }

    private void update_data() {
        health = 40 * level;
        mana = 20 * level;
        damage = 5 * level;
    }

    private int get_equipment_damage() {
        int final_damage = 0;
        if (left_hand != null)
            final_damage += left_hand.get_damage();
        if (right_hand != null)
            final_damage += right_hand.get_damage();
        return final_damage;
    }
}

class Equipment {
    private String name;
	private int weight = 0;
	private int price = 0;
	private int damage = 0;

    public Equipment() {}
	public Equipment(int dmg)
    {
        damage = dmg;
    }

	public int get_damage()
    {
        return damage;
    }
    public void set_damage(int value)
        {
            try
            {
                if (value < 0)
                    throw new IOException("-1");
                if (value >= 1000)
                    throw new IOException("Too much damage");
                damage = value;
            }
            catch (IOException a)
            {
                if (a.getMessage() == "-1")
                {
                    System.out.println("We caught an exception. Reset damage to 0\n");
                    damage = 0;
                }
                else if (a.getMessage() == "Too much damage")
                {
                    System.out.println("We caught an exception. Reset damage to 999\n");
                    damage = 999;
                }
            }
        }
}

public class Main {
	  public static void main(String[] args) { 
        Character player = new Character("Player Name", "Human", 3, new Equipment(20), new Equipment(15));
        player.display();
        player.level_up();
        Character.display(player);
        player.get_left_hand().set_damage(-1);
        player.get_right_hand().set_damage(1000);
        Character.display(player);
        
        Character player1 = new Character("New Name");
        player1.display();

        Character [] players = new Character[5];
        for (int i = 0; i < players.length; i++)
        {
            players[i] = new Character();
            players[i].display();
        }
        System.out.printf("Created characters count: %d%n", Character.get_counter());
    }
}