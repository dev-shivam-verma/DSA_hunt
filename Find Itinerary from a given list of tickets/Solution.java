import java.util.HashMap;
import java.util.Map;

public class Solution {
    public static void main(String[] args) {
        Map<String, String> map = new HashMap<>();
        map.put("Chennai", "Banglore");
        map.put("Bombay", "Delhi");
        map.put("Goa", "Chennai");
        map.put("Delhi", "Goa");

        String startDestination = "";
        for (Map.Entry<String,String> entry : map.entrySet()){
            if (!map.containsValue(entry.getKey())){
                startDestination = entry.getKey();
                break;
            }
        }

        String key = startDestination;
        while (map.containsKey(key)){
            System.out.println(key + " -> " + map.get(key));
            key = map.get(key);
        }
    }
}
