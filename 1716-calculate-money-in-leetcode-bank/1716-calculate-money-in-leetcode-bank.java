class Solution {
    public int totalMoney(int n) {
        int count = 1; 
        int a = n/7; 
        int b = n % 7;
        int sum = 0;

        for (int i = 0; i < a; i++) {
            int weekSum = sumUptoN(count + 6) - sumUptoN(count - 1);
            sum += weekSum;

            count++;
        }

        sum += sumUptoN(count + b - 1) - sumUptoN(count - 1);

        return sum;
    }

    public int sumUptoN(int n) {
        return (n * (n + 1)) / 2;
    }
}