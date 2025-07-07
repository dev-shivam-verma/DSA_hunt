class Solution {
    public List<String> validateCoupons(String[] code, String[] businessLine, boolean[] isActive) {
        Map<String, PriorityQueue<String>> cStore = new TreeMap<>();
        List<String> validatedCoupons = new ArrayList<>();
        
        cStore.put("electronics", new PriorityQueue<String>());
        cStore.put("grocery", new PriorityQueue<String>());
        cStore.put("pharmacy", new PriorityQueue<String>());
        cStore.put("restaurant", new PriorityQueue<String>());

        int n = code.length;
        for (int i = 0; i < n; i++) {
            boolean isAlphaNumeric = true;
            
            for (char c: code[i].toCharArray()) {
                if (!Character.isLetterOrDigit(c) && c != '_') isAlphaNumeric = false;
            }

            if (!isAlphaNumeric) continue;
            if (!isActive[i]) continue;
            if (code[i].length() == 0) continue;

            
            if (cStore.containsKey(businessLine[i])) {
                cStore.get(businessLine[i]).add(code[i]);
            }
        }

        for (Map.Entry<String, PriorityQueue<String>> business: cStore.entrySet()) {
            PriorityQueue<String> coupans = business.getValue();
            while (!coupans.isEmpty()) {
                validatedCoupons.add(coupans.poll());
            }
        }

        return validatedCoupons;
    }
}