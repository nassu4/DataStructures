//三向切分的快速排序
public class Quick3way {
	public static void sort(Comparable[] a)
	{
		StdRandom.shuffle(a);
		sort(a,0,a.length-1);
	}
	private static void sort(Comparable[] a, int lo, int hi)
	{
		if( hi <= lo ) return;
		
		int lt = lo, i = lo + 1, gt = hi;
		Comparable v = a[lo];
		while( i <= gt ) {
			int tmp = a[i].compareTo(v);
			if ( tmp < 0 ) exch(a, lt++, i++);
			else if( tmp > 0 ) exch(a, i, gt--);
			else i++;
		}	//now a[lo...lt-1] < v = a[lg...gt] < a[gt+1...hi]
		
		sort(a,lo,lt-1);
		sort(a,gt+1,hi);
		
	}
	private static boolean less(Comparable v, Comparable w)
	{
		return v.compareTo(w) < 0;
	}
	private static void exch(Comparable[] a, int i, int j)
	{
		Comparable t = a[i];
		a[i] = a[j];
		a[j] = t;
	}
	public static boolean isSorted(Comparable[] a)
	{
		int N = a.length;
		for( int i = 1; i < N; i++ ) {
			if( less(a[i],a[i-1]) ) return false;
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
		String[] a = StdIn.readAllStrings();
		sort(a);
		assert isSorted(a);
		show(a);
	}
}
