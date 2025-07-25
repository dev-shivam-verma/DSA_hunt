class DisjointSet {
    int[] size;
    int[] parent;

    DisjointSet(int n) {
        size = new int[n];
        parent = new int[n];

        for (int i = 0; i < n; i++) {
            size[i] = 1;
            parent[i] = i;
        }
    }

    public int findUPar(int node) {
        if (parent[node] == node) return node;

        // Path compression
        return parent[node] = findUPar(parent[node]);
    }

    public void union(int u, int v) {
        int paru = findUPar(u);
        int parv = findUPar(v);

        if (paru == parv) return;

        // Union by size
        if (size[paru] < size[parv]) {
            parent[paru] = parv;
            size[parv] += size[paru];
        } else {
            parent[parv] = paru;
            size[paru] += size[parv];
        }
    }
}


class Solution {
    public List<List<String>> accountsMerge(List<List<String>> accounts) {
        int n = accounts.size();
        DisjointSet ds = new DisjointSet(n);
        Map<String, Integer> emailAccountMap = new HashMap<>();

        for (int i = 0; i < n; i++) {
            List<String> account = accounts.get(i);

            for (int j = 1; j < account.size(); j++) {
                String email = account.get(j);

                if (emailAccountMap.containsKey(email)) {
                    int ac = emailAccountMap.get(email);

                    ds.union(ac, i);
                } else {
                    emailAccountMap.put(email, i);
                }
            }
        }

        Map<Integer, List<String>> mergedEmails = new HashMap<>();

        for (Map.Entry<String, Integer> email : emailAccountMap.entrySet()) {
            int acc = ds.findUPar(email.getValue());
            if (!mergedEmails.containsKey(acc)) {
                mergedEmails.put(acc, new ArrayList<String>());
            } 

            mergedEmails.get(acc).add(email.getKey());
        }

        List<List<String>> mergedAccounts = new ArrayList();

        for (Map.Entry<Integer, List<String>> emails: mergedEmails.entrySet()) {
            Collections.sort(emails.getValue());
            List<String> account = new ArrayList<>();

            account.add(accounts.get(emails.getKey()).get(0));
            account.addAll(emails.getValue());
            mergedAccounts.add(account);
        }

        return mergedAccounts;
    }
}