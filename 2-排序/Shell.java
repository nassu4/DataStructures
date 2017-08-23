//希尔排序
public class Shell {
	public static void sort(Comparable[] a)
	{
		int N = a.length;
		int h = 1;
		while( h < N/3 ) h = h*3 + 1; //1,4,13,40
		while( h >= 1 ) {
			//构造h有序数组
			for( int i = h; i < N; i++ ) {
				//将a[i]插入到a[i-h],a[i-2h],a[i-3h]......
				for( int j = i; j >= h && less(a[j],a[j-h]); j -= h ) {
					exch(a, j, j-h);
				}
			}
			h = h/3;
		}
	}
	private static boolean less(Comparable v, Comparable w)
	{ return v.compareTo(w) < 0; }
	private static void exch(Comparable[] a, int i, int j)
	{ Comparable t = a[i]; a[i] = a[j]; a[j] = t; }
	public static boolean isSorted(Comparable[] a)
	{
		int N = a.length;
		for( int i = 1; i < N; i++ ) {
			if ( less(a[i],a[i-1]) ) return false;
		}
		return true;
	}
	public static void show(Comparable[] a)
	{
		int N = a.length;
		for( int i = 0; i < N; i++ ) {
			StdOut.print(a[i] + " ");
		}
		StdOut.println();
	}
	public static void main(String[] args)
	{
		String[] a = In.readStrings();
		sort(a);
		assert isSorted(a);
		show(a);
	}
}
