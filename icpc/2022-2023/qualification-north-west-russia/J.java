/**
 *   @idea_author: Vladimir Nazarov
 *   @code_author: Vladimir Nazarov
 *   @problems:
 *       * Code has a problem with a time limit exception in pcms
 *   @pcms: Time limit exceeded, test 11
 *   @date: 08.10.2022
*/

import java.io.BufferedReader;
import java.io.InputStream;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Collections;

public class J {
    public static void main(String[] args) {
        solve(new Reader(System.in));
    }

    static int N;
    public static ArrayList<ArrayList<Integer>> paths;
    public static int[][][] costs;
    public static int[][] dp_costs;
    public static boolean[] dp_need;
    public static ArrayList<Integer> local_minimum_paths;

    public static boolean nd = false;
    public static int c_g = 0;
    public static int c_j = 0;

    private static void solve(Reader in) {
        N = in.nextInt();
        int M = in.nextInt();
        int Q = in.nextInt();

        paths = new ArrayList<>();
        dp_need = new boolean[N];
        for (int i = 0; i < N; i++) {
            paths.add(new ArrayList<>());
        }
        costs = new int[N][N][2];
        dp_costs = new int[N][2];

        for (int i = 0; i < M; i++) {
            int u = in.nextInt() - 1;
            int v = in.nextInt() - 1;
            int s = in.nextInt();
            int w = in.nextInt();
            paths.get(u).add(v);
            costs[u][v][0] = s;
            costs[u][v][1] = w;
        }
        for (int i = 0; i < N; i++) {
            Collections.shuffle(paths.get(i));
        }

        findLocMinimum(0, 0, 0);
        for (int i = 0; i < Q; i++) {
            int a = in.nextInt();
            int b = in.nextInt();

            if (c_g * a > c_j * b) {
                System.out.println("YES");
            } else {
                System.out.println("NO");
            }

        }

    }

    public static boolean findLocMinimum(int from, int g, int j) {
        if (from + 1 == N) {
            if (!nd) {
                c_g = g;
                c_j = j;
                nd = true;
            } else {
                if (c_g - c_j < g - j) {
                    c_g = g;
                    c_j = j;
                }
            }
            return true;
        }


        if (from != 0) {
            if (dp_costs[from][0] == 0) {
                dp_costs[from][0] = g;
                dp_costs[from][1] = j;
            } else {
                if (dp_costs[from][0] - dp_costs[from][1] >= g - j) {
                    return dp_need[from];
                }
            }
        }

        boolean sm = false;
        for (int i : paths.get(from)) {
            if (dp_need[i]) {
                continue;
            }

            int _g = costs[from][i][0];
            int _j = costs[from][i][1];
            boolean out;
            if (from == 0) {
                out = findLocMinimum(i, _g, _j);
            } else {
                if (g - j > _g - _j) {
                    out = findLocMinimum(i, _g, _j);
                } else {
                    out = findLocMinimum(i, g, j);
                }
            }

            if (out) {
                sm = true;
            }
        }
        if (!sm) {
            dp_need[from] = true;
        }
        return sm;
    }


    public static class Reader {
        private int cnt = 0;
        private String[] line = null;
        private final BufferedReader reader;

        public Reader(InputStream inputStream) {
            this.reader = new BufferedReader(new InputStreamReader(inputStream));
        }

        public String nextString() {
            if (line == null || cnt >= line.length) {
                try {
                    line = reader.readLine().split("\\s");
                    cnt = 0;
                } catch (Exception e) {
                    throw new RuntimeException(e);
                }
            }
            return line[cnt++];
        }

        public int nextInt() {
            return Integer.parseInt(nextString());
        }

        public long nextLong() {
            return Long.parseLong(nextString());
        }
    }
}