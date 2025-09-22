import java.util.*;
import java.io.*;

public class Main {

    public static void main(String[] args) throws Exception {
        Scanner scan = new Scanner(System.in);
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        PrintWriter pw = new PrintWriter(new OutputStreamWriter(System.out));
        StringTokenizer st;

        st = new StringTokenizer(br.readLine());
        int l = Integer.parseInt(st.nextToken());
        int h = Integer.parseInt(st.nextToken());
        int k = Integer.parseInt(st.nextToken());
        char[][] arr = new char[h][l];
        for(int i = 0; i < h; i++) Arrays.fill(arr[i], '_');

        for(int i = 0; i < k; i++) {
            st = new StringTokenizer(br.readLine());
            int L = Integer.parseInt(st.nextToken());
            int H = Integer.parseInt(st.nextToken());
            int a = Integer.parseInt(st.nextToken());
            int b = Integer.parseInt(st.nextToken());

            char val = (char)('a' + i);
            for(int r = b; r < Math.min(h, b + H); r++) {
                for(int c = a; c < Math.min(l, a + L); c++) {
                    arr[r][c] = val;
                }
            }
        }

        for(int i = 0; i < h; i++) {
            for(int j = 0; j < l; j++) {
                pw.print(arr[i][j]);
            }
            pw.println();
        }

        scan.close();
        br.close();
        pw.close();
    }
}