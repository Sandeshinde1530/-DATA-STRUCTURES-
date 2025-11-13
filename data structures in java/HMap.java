import java.util.HashMap;


class HMap
{
    public static void main(String a[])
    {
         String[] words = {"apple", "banana", "apple", "orange", "banana", "apple"};

        HashMap <String , Integer> map = new HashMap<>();

        for(String word : words)
        {
            map.put(word , map.getOrDefault(word , 0) + 1);
        }

        System.out.println(map);


    }
}