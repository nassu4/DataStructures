
public class Quick {
	public static void sort(Comparable[] a)
	{
		StdRandom.shuffle(a);
		sort(a,0,a.length-1);
	}
	private static void sort(Comparable[] a, int lo, int hi)
	{
		if( hi <= lo ) return;
		int j = partition(a, lo, hi); //�з�
		sort(a,lo,j-1);		//�ݹ�������������
		sort(a,j+1,hi);		//�ݹ�������������
	}
	private static int partition(Comparable[] a, int lo, int hi)
	{
		int i = lo, j = hi+1;	//����ɨ��ָ��
		Comparable v = a[lo];	//�з�Ԫ��
		while( true ) {
			while( less(a[++i],v) ) { if( i == hi) break; }
			while( less(v,a[--j]) ) { if( j == lo) break; }
			if( i >= j ) break;
			exch(a , i, j);
		}
		exch(a,lo,j);  //��v = a[j]������ȷλ��
		return j;      //a[lo...j-1] <= a[j] <= a[j+1...hi]���
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
