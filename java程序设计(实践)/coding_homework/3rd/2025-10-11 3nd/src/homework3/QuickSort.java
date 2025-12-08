package homework3;

import java.util.Scanner;

public class QuickSort {
    static int[] a = new int[20];

    public static void QSort(int l, int r) {
        if (l < r) {
            int i = l, j = r;
            int tmp = a[l];
            while (i < j) {
                while (i < j && a[j] >= tmp) {
                    j--;
                }
                if (i < j) {
                    a[i++] = a[j];
                }
                while (i < j && a[i] < tmp) {
                    i++;
                }
                if (i < j) {
                    a[j--] = a[i];
                }
            }
            a[i] = tmp;
            QSort(l, i - 1);
            QSort(i + 1, r);
        }
    }

    public static int BinarySearch(int size, int x) {
        int l = 0, r = size - 1;
        int mid;
        while (l <= r) {
            mid = (l + r) >> 1;
            if (x < a[mid])
                r = mid - 1;
            else if (x > a[mid])
                l = mid + 1;
            else
                return mid;
        }
        return -1;
    }

    public static void main(String[] args) {

        int n;
        Scanner sc = new Scanner(System.in);
        System.out.println("请输入数组的长度（1~20）：");
        n = sc.nextInt();
        System.out.println("请输入" + n + "个数");
        for (int i = 1; i <= n; i++) {
            a[i - 1] = sc.nextInt();
        }
        QSort(0, n - 1);
        System.out.println("排序之后的数组为：");
        for (int i = 0; i < n; i++) {
            System.out.printf(a[i] + " ");
        }
        int T;
        System.out.println("请输入你要查询元素的次数：");
        T = sc.nextInt();
        while (T > 0) {
            T--;
            int x;
            System.out.print("请输入你要查询的元素：");
            x = sc.nextInt();
            int ans = BinarySearch(n, x);
            if (ans == -1) {
                System.out.println(x + "不在数组中");
            } else {
                System.out.println(x + "在数组中下标为" + ans);
            }
        }
    }
}
