import java.util.*;
import java.io.*;

public class Main {

    public static void main(String[] args) throws Exception {
        Scanner scan = new Scanner(System.in);
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        PrintWriter pw = new PrintWriter(new OutputStreamWriter(System.out));
        StringTokenizer st;

        int n = Integer.parseInt(br.readLine());
        int[] arr = new int[10001];
        st = new StringTokenizer(br.readLine());
        for(int i = 0;  i < n; i++) {
            int val = Integer.parseInt(st.nextToken());
            arr[val]++;
        }
        int turns = 0;
        for(int i = 1; i <= 10000; i++) {
            if(arr[i] > arr[i - 1]) {
                turns += arr[i] - arr[i - 1];
            }
        }
        pw.println(turns);

        scan.close();
        br.close();
        pw.close();
    }
}