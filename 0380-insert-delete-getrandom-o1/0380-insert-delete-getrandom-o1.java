class RandomizedSet {
    private HashSet<Integer> set;

    public RandomizedSet() {
        set = new HashSet<Integer>();
    }
    
    public boolean insert(int val) {
        boolean contains = set.contains(val);
        set.add(val);
        return !contains;
    }
    
    public boolean remove(int val) {
        boolean contains = set.contains(val);
        set.remove(val);
        return contains;
    }
    
    public int getRandom() {
        return set.iterator().next();
    }
}

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet obj = new RandomizedSet();
 * boolean param_1 = obj.insert(val);
 * boolean param_2 = obj.remove(val);
 * int param_3 = obj.getRandom();
 */