import java.util.*;
import java.io.*;

public class Main {

    public static void main(String[] args) throws Exception {
        Scanner scan = new Scanner(System.in);
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        PrintWriter pw = new PrintWriter(new OutputStreamWriter(System.out));
        StringTokenizer st;


        int n = Integer.parseInt(br.readLine());
        String[] racers = new String[n];
        double[][] times = new double[n][2];
        for(int i = 0; i < n; i++) {
            st = new StringTokenizer(br.readLine());
            racers[i] = st.nextToken();
            times[i][0] = Double.parseDouble(st.nextToken());
            times[i][1] = Double.parseDouble(st.nextToken());
        }
        double currTime = 0;
        double bestTime = Double.MAX_VALUE;
        int[] ans = new int[4];

        for(int i = 0; i < n; i++) {
            currTime = times[i][0];
            int a = -1, b = -1, c = -1;
            for(int j = 0; j < n; j++) {
                if(j == i) continue;
                if(c == -1 || times[j][1] < times[c][1]) {
                    a = b;
                    b = c;
                    c = j;
                } else if (b == -1 || times[j][1] < times[b][1]) {
                    a = b;
                    b = j;
                } else if(a == -1 || times[j][1] < times[a][1]) {
                    a = j;
                }

                currTime = times[i][0] + (a == -1? 0: times[a][1])
                        + (b == -1? 0: times[b][1] + (c == -1? 0: times[c][1]));
            }
            if(currTime < bestTime) {
                bestTime = currTime;
                ans[0] = i;
                ans[1] = a;
                ans[2] = b;
                ans[3] = c;
            }
        }

        pw.println(bestTime);
        for(int e: ans) {
            pw.println(racers[e]);
        }

        scan.close();
        br.close();
        pw.close();
    }
}